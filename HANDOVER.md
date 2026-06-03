# HANDOVER — PulseKit „Radial-Pulse-Wand" (Stand 2026-06-03)

> Übergabe an die Reinkarnation. Self-contained → taugt als Respawn-Prompt. Kann veralten — bei Widerspruch gilt OPEN_DECISIONS + Memory + Live-Editor.

## ⚡ ARBEITSWEISE (Operator-Anweisung — BINDEND)

- **WORKFLOWS / SUBAGENTS NUTZEN — nicht alles sequenziell selbst.** Der Vorgänger hat ~300k Token in sequenzielle Einzel-Tool-Diagnose gesteckt, bevor er produktiv wurde. Das ist der Anti-Pattern. Konkret:
  - **Breite Diagnose** (Router-Bindings + MPC + Component-Live-State + Logs + Screenshot) → in EINEM Schwung als parallele Explore/Verify-Agents, nicht 15 Einzel-Calls hintereinander.
  - **Bau + Verify** (C++-Umbau + Material-Authoring + Review + Build) → Workflow-Pipeline oder parallele Worker; Verify-Agents frontloaden (z.B. UE-API-Drift-Lookup parallel zum Coden).
  - **Solo nur** für triviale Einzeledits. Konvention H + [[feedback-reincarnation-subagent-workflow]]: Subagents maximal, Background-Jobs frontloaden.
