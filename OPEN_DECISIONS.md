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

## Decided

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
