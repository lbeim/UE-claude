# OPEN DECISIONS — UE-Claude

Live-Tracker fuer Operator-Pending, Decided-Anker, Verify-Open. Status-Tags: `[PENDING]` / `[DECIDED YYYY-MM-DD]` / `[VERIFY-OPEN]`.

---

## Pending / Verify-Open

### D-1 Pulse-Trial-Hard-Gaps Verify  `[VERIFY-OPEN]`

5 Hard-Gaps + 3 Schnittstellen-Findings aus Pulse-Trial 2026-05-12 (rbga-smart-core) muessen gegen aktuellen Epic-Plugin-Stand verifiziert werden, bevor sie als `docs/pulse-trial-lessons.md` oder Memory landen.

**Kriterium**: muessen allgemeine Relevanz haben UND echte Friction beheben — sonst Pflege-Overhead.

**Naechster Schritt**: Material-Authoring-Trial mit Epic's MaterialTools im UE-Editor → re-evaluieren welche Gaps mit Epic-Adopt noch existieren.

**Quelle**: `C:\Privat\RBGA\ClaudeCode\rbga-smart-core` Memory `project_material_authoring_vision` + Pulse-Trial-Log 2026-05-12.

---

### D-3 Inline-STOP-Konvention  `[PENDING]`

In CLAUDE.md Sektion C als optional vermerkt (auskommentiert). Operator hat Ctrl+C als Default-STOP-Mechanik. Soll Inline-STOP (Claude reagiert auf "STOP/halt/warte" im Text) als zusaetzliche Soft-Variante aktiviert werden?

**Status**: aktuell deaktiviert. Operator entscheidet bei Bedarf.

---

### D-12 OSCBridge Receiver Editor-Mode-Cycle  `[PENDING]`

Beobachtet 2026-05-16 in Editor-Logs: Receiver durchlaeuft mehrere Stop/Destroy/Start-Cycles waehrend Map-Load + nach PIE-End. Auszuege:
- Editor-Mode beim Start: 2-3x `Started -> Destroying -> Killed -> Started` direkt hintereinander, ohne offensichtlichen Trigger. Port wechselt zwischen `0.0.0.0:0` (vermutlich CDO/Default-Konstruktion) und `0.0.0.0:8000` (echte Listener-Instanz).
- Nach PIE-End: `Failed to bind ... SE_EADDRINUSE` direkt nach `PIE ended - resuming editor-mode OSC receiver`, dann Destroy + Start mehrfach.

**Wirkt funktional nicht** (Stream funktioniert nach jedem Cycle weiter, Verifikation D-11), nur Log-Noise + potentielle Race-Bedingungen. Kandidat-Fixes:
- Receiver-World-Type-Filter strenger (z.B. nur `EWorldType::Editor`, nicht `EditorPreview`).
- Resume-Delay um Port-Release abzuwarten (`SE_EADDRINUSE`-Retry mit Backoff statt Sofort-Bind).
- `OnConstruction` re-entry-Guard waehrend laufender Listen-Session.

**Naechster Schritt:** wann Operator das nervt. Aktuell Side-Issue.

---

## Decided

### D-14 MCP-Bridge-Worker — Session-Robustheit über Editor-Restart  `[DECIDED 2026-06-01]`

Operator-Pain: nach jedem Editor-Rebuild/Neustart muss die MCP-Session von Hand neu verbunden (`/mcp` → `unreal-mcp`) + Toolsets neu geladen werden ([[reference-ue-editor-tick-ftickable-proxy]] Punkt 3). Operator-Auftrag 2026-06-01: robust machen „wie im Browser".

**Root-Cause (verifiziert via Explore + claude-code-guide):** Der MCP-Server lebt IM Editor-Prozess (Epic `ModelContextProtocol`-Plugin). (1) Session-ID = `FGuid::NewGuid()` pro `initialize`, rein In-Memory, nie persistiert → neuer Editor lehnt altes Token mit HTTP 400 „unknown session" ab; stabile ID im Plugin nicht vorgesehen. (2) `load_toolset`-State ist prozess-global → nach Restart weg. (3) Claude Codes Auto-Reconnect deckt nur ~30 s (5 Versuche Backoff) ab — ein Build hält den Editor Minuten unten; zusätzlich re-initialisiert Claude bei Session-Invalidierung nicht von selbst (GitHub #60949). Editor-Transport ist POST-only (GET/SSE geblockt).

**Operator-Decisions (AskUserQuestion 2026-06-01):** (a) **Voller Worker** statt nur Session-Broker oder Minimal-Auto-Start. (b) „sie müssen nur speichern" = **Projekt vor Stop automatisch sichern** (dirty packages), kein Datenverlust.

