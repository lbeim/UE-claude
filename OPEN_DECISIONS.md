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

### D-2 UE-Projekt-Pfad  `[PENDING]`

CLAUDE.md Sektion K (Permissions-Tabelle) hat `<TBD>` fuer UE-Projekt-Pfad. Sobald UE-Projekt-Repo fix ist, Operator nennt den konkreten Pfad → CLAUDE.md Update.

**Aktuell beobachtet**: Operator hat UE-Projekt `MCP` unter `..\Projects\MCP\MCP\` aktiv (aus UE-Log 2026-05-13). Ist das der finale Pfad oder Throwaway-Test-Projekt?

---

### D-3 Inline-STOP-Konvention  `[PENDING]`

In CLAUDE.md Sektion C als optional vermerkt (auskommentiert). Operator hat Ctrl+C als Default-STOP-Mechanik. Soll Inline-STOP (Claude reagiert auf "STOP/halt/warte" im Text) als zusaetzliche Soft-Variante aktiviert werden?

**Status**: aktuell deaktiviert. Operator entscheidet bei Bedarf.

---

## Decided

### D-0 Phase-Pivot Epic-MCP-Adopt  `[DECIDED 2026-05-13]`

Verschiebung von Custom-Build (`rbga-smart-core`, 3000 LoC C++ Material-Tools) zu Adoption von Epic's `Unreal MCP`-Plugin in UE 5.8 Preview.

**Was wegfaellt**: eigener MCP-Server, eigene Tool-Registry, eigenes uplugin-Modul, Test-Harness, Worker-Coord-Daemon, Run-Types-Maschinerie.

**Was bleibt**: UE-Claude als duennes Companion-Repo (`C:\Claude_Projects\UE-claude\`) mit Konventionen + Memory + Decision-Tracker + (on-demand) Skills/Docs.

**Memory-Anchor**: `project_phase_pivot_epic_mcp_adopt` im rbga-smart-core-Slug.

**Begruendung**: Epic shipped MaterialTools (14 Calls) + MaterialInstanceTools (13 Calls) + ProgrammaticToolset (Python-Sandbox-Batching) komplett. Eigene Coverage von 95%+ ist obsolet, Pre-Phase-3-Investment war Lehrgeld.
