# PulseKit — Audio-Channel → Material/Visual Design Map

**Author:** Channel-Research worker (read-only investigation)
**Date:** 2026-06-01
**Scope:** Map all 13 live `mod_out` OSC channels (rbga-engine "beat core" / hotframe) to the PulseKit radial-pulse material `M_RadialPulse` + the linear-HDR OSC color pipeline, design the LOW glowing-pattern feature, supply a reusable texture help-prompt, and recommend the OSCBridge capture additions for the not-yet-captured channels.

> **Primary source = the engine code itself.** All channel semantics below are quoted/derived from the rbga-engine repo on disk (`C:\Privat\RBGA\ClaudeCode\rbga-engine`, commit `81d0b11` "channels: K1/K2/K3 — sub_pressure + spectrum_tilt + roughness (mod_out → 13)"). Web research only corroborates the DSP *meaning* of the three new descriptors; it is cited inline and in §Sources.

---

## 0. Ground Truth — what the engine actually emits today

### 0.1 The exact 13 `mod_out` channels (authoritative)

From `tools/audio_monitor/backend/engine_controller.py`, the `mod_out` dict (post-commit `81d0b11`) — these are **exactly** the 13 channels currently leaving the engine. Note: as of this commit the **clean** `mod/BASS…mod/HIGH` are **no longer emitted** (they keep running internally; `_xf`/significance/state depend on them — "KEIN Abkapseln, nur kein Output"). Frequency content is now the **decorrelated `_xf` set only**.

| # | mod_out key | Range | What it is (engine docstring) |
|---|-------------|-------|-------------------------------|
| 1 | `mod/BASS_xf` | [0,1] | BASS, cross-filtered (neighbour-bleed removed). subbass 20–80 Hz: sub-pressure / kick fundament |
| 2 | `mod/LOW_xf` | [0,1] | LOW, cross-filtered. bass+lowmid 80–800 Hz: kick body + bassline |
| 3 | `mod/MID_xf` | [0,1] | MID, cross-filtered. mid 800–2000 Hz: vocal / lead / snare-body |
| 4 | `mod/HIGH_xf` | [0,1] | HIGH, cross-filtered. highmid+presence+air 2–16 kHz: snare-crack, hats, air |
| 5 | `mod/roughness` | [0,1] | **K3** sensory roughness / beating proxy = sum of positive adjacent covariance (shared neighbour co-movement), PeakNorm'd, optionally companded |
| 6 | `mod/sub_pressure` | [0,1] | **K1** slow sustain-EMA on `BASS_xf` (bassline-bleed-cleaned sub) × tanh-compand → held sub *pressure*, not per-kick transient |
| 7 | `mod/spectrum_tilt` | **[-1,+1]** | **K2** `(HIGH_xf − BASS_xf)/(HIGH_xf + BASS_xf)`, scale-free. +1 bright / −1 dark / 0 balanced **or silence** |
| 8 | `mod/significance` | [0,1] | Cross-channel **onset coincidence**: ≥3-of-4 channels *attack synchronously* → pulse (order-statistic, asymmetric attack/release envelope) |
| 9 | `mod/sustain_trend_BASS` | **[-1,+1]** | sustain(now) − sustain(2 s ago) for BASS group: rising/falling held energy |
| 10 | `mod/sustain_trend_LOW` | **[-1,+1]** | sustain trend, LOW group |
| 11 | `mod/sustain_trend_MID` | **[-1,+1]** | sustain trend, MID group |
| 12 | `mod/sustain_trend_HIGH` | **[-1,+1]** | sustain trend, HIGH group |
| 13 | `mod/audio_present` | **int 0/1** | gate: is there audio at all (silence detector) |

**OSC address convention (confirmed via project memory `[[project-pulsekit-radial-pulse]]`): the engine key `mod/BASS_xf` arrives in UE as `/mod/mod/BASS_xf`** — the `/mod/` transport namespace is prepended to the already-`mod/`-prefixed HotFrame key. So a single wildcard binding `/mod/mod/*` captures the whole block, and the captured suffix (`BASS_xf`, `roughness`, …) becomes the MPC parameter name (see §5).

### 0.2 Engine docstring quotes (verbatim, the load-bearing semantics)

**K3 roughness** (`engine/channels/base.py`, `CrossFilter`):
> "the sum of the positive adjacent covariance — how strongly neighbouring bands fluctuate TOGETHER — is a texture/beating measure [0,1] (PeakNorm-normalised, AP-3). Pure by-product: `step()` does NOT change the 4 `_xf` outputs … Cheap proxy — true Vassilakis envelope modulation (20–300 Hz) would be K3-P2."

**K1 sub_pressure** (`class SubPressure`):
> "slow sustain-envelope on `BASS_xf` (sub-pressure as driver, not per-kick transient) × tanh_compand lift. `BASS_xf` is the LOW-bleed-cleaned sub-energy → pure held sub pressure. In silence `bass_xf → 0 → EMA → 0 → 0` (AP-3)."

**K2 spectral_tilt** (`def spectral_tilt`):
> "`(high − bass)/(high + bass)`, clamped to [-1,+1]. +1 = bright (energy up top), −1 = dark (energy down low), 0 = balanced OR silence … scale-free (ratio) → reacts to the *distribution*, not the level."

**Significance** (`class Significance`):
> "a signal as soon as ≥3 of the 4 channels swing roughly synchronously — and *onset-y* (on the attack, not the level; a held hill is not an onset) … the 3rd-largest of the 4 onsets is high ⟺ at least 3 channels attack simultaneously."

**sustain_trend** (`engine/feature/bands.py`): `sustain − Lag(sustain, 2 s)`, range [-1,1] — the slope of held-energy over a 2 s window (build-up vs drop).