**Architektur:** dauerlaufender stdlib-Python-Broker (Python 3.14 via `py`-Launcher, KEIN pip — Konvention K) zwischen Claude Code und Editor. Claude → Broker `:8765/mcp` (stabile, nie-invalidierende Session) → Editor `:8000/mcp` (flüchtig). Broker hält Claudes Session am Leben, re-initialisiert die Editor-Session beim Wiederkommen, spielt geladene Toolsets verbatim nach, parkt Calls während Restart. Synthetisches Tool `bridge_rebuild` (M2) besitzt den Zyklus speichern→zu→Build.bat→auf→reinit. Ablage `C:\development\Projects\MCP\Tools\mcp-bridge\` ([[feedback-project-files-in-project]]).

**Bewusster Teil-Rückbau von D-0:** dort wurde der „Worker-Coord-Daemon" gestrichen. Hier kommt ein *dünner* Worker zurück — nur Lifecycle/Robustheit, NICHT Tool-Hosting (Tools bleiben Epics Plugin).

**Status 2026-06-01 — M1 + M2 verifiziert (Run-Test, kein Crash):**
- **M1** (transparenter Reconnect-Broker) ✓: `bridge.py` stdlib-Broker auf `:8765`; stabile Claude-Session; **SSE-Streaming-Client** (`http.client`, liest tools/call-SSE bis zum Ergebnis-Event); Auto-Reconnect bei „Invalid session id"; Single-Instance-Guard. Voller Pfad Claude→Broker→Editor inkl. echtem `tools/call` gegen den Editor verifiziert.
- **M2** (`bridge_rebuild`) ✓: save→stop→`Build.bat`→start→reinit→replay, mit **Safety-Gate** (kein Schließen wenn Save fehlschlägt). Save = `toolset_registry.toolsets.core.asset.AssetTools.save_assets({asset_paths:[]})` (alle dirty). Voller Zyklus verifiziert: **dieselbe Claude-Session überlebt den Editor-Neustart, `tools/call` ohne Reconnect**. `lifecycle.py` startet Editor mit `-StartModelContextProtocolServer` (MCP-Autostart).
- **Crash-Lehren** (2 Editor-Crashes im Bau, beide gefixt): naiver close-early-Client crasht Editor ([[reference-ue-mcp-toolcall-sse-async-crash]]); Zombie-Broker via netstat-Locale-Bug ([[reference-windows-netstat-locale-single-instance]]).
- **Files**: `Tools/mcp-bridge/` (bridge.py, lifecycle.py, config.json, selftest.py, test_client.py, start-bridge.cmd, README.md). `.mcp.json` → `:8765` (timeout 300000) umgestellt.
- **M3.2 Auto-Prime** ✓: `bridge_rebuild` löst nach dem Neustart `Alt+P→ESC` via `SlateInspectorToolset.PressKey` aus (PIE-Zyklus → OSC→MPC live), best-effort + Reminder. Operator-Eye-Test 2026-06-01: „sauber funktioniert" ([[reference-ue-editor-pie-cycle-primes-mpc-stream]]).
- **M3.3 Long-Build** ✓: Client-Timeout `.mcp.json` → 1.200.000 ms (20 min) + Worker-`build_timeout_s` 1800 s; lange Voll-Rebuilds brechen die Claude-Session nicht mehr ab. **SSE-Live-Progress-zu-Claude bewusst deferred** (Timeout gelöst, Schritte stehen im Ergebnis + Broker-Konsole; Mehrwert marginal, nachrüstbar).
- **CLAUDE.md-Anker** ✓ (Operator-Wunsch statt OS-Autostart): Broker-Start als Bootstrap-Schritt 4 + Bridge-Status-Topologie in Projekt-`CLAUDE.md` verankert.
- **Offen — Adoption** `[VERIFY-OPEN]`: Operator startet `start-bridge.cmd` dauerhaft + Claude einmal neu → Robustheit dauerhaft live. (Optional M4: Boot-Autostart, SSE-Live-Progress.) Operational-Doku: Memory [[project-mcp-bridge-worker]].

---

### D-13 Radialer Bass-Puls-Shader: Material + PulseKit-C++-Plugin  `[DECIDED 2026-06-01]`

Operator-Auftrag: radiale Welle vom Center, World-Position, impulsartig + randomisiert, von BASS getriggert, X Einschuss-Punkte, Sequence/Random. Details: Memory [[project-pulsekit-radial-pulse]].

**Material** `/Game/Materials/M_RadialPulse` via MCP (MaterialTools/ObjectTools/Programmatic): ein Custom-HLSL-Node als Kern, 8-Slot-Kaskade + Attack/Decay + nahtlose orientierungs-unabhängige Wobble (Normalen-Tangenten-Ebene). Authoring-Learnings: [[reference-mcp-material-graph-authoring]].

**Architektur-Pivot (Operator-Decision)**: Bass-Trigger NICHT im BP (MPC-Scalar-Read im BP-Graph via MCP nicht erzeugbar — Node-Ambiguität, [[reference-mcp-bp-graph-authoring]]) und NICHT im OSCBridge-Plugin (Operator: OSC sauber halten). Stattdessen **eigenes Runtime-Plugin `Plugins/PulseKit/`** mit `UPulseTriggerComponent` (+Add-Component, Details-konfigurierbar): liest MPC-Scalar, Edge-Detect Threshold 0.65, feuert Spline-Punkte (Sequence/Random) auf die `TargetSurface`-MID. Editor-Tick via nested-FTickableGameObject-Proxy (FTSTicker scheiterte) — [[reference-ue-editor-tick-ftickable-proxy]]. **Verified 2026-06-01**: tickt im Editor (Log), treibt die Wand-MID; kompiliert grün gegen UE 5.8 (Build.bat).

**Files**: + `Plugins/PulseKit/` (uplugin + 4 Source-Files, N&M-Authorship), + `/Game/Materials/M_RadialPulse` (+ `_Inst`), + `/Game/BP/BP_PulseField` (Spline + Component), Instanz in **LED_Ndisplay** auf `SM_LED_Front_merged` (Cross-Map-Save-Falle: muss in Wand-Map liegen, nicht Main).

**Status 2026-06-01**: Code grün + Editor-Preview + Wand-Drive verifiziert. **Operator-Eye-Test offen** (Bass-Trigger im Play/nDisplay). `[VERIFY-OPEN]`-Feinschliff: (a) **Multi-Target** — `TargetSurface`→`TargetSurfaces` (Array) **umgebaut, Build grün 2026-06-01**: jedes Mesh eigene MID, alle synchron vom selben Puls (gleicher Center/Slot/Zeit = 1 kohärente Welle), Cache-Rebuild bei Listen-Edit (`PostEditChangeProperty`). **Pro Mesh M_RadialPulse(_Inst) auf Material-Slot 0 Pflicht**, sonst no-op. Offen: Multi-Mesh-Preview-Eye-Test + Listen-Neufüllung am platzierten BP_PulseField in LED_Ndisplay (alte Einzel-Ref durch Typwechsel weg). (b) Debug-`UE_LOG` raus **done**. (c) Default-Spline über die Wand — offen. (d) Bass-Eye-Test im Play — offen. **Build-Lesson**: Live Coding (Strg+Alt+F11) scheitert bei diesem Header/Reflection-Change (UBT Exit 6 `Unable to build while Live Coding is active` + Hot-Compile `Ensure: GC lock … game thread` beim Reflection-Rebuild) → voller Build + Editor-Restart Pflicht, [[reference-oscbridge-build-commands]].

**Pivot 2026-06-01 (Operator-Decision, AskUserQuestion):** weg vom binären Threshold → **kontinuierlich kurvengetrieben**. Die `_xf`-Modulations-Kurven (von **beat core** / `rbga-engine`, Cross-Projekt) modulieren die Welle organisch (Energie/Größe/Tempo); Start `BASS_xf` (live in OSC_MPC, auch im Editor; Adresse `/mod/mod/BASS_xf`). Bereits **gebaut+grün**: Actor-Array-`TargetSurfaces`, `PulseMaterial`-Parent, `Apply`-Button, `SourceParameter`-Dropdown, Editor-Bass-Trigger. Umsetzungs-Plan freigegeben: `~/.claude/plans/atomic-watching-goose.md`. Reinkarnation für die Umsetzung. Offen: M_RadialPulse Wellen-Params (WaveSpeed/Width/Intensity) via MCP exposen + C++-MPC-Modulation; Autopulse-Altlast (MID PulseAutoFire) per MCP-Debug.

---

### D-11 OSCBridge Editor-Dispatch-Fix + Wizard-UX + Inspector-RC-Tag-Auto  `[DECIDED 2026-05-16]`

D-8/D-9/D-10 Operator-Eye-Test 2026-05-15: trotz D-9 Watchdog kam OSC->MPC im Editor-Mode nicht durch. Logs zeigten "subscribed to ..."-Display korrekt, aber Router-OnFloat-Events fired ausschliesslich nach PIE-Start. Diagnose-Patch (CVar `OSCBridge.RouterDebug`, Tick-Heartbeat, Subscribe-Audit) am 2026-05-16 bestaetigte: **BlueprintAssignable Dynamic Multicast `OnCaptured` am Receiver dispatcht nicht in Editor-World** — gleicher Effekt wie UOSCServer's eigene Dynamic-Variante (siehe Memory [[reference-ue-osc-native-delegate-editor]] mit Generalisierung).

**Editor-Dispatch-Fix:** Receiver bekommt parallelen Native-Multicast `OnCapturedNative` (`DECLARE_MULTICAST_DELEGATE_TwoParams`). `RecordMessage` broadcastet beide. Router subscribed via `FDelegateHandle` + `AddUObject` auf Native (kein `AddDynamic` mehr). BP-Subscriber koennen weiterhin am Dynamic-OnCaptured haengen. `HandleReceiverCaptured` ist nicht mehr UFUNCTION. **Verified 2026-05-16**: Operator-"funktioniert!"-Quote, Editor-MPC reagiert live ohne Play.

**Inspector-Rechtsklick Tag-Auto-Create** (Op-Decision via AskUserQuestion 2026-05-16): "Create Binding from this signal" generiert jetzt einen GameplayTag aus der Adresse (gleiche `AddressToTagName`-Logik wie Wizard, dort dupliziert) und setzt ihn am Binding. Tag wird via `AddNewGameplayTagToINI` in `Config/Tags/OSCBridge.ini` registriert. Vorher nur Pattern ohne Tag — Tag-Getter im BP fand nichts.

**Wizard Auto-Learn + Reset-Bug-Fix** (Op-Friction 2026-05-15/16): `bLearning`-Flag raus, Wizard pollt ab Open, alle bekannten Adressen erscheinen ohne Klick. Initial-Design hatte zwei State-Sets (Snapshot + Queue) die zu Reset-Bug fuehrten ("wenn ich den wizard resette, dann fuellt er sich nicht mehr"). Konsolidiert zu einem `KnownToWizard`-Set; PollTick filtert zusaetzlich Adressen mit exact-Match-Binding am Router aus (Wildcard-Bindings bleiben sichtbar fuer Override-Workflow). Reset clears KnownToWizard + NewSignals — naechster Tick re-fuellt mit aktuellen ungebundenen Adressen. Status-Text zeigt explizit `Receiver: X   Router: Y` (Operator-Praeferenz [[feedback-explicit-references-preferred]]).

**Router-Diagnose-Patch + Snap-Button**: `bStartWithTickEnabled=true` + `SetActorTickEnabled(true)` in OnConstruction (defensive), Tick-Heartbeat-Log + Wait-Heartbeat-Log, CVar `OSCBridge.RouterDebug` fuer per-Message-Trace. Neue CallInEditor `SnapToActiveReceiver` der den expliziten Receiver-Slot fest setzt und `bAutoFindActiveReceiver` ausschaltet (Op-Praeferenz [[feedback-explicit-references-preferred]]).

**6 Tag-Getter BP-Naming** (Op-Friction: "nodes sollten get OSC float etc heißen"): `GetLatestFloat/Int/Vector3/Vector4/Bool/String` haben jetzt `DisplayName="Get OSC <Type>"` + `Keywords="OSC Latest Bridge ..."` damit BP-Node-Search findet.

**Konsequenz fuer D-8/D-9/D-10:** alle drei hatten Status "Operator-Eye-Test offen". Mit D-11 sind die Bauten **verifiziert grün im Editor-Mode** (D-8 Hz/Jitter, D-9 Editor-MPC via Native-Delegate, D-10 Tag-Getter im BP).

**Performance-Status 2026-05-16**: Op-Check ergab Hot-Path sauber (~0.015% Frame-Budget Baseline aus D-6, plus zweiter Native-Broadcast = ein FunctionPointer-Deref pro Bind). Sub-Optimierungen (Pattern-Index-Cache, Dynamic-Broadcast-IsBound-Gate) aktuell nicht noetig.

**MPC-Asset-Default-Default-Frage 2026-05-16**: Operator wollte wissen ob der Default im offenen MPC-Asset live zu sehen ist. Antwort: nein, by-design — MPC-Asset haelt Defaults (Source-of-Truth), Router schreibt nur Per-World-`UMaterialParameterCollectionInstance`-Overrides. Live-Werte sieht man im OSCBridge-Inspector, am Material-auf-Mesh, oder via `Get OSC <Type>(Tag)` im BP. Custom-Slate-Panel "OSC MPC Live-State" waere separate Feature.

**Files**: geaendert `OSCBridgeReceiver.h/.cpp`, `OSCBridgeRouter.h/.cpp`, `SOSCInspectorPanel.cpp`, `SOSCLearnWizard.h/.cpp`. 3 Auto-Builds gruen gegen UE 5.8 (~8s + ~16s + ~8s).

**Status 2026-05-16:** Code grün, Operator-Eye-Test grün — Editor-MPC live ohne Play, Wizard-Reset-Refresh OK, Inspector-RC-Tag-Auto built.

---

### D-10 OSCBridge Tag-Taxonomie + Tag-Getter + Wizard-Prefill  `[DECIDED 2026-05-15]`

Operator-Decisions im Iterations-Dialog 2026-05-15.

**Tag-Taxonomie — Zweck-Root.** Schema `<Zweck>.<Leaf>` (z.B. `Lighting.Brightness`, `Motion.MoveSpeed`). `OSC.`-Prefix gestrichen — wenn eh alles OSC ist, ist die Root tot. Quelle (`React`/`Companion`/…) steht am Receiver, nicht im Tag. Begruendung: matches BPs-organized-by-system, "was es tut" als primaere Navigation. Konsequenz: keine generischen Plugin-Defaults moeglich — Kategorien sind Show-spezifisch und wachsen ueber Wizard-Nutzung. Verworfen: Herkunft-Root (Picker nach Geraet), "kein Tag, nur Adresse" (kein Tippfehler-Schutz, kein Decoupling). Revidiert teilweise D-7's "OSC."-Prefix-Annahme.

**Tag-Getter am Router (Pull-Pattern).** 6 BlueprintCallable Getter `GetLatest<Float/Int/Vector3/Vector4/Bool/String>(FGameplayTag Tag)` in Kategorie `OSC|Values`. Zero-Default wenn Tag noch nicht geroutet. Router cached post-transform Wert per Tag in 6 `TMap<FGameplayTag, T>`, Cache-Writes in den 6 `ApplyXBinding`-Funktionen (gating auf `Binding.Tag.IsValid()`). Drei-Spuren-Modell fuer BP-Werte-Konsum: **MPC** treibt Material direkt, **Tag-Getter** liefert Werte fuer BP-Logik (zentrale, ueberall-verfuegbare Stelle), **`OnFloat`/`OnBang`-Events** nur fuer reaktive Moment-Logik. Loest "ein OnFloat-Event fuer N Channels"-Ergonomie-Problem.

**Wizard-Prefill (`SOSCLearnWizard::AddressToTagName`).** `OSC.`-Prefix raus, Segmente PascalCase, Adress-Platzhalter. `/mod/intensity` → `Mod.Intensity`. Operator benennt leading Segment auf Zweck um.

**MPC-Auto-Create:** angenommen aber vertagt — braucht HOW-Decision wann/wo es einhakt (Inspector "Create Binding" hat noch keinen MPC-Target zur Anlage-Zeit; ggf. Router-Button "Auto-Create missing params for all bindings").

**Files:** geaendert: `OSCBridgeRouter.h/.cpp`, `SOSCLearnWizard.cpp`. Build gruen gegen UE 5.8.

**Status 2026-05-15:** Code fertig + kompiliert gruen. Operator-Eye-Test offen — gebuendelt mit D-8 und D-9.

---

### D-9 OSCBridge Editor-Mode-Routing — Watchdog-Fix + MPC-Propagation-Verify  `[DECIDED 2026-05-15]`

Operator-Befund 2026-05-15: erster Eye-Test der D-6/D-7-Bauten ergab, dass OSC→MPC nur in PIE/Play funktionierte, nicht im Editor — trotz `bRouteInEditor`-Flag am Router.

**Diagnose:** zwei Verdaechtige, einer bestaetigt, einer entlastet.
- **C2 (bestaetigt — der Bug):** Router-Editor-Subscription-Pfad hatte keinen Retry. `OnConstruction` ruft `RebindReceiver` einmal beim Platzieren — ist der Receiver da noch nicht aktiv (Normalfall, weil `bListenInEditor` default aus ist und der Operator es spaeter umlegt), haengt der Router sich nie an. PIE-Pfad (`BeginPlay`) hat 0.5s-Retry-Timer, deshalb funktionierte's dort.
- **C4 (entlastet — kein Engine-Bug):** Editor-World MPC-Instanz-Propagation. Gegen UE-5.8-Engine-Sources verifiziert via Verify-Subagent (`World.cpp`, `ParameterCollection.cpp`, `LevelTick.cpp`, `EditorEngine.cpp`): deferred MPC-Render-State-Updates flushen unconditional in `SendAllEndOfFrameUpdates`, das `UEditorEngine::Tick` fuer alle Worlds aufruft. Details: Memory [[reference-ue-editor-mpc-propagation]].

**Fix:** Router-Editor-Subscription-Watchdog. `PrimaryActorTick.bCanEverTick = true`, `ShouldTickIfViewportsOnly() → true`, `Tick` ruft `RebindReceiver` solange `IsEditorWorld() && bRouteInEditor`. Self-healing — Router klinkt sich am aktiven Receiver an, egal in welcher Reihenfolge platziert/aktiviert. `RebindReceiver` ist idempotent (early-return wenn Subscription aktuell), per-Tick-Kosten = paar Weak-Ptr-Derefs. Play-Pfad (`BeginPlay` + Retry-Timer) unangetastet.

**Realtime-Viewport-Pflicht:** Engine schreibt korrekt, aber non-realtime Level-Viewport zeichnet nicht laufend neu → User sieht's nicht. Strg+R / Viewport-Menue "Realtime" ist Pflicht fuer alles Live-im-Editor. PIE rendert immer Realtime, daher faellt's dort nicht auf.

**Lesson (Memory [[feedback-static-read-isnt-runtime-verify]]):** dass der Code-Pfad existiert (`bRouteInEditor` + `OnConstruction`-Branch) heisst nicht dass er funktioniert. Static-Read von Code begruendet nur Hypothese, kein "works" — Eye-Test oder Engine-Trace gegen-checken.

**Files:** geaendert: `OSCBridgeRouter.h/.cpp`. Build gruen gegen UE 5.8.

**Status 2026-05-15:** Code fertig + kompiliert gruen. Operator-Eye-Test offen — gebuendelt mit D-8 und D-10.

---

### D-8 OSCBridge — Hz-Berechnung gefixt + Jitter-Anzeige  `[DECIDED 2026-05-14]`

Operator-Befund: Hz-Spalte im Inspector zeigte wilde Ausreisser (30-2000 Hz) statt der realen ~60-Hz-Bundle-Rate. Ursache: `HzEMA` rechnete `1/Dt` pro Message (jitter-dominiert — zwei Messages 0,5 ms auseinander = 2000 Hz) und glaettete den verzerrten Kehrwert per EMA.

**Fix (Operator-Decisions):**
- **Fenster-Zaehlung statt EMA**: Rate = Messages pro Adresse im 1-s-Fenster. Stabil, unverzerrt, jitter-immun. Auch fuer seltene Bangs korrekt (EMA hatte die ueberhoeht).
- **Berechnung Receiver → Inspector verschoben**: `HzEMA`-Feld + Per-Message-Mathe raus aus dem Hot-Path. Neuer statischer `ComputeArrivalStats()` am Receiver (pure function ueber den Capture-Ring-Buffer). Inspector ruft ihn im 10x/s-Refresh — laeuft nur solange das Panel offen ist. Operator-Wunsch: "brauche das nur im Inspector".
- **Jitter-Spalte** (Operator-Decision "billiger Zusatz"): neue sortierbare Spalte neben Hz, zeigt Std-Abweichung der Message-Abstaende in ms — explizite Ablesung "wie sauber getaktet kommt das Signal an". Leeres Feld bei <3 Samples.
- Debug-Overlay (`OSCBridge.Debug` CVar) nutzt denselben Helper.

**Files:** geaendert: `OSCBridgeReceiver.h/.cpp`, `SOSCInspectorPanel.h/.cpp`. Build gruen gegen UE 5.8 (11 s).

**Status 2026-05-14:** Code fertig + kompiliert gruen. Operator-Eye-Test offen — buendeln mit Phase-2/3-Eye-Test.

---

### D-7 OSCBridge Phase 3 — Foundation + Learn-Mode-Wizard  `[DECIDED 2026-05-14]`

Phase 3 in einem autonomen Overnight-Run umgesetzt (Operator-Auftrag 2026-05-14, Eye-Test gebündelt auf 2026-05-15). Alle Module kompilieren grün gegen UE 5.8 (`Build.bat`, Editor-Target).

**Foundation:**
- **`EOSCSignalType`-Enum** (neu: `OSCBridgeTypes.h`): Float/Int/Vector3/Vector4/Bool/String/Bang/Raw — gemeinsames Typ-Vokabular für Wizard + Rechtsklick-Menü.
- **Kanal-Identität → GameplayTag** (Operator-Decision): `Tag`-Feld an allen Binding-Structs + den `OnX`-Events von `FName` auf `FGameplayTag`. `Pattern` bleibt `FName` (Wildcard-Matching). In BP wird gegen Tag-Literale aus dem Picker verglichen statt Strings getippt. `GameplayTags`-Modul-Dep im Runtime-Modul.
- **Int- + Raw-Binding-Typen** (Int: Operator-Decision): `FOSCIntBinding` (near-clone Float, int-getypte Transforms, kein Smoothing) + `FOSCRawBinding` (Pattern+Tag, feuert `OnRaw` mit vollem Entry-Payload, unabhängig von anderen Matches). Je TArray + Event + Apply-Pfad am Router.

**Stufe 1** — Inspector-Rechtsklick "Create Binding from this signal →": Typ aus `ArgTypeSignature` der selektierten Adresse vorausgewählt, Binding an `AOSCBridgeRouter::GetActiveRouter()` angehängt, `FScopedTransaction` + `Modify()` + `PostEditChange()` für Undo/Dirty. `GetActiveRouter()` als statischer Pointer analog `GetActiveReceiver()` (gesetzt in BeginPlay/OnConstruction, geleert in EndPlay/Destroyed).

**Stufe 2** — Learn-Mode-Wizard (`SOSCLearnWizard`, eigener Editor-Tab "OSC Learn Wizard" unter Developer Tools): Snapshot bei Start → neu auftauchende Adressen werden als Queue gelistet, je Zeile Typ-Combo + Tag-Name (vorausgefüllt `/mod/intensity` → `OSC.mod.intensity`) + Create-Button. Create registriert den GameplayTag via `IGameplayTagsEditorModule::AddNewGameplayTagToINI` in Tag-Source `OSCBridge.ini` (→ `Config/Tags/OSCBridge.ini`, NICHT die Projekt-Default-Ini) und legt das Binding am aktiven Router an. `GameplayTagsEditor` als Editor-Modul-Dep + `.uplugin`-Plugin-Dependency. Details: Memory [[ue-gameplaytag-registration]].

**Files:** + `OSCBridgeTypes.h`, `SOSCLearnWizard.h/.cpp`; geändert: `OSCBridgeRouter.h/.cpp`, `SOSCInspectorPanel.h/.cpp`, `OSCBridgeEditorModule.cpp`, beide `Build.cs`, `OSCBridge.uplugin`.

**Status 2026-05-14:** Code fertig + kompiliert grün. Operator-Eye-Test offen — gebündelt mit Phase-2-Eye-Test auf 2026-05-15.

**Noch offen aus D-6:** Session Record/Replay, Data-Asset-basierte Binding-Tables, zeit-korrektes Smoothing.

---

### D-2 UE-Projekt-Pfad  `[DECIDED 2026-05-13]`

UE-Projekt liegt unter `C:\development\Projects\MCP\` (Single-Level, `MCP.uproject` direkt drin). nDisplay-Setup, kein `Source/`-Ordner — reines Content/BP-Projekt. CLAUDE.md Sektion K Permissions-Tabelle entsprechend gefuellt.

**Korrektur zur Vorbeobachtung**: alte Notiz `..\Projects\MCP\MCP\` (doppelt geschachtelt) war falsch.

---

### D-4 MCP-Bridge-Setup  `[DECIDED 2026-05-13]`

Bridge-Architektur zur `unreal-mcp`-Anbindung:

- **Plugin**: `ModelContextProtocol` (FriendlyName "Unreal MCP") in UE 5.8 Engine-Plugins, aktiv im Editor.
- **Transport**: HTTP, Server unter `http://127.0.0.1:8000/mcp`, registriert als Server-Name `unreal-mcp`.
- **Config-Trigger**: Editor-Console-Command `ModelContextProtocol.GenerateClientConfig ClaudeCode` schreibt `.mcp.json` ins UE-Projekt-Root.
- **Working-Directory**: Claude-Code-Session laeuft aus `C:\development\Projects\MCP\` (UE-Projekt-Root), nicht aus Companion-Repo. Sauber getrennt: Companion-Repo = Konventionen/Memory/Tracker, UE-Projekt-Session = Editor-Drive.
- **Coupling**: Stub-`CLAUDE.md` im UE-Projekt-Root verweist auf Companion-Repo CLAUDE.md + OPEN_DECISIONS + UE-Claude-Memory-Slug (`C--Claude_Projects-UE-claude`). Single Source of Truth bleibt das Companion-Repo.

**Implikation**: Memory-Updates schreibt Claude immer in den UE-Claude-Slug, unabhaengig vom aktuellen CWD-Slug. Im Stub-CLAUDE.md dokumentiert.

---

### D-6 OSCBridge Phase 2 — Routing-Layer  `[DECIDED 2026-05-14]`

Phase 2 des OSCBridge-Plugins: typisierter Routing-Layer auf dem Capture-Foundation (D-5).

**AOSCBridgeRouter** (Pure Actor, BP-subclassable): subscribed sich an Receiver's `OnCaptured`, haelt 6 Binding-Tabellen (Float / Vector3 / Vector4 / Bool / String / Bang), routet eingehende Messages auf Targets.

**Binding-Modell**:
- Jedes Binding: `Pattern` (FName, exact oder trailing-wildcard `/mod/*`) + `Tag` (op-Label fuers Event) + optional MPC-Target + Transform (Scale/Offset/Clamp) + Smoothing-Alpha (EMA).
- Wildcard-Capture: `/mod/*` + ParameterName leer → captured suffix wird Param-Name → `/mod/intensity` schreibt `MPC.intensity`. Eine Zeile deckt einen ganzen Address-Prefix.
- Bang: type-agnostic, feuert pro Message am Address, optional Cooldown gegen 60Hz-Spam.
- Vector4 mit `bAcceptOSCColor`: OSC `r`-Type wird zu RGBA zerlegt.

**Targets**: Material Parameter Collection (auto-write, kein BP-Code) UND/ODER BlueprintImplementableEvents (OnFloat/OnVector3/OnVector4/OnBool/OnString/OnBang/OnUnboundMessage) fuer BP-Subclass-Logik.

**Receiver-Extension fuer Phase 2**: `OnCaptured` jetzt TwoParams (Entry + FOSCMessage). `FOSCBridgeCaptureEntry` erweitert um FloatArgs/FirstStringArg/FirstBoolArg/LinearColorArg fuer BP-Ergonomie. Hot-Path-Overhead gemessen ~0.015% Frame-Budget — Operator-Decision: behalten, keine Gate-Optimierung.

**Konkrete Learnings**:
- PIE-Duplication kopiert BlueprintAssignable-Delegate-Invocation-Lists aus der Editor-World → `AddDynamic` in BeginPlay triggert Duplicate-Ensure. Fix: defensives `RemoveDynamic` vor `AddDynamic`. Siehe [[reference-ue-pie-delegate-duplication]].
- `FOSCBridgeAddressFilter` (Single-FName-Wrapper-Struct) war Premature-Abstraction → geflattet zu direktem `Pattern`-Feld nach Operator-Friction (Adresse landete intuitiv im ersten Textfeld = Tag).

**Files**: + `OSCBridgeRouter.h/.cpp` im OSCBridge-Runtime-Modul. Build clean gegen UE 5.8.

**Status 2026-05-14**: Code fertig + kompiliert, Operator-Eye-Test verschoben auf 2026-05-15.

**Open Phase 3**:
- **`Raw`-Binding-Typ** (7. Binding-Typ) — matcht Pattern, feuert `OnRaw(Tag, Address, Entry)` mit dem vollen Entry-Payload, unabhaengig davon ob andere Bindings auch matchen. Fuer Custom-Multi-Arg-Messages ohne aufwaendiges Sender-Schema. ~30 Zeilen, simpelster Binding-Typ. **Performance-Klarstellung dazu**: das Plugin fan-t NICHT aus — 1 Message = 1 `OnCaptured` = 1 `HandleReceiverCaptured`, die Args reiten im `Entry.FloatArgs`-Array. Kosten skalieren mit `(Messages/s × matchende Bindings)`, NICHT mit Arg-Count. `Raw` ist das Anti-Overload-Tool: 1 Match statt N Einzel-Bindings auf einer fetten Message.
- **Learn-Mode-Wizard** — siehe `docs/handover-learn-mode-wizard.md` (inkl. Vorab-Frage Identifier-/Enum-Strategie).
- Session Record/Replay.
- Data-Asset-basierte Binding-Tables fuer Multi-Level-Reuse.
- Zeit-korrektes Smoothing (DeltaTime statt per-Message) falls Bridge-Rate variabel.

---

### D-5 OSCBridge Plugin  `[DECIDED 2026-05-14]`

Eigenes UE-Plugin `Plugins/OSCBridge/` im MCP-Projekt zum Empfang des React-Dashboard OSC-Streams (`C:\Privat\RBGA\ClaudeCode\react-dashboard\tools\osc_bridge.py` — WebSocket→OSC-UDP, ~60 Hz Frame-Bundles aus mod/state-Channels + Bangs).

**Design-Paradigma**: Capture-First, Route-Later. Receiver erfasst jede eingehende Message in per-Address-Stats + Ring-Buffer ohne Schema-Wissen. Slate Inspector Panel (Window → Developer Tools → "OSC Inspector") visualisiert live in Editor + PIE. Routing-Layer (Path-Handler-Bindings, Wildcards) bewusst zurueckgestellt als Phase 2.

**Architektur**:
- 2 Module: `OSCBridge` (Runtime, AOSCBridgeReceiver Actor) + `OSCBridgeEditor` (Editor, SOSCInspectorPanel)
- **Pure Actor**, KEIN Component+Wrapper-Pattern. Properties direkt am Actor-Root (Port, IP, bAutoStartInGame, bListenInEditor, RingBufferSize), `CallInEditor`-Buttons fuer Start/Stop/Clear
- Editor-Mode-Capture: `bListenInEditor`-Flag, OnConstruction + PostEditChangeProperty Reactivity
- PIE-Cycle: BeginPIE-Hook stoppt Editor-Receiver (Port-Konflikt), EndPIE-Hook resumed via TActorIterator

**Kritisches API-Learning**: `UOSCServer::OnOscMessageReceived` (BlueprintAssignable Dynamic Multicast) dispatcht NICHT in Editor-World — nur in PIE/Game. Native-Variante `OnOscMessageReceivedNative` (DECLARE_MULTICAST_DELEGATE_ThreeParams) funktioniert in beiden Modes. Plugin nutzt deshalb Native-Delegate. Details siehe Memory [[reference-ue-osc-native-delegate-editor]].

**BP+C++ Hybrid Status**: MCP.uproject bleibt BP-klassifiziert (keine `Modules:`-Section), Plugin-Module sind separat im `.uplugin`. First-Compile-Cost ~1 min einmalig, dann gecached. Identisch zur smart-core uplugin-Erfahrung.

**Files**: `C:\development\Projects\MCP\Plugins\OSCBridge\` (10 Source-Files + README + .uplugin). VS Build Tools 2022 required (Operator bestaetigt installiert).

**Open Phase 2 (Routing-Layer)**: Path-basierte typisierte Handler-Bindings, Wildcards `/mod/*`, optional Session Record/Replay. Aktuell BP-Side via `OnCaptured`-Event mit Address-Compare.

---

### D-0 Phase-Pivot Epic-MCP-Adopt  `[DECIDED 2026-05-13]`

Verschiebung von Custom-Build (`rbga-smart-core`, 3000 LoC C++ Material-Tools) zu Adoption von Epic's `Unreal MCP`-Plugin in UE 5.8 Preview.

**Was wegfaellt**: eigener MCP-Server, eigene Tool-Registry, eigenes uplugin-Modul, Test-Harness, Worker-Coord-Daemon, Run-Types-Maschinerie.

**Was bleibt**: UE-Claude als duennes Companion-Repo (`C:\Claude_Projects\UE-claude\`) mit Konventionen + Memory + Decision-Tracker + (on-demand) Skills/Docs.

**Memory-Anchor**: `project_phase_pivot_epic_mcp_adopt` im rbga-smart-core-Slug.

**Begruendung**: Epic shipped MaterialTools (14 Calls) + MaterialInstanceTools (13 Calls) + ProgrammaticToolset (Python-Sandbox-Batching) komplett. Eigene Coverage von 95%+ ist obsolet, Pre-Phase-3-Investment war Lehrgeld.
