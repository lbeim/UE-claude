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

### D-0 Phase-Pivot Epic-MCP-Adopt  `[DECIDED 2026-05-13]`

Verschiebung von Custom-Build (`rbga-smart-core`, 3000 LoC C++ Material-Tools) zu Adoption von Epic's `Unreal MCP`-Plugin in UE 5.8 Preview.

**Was wegfaellt**: eigener MCP-Server, eigene Tool-Registry, eigenes uplugin-Modul, Test-Harness, Worker-Coord-Daemon, Run-Types-Maschinerie.

**Was bleibt**: UE-Claude als duennes Companion-Repo (`C:\Claude_Projects\UE-claude\`) mit Konventionen + Memory + Decision-Tracker + (on-demand) Skills/Docs.

**Memory-Anchor**: `project_phase_pivot_epic_mcp_adopt` im rbga-smart-core-Slug.

**Begruendung**: Epic shipped MaterialTools (14 Calls) + MaterialInstanceTools (13 Calls) + ProgrammaticToolset (Python-Sandbox-Batching) komplett. Eigene Coverage von 95%+ ist obsolet, Pre-Phase-3-Investment war Lehrgeld.
