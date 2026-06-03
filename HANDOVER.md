# HANDOVER — PulseKit (Stand 2026-06-03, nach per-Puls-Glow v0.7 + Atlas-Color-Socket)

> Übergabe an die Reinkarnation. Self-contained → taugt als Respawn-Prompt. Bei Widerspruch gilt OPEN_DECISIONS + Memory + **Live-Editor** (immer live gegenprüfen).

## ⚡ ARBEITSWEISE (Operator-Anweisung — BINDEND)
- **WORKFLOWS / SUBAGENTS gebündelt/parallel** für **Diagnose/Research/Reads** (Datei-Seite fan-out-bar). **Editor-Bridge = single-threaded → alle Editor-MUTATIONEN sequenziell**, ein Call pro Message bei strukturellen/destruktiven Schritten. Solo nur für triviale Edits.
- **Operator = Non-Coder, Eye-Test-Master.** Tunt live an `M_RadialPulse_Inst`. Will: **distinctive/parameter-abhängige** Effekte, **reiche Live-Knopf-Fläche** + saubere isolierte Params, **Fortschritt > Zeremonie** (weniger Rückfragen, grün → ihm), **High-Level-Trade-offs + Empfehlung** statt Code. **Versions-Stempel** in `.hlsl` Pflicht.
- **REINKARNATION bei großen Features statt am Budget-Limit halb bauen** (Operator-Wunsch 2026-06-03: „Conductor lieber neue Inkarnation"). Diese Übergabe wurde bei ~300k gesetzt, damit der Conductor mit vollem Budget gebaut wird.

## 0. BOOTSTRAP
1. **CLAUDE.md** (CWD `C:\development\Projects\MCP`) → Konventionen `C:\Claude_Projects\UE-claude\CLAUDE.md`, `OPEN_DECISIONS.md`, Memory-Index.
2. **`C:\Privat\RBGA\ClaudeCode\rbga-engine\docs\spec\07_CHANNEL_REFERENCE.md`** = LIVE-Wahrheit der MPC-Kanäle. **Index (OSC_MPC-Order):** 0 BASS·1 LOW·2 MID·3 HIGH·4 tilt_velocity·5 roughness·6 shimmer·7 spectrum_tilt·8 sub_pressure·9 phase·10 centroid_zscore·11 tension_rise·12 Warmth.
3. **Memory** (`~\.claude\projects\C--Claude_Projects-UE-claude\memory\`): `project_pulsekit_radial_pulse`, `reference_mcp_material_graph_authoring`, `reference_shader_code_loop_pipe`, `feedback_shader_tuning_surface`, `reference_oscbridge_atlas_persistence`, `project_mcp_bridge_worker`.

## 1. BRIDGE-GATE + TOOL-HANDLES
`bridge_status` → `editor_reachable=true` erwartet. **Editor zu (reachable=false, Broker antwortet) = SOFORT Operator-Handoff.** Nur Broker-down = autonom neu starten. „Unknown tool" trotz reachable → state.json `loaded_toolsets`=[] (stable_session_id behalten) + Broker-Neustart + `load_toolset`.
- **Tools sind deferred → Schema via ToolSearch `select:<voller_name>` laden, dann callbar.** Voller Name = `mcp__unreal-mcp__toolset_registry_toolsets_core_<modul>_<Toolset>_<tool>` (Dots→Underscores). Reader = `mcp__unreal-mcp__OSCBridgeEditor_MaterialGraphReaderToolset_ReadMaterialGraph`. Gebraucht: MaterialTools_{add_expression, connect_expressions, disconnect_expressions, get_expression_input_names, recompile}; ObjectTools_{get_properties, set_properties}; AssetTools_save_assets; ProgrammaticToolset_execute_tool_script; LogsToolset_GetLogEntries.

## 2. WAS LÄUFT (gebaut + grün + GESPEICHERT + committed, lokal main MCP-Repo)
- **per-Puls-Glow v0.7** (`e70fd72`): out3 `GlowIntensity` moduliert **pro Welle** nach `PulseEnergy<N>` (Helligkeit + Venen-Dichte); Pattern-Glow verschmilzt mit Pulse-Glow. Im RIPPLE-Macro `gPulseW += band·fades`, `gPulseE += band·fades·ENERGY` → `ppAct = saturate(gPulseE/max(gPulseW,1e-4))`; `gPattP = pow(gPatt, lerp(1,.5,ppAct))`; `gSig = (gBase+ppAct)·gPattP + gSpike·gCoreP + gCalm·…`. **ppAct=0 ⇒ exakt v0.6-Look.** Reiner Code-Loop, **KEINE neuen Inputs** (nutzt PulseEnergy0..11 = Pins 48–59, vorher ungenutzt), recompile-only. `Shaders/RadialRipples.hlsl` v0.7 + Contract v0.7.
- **Atlas-Color-Socket** (Graph): `Multiply_1.B` = Glow-Farbe. **Operator hat 2026-06-03 seinen fertigen Atlas-Color-Output dort verdrahtet + gespeichert** (Bootstrap-Dummy `Constant3Vector_1`/Magenta ersetzt; Alt-`GlowColor` `VectorParameter_13` verwaist im Graph, reaktivierbar). Glow-Kette: `out3 → Multiply_1 (×Farbe) → Add_1.B → MP_EmissiveColor`. out0/BaseColor/WPO unverändert.
- Vorgänger: Engine-Param-Sichtbarkeit-Fix + Glow v0.6 (`444dff9`), generische Channel-Engine (`a6fac71`).

## 3. NÄCHSTE AUFGABE — CONDUCTOR (Schicht 2/3, C++) [Operator-Auftrag, Plan GELOCKT]
Operator-Vision: pattern+pulse-glow „supersmart verschmelzen" (✓ Schicht 1) + **musikalisch modulieren** (Conductor). **Gelockt (2026-06-03):** per-Puls = Helligkeit+Venen-Dichte (**Farbe bleibt global/Atlas**) · Signale = **ALLE 3** (Intensity-Envelope + Clean-Beat + Build/Drop) · Reihenfolge = Shader (done) → Conductor.

**VERIFIZIERTE TOPOLOGIE (2 Worker-Agents, 2026-06-03):**
- **Komponente:** `UPulseTriggerComponent` — `Plugins\PulseKit\Source\PulseKit\Public\PulseTriggerComponent.h` + `Private\PulseTriggerComponent.cpp`. Editor-Tick via nested `FPulseTickProxy` (FTickableGameObject, IsTickableInEditor=true) → `DoTick(DeltaTime)`.
- **MPC-Read:** `SourceCollection` (=OSC_MPC) via `GetScalarParameterNames()` (stabile Index-Order) + `ReadChannelByIndex(W,names,idx)` = `UKismetMaterialLibrary::GetScalarParameterValue`. Channel-Engine-Indizes (TriggerChannel/EnergyChannelA/B/…) liest C++ aus `MIDs[0]`, RoundToInt.
- **MID-Write (pro Tick, auf ALLE CachedMIDs):** `PulseAge%d`, `PulseEnergy%d` (0..11), `PulseLife`. **Schreibt NIE in die MPC — nur lesen.** CachedMIDs = je `AStaticMeshActor` in `TargetSurfaces` ein `CreateDynamicMaterialInstance`.
- **FirePulse (Geburt):** `SlotEnergy[slot] = (A op B)·EnergyScale + EnergyBias` (A/B via EnergyChannelA/B-Index, Op +−×÷), schreibt Center%d/PulseAge%d=0/PulseEnergy%d. `SlotAge[12]`/`SlotEnergy[12]`, NumSlots=12, round-robin.
- **CONDUCTOR-INSERT (Worker-empfohlen, minimal-disruption):** privater `void TickConductor(UWorld* W, const TArray<FName>& ChannelNames)`, aufgerufen in `DoTick` NACH dem `MIDs`-Validity-Guard + SpeedBrake-Reads, VOR der Slot-Loop. Liest rohe Kanäle, hält geglättete Member-Floats, schreibt 3 abgeleitete Signale via `UKismetMaterialLibrary::SetScalarParameterValue(W, SourceCollection, FName, value)` in die MPC. Neue UPROPERTY-Gruppe „Pulse|Conductor" für Smoothing-Coeffs.
- **Per-Puls-Mod (Schicht 3):** in `FirePulse` `SlotEnergy *= (1 + Boost·cond_intensity)` o.ä. → im Build-up geborene Wellen glühen heißer.

**3 Signale (Vorschlag):** `cond_intensity` = EMA der Gesamt-Energie (z.B. sub_pressure o. BASS+LOW+MID+HIGH) · `cond_beat` = entzitterter Takt-Puls aus `phase` (Kanal 9, Wrap/Rising→1.0 + exp-Decay) · `cond_drop` = Rate-of-Change der Envelope (scharfer Abfall = Drop-Event / Anstieg = Build).

**MPC-KANAL-REZEPT (verifiziert):** neue Scalar-Params ans **ENDE** von `/Game/OSC/OSC_MPC` (Index-sicher; mittig einfügen renummeriert + bricht Channel-Engine-Indizes!). Namen `cond_intensity`/`cond_beat`/`cond_drop` (Index 13/14/15). **KEIN Router-FloatBinding** nötig (C++-derived, nicht OSC). PulseKit entdeckt sie autom. (ChannelMap). **OFFEN/ZUERST KLÄREN:** wie Scalar-Params zur MPC via MCP hinzufügen — `ObjectTools.set_properties` auf die Collection (`ScalarParameters`-Array) testen, sonst Operator legt sie manuell im Editor an.
**Material-Konsum — 2 Wege (mit Operator entscheiden):** (A) 3 CollectionParameter-Nodes → NEUE Custom-Node-Inputs (Full-Struct-Append 90→93, recompile) → HLSL nutzt sie explizit. (B) **simpler:** die bestehenden Glow-Channel-CollectionParameter (GlowDrive/Peak/Calm) auf die `cond_*`-Kanäle umhängen (kein Append) — Conductor speist dann direkt die vorhandenen Glow-Hebel.
**Build:** nach C++-Edit **`bridge_rebuild`** (mit `save_assets([])` davor!; `build_rc=6` SPURIOUS → Verdikt via `_rebuild_build.log` „Result: Succeeded"). Dann MPC + Material-Wiring + ggf. Shader (Code-Loop) → `save_assets` → Eye-Test.

## 4. PIPES & GOTCHAS (must-know)
- **`save_assets(["/Game/Materials/M_RadialPulse"])` nach JEDEM Material-Deploy** — sonst beim (instabilen) Editor-Restart WEG.
- **Shader-Code-Loop:** `.hlsl` editieren → Body von `Tools/shader-deploy/deploy_radialripples.py` via `execute_tool_script` mit **DRY_RUN=False** (setzt `Code` → recompile → readback+Reader, roots-check). **Compile-Verdikt:** `GetLogEntries(category="LogShaderCompilers", pattern=".")` → „Materials Translated: N" + `category="LogMaterial"` LEER = grün. Dann `save_assets`. Version in `.hlsl` hochzählen.
- **ReadMaterialGraph** liefert ~68KB → landet in Datei (tool-results), mit PowerShell parsen (ConvertFrom-Json doppelt: `.returnValue` → inner; Top-Keys `material/expressions/rootInputs`; Edges = pro Node `inputs[].source.refPath`). Custom-Node = **90 Inputs / 4 Outputs** (out0 return/Emissive-Base · out1 BaseColor · out2 WPO · out3 GlowIntensity).
- **Graph-Append:** connection-preserving Full-Struct (Reader-Readback vor+nach, Alt-Kanten byte-erhalten). **Unverbundene Params = im MI UNSICHTBAR** → als Input verbinden + Keepalive `total += 1e-9*(…)`.
- **⚠️ RBGA-Workstream parallel:** `MCP.uproject` (MCP-Repo) + evtl. `OPEN_DECISIONS.md` (Companion-Repo) dirty mit RBGA. **NICHT anfassen, IMMER chirurgisch `git add <meine files>`, nie `-A`, nie push ohne Op-OK.** `.uasset` = Plastic (Operator). Memory → UE-Claude-Slug.
- Nach manuellem Editor-(Re)Start einmal **ALT+P→ESC** (primet OSC→MPC). `Slate.bAllowThrottling=0` in DefaultEngine.ini = Viewport live (nicht entfernen).

## 5. NÄCHSTER SCHRITT (konkret)
Conductor bauen (§3) inkrementell: (1) `TickConductor` C++ (3 Signale → MPC-Write) + `FirePulse`-Boost → `bridge_rebuild` + Log-grün. (2) 3 MPC-Kanäle anlegen (Mechanismus zuerst klären). (3) Material-Wiring Weg A/B mit Operator. (4) ggf. Shader-Tweak (Code-Loop). (5) `save_assets` → Operator-Eye-Test. Immer: grün → speichern → ihm.
- **Offen aus Schicht 1:** dedizierte `PulseGlowGain`/`PulseGlowDensity`-Knöpfe (Struct-Append, recompile-only) falls Operator feinere per-Puls-Kontrolle will.