- **Operator = Non-Coder, Eye-Test-Master.** Tunt den Look SELBST live an der Material-Instanz. Will: **distinctive/parameter-abhängige** Effekte (uniform = „kann jeder"), **Fortschritt > Zeremonie** (weniger Rückfragen, größere Self-Verify-Schritte, NICHT endlos verifizieren), **Versions-Stempel** in Shader-Scripts, **High-Level-Trade-offs + Empfehlung** statt Code-Snippets in Rückfragen.

## 0. BOOTSTRAP
1. **CLAUDE.md** (CWD `C:\development\Projects\MCP`) → Konventionen `C:\Claude_Projects\UE-claude\CLAUDE.md`, `OPEN_DECISIONS.md`, Memory-Index.
2. **`C:\Claude_Projects\UE-claude\docs\pulsekit-channel-map.md`** = großer Design-Plan (LOW-Glow-Shader-Spec §3, Textur-Prompt §4, Conductor-C++ §6). ⚠️ Sein §0/§5-Kanal-Set ist Repo-Spec — die **LIVE-Wahrheit der Kanäle** ist `C:\Privat\RBGA\ClaudeCode\rbga-engine\docs\spec\07_CHANNEL_REFERENCE.md` (13 Kanäle, vom Operator in MPC + Router gespiegelt).
3. **OPEN_DECISIONS.md** → D-13, D-15, D-16, D-17.
4. **Memory** (`~\.claude\projects\C--Claude_Projects-UE-claude\memory\`): `project-pulsekit-radial-pulse` (Feature-Chronik), `reference-shader-code-loop-pipe` (Deploy-Pipe), `reference-mcp-material-graph-authoring` (Param/Pin-Authoring + Gotchas), `reference-oscbridge-build-commands` (build_verdict statt rc), `reference-ue-slate-throttling-viewport-freeze`, `feedback-shader-tuning-surface`, `feedback-reincarnation-subagent-workflow`, `project-mcp-bridge-worker`.

## 1. BRIDGE-GATE
`bridge_status` → `editor_reachable=true` erwartet. **Editor zu (reachable=false, Broker antwortet) = SOFORT Operator-Handoff, KEINE Recovery-Kette.** Nur Broker-down (bridge_status antwortet gar nicht) = autonom Broker neu starten ([[project-mcp-bridge-worker]]). MCP-Toolset-Tools heißen voll-pfadig (`mcp__unreal-mcp__toolset_registry_…`) — via ToolSearch `select:<name>` laden.

## 2. WAS LÄUFT (gebaut + grün + verifiziert; nur Operator-Eye-Test offen)
Material `/Game/Materials/M_RadialPulse`, Custom-Node `MaterialExpressionCustom_0` = **61 Inputs**, HLSL-Source `Shaders\RadialRipples.hlsl` (v0.4), Deploy via Code-Loop-Pipe ([[reference-shader-code-loop-pipe]]). C++ `Plugins\PulseKit\` (`UPulseTriggerComponent`). Vollständiger Material-/C++-Contract: `Shaders\RadialRipples.contract.md`.
- **Wellen-Core:** 12 additive Ripple-Slots (`Center0..11`/`PulseAge0..11`), inaktiv = Age −1. C++ besitzt die Uhr (drift-sicher).
- **WaveMode** 0..4 (Clean Ring/Soft Swell/Multi-Ring/Organic/Spike) — live umschaltbar, kein Recompile.
- **3 Outputs:** out0=Emissive (× AtlasColor × MPC·PulseGain) · out1=BaseColor (× `BaseColorScale`, Default 0 = aus) · out2=WPO (von Helligkeit entkoppelt).
- **Helligkeit:** `Floor`(0.2)+`BassGain`·BASS, Reinhard-`Clip`(0.1). **Rotation:** `Spin`(7)/`SpinLobes`(9).
- **GENERISCHE CHANNEL-ENGINE (`a6fac71`):** C++ enumeriert ALLE MPC-Kanäle (`GetScalarParameterNames()`); **Trigger + Energy per Index LIVE aus Material-Scalars** wählbar (kein Rebuild fürs Iterieren). Tempo in C++-Zeit-Integration gefaltet (Brake-Akkumulator → kein Ring-Retraction beim Live-Drehen). Config lebt in Material-Defaults = **durable über Editor-Neustart**. Regler s. §3.
- **Builds grün** via `_rebuild_build.log` „Result: Succeeded". ⚠️ `bridge_rebuild build_rc=6` ist **SPURIOUS** (laufender Broker vor der build-verdict-Härtung gestartet) → Verdikt IMMER via Log lesen, nie via rc.

## 3. EINSTELLUNGSMÖGLICHKEITEN (Instanz `M_RadialPulse_Inst`, live, kein Recompile)
- **0 Pulse - Engine (generische Engine):** `TriggerChannel`(9=phase), `TriggerThreshold`(0.7), `TriggerMode`(0 Rising/1 Falling/2 Level/3 Wrap=Sägezahnreset) · `EnergyChannelA`(1=LOW), `EnergyChannelB`(0=BASS, **−1=aus**), `EnergyOp`(0+/1−/2×/3÷), `EnergyScale`(1), `EnergyBias`(0) → `Energie=(A op B)*Scale+Bias` (bei Geburt gelatcht, speist Tempo+Bremse). **Index-Tabelle:** 0 BASS·1 LOW·2 MID·3 HIGH·4 tilt_velocity·5 roughness·6 shimmer·7 spectrum_tilt·8 sub_pressure·9 phase·10 centroid_zscore·11 tension_rise·12 Warmth (= MPC-Asset-Order; bei MPC-Umbau verschiebt sich der Index → Readout `ChannelMap` im Panel ist Live-Wahrheit).
- **1 Pulse - Form:** PulseSpeed(400), PulseWidth(29), PulseBounds(1426), PulseWobble(0.72), PulseWobbleFreq(3), PulseSeed, SpeedScale(0.5), SpeedBrake(1.0), BrakeBias(0).
- **2 Pulse - Mode:** WaveMode, AutoMode(0=aus), AutoPeriod, AutoCenter.
- **3 Brightness:** BassGain, Floor(0.2), Clip(0.1). · **4 Sparkle/Spin:** Sparkle, SparkleGain, Spin(7), SpinLobes(9). · **5 BaseColor:** BaseColorScale(0=aus).
- **9 Runtime (C++):** Life (read-only) + Center/PulseAge/PulseEnergy 0..11 (C++ schreibt, nicht tunen).
- **0 Atlas (separat, NICHT PulseKit, nicht anfassen):** Operator-Farbe (StateRow/Brightness/GradientStrength/SpeedX/SpeedY).
- **Component `PulseTrigger`** (BP_PulseField in **LED_Ndisplay**): SourceCollection→OSC_MPC, RetriggerCooldown(0.06), bEnabled, bAutoFirePreview(false), Mode(Seq/Random), SpawnSplineName, PulseMaterial, TargetSurfaces(=Wand), MaxConcurrent(12) + **read-only Readouts** ChannelMap/ActiveTrigger/ActiveEnergy. ⚠️ Trigger/Energy-Config lebt jetzt im **Material** (durable) — Component-Instanz-Overrides sind weiterhin nicht durable (CS recreated), aber die Engine braucht keine mehr.

## 4. UNGEBAUTER SCOPE (Forward-Backlog — nichts verlieren)
**Headline-Feature (designed, NICHT gebaut):**
- **LOW-Glow-Pattern** — leuchtendes Muster, Noise-Panner, Strukturen *aus der Bass-Welle abgeleitet*, *zur Farbkurve korrespondierend*, glüht an der aktiven Fläche, Shimmer bei Ruhe, von Overlay-Patterns verschleiert. Voller Per-Pixel-Shader-Spec `channel-map.md` §3 (reiner Shader, kein C++, summiert unter die Ring-`band`). Tunables §3.5.
- **Textur-Gen:** 3 seamless Grayscale (`T_LowPattern`/`T_Veil_A`/`T_Veil_B`) — AI-Prompt + Fills `channel-map.md` §4 (Operator generiert/swappt).

**Audio→Visual-Mapping (designed, größtenteils nicht gebaut) — jetzt baubar, da alle 13 Kanäle LIVE in der MPC sind:** LOW→Glow-Flow, MID→Pattern-Änderung, HIGH→Sparkle, sub_pressure→Glow-Floor/WPO-Swell, spectrum_tilt→Farbkurve, roughness→Grain, tension_rise→Makro-Arc, shimmer→Air-Sparkle. **Conductor-C++** (`UPulseConductorComponent`, `channel-map.md` §6): Makro-Ramps aus trägen Kanälen, Smoothing, Struktur-Morph = „musikalische Kohärenz"-Schicht.

**Kleiner/konkret offen:**
- **BaseColor aktivieren** (D-16): `BaseColorScale>0` ODER out1→Roughness/Specular umhängen (Operator-Entscheid).
- **Per-Ripple-Brightness:** `PulseEnergy0..11` sind per-Geburt gelatcht, radius-seitig unused → für per-Welle-Brightness nutzbar (jeder Kick behält seine Helligkeit beim Rauswandern).
- **Farb-/Atlas** (D-15): `M_OSCGradientAtlas`/`RT_OSCGradientAtlas` existieren (self-healing, 12 Demo-MIs). Offen: Niagara `DataInterfaceTexture`/MaterialFunction, C++-Button „Generate State Instances". LOW-Glow soll an diese Kurve sampeln.

**Operator-Manual (kein Code):** Spline über die GANZE Wand (X −650…+650, Z 100…605; aktuell ~1/3) · Effekt dezent für die ~20-m-Wand.

**GEPARKT (Worker-Risiko-Scan, nicht ohne Grund anfassen):** volle generische `UWaveDataBridge` + PulseTrigger→Scheduler-Split — verdoppelt BP_PulseField-Construction-Script-Fragilität für 0 sichtbaren Mehrwert. Spec in D-17.

## 5. DECISION-TRACKER (Kurzstand — Detail in OPEN_DECISIONS.md)
- **D-13** `[VERIFY-OPEN]` PulseKit-Tuning: (a) dezenter, (b) Spline ganze Wand, (d) Licht+Muster. *(c significance obsolet — Trigger ist generisch.)*
- **D-15** `[VERIFY-OPEN]` OSC-Gradient-Atlas (Farbe). · **D-16** `[VERIFY-OPEN]` Shader-Refactor; BaseColor-Aktivierung offen.
- **D-17** `[VERIFY-OPEN]` per-Welle-Energie + **generische Channel-Engine GEBAUT+GRÜN** (`a6fac71`), nur Eye-Test offen. Geparkt: WaveDataBridge.
- Klein/kosmetisch: D-1, D-3, D-12, D-14.

## 6. GOTCHAS (must-know)
- **Drei-Loop-Trennung:** Code-Loop (HLSL, autonom, Einheit = 1 self-verifiziertes `execute_tool_script` via Deploy-Pipe `Tools\shader-deploy\deploy_radialripples.py`) · Graph-Loop (Pin/Param/Rewire = gemeinsam, Reader-Readback vor/nach [[reference-mcp-material-graph-authoring]]) · Eye-Test (Operator).
- **Material-Steuer-Params, die nur C++ liest** (Index/Op/Threshold): einfach als **freie ScalarParameter** anlegen — unverbunden, **kein Custom-Node-Pin nötig** (MID-lesbar, Engine-Source-verifiziert [[reference-mcp-material-graph-authoring]]). Connection-preserving Pin-APPEND nur für echte Shader-Inputs.
- **Build nach C++/Plugin-Edits = `bridge_rebuild`** (mit `save_assets([])` direkt davor, sonst hängt der Build am Save-Modal). rc=6 SPURIOUS → Verdikt via Log. **Schließt den Editor** → nicht während Operator live tunt; vorher ansagen.
- **Slate.bAllowThrottling=0** in `Config\DefaultEngine.ini` → Viewport bleibt nach Rebuild live. NICHT entfernen.
- **Tunen IMMER an der Instanz** `M_RadialPulse_Inst`. Nach Editor-(Re)Start einmal **ALT+P→ESC** ([[reference-ue-editor-pie-cycle-primes-mpc-stream]]).
- **Clamp-Philosophie (Operator):** Clamps NUR gegen echte Render-Artefakte, nie als Geschmacks-Limit; extreme/Umkehrungen okay wenn's sauber rendert. Look-Tweaks nicht endlos verifizieren ([[feedback-shader-tuning-surface]]).
- **NIE** `ModelContextProtocol.GenerateClientConfig` (überschreibt `.mcp.json`, umgeht den Broker).
- **Git:** committed (`a6fac71` C++ · `210826a` Contract · `582ee4a` Companion-Docs; nicht gepusht). UE-Content = Plastic (`.uasset` checkt Operator selbst ein). Operator-`Config\Tags\OSCBridge.ini` (sein Routing-Fix) uncommitted = seine Arbeit, nicht anfassen. Memory-Writes → UE-Claude-Slug.

## 7. NÄCHSTER SCHRITT
1. **Operator-Eye-Test der generischen Engine** (sein Feld): BrakeBias-Spreizung beim Bremsen, Energy-Kombis (LOW+BASS vs nur-LOW vs ×), Trigger-Modi (Rising vs Wrap auf phase).
2. Danach Scope-Pick (High-Level anbieten, **mit Workflow/Workern bauen**): **LOW-Glow-Feature** (§4, Headline, reiner Shader) vs. **BaseColor/Licht** vs. **Conductor-C++** (musikalische Kohärenz). Operator will mehr Live-Knöpfe/Kombinationen + distinctive Effekte.
