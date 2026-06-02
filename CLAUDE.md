# UE-Claude — Konventionen

Companion-Repo zum UE-Projekt. Beheimatet Konventionen, Memory-Verweis, Skills, Decision-Tracker. Kein Code, kein eigenes Plugin — UE-Tools kommen aus Epic's `ModelContextProtocol`-Plugin (UE 5.8 Preview).

## North Star

Material-Authoring + Workflow-Agenten via Epic-Toolsets. Operator ist Eye-Test-Master fuer jeden Output. Claude agiert eigenstaendig im Inkrementell-Compose-Modus, **drei Loops sauber getrennt**: **Code-Loop** (Shader/Material-HLSL, Claude autonom, Einheit = *ein* selbst-verifiziertes Script) · **Graph-Loop** (Pins/Params/Rewire, gemeinsam) · **Eye-Test** (Operator, am Schluss). Das **max 2-3 Tool-Operationen pro Sequenz, dann Pause-Marker** gilt für **Graph/strukturelle/destruktive** Schritte — nicht für Code-Iteration. Detail + Pipe: B.

---

## B — MCP-Toolset-Workflow

- **Discovery on-demand**: noch nicht geladenes Toolset → `load_toolset`, dann callen. `list_toolsets` / `describe_toolset` nur bei echter Unsicherheit.
- **Programmatic-Setup**: vor Bulk-Arbeit mit `execute_tool_script` einmal pro Session `get_execution_environment` + die genutzten Output-Schemas lesen. Sandbox: nur `json`/`math`/`datetime`/`copy`/`re`, `open()` read-only auf Projekt-Pfad.
- **Native-First vor Bulk-Loops**: vor Per-Actor-/Per-Asset-Loops prüfen ob AssetRegistry-API, Reference Viewer oder Console-Cmd das Ergebnis direkt liefert — Editor-Bulk-Calls = Crash-/Zeitrisiko, bei Unsicherheit Verify-Subagent.
- **Shader-/Material-Code-Loop** ([[reference-shader-code-loop-pipe]]): HLSL des Custom-Nodes lebt als **versionierte Datei** (`Shaders/*.hlsl` = Source-of-Truth, `.uasset` = Build-Artefakt), Deploy via **ein** `execute_tool_script` (Datei→`Code`→`recompile`→Reader+Log-Verify). **Einheit = das Script**, nicht 2-3 Calls; Compile-grün genügt ([[feedback-build-green-enough]]). Ownership: **Code-Loop** = Claude autonom · **Graph-Loop** (neuer Pin/Param/Rewire/Prune) = beide gemeinsam, **Reader-Readback VOR Delete** ([[reference-mcp-material-connection-read-gap]]) · **Eye-Test** = Operator. `recompile` meldet Shader-Fehler NUR im Log → ggf. frischen Translate erzwingen (Cache-Bust).

## C — Operator-Beziehung

- **Decision-Level**: Operator ist non-coder. Keine Code-Snippets in Fragen, sondern High-Level-Trade-off-Form (A vs B + Folgen + Empfehlung).
- **Default-Sub-Decision**: Claude entscheidet eigenstaendig bei Implementierungs-Details, Tool-Auswahl, Werte/Defaults, Naming, Ordnerstruktur. Operator-Pflicht-Frage nur bei: Scope/Phase, Architektur-Pivot, Security/Trust-Boundary, Default-Wechsel im Workflow.
- **Asset-Modification-Protection + Scope-Discipline**: vor Trim/Reduce/Remove an muehevoll-erstellten Assets Operator-Pflicht-Frage. Claude bearbeitet nur Assets/Files die im aktuellen Operator-Auftrag explizit benannt sind — **Nebenher-Touch ist verboten**.

## D — Plan & Eye-Test

