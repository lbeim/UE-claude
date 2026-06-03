# HANDOVER — PulseKit „Radial-Pulse-Wand" (Stand 2026-06-03, nach Glow v0.6)

> Übergabe an die Reinkarnation. Self-contained → taugt als Respawn-Prompt. Kann veralten — bei Widerspruch gilt OPEN_DECISIONS + Memory + **Live-Editor** (immer live gegenprüfen).

## ⚡ ARBEITSWEISE (Operator-Anweisung — BINDEND)
- **WORKFLOWS / SUBAGENTS NUTZEN, gebündelt/parallel** — Breite Diagnose + Bau/Verify in EINEM Schwung (parallele Agents), nicht 15 Einzel-Calls. Datei-/Research-Seite fan-out-bar; **Editor-Bridge ist single-threaded** → Deploy sequenziell ([[reference_shader_code_loop_pipe]]). Solo nur für triviale Edits.
- **Operator = Non-Coder, Eye-Test-Master.** Tunt live an `M_RadialPulse_Inst`. Will: **distinctive/parameter-abhängige** Effekte (uniform = öde), **reiche Live-Knopf-Fläche** + saubere isolierte Params, **Fortschritt > Zeremonie** (weniger Rückfragen, Look nicht endlos selbst-verifizieren → grün → ihm), **High-Level-Trade-offs + Empfehlung** statt Code-Snippets, **Versions-Stempel** in `.hlsl`.
- **NEUE LEHREN diese Session (teuer bezahlt):**
  1. **`save_assets(["/Game/Materials/M_RadialPulse"])` nach JEDEM Material-Deploy.** Unsaved = nur in-memory → beim Editor-Restart WEG (genau das ist passiert → „v4"-Verwirrung). Im Build-Flow verankern.
  2. **MI-Sichtbarkeit IMMER live prüfen** (Param-Suche im Instance-Editor), NIE aus C++-Readout/Reflection schließen: **unverbundene ScalarParameter sind im MI-Editor UNSICHTBAR** (obwohl C++ sie per Name liest). [[reference_mcp_material_graph_authoring]]
  3. **Editor war instabil** (mehrfach-Restart, `editor_session_id` flippte 4ab29→84b99→d3029). Robust arbeiten, früh speichern, Live-State gegenprüfen statt Doku glauben.

## 0. BOOTSTRAP
1. **CLAUDE.md** (CWD `C:\development\Projects\MCP`) → Konventionen `C:\Claude_Projects\UE-claude\CLAUDE.md`, `OPEN_DECISIONS.md`, Memory-Index.
2. **`C:\Privat\RBGA\ClaudeCode\rbga-engine\docs\spec\07_CHANNEL_REFERENCE.md`** = LIVE-Wahrheit der 13 MPC-Kanäle. **Index-Tabelle (OSC_MPC `/Game/OSC/OSC_MPC`-Order):** 0 BASS·1 LOW·2 MID·3 HIGH·4 tilt_velocity·5 roughness·6 shimmer·7 spectrum_tilt·8 sub_pressure·9 phase·10 centroid_zscore·11 tension_rise·12 Warmth. (`channel-map.md` §0 ist veraltet — nur §3/§4 als Skelett brauchbar.)
3. **OPEN_DECISIONS.md** → D-13, D-15, D-16, D-17.
4. **Memory** (`~\.claude\projects\C--Claude_Projects-UE-claude\memory\`): `project_pulsekit_radial_pulse` (Chronik), `reference_mcp_material_graph_authoring` (Param/Pin-Authoring + ⚠️ unverbunden≠sichtbar), `reference_shader_code_loop_pipe` (Deploy-Pipe), `feedback_shader_tuning_surface`, `reference_oscbridge_atlas_persistence` (Atlas), `project_mcp_bridge_worker` (Bridge-Recovery).

## 1. BRIDGE-GATE
`bridge_status` → `editor_reachable=true` erwartet. **Editor zu (reachable=false, Broker antwortet) = SOFORT Operator-Handoff.** Nur Broker-down (bridge_status antwortet gar nicht) = autonom Broker neu starten. **„Unknown tool" TROTZ reachable=true** (nach Editor-Restart, Toolset-Replay-Bug): `load_toolset` ist no-opt → Fix = Broker stoppen / `state.json` `loaded_toolsets`=[] (stable_session_id behalten) / Broker starten / `load_toolset`. **Diese Session:** der Editor flippte zwischen Sessions; oft genügte Warten/Neu-Test (`list_parameter_groups` als billiger Liveness-Test). Toolset-Tools voll-pfadig via ToolSearch `select:<name>` laden.

## 2. WAS LÄUFT (gebaut + grün + GESPEICHERT + committed `444dff9` lokal main)
Material `/Game/Materials/M_RadialPulse`, Custom-Node `MaterialExpressionCustom_0` = **90 Inputs, 4 Outputs**. HLSL `Shaders\RadialRipples.hlsl` **v0.6**, Contract `Shaders\RadialRipples.contract.md` v0.6. Deploy via `Tools\shader-deploy\` (`deploy_radialripples.py` = Code-Loop; `deploy_glow_build.py` = der einmalige Glow/Engine-Build).
- **ENGINE-PARAM-FIX (DER Session-Bug, GELÖST):** die 8 Trigger/Energy-Params (`ScalarParameter_53..60`) waren **unverbunden → im MI unsichtbar**; jetzt als Custom-Node-Inputs verbunden + Nullgewichts-Keepalive im HLSL → **sichtbar/tunebar** in Gruppe „0 Pulse - Engine".
- **GLOW v0.6 (GEBAUT+GRÜN):** out3 `GlowIntensity` = zustandslose per-Pixel-Funktion, domain-warped value-noise Venen (**NON-global**). HIGH→`GlowDrive` (normal hell), shimmer→`GlowPeak` (Spike bis MAX, `PeakKnee` macht niedrige shimmer 0.1-0.3 hell), Warmth→`GlowCalm` (mystisch in Ruhe, Auto-Duck). **Animiert** (GlowScrollX/Y·GlowWarpSpeed·GlowPan). **Nur auf den Pulses** (`WaveLink`=1 maskiert mit der Ring-Summe `total`, `PulseMaskGain`=Breite). **Kanäle Operator-verdrahtet** (CollectionParameter HIGH/shimmer/Warmth → die 3 Inputs). **Farbe:** `GlowColor` (VectorParam, HDR-Beispiel) × out3 → `Add_1` auf die Ring-Emissive.
- **Generische Channel-Engine (C++ `a6fac71`):** Trigger+Energy per Index aus Material-Scalars (TriggerChannel/Mode/Threshold, EnergyChannelA/B/Op/Scale/Bias). Tempo in C++-Zeit-Integration (Brake-Akkumulator, BrakeBias). Wellen-Core 12 additive Slots, WaveMode 0..4. **Builds grün** via `_rebuild_build.log` „Result: Succeeded" (rc=6 spurious).
- **Graph aufgeräumt:** Glow-Params + Engine/Speed-Params in repositionierte Cluster (~x −3200) + 2 Kommentar-Labels.

## 3. EINSTELLUNGEN (Instanz `M_RadialPulse_Inst`, live, kein Recompile — Häkchen=Override!)
- **„0 Pulse - Engine":** `TriggerChannel`(9=phase)·`TriggerMode`(0 Rising/1 Falling/2 Level/3 Wrap)·`TriggerThreshold`(0.7) · `EnergyChannelA`(1=LOW)/`B`(0=BASS,−1=aus)/`Op`(0+/1−/2×/3÷)/`Scale`/`Bias`.
- **„5 Pulse - Glow" (19):** Kanäle kommen via CollectionParameter (HIGH/shimmer/Warmth). `DriveGain`(0.5)·`DriveGamma`(1.5)·`PeakGain`(1.5)·`PeakSharp`(1)·`PeakKnee`(0.22)·`CalmGain`(0.35)·`CalmMod`(0.7)·`ActSense`(2)·`GlowGain`(1.5)·`GlowMax`(2)·`GlowFloor`(0.4=Venen-Dichte)·`GlowTiling`(0.01)·`GlowScrollX`(0.3)·`GlowScrollY`(0.15)·`GlowWarpSpeed`(0.3)·`GlowPan`(1.0=Master-Tempo)·`PulseMaskGain`(1.5)·`WaveLink`(1)·`GlowColor`(HDR).
- **„1 Pulse - Form":** Speed/Width/Bounds/Wobble/Seed + SpeedScale/SpeedBrake/BrakeBias. + Mode/Brightness/Sparkle/Spin/BaseColor wie gehabt. Nach Editor-(Re)Start einmal **ALT+P→ESC** (primet OSC→MPC).

## 4. OFFEN / NÄCHSTER SCHRITT
1. **Operator-Eye-Test v0.6 läuft** — Animation (bewegt sich's schön?), nur-Pulses (klebt's an den Ringen?), Spike-Helligkeit (zünden niedrige shimmer richtig?). Defaults sind Startwerte → live nachtunen.
2. **Atlas-Farbe rein:** Operator/Claude hängt in `Multiply_1` den B-Eingang von `GlowColor` auf ein Atlas-Sample (Modell B: Zeile 2k Solid / 2k+1 Gradient, Master `M_OSCGradientAtlas`, linear-HDR). [[reference_oscbridge_atlas_persistence]]
3. **Klein:** „5 Pulse - BaseColor" + „5 Pulse - Glow" teilen Präfix „5" → BaseColor auf „6" bumpen (Operator-OK abwarten). Comment-Box-Size via MCP nicht setzbar → manuell.
4. **Overlap „addiert nicht":** liegt am Szenen-Tonemapper(ACES)/Sättigung (PulseGain hoch), NICHT am Shader (`Clip`=0, addiert linear). Hebel = Show-Level Tonemap/Exposure/unlit, falls gewünscht.
5. **Backlog:** Conductor-C++ (musikalische Kohärenz aus trägen Kanälen) · per-Welle-Brightness (`PulseEnergy0..11` radius-seitig ungenutzt) · Textur `T_GlowPattern` (optional, channel-map §4) · geparkt: volle `UWaveDataBridge` (D-17, Risiko-Scan).

## 5. DECISION-TRACKER (Detail in OPEN_DECISIONS.md)
- **D-17** generische Channel-Engine + per-Welle-Energie: GEBAUT+GRÜN; **Engine-Param-Sichtbarkeit-Fix + Glow v0.6 diese Session gebaut+gespeichert+committed (444dff9)**, Operator-Eye-Test v0.6 offen.
- **D-13** Tuning (dezent/Spline ganze Wand) · **D-15** OSC-Gradient-Atlas (Farbe, für Glow) · **D-16** Shader-Refactor/BaseColor — Eye-Test-offen.

## 6. GOTCHAS (must-know)
- **save_assets nach jedem Material-Deploy** (s. Arbeitsweise). **Unverbundene Params = im MI unsichtbar** → C++-Read-Params als Custom-Node-Input verbinden + Nullgewichts-Keepalive (`total += 1e-9*(...)`).
- **Drei-Loop-Trennung:** Code-Loop (HLSL via Deploy-Pipe, autonom) · Graph-Loop (Pin/Param/Rewire, connection-preserving Full-Struct-Append, Reader-Readback) · Eye-Test (Operator).
- **Connection-preserving Append/Reorder:** Full-Structs verbatim aus Read + neue im exakten Format; Reader-Verify (broken old connections?) + Auto-Restore-Snapshot. [[reference_mcp_material_graph_authoring]]
- **Build nach C++-Edits** = `bridge_rebuild` (mit `save_assets([])` davor); rc=6 spurious → Verdikt via Log. Glow ist **reiner Shader** → kein Rebuild nötig.
- **Tunen IMMER an der Instanz** `M_RadialPulse_Inst`; ALT+P→ESC nach (Re)Start. `Slate.bAllowThrottling=0` in DefaultEngine.ini → Viewport bleibt live (nicht entfernen).
- **Git:** MCP-Repo committed `444dff9` (HLSL/Contract/deploy_glow_build, lokal main, nicht gepusht). Companion-Repo: HANDOVER committed; **`OPEN_DECISIONS.md` NICHT von mir committet** (s.u.). `.uasset` = Plastic (Operator). Memory-Writes → UE-Claude-Slug.
- **⚠️ PARALLELE WORKSTREAM läuft (Operator-bestätigt):** **RBGA — RC Param-Surface** (OPEN_DECISIONS „RBGA — RC Param-Surface"/RBGA-U1, + `MCP.uproject`-Änderung) ist **separat von PulseKit, NICHT anfassen**. `OPEN_DECISIONS.md` war diese Session dirty mit deren uncommittetem RBGA-Eintrag → ich hab OPEN_DECISIONS **bewusst nicht editiert/committet** (sonst hätte ich deren Arbeit mit-committet). Der Glow/Engine-Fix-Eintrag für OPEN_DECISIONS fehlt daher dort noch — **nachtragen, sobald RBGA committet ist** (Stand steht hier + in Memory `project_pulsekit_radial_pulse`). Beim Committen IMMER chirurgisch `git add <meine files>`, nie `-A`.

## 7. NÄCHSTER SCHRITT (konkret)
Auf Operator-Eye-Test-Verdikt v0.6 warten → entweder Glow-Feintuning (Params) ODER Atlas-Farbe reinhängen (§4.2) ODER nächstes Feature (Conductor/Light). Immer: bauen → grün → **speichern** → ihm zum Eye-Test.
