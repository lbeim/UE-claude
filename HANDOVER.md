# HANDOVER — PulseKit „Radial-Pulse-Wand" (Stand 2026-06-03)

> Lückenlose Übergabe an den Nachfolger (Reinkarnation). Self-contained → taugt auch als Respawn-Prompt. Kann nach Abarbeitung veralten — bei Widerspruch gilt OPEN_DECISIONS + Memory + Live-Editor.

Du übernimmst eine UE-5.8-Material/Shader-Session. **Operator = Non-Coder, Eye-Test-Master.** Er tunt den Look SELBST live an der Material-Instanz, will **distinctive/parameter-abhängige** Effekte (uniform = öde, „kann jeder"), **Fortschritt > Zeremonie** (weniger Rückfragen, größere Self-Verify-Schritte, NICHT endlos verifizieren), **Versions-Stempel** in Shader-Scripts, und **High-Level-Trade-offs + Empfehlung statt Code-Snippets** in Rückfragen. Dieses Dokument ist bewusst **lückenlos**: alles Gebaute, der komplette offene Scope, und die Drifts zwischen Tracker und Live-Realität.

## 0. BOOTSTRAP (zuerst lesen)
1. **CLAUDE.md** (CWD `C:\development\Projects\MCP`) → zeigt auf Konventionen `C:\Claude_Projects\UE-claude\CLAUDE.md`, `OPEN_DECISIONS.md`, Memory-Index.
2. **`C:\Claude_Projects\UE-claude\docs\pulsekit-channel-map.md` = DER große Design-Plan.** Hier liegt der meiste UNGEBAUTE Scope: alle 13 OSC-Kanäle→Material-Mapping (§2), das **LOW-Glow-Pattern-Feature** mit vollem Shader-Spec (§3), ein **AI-Textur-Generier-Prompt** (§4), die OSCBridge-Capture-Additions (§5) und das **Conductor-C++-Konzept** (§6). **Das ist „wo der Scope hingewandert ist".**
3. **OPEN_DECISIONS.md** → D-13, D-15, D-16, D-17 (alle PulseKit-relevant, alle Eye-Test-/Teil-offen).
4. **Memory** (`~\.claude\projects\C--Claude_Projects-UE-claude\memory\`): `project-pulsekit-radial-pulse` (Feature-Chronik), `reference-shader-code-loop-pipe` (Deploy-Pipe), `reference-mcp-material-graph-authoring` (Pin-Append + Gotchas), `reference-osc-mod-channel-map` (Live-Draht ≠ Repo-Spec!), `reference-oscbridge-build-commands` (build_verdict statt rc), `reference-ue-slate-throttling-viewport-freeze`, `feedback-shader-tuning-surface`, `feedback-direct-fast-shader-iteration`, `reference-oscbridge-atlas-persistence` (D-15 Farb-Atlas), `project-mcp-bridge-worker`.

## 1. BRIDGE-GATE
`bridge_status` → `editor_reachable=true` erwartet; Toolsets meist geladen (Programmatic, ObjectTools, MaterialTools, AssetTools, OSCBridgeEditor.MaterialGraphReaderToolset, Logs). **Editor zu (reachable=false, Broker antwortet) = SOFORT Operator-Handoff, KEINE Recovery-Kette.** Nur Broker-down (bridge_status antwortet gar nicht) = autonom Broker neu starten ([[project-mcp-bridge-worker]]). MCP-Toolset-Tools heißen voll-pfadig, z.B. `mcp__unreal-mcp__toolset_registry_toolsets_core_programmatic_ProgrammaticToolset_execute_tool_script` — bei Bedarf via ToolSearch `select:<name>` laden.

## 2. WAS GEBAUT + GRÜN IST (verifiziert; Operator-Eye-Test offen; Git-Commit 2026-06-03 als Checkpoint gesetzt)
Material **`/Game/Materials/M_RadialPulse`**, Custom-Node `MaterialExpressionCustom_0` = **61 Inputs**, HLSL-Source-of-Truth `Shaders\RadialRipples.hlsl` (**v0.4**), Deploy via Code-Loop-Pipe ([[reference-shader-code-loop-pipe]]). C++ `Plugins\PulseKit\` (`UPulseTriggerComponent`).
- **Wellen-Core:** 12 überlappende radiale Ripple-Slots (`Center0..11`/`PulseAge0..11`), additiv summiert; inaktiv = Age −1. C++ besitzt die Uhr (clock-drift-sicher).
- **WaveMode** 0..4 (Clean Ring/Soft Swell/Multi-Ring/Organic/Spike) — live in der Instanz umschaltbar, kein Recompile.
- **Direkte OSC_MPC-Reads** im Shader (BASS etc. via CollectionParameter).
- **3 Outputs:** out0=Emissive (× AtlasColor × MPC·PulseGain) · out1=BaseColor (× `BaseColorScale`, **Default 0 = AUS**) · out2=WPO (× Normal × Amount, von Helligkeit entkoppelt).
- **Helligkeit:** `Floor`(0.2)+`BassGain`·BASS, weicher Reinhard-`Clip`(0.1).
- **Rotation:** `Spin`(7)/`SpinLobes`(9) live.
- **D-17 Phase 1+2 — per-Welle-Energie→Speed:** `SpeedScale`(0.5)+`SpeedBrake`(1.0); 12 `PulseEnergy0..11`-Pins; C++ sampelt `EnergyParameter` (Default **`sub_pressure`**) bei Geburt → latch `SlotEnergy[]` → schreibt `PulseEnergy%d`.
- **D-17 Brake-Akkumulator (v0.4):** Tempo in die C++-Zeit-Integration gefaltet. `DoTick`: `SlotAge[i] += factor*dt` mit `factor=max((1+SpeedScale*SlotEnergy[i])*WaveBrake, 0.02)`. HLSL nur noch `radius = Speed*age` (energy/spd-Zeilen raus). → Live-Drehen ändert nur die RATE, **kein Ring-Retraction mehr**. Retire `effAge>=Bounds/Speed` → radius=Bounds am Rand.
- **D-17 non-uniform Brake `BrakeBias`:** `WaveBrake=lerp(SpeedBrake,1,clamp(SlotEnergy[i]*BrakeBias,0,1))`. `BrakeBias` (Pin 60, `ScalarParameter_52`, Group „1 Pulse - Form" Sort 8, Default 0). 0=uniform, hoch=energievolle Wellen widerstehen dem Bremsen → Rudel spreizt.
- **Builds grün** (`_rebuild_build.log` „Result: Succeeded", PulseTriggerComponent.cpp compiled+linked). ⚠️ `bridge_rebuild build_rc=6` ist **SPURIOUS** — der laufende Broker ist VOR der build-verdict-Härtung gestartet (liefert noch das alte Format ohne `build_ok`). Verdikt IMMER via Log lesen.

## 3. DEINE EINSTELLUNGSMÖGLICHKEITEN (existieren JETZT — Antwort auf „wo sind meine settings")
**An der Instanz `M_RadialPulse_Inst` (live, kein Recompile):**
- **1 Pulse - Form (9):** PulseSpeed(400), PulseWidth(29), PulseBounds(1426), PulseWobble(0.72), PulseWobbleFreq(3), PulseSeed, **SpeedScale(0.5)**, **SpeedBrake(1.0)**, **BrakeBias(0)**.
- **2 Pulse - Mode (4):** WaveMode(0..4), AutoMode(0=aus), AutoPeriod, AutoCenter.
- **3 Pulse - Brightness:** BassGain, Floor(0.2), Clip(0.1) (BASS = OSC-Read).
- **4 Pulse - Sparkle/Spin:** Sparkle, SparkleGain, Spin(7), SpinLobes(9).
- **5 Pulse - BaseColor:** BaseColorScale (Default 0 = aus).
- **9 Pulse - Runtime (C++):** Life (read-only) + Center/PulseAge/PulseEnergy 0..11 (C++ schreibt, nicht tunen).
- **0 Atlas (separat, NICHT PulseKit, nicht anfassen):** StateRow, Brightness, GradientStrength, SpeedX, SpeedY (Operator-Farbe).

**Am Component `PulseTrigger` (Details-Panel, in BP_PulseField in LED_Ndisplay):** SourceCollection→OSC_MPC, TriggerParameter(`significance`), Threshold(0.5), RetriggerCooldown(0.06), **EnergyParameter(`sub_pressure`)**, bEnabled, **bAutoFirePreview** (Default false, **CS erzwingt true — s. §4b**), Mode(Seq/Random), SpawnSplineName, PulseMaterial, TargetSurfaces(=Wand), MaxConcurrent(12), PreviewInterval(0.45). ⚠️ Instanz-Overrides am Component sind **nicht durable** (Construction-Script erzeugt ihn neu → nur C++-Defaults persistieren).

## 4. ⚠️ KRITISCHE OFFENE RECONCILIATIONS (Drift: Code ≠ Live-Draht — HIER zuerst hinschauen)
**(a) Energie-Features evtl. INERT — höchste Prio.** C++ liest `EnergyParameter=sub_pressure` aus OSC_MPC. Aber laut [[reference-osc-mod-channel-map]] + `channel-map.md` §LIVE-WIRE (2026-06-02) liegt **`sub_pressure` NICHT auf dem Live-Draht** (der laufende Sender ist älter als das 13-Kanal-Commit; emittiert nur `{BASS,LOW,MID,HIGH, *_xf, significance, contrast, state_pulse, tension_arc, phase}`). Folge: `SlotEnergy` = 0 → **SpeedScale/BrakeBias bewirken NICHTS** (alle Wellen identisch). → **Verifizieren** (ist `sub_pressure` ein gebundener OSC_MPC-Scalar mit Werten?), dann eins von: EnergyParameter live auf **`BASS`** oder **`significance`** stellen (sofort wirksam), ODER `sub_pressure` in OSC_MPC routen + Sender auf ≥`81d0b11` updaten. *Das erklärt evtl., warum der per-Welle-Effekt im Eye-Test „zahm" wirkt.* Hinweis: die *globale* Bremse (`SpeedBrake`) + der Akkumulator funktionieren auch bei Energie=0 — nur die energie-ABHÄNGIGE Spreizung nicht.
**(b) „significance scharf" — Tracker vs. Operator.** Operator sagt „die Wand is schon lange scharf" (reagiert auf Beats). Tracker D-13(c) + `channel-map.md` sagen: `significance` „arrives but NOT yet bound to MPC" (2026-06-02) UND das Construction-Script **erzwingt `bAutoFirePreview=true`** → de facto spawnt der **Preview-Timer** (0.45 s), nicht der significance-Rising-Edge. **Reconcilen** (live): ist `significance` in OSC_MPC gebunden? steht `bAutoFirePreview` aktuell true/false? BP_PulseField-CS prüfen. Fix = CS-erzwungenes `true` raus + significance binden.
**(c) BrakeBias-Clamp-Drop (operator-approved, pending).** Operator: „obergrenzen nur wenn es sonst artefakte gibt — wenn's sauber rendert sind extreme/umkehrungen/komisches verhalten okay." → beim **nächsten** PulseKit-C++-Build das `clamp(SlotEnergy*BrakeBias,0,1)` in `DoTick` entfernen (Factor-Min-Clamp 0.02 BLEIBT = Artefakt/frozen-slot-Schutz). Kein Extra-Rebuild nur dafür.

## 5. KOMPLETTER UNGEBAUTER SCOPE (lückenlos — nichts darf verloren gehen)
**Headline-Feature (designed, NICHT gebaut):**
- **LOW-Glow-Pattern** — leuchtendes Muster, Noise-Panner, Strukturen *aus der Bass-Welle abgeleitet*, *zur Farbkurve korrespondierend*, glüht stärker an der zitternden/aktiven Fläche, subtiles Shimmer bei Ruhe, von Overlay-Patterns verschleiert. **Voller Per-Pixel-Shader-Spec in `channel-map.md` §3** (kein C++ nötig, summiert unter die Ring-`band`). Tunables §3.5.
- **Textur-Generierung** für das Feature: 3 seamless Grayscale-Texturen (`T_LowPattern`, `T_Veil_A`, `T_Veil_B`) — **fertiger AI-Prompt + 3 Fills in `channel-map.md` §4** (Operator generiert/swappt selbst).

**Audio→Visual-Mapping (designed §2, größtenteils nicht gebaut):** LOW→Glow-Flow, MID→strukturelle Pattern-Änderung, HIGH→Sparkle-Akzente, sub_pressure→Glow-Floor/WPO-Swell, spectrum_tilt→Farbkurven-Position, roughness→Grain-Veil, significance→Punch/Retrigger, sustain_trend_*→Makro-Arc (Build/Drop), audio_present→Master-Fade. **Voraussetzung:** Sender muss die neuen Kanäle emittieren (§4a) + OSCBridge-Routing (§5 des Docs).
- **Conductor-C++-Konzept** (`UPulseConductorComponent`, `channel-map.md` §6): significance-Rising-Edge→FirePulse, sustain_trend→langsame Makro-Ramps, audio_present-Smoothing, MID-Struktur-Morph-Lerp. = die „musikalische Kohärenz"-Schicht.

**Kleiner/konkret offen:**
- **BaseColor aktivieren** (D-16): `BaseColorScale>0` ODER out1→Roughness/Specular umhängen (Operator-Entscheid).
- **Per-Ripple-Geburts-Helligkeit:** `PulseEnergy0..11` sind schon per-Geburt gelatcht, radius-seitig aber jetzt unused → für **per-Welle-Brightness** nutzbar (jeder Kick behält seine Helligkeit beim Rauswandern).
- **Licht + leuchtendes Muster auf echter LED** (D-13d).
- **Farb-/Atlas-Anbindung** (D-15): `M_OSCGradientAtlas`/`MPC_OSCColorCurve`/`RT_OSCGradientAtlas` existieren (self-healing Persistenz, 12 Demo-MIs `MI_Atlas_*`). Offen: §C Niagara `DataInterfaceTexture`/MaterialFunction; C++-Button „Generate State Instances". LOW-Glow soll an diese Kurve sampeln.

**Operator-Manual (kein Code):** Spline über die GANZE Wand verteilen (X −650…+650, Z 100…605; aktuell ~1/3, D-13b) · Effekt dezenter tunen für die ~20-m-Wand (D-13a).

**Bewusst GEPARKT (Worker-Risiko-Scan, nicht ohne Grund anfassen):** volle generische **`UWaveDataBridge`** + PulseTrigger→Scheduler-Split (`SubmitWave(center,{attrs})`) — verdoppelt die BP_PulseField-Construction-Script-Fragilität für 0 sichtbaren Mehrwert. Spec in D-17.

**OSCBridge/Backlog:** alle 13 Kanäle sauber routen (`channel-map.md` §5, Wildcard `/mod/mod/*` vs. explizite Bindings) · Sender auf ≥`81d0b11` bringen · Session Record/Replay, Data-Asset-Binding-Tables, zeit-korrektes Smoothing (D-6/D-7-Reste).

## 6. DECISION-TRACKER (Kurzstand)
- **D-1** `[VERIFY-OPEN]` Pulse-Trial-Gaps re-eval. · **D-3** `[PENDING]` Inline-STOP (schließbar). · **D-12** `[PENDING]` OSCBridge Log-Noise (kosmetisch).
- **D-13** `[VERIFY-OPEN]` PulseKit-Tuning: (a) dezenter, (b) Spline ganze Wand, (c) significance scharf [§4b], (d) Licht+Muster. Grün, Eye-Test offen.
- **D-14** Bridge-Worker-Adoption: Broker dauerhaft + adoptiert die gehärtete build_verdict-Logik **erst nach Broker-Neustart** (aktuell noch altes Format → rc=6-Fehlalarm).
- **D-15** `[VERIFY-OPEN]` OSC-Gradient-Atlas (Farbe). · **D-16** `[VERIFY-OPEN]` Shader-Refactor+Graph-Reader; BaseColor-Aktivierung offen.
- **D-17** `[PENDING]` per-Welle-Energie→Speed: Phase 1+2 + Brake-Akkumulator + BrakeBias **GEBAUT+GRÜN**, Eye-Test offen, committed 2026-06-03 (Checkpoint). Geparkt: WaveDataBridge.

## 7. GOTCHAS / WORKFLOW (must-know)
- **Drei-Loop-Trennung:** Code-Loop (HLSL, Claude autonom, Einheit = 1 self-verifiziertes `execute_tool_script` via Deploy-Pipe `Tools\shader-deploy\deploy_radialripples.py`-Muster) · Graph-Loop (Pin/Param/Rewire = gemeinsam, **Reader-Readback vor/nach** [[reference-mcp-material-graph-authoring]]) · Eye-Test (Operator).
- **Pin-Append** connection-preserving via **Full-Struct** (Inputs verbatim lesen → 1 Eintrag anhängen im exakten Read-Format `{"inputName":..,"input":{"expression":{"refPath":..},"outputIndex":0,"inputName":"None","mask":0,..}}` → set_properties; atomar, Auto-Restore-Netz). `get_properties` **wirft** auf Nicht-Param-Nodes → vorher `get_class` filtern.
- **Build nach C++/Plugin-Edits = `bridge_rebuild`** (mit `save_assets([])` direkt davor, sonst hängt der Build am Save-Modal). rc=6 = SPURIOUS → Verdikt via `_rebuild_build.log` „Result: Succeeded". **`bridge_rebuild` schließt den Editor** → nicht während Operator live tunt; vorher ansagen.
- **Slate.bAllowThrottling=0** ist in `Config\DefaultEngine.ini` persistiert → Viewport bleibt nach Rebuild live. NICHT entfernen.
- **Tunen IMMER an der Instanz** `M_RadialPulse_Inst` (live), nie am Material/BP. Nach Editor-(Re)Start einmal **ALT+P→ESC** ([[reference-ue-editor-pie-cycle-primes-mpc-stream]]).
- **recompile** meldet Shader-Fehler NUR im Log; bei unverändertem Code Cache-Hit (kein Re-Log) → ggf. Cache-Bust.
- **Clamp-Philosophie (Operator):** Clamps NUR gegen echte Render-Artefakte/Malfunctions, nie als Geschmacks-Limit; extreme/Umkehrungen/komisch sind okay wenn's sauber rendert. Look-Tweaks **nicht endlos verifizieren** ([[feedback-shader-tuning-surface]]).
- **NIE** `ModelContextProtocol.GenerateClientConfig` (überschreibt `.mcp.json`, umgeht den Broker).
- **Git:** D-17-Code committed 2026-06-03 (Checkpoint, Eye-Test weiter offen). UE-Content = Plastic (Material-`.uasset` checkt der Operator selbst ein); durable Notizen → UE-claude-git. Memory-Writes → UE-Claude-Slug.

## 8. NÄCHSTER SCHRITT (Empfehlung)
1. **Zuerst §4a klären** (read-only): liegt `sub_pressure` lebendig in OSC_MPC? Wenn nein → EnergyParameter live auf `BASS`/`significance` → DANN macht der Operator-Eye-Test von Akkumulator+BrakeBias überhaupt erst Sinn (sonst testet er ein inertes Feature). Gilt analog für §4b/significance.
2. Operator-Eye-Test Akkumulator + BrakeBias (LED_Ndisplay). Clamp-Drop (§4c) beim nächsten Build mitnehmen.
3. Danach Scope-Pick (Operator-Entscheid, High-Level anbieten): **LOW-Glow-Feature** (§5, das Headline-Stück, reiner Shader) vs. **BaseColor/Licht** vs. **Energie-/Kanal-Routing solide machen**. Operator will mehr Live-Knöpfe/Kombinationen + distinctive Effekte.