- **Eye-Test-Master**: Operator prüft visuell ab. Bei > 2-3 Tool-Calls kurzer Plan vorab, danach Stopp mit `→ Eye-Test-Punkt`. (Creative-Mode „spiel rum" = vagere Plans OK.)
- **Self-Verify-First**: Claude verifiziert selbst so weit möglich (Build grün, Logs, Engine-Trace, `CaptureEditorImage`) und schließt die Aufgabe damit ab — der Operator-Eye-Test ist Ästhetik/Abnahme, **kein Blocker für Fortschritt**. Aus reinem Static-Read von Code nie „funktioniert" behaupten ([[feedback-static-read-isnt-runtime-verify]]): Trace/Image statt Behauptung.

## E — Antwort-Disziplin

- **Bias-to-Action**: konkrete Aussagen, kein Effort-Konservatismus, keine reflexartigen Caveats. Polish/Nice-to-Haves dürfen inline mit rein — nicht reflexartig defern.

## F — UE-Spezifika

- **UE-API-Drift-Lookup**: Trainings-Wissen ueber UE-APIs ist nicht vertrauenswuerdig (Drift zwischen 5.x). 3-Quellen-Lookup Prio: lokale Engine-Headers (`C:\development\Epic Games\UE_5.8\Engine\`) > Epic-Docs > Foren. Bei Unsicherheit Verify-Subagent.
- **Authoring-Trial-First**: vor Tool-Eigenbau (Erweiterung von Epic-Tools oder eigenes Toolset) erst echter Authoring-Trial mit Operator am Eye-Test. Real-Use-Gaps statt Hypothesen.

## G — Memory-Layer

- **Memory-Pointer**: Folder `~/.claude/projects/C--Claude_Projects-UE-claude/memory/` (auto-loaded). `reference_*` = UE-Wissen (wertvoll, behalten), `feedback_*` = Arbeitsweise, `project_*` = laufender Stand. Isoliert von rbga-smart-core.
- **Lernen & Recall**: rekurrente Operator-Patterns proaktiv speichern; bei „wir hatten das mal so" erst Memory + git-log durchsuchen, dann handeln.

## H — Subagents

- **Subagents wo sie tragen**: Verify bei echter Uncertainty, Explore bei breiter Suche, parallele Jobs im Background frontloaden statt sequentiell.
- **Pre-Spawn-Permission-Audit**: vor Background-Subagent `settings.json` `allow`-Liste prüfen (Subagent-Layer kann enger sein als Top-Level).

## I — Decision-Tracking

- **`OPEN_DECISIONS.md` = reiner Vorwärts-Backlog**: nur offene Items (`[PENDING]` / `[VERIFY-OPEN]`). **Erledigtes lebt im git-Commit, nicht als Essay in der Datei** — gitlog ist das Archiv. Claude pflegt proaktiv: bei Major-Decision (Architektur/Scope/Default) offenes Item rein bzw. erledigtes raus, mit Commit.

## J — Build, Commit & Save

- **Auto-Build nach Plugin-Source-Edits**: nach Edits an `Plugins/<Plugin>/Source/**` ruft Claude eigenmächtig **`bridge_rebuild`** auf (save→Editor-zu→`Build.bat`→auf→reinit→Toolsets, MCP-Session überlebt; [[project-mcp-bridge-worker]]). **Pre-Save `save_assets([])` direkt davor**, sonst hängt der Build am Save-Modal. Fallback ohne Broker: `Build.bat` manuell ([[reference-oscbridge-build-commands]]). Memory-/Konventions-/Doku-Edits → KEIN Build.
- **Milestone-Commit eigenmächtig** bei abgeschlossenen Convention-/Memory-/Skill-Updates. Keine Mini-Commits.

## K — Permissions & Whitelist

Volldetail (R/W-Pfad-Tabelle, Bash-Whitelist, Security-Disziplin): **`docs/permissions.md`** — bei Permission-/Pfad-/Security-Frage dort nachschlagen. Always-on-Guardrails:

- **`Content/` (`.uasset`/`.umap`) NIE direkt** — nur via MCP-Tools. `Source/`/`Config/`-Write + `git push` = Op-Pflicht-Frage. Andere Repos/Projekte, `.plastic/`, `.git/` = ✗. Engine-Headers nur Read.
- **`rm`/`del`/`git reset --hard` NIE ohne Op-OK**; `pip install`/Package-Install NIE; `cm`/`plastic` macht der Operator selbst. UnrealEditor-Launch/Stop: Claude darf selbst, save-dirty-first ([[feedback-editor-lifecycle-permission]]).
- **Security (Defender/Firewall/Permission/Network/Credentials) = IMMER Op-Signoff**; Permission-Bypass/Validation-Skip explizit flaggen (Code-Comment + Antwort-Block).
- **UE-Projekt = Plastic SCM, nicht git**; `Saved/` transient → durable Notizen ins UE-claude-git. Memory isoliert (eigener Slug), kein Cross-Project-Pfad-Hardcoding.

---

## Repo-Layout

```
C:\Claude_Projects\UE-claude\
├── CLAUDE.md           # diese Datei
├── OPEN_DECISIONS.md   # Vorwärts-Backlog (offen; erledigt → git log)
├── docs/               # on-demand (z.B. material-roadmap, anti-patterns)
└── skills/             # on-demand Workflow-Trigger
```

Memory: `~/.claude/projects/C--Claude_Projects-UE-claude/memory/MEMORY.md` (auto-loaded vom Harness).

## Quick-Pointers

- **Material-Authoring**: Param-Pattern statt Constants; HLSL = versionierte Datei + Deploy-Pipe (Code-Loop, [[reference-shader-code-loop-pipe]]), Eye-Test am Schluss
- **Neue Domain**: `load_toolset`, dann callen — keine Discovery-Rituale
- **„Wir hatten das mal..."**: erst Memory + git-log durchsuchen, dann handeln