**Character-per-channel** (`CHAR_MIX`, `ChannelsBase`): each frequency channel is *not* raw loudness; it is a convex mix per musical role:
- BASS = 0.70 sustain + 0.30 transient (body + a little punch)
- LOW = 0.45 sustain + 0.55 transient (punch + body, balanced)
- MID = 0.55 sustain + 0.45 transient (body + punch)
- HIGH = 0.25 sustain + 0.45 transient + 0.30 density (shimmer + busyness)
This matters: `*_xf` already carries musical character (attack vs sustain weighting), not a bare envelope follower.

### 0.3 Historic "mod-curves" in project memory — reconciliation

Project memory referenced `Kick_punch, Sub_pressure, Snare_punch, Contrast, Cymbal_shimmer, Phase`. Mapping to today's actual emitted set:
- **Sub_pressure** → shipped as `mod/sub_pressure` (K1). ✔
- **Kick_punch / Snare_punch** → *not* discrete channels today; they live inside `LOW_xf` / `MID_xf`/`HIGH_xf` (transient-weighted character) and fire `significance` on coincident onsets. Treat `significance` as the global "punch" pulse; per-register punch = the transient bias already baked into the `_xf` channels.
- **Cymbal_shimmer** → `HIGH_xf` (transient+density character of hats/air) — use it for sparkle (operator's HIGH intent). A dedicated shimmer channel is *not* emitted.
- **Contrast** → closest live analog is `spectrum_tilt` (bright↔dark balance) and `roughness` (textural busyness). No separate "contrast" channel.
- **Phase** → **not in the 13**. The engine has `phase.beat_interval` internally and a `phase` block in the HotFrame, but it is outside the `mod/` budget. If beat-phase-locked motion is wanted, it must be re-enabled/added (see §5.4). Until then, derive cyclic phase **in-shader** from `Time`/`PulsePeriod` (the material already self-cycles).

---

## 1. The visual target — `M_RadialPulse` parameter surface (confirmed from the asset)

Extracted from `C:\development\Projects\MCP\Content\Materials\M_RadialPulse.uasset` (Custom-HLSL core → Emissive + WorldPositionOffset). Parameter groups: **Pulse - Geometry**, **Pulse - Shape**, **Pulse - Look**.

| Param | Type | Role (from HLSL core) |
|-------|------|------|
| `PulseSpeed` | Scalar | wave propagation speed; `radius = Speed * localT` |
| `PulseWidth` | Scalar | ring thickness; `xb = (dist − front)/Width`; also scales wobble amplitude |
| `PulseBounds` | Scalar | max radius; `boundsFade = 1 − smoothstep(Bounds*0.85, Bounds, radius)` |
| `PulseGain` | Scalar | output intensity multiplier (emissive strength) |
| `PulsePeriod` | Scalar | self-cycle period; `localT = Time − floor(Time/Period)*Period` |
| `PulseWobble` | Scalar | wobble amount on the wavefront (`front += w * Wobble * Width`) |
| `PulseWobbleFreq` | Scalar | angular frequency of the seamless wobble harmonics |
| `PulseColor` | Vector | emissive tint (linear/HDR) |
| `PulseSeed` | Scalar | per-instance randomisation |
| `PulseCenter` | Vector | wave origin in world space |
| `PulseWPOAmount` | Scalar | world-position-offset displacement amount |

Core math (verbatim from the asset's Custom node):
```hlsl
float pp = max(Period, 1e-3);
float w = sin(ang*WobbleFreq + ph*1.3) * 0.55
        + sin(ang*WobbleFreq*1.91 - ph*0.7) * 0.30
        + sin(ang*WobbleFreq*3.74 + ph*2.1) * 0.15;   // seamless integer-harmonic wobble
float radius = Speed * localT;
float front  = radius + w * Wobble * Width;
float xb     = (dist - front) / max(Width, 1e-3);
float band   = <ring profile of xb>;
float centerFade = saturate(dist / max(Width, 1e-3));
float boundsFade = 1.0 - smoothstep(Bounds*0.85, Bounds, radius);
return band * centerFade * boundsFade * lifeFade;
```

There is also the **linear-HDR OSC color pipeline** (`Content/OSC/*`): `MPC_OSCColorCurve` + `M_OSCGradientAtlas` (RGBA16f render-target atlas, `RT_OSCGradientAtlas`) fed by `OSCBridgeRouter` `CurveBindings` on `/col/*`. The "color curve" is the gradient the operator wants the LOW glow to *correspond to* (see §3). Pipeline is end-to-end linear; sRGB only at the React display edge (memory `[[reference-osc-color-pipeline-linear]]`).

---

## 2. Per-channel design map (all 13)

For each: **(a)** what it measures, **(b)** value character, **(c)** concrete material mapping (param + how: base+gain / envelope / curve-shape), **(d)** architecture layer.

Architecture layers used below:
- **Shader** = drive an MPC scalar/vector straight into `M_RadialPulse` / color material (cheap, continuous).
- **Conductor (C++)** = the PulseKit C++ component (`UPulseTriggerComponent` / a new `UPulseConductorComponent`) does heavy lifting: envelope shaping, beat-sync, multi-channel mixing, slot scheduling, mapping bipolar → unipolar with smoothing. This is where "monster fat" coherence is built.
- **BP glue** = OSCBridgeRouter bindings + MID parameter wiring; no logic.

> Normalisation note: bipolar channels (`spectrum_tilt`, `sustain_trend_*`) must be remapped before they hit a material that expects [0,1]. Either bind with `Scale=0.5, Offset=0.5` in the Router (→ [0,1]) **or** keep them raw in the MPC and remap in-shader/conductor where a signed push is wanted. Recommendation per channel below.

### 2.1 `BASS_xf` — sub/kick fundament  → **the wave engine itself**
- **(a)** Cross-filtered subbass character (sustain-biased, 0.70/0.30). The cleanest "the kick/sub is hitting now" continuous signal.
- **(b)** [0,1], impulsive-on-sustain-bed: spikes on kicks, decays between. Already character-shaped + companded.
- **(c)** Primary **drive** of the pulse. `PulseGain = GainBase + BASS_xf * GainSpan` (base+gain so the wave never fully dies — operator's "subtle shimmer when calm"). Secondary: feed the **LOW glow's activity term** (§3) — the operator explicitly wants the LOW glow computed *partly from the current bass-wave position*. Also a good `PulseWPOAmount` driver for physical "thump" displacement on kicks.
- **(d)** Shader for `PulseGain`; **Conductor** for retrigger/slot scheduling (already the pivot in `[[project-pulsekit-radial-pulse]]`: continuous curve-driven instead of binary threshold) and for feeding the LOW feature.

### 2.2 `LOW_xf` — kick body + bassline  → **LOW glowing pattern (operator's headline feature)**
- **(a)** bass+lowmid, balanced punch/body (0.45/0.55). The "bassline groove" register.
- **(b)** [0,1], rhythmic, more continuous than BASS (bassline sustain).
- **(c)** Drives the **LOW glow feature** (full spec §3): a noise-panned glow that emits clean structures *derived from the bass wave* and *corresponding to the color curve*; glow strength scales with surface activity (trembling), subtle shimmer when calm, veiled by overlaid patterns. Concretely: `GlowStrength = f(LOW_xf, BASS_xf, |WPO velocity|)`, panner speed ∝ a slow function of LOW.
- **(d)** **Shader** for the glow sampling/compositing; **Conductor** supplies the smoothed activity envelope + bass-wave phase. Bind `Scale/SmoothingAlpha` for a musical (not flickery) glow.

### 2.3 `MID_xf` — vocal / lead / snare-body  → **structural pattern changes**
- **(a)** Pure mid band (highmid moved to HIGH so hats don't bleed). Vocal/lead/snare body.
- **(b)** [0,1], melodic/structural; less strobey than HIGH.
- **(c)** Operator: **MID → structural changes in the pattern.** Drive *structure-defining* params, not brightness: `PulseWobbleFreq` (changes the wavefront geometry/harmonic complexity), `PulsePeriod` (re-times the cycle on a section change), and the **structure/veil selection** in the LOW feature (which overlaid pattern is foregrounded, or pattern UV scale). Use as a slow morph target, not a per-frame jitter.
- **(d)** **Conductor** (slow-morph / lerp between structural presets so changes read as deliberate), MPC scalar to shader for the chosen structural value.

### 2.4 `HIGH_xf` — hats / cymbals / air  → **highlights & sparkle accents**
- **(a)** highmid+presence+air, transient+density character (shimmer + busyness). Hi-hat attack/pattern.
- **(b)** [0,1], spiky/fast.
- **(c)** Operator: **HIGH → highlights / sparkle accents.** Additive sparkle on the wavefront: a high-frequency sparkle term `+= HIGH_xf * SparkleGain` added to emissive at the ring crest, and a `PulseColor` highlight push toward the bright end of the color curve. Keep it *additive accent* (rim sparkle), never the base — so calm passages stay clean.
- **(d)** **Shader** (cheap additive sparkle, e.g. high-freq noise gated by `HIGH_xf` at the ring band); optional **Conductor** smoothing to tame strobe per the AP-4 note in `05_channels_base.md`.

### 2.5 `roughness` (K3) — sensory beating / texture  → **grain / dissonance veil**
- **(a)** Shared neighbour co-movement = how "beaty/rough/busy" the spectrum is (cheap Vassilakis-style proxy; corroborated by Vassilakis roughness literature — roughness = buzzing sensation from ~15–150 Hz amplitude modulation / sensory dissonance, [acousticslab.org](http://www.acousticslab.org/papers/diss1.htm), [Wikipedia spectral concepts]).
- **(b)** [0,1], slow-ish (4 s PeakNorm halflife), continuous "texture energy".
- **(c)** Drives **textural grain / micro-detail**: amplitude of a fine high-frequency noise overlay on the surface (more roughness → more grain/boil), and a small additive on `PulseWobble` (rougher mix → more wavefront tremble). In the color path, roughness can push saturation/contrast (rough = harsher). This is a *veil/texture* control, not a primary pulse.
- **(d)** **Shader** (noise amplitude + wobble add). Low rate ⇒ no conductor needed; bind with mild `SmoothingAlpha`.

### 2.6 `sub_pressure` (K1) — held sub pressure  → **ambient glow floor / WPO swell**
- **(a)** Slow sustain-EMA on `BASS_xf` = the *felt* sub pressure (felt-not-heard 20–80 Hz weight; corroborated by sub-bass production refs — sub is "felt more than heard", sustains energy, [EDMProd](https://www.edmprod.com/sub-bass/), [Wood&Fire](https://woodandfirestudio.com/en/sub-bass-eq/)).
- **(b)** [0,1], **slow / smooth** (0.8 s τ). The continuous "how much weight is in the room" driver — not transient.
- **(c)** Perfect for the operator's **"glow stronger around the trembling/active surface, subtle shimmer when calm"** *floor*: `GlowFloor = sub_pressure` raises the LOW glow's baseline and a slow `PulseWPOAmount` swell (the wall "breathes" under sustained sub). Also a global `PulseGain` floor so the whole field has body during a sustained drop/build. Because it is already slow, it needs little smoothing.
- **(d)** **Shader** (direct floor add); **Conductor** mixes it into the LOW glow envelope.

### 2.7 `spectrum_tilt` (K2) — bright↔dark balance  → **color-curve position / palette tilt**
- **(a)** Scale-free HIGH-vs-BASS balance = brightness/tilt of the mix (spectral-slope/tilt descriptor: how the spectrum tips bright vs dark, [Wikipedia: Spectral slope](https://en.wikipedia.org/wiki/Spectral_slope), [ScienceDirect: Spectral slope](https://www.sciencedirect.com/topics/engineering/spectral-slope)).
- **(b)** **[-1,+1]**, smooth-ish, *0 also means silence* — so gate with `audio_present` or `sub_pressure` to avoid drifting to "balanced/neutral" colour during silence.
- **(c)** **Drives palette/color-curve sampling position.** Map tilt → the U coordinate into the OSC gradient atlas / `MPC_OSCColorCurve` so a bright mix samples the bright end of the operator's color curve and a dark mix the dark end. This is the cleanest realisation of "highlights/structure that correspond to the color curve". Optionally a subtle `PulseColor` temperature shift. Remap [-1,+1] → [0,1] with `Scale=0.5,Offset=0.5`.
- **(d)** **Shader** (gradient-U from an MPC scalar). Gate-in `audio_present` either in the **Conductor** or via a `min(tilt01, audio_present)`-style shader mul.

### 2.8 `significance` — ≥3-of-4 synchronous onset  → **the global "punch" event**
- **(a)** Onset coincidence pulse — fires when the whole kit hits together (downbeats, drops, big hits). Clean onset envelope (instant attack, short release).
- **(b)** [0,1], **impulsive** (sharp pulse, not continuous).
- **(c)** The **primary pulse trigger / accent**. Two uses: (1) a **retrigger gate** in the Conductor — fire a new radial wave slot when `significance` crosses a threshold (this is the musical "X injection points, sequence/random" the original design wanted, now beat-coherent instead of bass-threshold); (2) a momentary global `PulseGain`/bloom kick (`Gain += significance * PunchSpan`) for whole-field emphasis on synchronised hits.
- **(d)** **Conductor** (rising-edge → `FirePulse()`, cooldown; this replaces the old binary BASS threshold). Shader for the additive bloom kick.

### 2.9–2.12 `sustain_trend_{BASS,LOW,MID,HIGH}` — build/drop slope  → **macro-arc / dramaturgy**
- **(a)** Per-register slope of held energy over 2 s: **+ = building, − = dropping/breakdown.** This is the *arrangement-level* dramaturgy signal (the engine explicitly uses these for break/build state detection).
- **(b)** **[-1,+1]**, slow (2 s window). Four near-independent macro signals.
- **(c)** Drive **slow macro modulation**, not per-frame motion:
  - `sustain_trend_BASS/LOW` → ramp `PulseBounds`/`PulseGain` *up* during a build (wave reaches further, brighter), pull *in* during a drop → the field literally inhales on a breakdown and explodes on the drop. Great "monster fat" macro behaviour.
  - `sustain_trend_HIGH` → ramp the HIGH sparkle ceiling (riser/sweep energy).
  - `sustain_trend_MID` → bias the structural-morph direction (§2.3).
  - Sign is the value: feed raw [-1,+1] into the Conductor and let it integrate/ramp a target so a sustained + slowly opens the field and a sustained − closes it.
- **(d)** **Conductor** (these *must* be integrated/smoothed into slow targets; raw they are too slow/noisy to bind to a param directly). Keep raw [-1,+1] in the MPC for diagnostics.

### 2.13 `audio_present` — silence gate  → **master fade / neutral-guard**
- **(a)** 0/1 (int) is-there-audio.
- **(b)** Binary, slow.
- **(c)** **Master enable / fade-to-calm.** Multiply the whole emissive/glow chain by a smoothed `audio_present` so silence → graceful fade to the calm shimmer floor (not a hard cut). Crucially also **gates `spectrum_tilt`** (whose 0 is ambiguous with silence) and any ratio-based channel so they don't drift to a false "neutral/balanced" colour in silence.
- **(d)** **Conductor** (smooth the 0/1 into a fade envelope; bind as int, EMA in C++). Shader consumes the smoothed scalar.

---

## 3. LOW glowing-pattern feature — shader-feature spec

**Goal (operator, verbatim intent):** a glowing pattern that, via a **noise-panner**, emits clean clear **structures derived from the bass wave** that **correspond to the color curve**; computed *partly from the current bass-wave position*; **glows stronger around the trembling/active surface** and only **subtly shimmers when calm**, **partly veiled by overlaid patterns** (operator supplies/generates those patterns — see §4).

This is a self-contained feature inside (or alongside) `M_RadialPulse`'s emissive, summed under the existing ring `band`.

### 3.1 Inputs (MPC scalars/vectors + textures)
- From audio (OSC_MPC): `LOW_xf`, `BASS_xf`, `sub_pressure`, `spectrum_tilt` (→tilt01), `roughness`, smoothed `audio_present`.
- From the wave core (computed in the same Custom node, already present): `radius`, `front`, `dist`, `band`, `localT`, the wobble `w`.
- Textures (operator-generated, §4): `T_LowPattern` (primary structure), `T_Veil_A`, `T_Veil_B` (overlay/veil patterns) — seamless, tileable, grayscale/packed.
- Color: the OSC gradient atlas row (`RT_OSCGradientAtlas` / `MPC_OSCColorCurve`) = "the color curve".

### 3.2 Algorithm (per pixel)
```hlsl
// --- 1. Bass-wave-derived coordinate (the "structure derived from the bass wave") ---
// Use the live wavefront as a moving iso-line. Distance-from-front, signed & normalized:
float waveCoord = (dist - front) / max(Width*3.0, 1e-3);     // 0 at the crest, grows outward
float wavePhase = frac(localT / pp + dist * RingDensity);    // concentric rings tied to THIS pulse

// --- 2. Noise-panner: pan pattern UVs along the wave's outward direction, speed from LOW ---
float2 dir   = normalize(worldToSurface(P) - PulseCenter.xy);// radial outward on the surface plane
float  panSp = PanBase + LOW_xf * PanGain;                   // bassline drives flow speed
float2 uv    = surfaceUV(P) * PatternTiling + dir * (Time * panSp);
float  patt  = T_LowPattern.Sample(uv).r;                    // clean primary structure
// bind the structure to the bass wave: keep structure only where the wave is "present"
float  structure = patt * smoothstep(1.2, 0.0, abs(waveCoord))  // concentrated near the front
                 + patt * wavePhase * RingWeight;               // + concentric bass rings

// --- 3. Activity term (glow stronger around the trembling/active surface) ---
// "trembling" = local wavefront motion + wobble + transient energy.
float wobbleTremor = abs(w) * Wobble;                        // geometric tremble already in the core
float activity = saturate( ACT_K0
               + ACT_K1 * BASS_xf                            // operator: part of it from the bass wave
               + ACT_K2 * LOW_xf
               + ACT_K3 * wobbleTremor
               + ACT_K4 * roughness );                       // rough mix => more agitated glow
float floorGlow = sub_pressure * CALM_FLOOR;                // subtle shimmer when calm (held sub)
float glowStrength = max(floorGlow, activity);              // never below the calm floor

// --- 4. Veil: overlay operator patterns, partly occluding (multiplicative veil) ---
float2 vuv = surfaceUV(P) * VeilTiling - dir * (Time * panSp * VeilDrift);
float veil = lerp(1.0, T_Veil_A.Sample(vuv).r, VeilAmtA)
           * lerp(1.0, T_Veil_B.Sample(vuv*1.37 + 0.5).r, VeilAmtB);
// MID picks/foregrounds the veil (structural change, §2.3): VeilAmtA/B or VeilSelect from MID_xf.

// --- 5. Color correspondence: sample the operator color curve ---
float curveU = saturate(0.5 + 0.5*spectrum_tilt);          // tilt drives palette position
// optionally fold structure into U so brighter structures pull a brighter colour:
curveU = saturate(curveU + structure * CURVE_STRUCT_W);
float3 glowColor = SampleColorCurve(curveU);               // RT_OSCGradientAtlas row (linear/HDR)

// --- 6. Composite ---
float3 lowGlow = glowColor * structure * glowStrength * veil * GlowGain;
lowGlow *= smoothedAudioPresent;                           // graceful fade in silence
// add UNDER the ring band so the ring still reads on top:
emissive += lowGlow;
```

### 3.3 Behaviour guarantees (mapping back to the brief)
- **Derived from the bass wave** → `waveCoord`/`wavePhase` are functions of the *same* `front`/`radius`/`localT` that draw the wave, and `BASS_xf` feeds both the wave gain and the activity term. "Computed partly from the current bass-wave position" is literal.
- **Corresponds to the color curve** → glow colour is sampled from `RT_OSCGradientAtlas` at a U driven by `spectrum_tilt` (+optional structure), i.e. the exact operator color curve, in the linear-HDR space the pipeline mandates.
- **Glows stronger around the trembling/active surface** → `glowStrength` rises with wobble tremor + BASS/LOW + roughness, concentrated near the moving front via `smoothstep(abs(waveCoord))`.
- **Subtle shimmer when calm** → `floorGlow = sub_pressure * CALM_FLOOR` keeps a gentle, slow shimmer when transients are absent; `glowStrength = max(floor, activity)` guarantees it never goes black while audio is present.
- **Partly veiled by overlaid patterns** → multiplicative `veil` from operator textures, drifting via the same panner; MID selects/foregrounds which veil (structural change).
- **AP-3 safe** → everything multiplies by smoothed `audio_present`; in silence `BASS_xf, sub_pressure → 0`, glow → 0.

### 3.4 Architecture split
- **Shader** owns §3.2 entirely (it is per-pixel and cheap: 3 texture taps + the already-computed wave terms; ~budget-friendly given the existing ~30-ALU core).
- **Conductor (C++)** owns: smoothing `audio_present` → fade; integrating `sustain_trend_*` into slow `GlowGain`/`PulseBounds` macro ramps; deriving a clean `activity` smoothing if the raw mix flickers; and the MID structural-morph lerp feeding `VeilSelect`/`PatternTiling`.
- **BP glue**: OSCBridge bindings (§5) and the MID instance parameter wiring.

### 3.5 Tunables (expose as MPC scalars or material params)
`RingDensity, RingWeight, PanBase, PanGain, PatternTiling, ACT_K0..K4, CALM_FLOOR, VeilTiling, VeilAmtA, VeilAmtB, VeilDrift, CURVE_STRUCT_W, GlowGain`. Default them dial-bar / eye-test-gated (matches the engine's whole "Worker-Default-Choice, eye-test-gated" doctrine).

---

## 4. Reusable HELP-PROMPT for texture generation (AI image/texture generator)

> **Use this prompt (fill the `{…}` slot) to generate the LOW-channel pattern + the two veils.** All three must be **seamless / tileable** and read as **clean organic VJ structures**, not photoreal.

### 4.1 Master prompt template
```
A seamless, perfectly tileable {STRUCTURE} texture for a live VJ / audio-reactive
shader. Grayscale (single-channel mask), high dynamic range, clean black background
(value 0) with luminous structures in mid-to-white. Organic, flowing, hand-of-a-
designer aesthetic — NOT noisy TV static, NOT photoreal, NOT 3D-rendered objects.
Structures are crisp and clearly readable at a distance, with smooth gradients
between them (no hard aliasing, no jpeg blocks). Even spatial distribution so it
tiles without visible seams or hotspots; edges wrap continuously on all four sides.
No text, no watermark, no border, no vignette, flat even lighting, orthographic top-
down. 2048x2048, square, looping/repeating motif. Designed to be panned and layered
in real time. Color space: linear-friendly grayscale (mid-grey ~0.5 carries the
structure; reserve pure white for accents only).
```

### 4.2 Three concrete fills

**(A) Primary LOW structure — `T_LowPattern`** (the clean structure the bass wave reveals):
```
{STRUCTURE} = "concentric and interweaving organic ring/contour lines, like
topographic iso-lines or ferrofluid ridges, smooth flowing bands of varying
thickness, gentle branching, suggesting energy radiating outward; medium density,
clear negative space between ridges"
```
Notes: ridge-like contours read beautifully when panned radially and gated by the wavefront. Keep ~40–60% black so the veil and ring stay visible.

**(B) Veil pattern A — `T_Veil_A`** (soft occluding overlay):
```
{STRUCTURE} = "soft cloudy filamentary veil, wispy smoke-like strands and slow
curl-noise tendrils, low contrast, mostly mid-grey with darker gaps, large smooth
features, dreamy and atmospheric"
```
Purpose: multiplicative veil that *partly* hides the structure (large soft features → gentle occlusion, not speckle).

**(C) Veil pattern B — `T_Veil_B`** (finer structural overlay, MID-selectable):
```
{STRUCTURE} = "fine organic cellular / Voronoi-membrane lattice, thin bright cell
walls on dark cells, irregular natural cell sizes, like soap-film or leaf-vein
microstructure, crisp thin lines, medium-high density"
```
Purpose: when MID foregrounds the veil, the surface gains visible fine structure (the "structural change in the pattern" intent).

### 4.3 Production guidance for whoever generates these
- **Verify tiling**: offset the image by 50% (wrap) and check seams; regenerate or heal the seam if visible. Most generators are *not* truly seamless by default — request "seamless tileable" explicitly and post-verify.
- **Deliver grayscale**, ideally pack the three into one RGBA: R=`T_LowPattern`, G=`T_Veil_A`, B=`T_Veil_B`, A=spare/derivative (e.g. a blurred copy for soft falloff). One texture tap instead of three → cheaper shader.
- **Resolution** 2048² (or 1024² if VRAM-tight); mipmaps on; **no sRGB** flag on the mask textures (they are data masks, sample linearly — consistent with the linear pipeline in `[[reference-osc-color-pipeline-linear]]`).
- **Variants**: generate 2–3 of each so the operator can hot-swap looks per show; keep the same density/contrast so the shader tuning carries over.

---

## 5. OSCBridge capture additions — wiring the not-yet-captured channels

### 5.1 What's already captured vs. what's missing
Project memory shows the live pivot started on **`BASS_xf`** at `/mod/mod/BASS_xf` (one float binding). The editor settings show the Router currently has ~5 FloatBindings configured. So **at most a few of the 13 are bound today**; the design below captures **all 13** cleanly with the wildcard pattern so nothing is hand-maintained.

### 5.2 Recommended binding strategy — one wildcard, one MPC
The OSCBridge router supports trailing-wildcard patterns where **the captured suffix becomes the MPC parameter name** (`ResolveParamName` → `CapturedSuffix`, confirmed in `OSCBridgeRouter.cpp`). So:

**Binding 1 — capture the whole unipolar `mod/` block in one go:**
- `Pattern = /mod/mod/*`
- `TargetMPC = OSC_MPC`
- `ParameterName = ` *(empty → use captured suffix, e.g. `BASS_xf`, `roughness`, `sub_pressure`, `significance`)*
- `Scale = 1`, `Offset = 0`, `bClamp = true`, `ClampMin = 0`, `ClampMax = 1`
- `SmoothingAlpha` = **per-channel** is impossible on a single wildcard binding (alpha is per-binding). Pick a **medium 0.4–0.5** as the block default; then **override the few that need different smoothing with explicit higher-priority exact bindings** (below). Because all matching bindings fire, prefer: wildcard for the long tail + **exact bindings for the channels you actively drive**.

> Caveat: a single wildcard means one Scale/Clamp/Smoothing for all matched channels, and it will also try to write `spectrum_tilt`, `sustain_trend_*` (which are [-1,+1]) and `audio_present` (int) as clamped [0,1] floats — wrong for the bipolar/int ones. **Therefore: wildcard ONLY the unipolar [0,1] set, and give the bipolar/int channels their own exact bindings.** Two clean options:

**Option A (recommended) — explicit per-channel bindings (full control, self-documenting):** one `FOSCFloatBinding` per channel. MPC param name = the channel name (create these scalars in `OSC_MPC`). This is the most predictable and is what the operator's "explicit references preferred" doctrine (`[[feedback_explicit_references_preferred]]`) favours.

**Option B — hybrid:** wildcard `/mod/mod/*` (clamp 0..1, alpha 0.45) for the unipolar block as a safety net, **plus** exact bindings (listed below) that override the bipolar/int channels and any channel needing different smoothing. (Exact + wildcard both fire; the last write per frame wins — order the array so exact bindings come after the wildcard, or just use Option A.)

### 5.3 Per-channel binding table (Option A — the full 13)

MPC params to add to `OSC_MPC` (Scalar unless noted). Names match the captured suffix so a later switch to the wildcard is drop-in.

| OSC address | MPC param (OSC_MPC) | Type | Scale | Offset | Clamp | SmoothingAlpha | Rationale |
|-------------|---------------------|------|-------|--------|-------|----------------|-----------|
| `/mod/mod/BASS_xf` | `BASS_xf` | Scalar | 1 | 0 | 0..1 | **0.6** (reactive) | drives the wave; want punch, light smoothing |
| `/mod/mod/LOW_xf` | `LOW_xf` | Scalar | 1 | 0 | 0..1 | 0.5 | LOW glow flow; medium |
| `/mod/mod/MID_xf` | `MID_xf` | Scalar | 1 | 0 | 0..1 | **0.3** (smooth) | structural morph; deliberate, not jittery |
| `/mod/mod/HIGH_xf` | `HIGH_xf` | Scalar | 1 | 0 | 0..1 | **0.7** (light) | sparkle wants to stay snappy |
| `/mod/mod/roughness` | `roughness` | Scalar | 1 | 0 | 0..1 | 0.4 | texture veil; medium |
| `/mod/mod/sub_pressure` | `sub_pressure` | Scalar | 1 | 0 | 0..1 | 0.5 (already slow) | glow floor / WPO swell |
| `/mod/mod/spectrum_tilt` | `spectrum_tilt` | Scalar | **0.5** | **0.5** | 0..1 | 0.4 | **remap [-1,1]→[0,1]** for gradient-U; gate w/ audio_present downstream |
| `/mod/mod/significance` | `significance` | Scalar | 1 | 0 | 0..1 | **0.0 / 0.8** | want the sharp onset; little/no smoothing (or read raw in conductor for edge-detect) |
| `/mod/mod/sustain_trend_BASS` | `sustain_trend_BASS` | Scalar | **0.5** | **0.5** | 0..1 | 0.3 | macro ramp; remap, smooth. (Or Scale=1/Offset=0 to keep raw signed in MPC and ramp in C++.) |
| `/mod/mod/sustain_trend_LOW` | `sustain_trend_LOW` | Scalar | 0.5 | 0.5 | 0..1 | 0.3 | macro ramp |
| `/mod/mod/sustain_trend_MID` | `sustain_trend_MID` | Scalar | 0.5 | 0.5 | 0..1 | 0.3 | structural bias |
| `/mod/mod/sustain_trend_HIGH` | `sustain_trend_HIGH` | Scalar | 0.5 | 0.5 | 0..1 | 0.3 | riser/sparkle ceiling |
| `/mod/mod/audio_present` | `audio_present` | **IntBinding** | 1 | 0 | 0..1 | n/a (smooth in C++) | master fade / neutral-guard; bind as Int, EMA the 0/1 in the conductor |

**Normalisation guidance recap:**
- **Unipolar [0,1] channels**: `Scale=1, Offset=0, Clamp 0..1`. SmoothingAlpha is the main dial — higher = more reactive (`0.6–0.7` for punch/sparkle, `0.3–0.4` for structural/textural, `0.5` default).
- **Bipolar [-1,+1] channels** (`spectrum_tilt`, `sustain_trend_*`): two valid policies — (i) **remap in the Router** `Scale=0.5, Offset=0.5, Clamp 0..1` so the MPC holds [0,1] (simplest for shader); or (ii) **keep raw** (`Scale=1, Offset=0`, no clamp) and remap where used (needed if the conductor wants the sign to integrate a ramp). Pick (i) for `spectrum_tilt` (shader gradient-U), (ii) for `sustain_trend_*` (C++ integrates the signed slope). The table shows (i) as default; switch the four trends to (ii) if you build the macro-ramp conductor.
- **`audio_present`**: use an **`FOSCIntBinding`** (it's an int 0/1), then smooth to a fade envelope in C++. Do not low-pass it in the Router (int).
- **`significance`**: keep `SmoothingAlpha` low (sharp onset) for the bloom-kick path; for the **retrigger** path read the value in the conductor and rising-edge detect (don't rely on smoothing).

### 5.4 Optional: re-enable parked channels / add `phase`
If the operator later wants more, the engine re-enables trivially (one-word swaps per the commit message): `transient_density_short_{BASS,LOW,MID,HIGH}` (busyness per register → drive `PulseWobble`/grain per band) and `rms/flux/centroid`. **`phase`** (beat phase) is *not* in `mod_out` but exists internally (`phase.beat_interval`) — to get beat-locked motion either surface a `phase/*` HotFrame channel and bind `/mod/phase/*`, or (cheaper now) derive cyclic phase in-shader from `Time/PulsePeriod` and only *re-sync* `PulsePeriod` from `significance` cadence in the conductor. Capturing these is the same pattern: exact float binding, clamp/normalise per range.

### 5.5 Mechanics notes
- `OSC_MPC` must contain a Scalar parameter for every name above before routing (the router writes by name; missing names are no-ops). Memory `[[reference-mcp-asset-creation-and-naming]]` covers MPC param JSON (camelCase + fabricated GUIDs) if adding via MCP.
- `bRouteInEditor=true` is required for the live editor preview (already the project's mode; MPC is live in-editor per OSCBridge D-9/D-11).
- After a manual editor restart, prime once with `ALT+P → ESC` so the OSC→MPC stream flows (`[[reference-ue-editor-pie-cycle-primes-mpc-stream]]`).

---

## 6. Architecture summary (where each thing lives)

| Layer | Owns |
|-------|------|
| **Shader** (`M_RadialPulse` Custom HLSL + color material) | Wave core; LOW glow feature (§3); HIGH sparkle; roughness grain; gradient-U from `spectrum_tilt`; all per-pixel compositing; consuming smoothed MPC scalars. |
| **Conductor (C++ — `UPulseTriggerComponent` → extend to `UPulseConductorComponent`)** | `significance` rising-edge → `FirePulse()` (retrigger, cooldown, sequence/random slot); integrate `sustain_trend_*` into slow macro ramps (`PulseBounds`/`GlowGain`); smooth `audio_present` → fade; gate `spectrum_tilt` by presence; MID structural-morph lerp; feed BASS-wave phase into the LOW feature; write driven params to the MIDs. |
| **BP glue (OSCBridgeRouter)** | The 13 bindings (§5); MID parameter wiring; `/col/*` color-curve atlas (existing). No logic. |

**Why this split:** the shader is cheap and continuous (good for the always-on glow/sparkle/grain); the C++ conductor is where *musical coherence* is built — beat-synced retriggers, slow macro dramaturgy from the trends, and the smoothing/normalisation that turns raw 100 Hz channels into a "monster fat", alive-but-not-flickery field. This matches the project's existing pivot (continuous curve-driven, conductor reads MPC) and the engine's own doctrine of eye-test-gated, dial-bar defaults.

---

## Sources

**Primary (on-disk repo — authoritative for all channel semantics):**
- `C:\Privat\RBGA\ClaudeCode\rbga-engine` — commit `81d0b11` ("channels: K1/K2/K3 — sub_pressure + spectrum_tilt + roughness (mod_out → 13)").
- `engine/channels/base.py` — `ChannelsBase` (CHAR_MIX character-per-channel), `PeakNorm`, `Significance`, `CrossFilter` (+ `.roughness` K3), `SubPressure` (K1), `spectral_tilt` (K2).
- `engine/channels/__init__.py` — public API.
- `engine/feature/bands.py` — `sustain_trend = sustain − Lag(sustain, 2 s)` [-1,1]; band-channel list.
- `tools/audio_monitor/backend/engine_controller.py` — the exact `mod_out` dict (the 13 emitted channels).
- `docs/spec/05_channels_base.md` — channels-base as-built (M3/M5 mapping, PeakNorm, AP-3/AP-4).
- `docs/spec/04_CHANNEL_RESEARCH.html`, `03_CHANNEL_VISION_RESEARCH.html` — referenced TD channel research (source of K1/K2/K3 candidates).

**UE project (on-disk):**
- `C:\development\Projects\MCP\Content\Materials\M_RadialPulse.uasset` — param surface + Custom HLSL core (extracted).
- `C:\development\Projects\MCP\Plugins\OSCBridge\Source\OSCBridge\Public\OSCBridgeRouter.h` + `Private\OSCBridgeRouter.cpp` — binding structs (Scale/Offset/Clamp/SmoothingAlpha), wildcard `Matches`/`CapturedSuffix`, `ResolveParamName`.
- Project memory (`~\.claude\projects\C--Claude_Projects-UE-claude\memory\`): `project_pulsekit_radial_pulse.md` (`/mod/mod/BASS_xf` address, pivot to curve-driven, conductor reads MPC), `reference_osc_color_pipeline_linear.md` (linear-HDR color curve / atlas), `reference_mcp_asset_creation_and_naming.md`, `reference_ue_editor_pie_cycle_primes_mpc_stream.md`.

**Web (corroborating DSP meaning of the three new descriptors):**
- Auditory/sensory roughness & beating (K3 roughness): Vassilakis, [acousticslab.org dissertation summary](http://www.acousticslab.org/papers/diss1.htm); [SRA / Roughness model SMC paper (PDF)](https://www.acousticslab.org/papers/Vassilakis2007SMC.pdf).
- Spectral tilt / spectral slope (K2 spectrum_tilt): [Wikipedia — Spectral slope](https://en.wikipedia.org/wiki/Spectral_slope); [ScienceDirect — Spectral slope overview](https://www.sciencedirect.com/topics/engineering/spectral-slope); [MathWorks — Spectral descriptors](https://www.mathworks.com/help/audio/ug/spectral-descriptors.html).
- Sub-bass as felt, sustained low-frequency pressure (K1 sub_pressure): [EDMProd — Sub-Bass](https://www.edmprod.com/sub-bass/); [Wood & Fire Studio — Sub-bass EQ](https://woodandfirestudio.com/en/sub-bass-eq/).

---

## LIVE-WIRE RECONCILIATION (2026-06-02)

This report's §0 channel set is derived from the **repo** (`rbga-engine` commit `81d0b11`). On 2026-06-02 the **running wire was inspected directly** and does **not** match that commit. What the live system actually does, authoritative for current wiring:

### What the running `hotframe/osc_bridge.py` sender actually emits (~50 Hz/frame)
- `/mod/mod/{BASS, LOW, MID, HIGH, significance, BASS_xf, LOW_xf, MID_xf, HIGH_xf}`
- `/mod/{contrast, state_pulse, tension_arc, phase}`

Note: the live sender emits **both** the clean `BASS…HIGH` **and** the `*_xf` set, plus `significance` — but **none** of the K1/K2/K3 + sustain_trend + audio_present descriptors from §0. So §0's 13-channel set (`roughness, sub_pressure, spectrum_tilt, sustain_trend_{BASS,LOW,MID,HIGH}, audio_present`) is **NOT on the live wire**. Implication: the **running sender predates commit `81d0b11`** (or needs restarting to emit the newer channels). Treat §0 as the *target* spec, not the current reality.

### Actual Router bindings (`OSCBridgeRouter_C_1` in `/Game/Maps/Main`)
- The four **`*_xf`** are bound as FloatBindings → **OSC_MPC scalars `{BASS, LOW, MID, HIGH}`** as **PASSTHROUGH** (Scale 1, Offset 0, **no clamp**, **smoothingAlpha 0** — the `_xf` is already smoothed at source, so no Router smoothing is applied).
- **⚠️ Naming:** `BASS_xf` is delivered into the MPC as the parameter named **`BASS`** (the `_xf` suffix is dropped by the binding's target param name). This is the scalar `UPulseTriggerComponent::DoTick` reads for the curve modulation (D-13). So in the §5 tables, "drive the wave from `BASS_xf`" = read MPC param **`BASS`**.
- `/mod/phase` is bound to a **tag only** (no MPC param).
- `significance, contrast, state_pulse, tension_arc` **arrive but are NOT yet bound** to the MPC.

### Consequence for §5 (capture additions)
The §5 plan assumed the `81d0b11` set on `/mod/mod/*`. Until the sender is updated, only the `*_xf` block + `significance` exist on the wire, and the `*_xf` already land in OSC_MPC as `{BASS, LOW, MID, HIGH}` (passthrough, no `_xf` suffix). Operator confirmed **any channel can be routed into OSC_MPC easily** (add an MPC scalar param + a FloatBinding). To realise the §2 designs that need `roughness/sub_pressure/spectrum_tilt/sustain_trend_*/audio_present`, the **sender must first be brought to ≥`81d0b11`** to emit them.

(Cross-ref: project memory `reference_osc_mod_channel_map.md`, `project_pulsekit_radial_pulse.md`.)
