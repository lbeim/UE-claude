# UE-Claude — Konventionen

Companion-Repo zum UE-Projekt. Beheimatet Konventionen, Memory-Verweis, Skills, Decision-Tracker. Kein Code, kein eigenes Plugin — UE-Tools kommen aus Epic's `ModelContextProtocol`-Plugin (UE 5.8 Preview).

## North Star

Material-Authoring + Workflow-Agenten via Epic-Toolsets. Operator ist Eye-Test-Master fuer jeden Output. Claude agiert eigenstaendig im Inkrementell-Compose-Modus — max **2-3 Tool-Operationen pro Sequenz**, dann Pause-Marker.

---

## B — MCP-Toolset-Workflow

- **Discovery on-demand**: bei in-Session-noch-nicht-geladenem Toolset `load_toolset` rufen, dann callen. `list_toolsets` / `describe_toolset` nur bei echter Unsicherheit.
- **Programmatic-Pre-Flight**: vor erstem `execute_tool_script` einmal pro Session `programmatic.get_execution_environment` aufrufen, Instructions lesen.
- **Schema-Pre-Look**: bei Multi-Tool-Scripts vorab Output-Schemas der genutzten Tools holen.
- **Sandbox-Awareness**: erlaubte Module nur `json` / `math` / `datetime` / `copy` / `re`, `open()` read-only auf Projekt-Pfad.
- **Native-First vor Bulk-Loops**: vor `execute_tool_script` mit Per-Actor-/Per-Asset-Loop pruefen ob AssetRegistry-API (`get_dependencies`/`get_referencers`), Reference Viewer, Asset Audit oder Console-Cmd das Ergebnis direkt liefert. Editor-Bulk-Calls = Crash-Risiko + Zeitkosten. Bei Unsicherheit Verify-Subagent statt Editor-Experiment.

## C — Operator-Beziehung

- **Decision-Level**: Operator ist non-coder. Keine Code-Snippets in Fragen, sondern High-Level-Trade-off-Form (A vs B + Folgen + Empfehlung).
- **Default-Sub-Decision**: Claude entscheidet eigenstaendig bei Implementierungs-Details, Tool-Auswahl, Werte/Defaults, Naming, Ordnerstruktur. Operator-Pflicht-Frage nur bei: Scope/Phase, Architektur-Pivot, Security/Trust-Boundary, Default-Wechsel im Workflow.
- **Asset-Modification-Protection + Scope-Discipline**: vor Trim/Reduce/Remove an muehevoll-erstellten Assets Operator-Pflicht-Frage. Claude bearbeitet nur Assets/Files die im aktuellen Operator-Auftrag explizit benannt sind — **Nebenher-Touch ist verboten**.

*(Optional Inline-STOP: wenn Operator "STOP/halt/warte" tippt → sofort kein weiterer Output. Redundant zu Ctrl+C, aktuell deaktiviert siehe OPEN_DECISIONS D-3.)*

## D — Plan & Eye-Test

- **Eye-Test-Master**: Operator prueft IMMER visuell. Tool-Output ist nie selbst-validierend.
- **Plan-First bei Multi-Step**: bei Aufgaben > 1 Tool-Call vorab kurzer Plan-Text (3-5 Bullets) was Claude tun wird, BEVOR Tool-Burst.
- **Pause-Marker**: nach Tool-Sequenz konsistent `→ Eye-Test-Punkt` schreiben. Operator weiss sofort: Burst done, schau ins UE.
- **Plan-Detail-Tiefe**: Standard = konkret-handlungsbezogen ("M_X erstellen, Constant3Vector als BaseColor, connect, recompile"). **Creative-Mode-Ausnahme**: wenn Operator "spiel rum"/"schau mal was geht" sagt, sind vagere Plans OK.

## E — Antwort-Disziplin

- **Pre-Read-Cache-Check + Static-Source-Once-Read**: vor Read/Grep/Glob pruefen ob Inhalt schon im Context. Konventions-Docs (CLAUDE.md, MEMORY.md, einzelne Memory-Files, Plugin-Header, Spec-Docs) werden **maximal EINMAL pro Session** gelesen. Default-Annahme bei Unsicherheit: schon gelesen.
- **State-Tracking-Block am Antwort-Ende bei Brainstorm**: bei Discussion-Antworten kurzer Block `Signed-off / Open / Active`. Trivial-Antworten ohne Block.
- **Bias-to-Action**: kein Effort-Konservatismus, keine reflexartigen Caveats. Konkrete Aussagen.
- **Nice-to-Haves opportunistisch in Build-Phase mit**: Polish darf inline mit eingebaut werden, nicht reflexartig defern. TECH_DEBT.md nur fuer echte Cleanup-Schulden.

## F — UE-Spezifika

- **UE-API-Drift-Lookup**: Trainings-Wissen ueber UE-APIs ist nicht vertrauenswuerdig (Drift zwischen 5.x). 3-Quellen-Lookup Prio: lokale Engine-Headers (`C:\development\Epic Games\UE_5.8\Engine\`) > Epic-Docs > Foren. Bei Unsicherheit Verify-Subagent.
- **Authoring-Trial-First**: vor Tool-Eigenbau (Erweiterung von Epic-Tools oder eigenes Toolset) erst echter Authoring-Trial mit Operator am Eye-Test. Real-Use-Gaps statt Hypothesen.

## G — Memory-Layer

- **Operator-Praeferenz-Learning**: Claude speichert rekurrente Operator-Patterns proaktiv als Memory ("Operator bevorzugt AskUserQuestion bei Discussions", "Pause-Marker-Phrase XYZ", "Plan-Detail-Default vs Creative-Mode"). Cross-Session lernen.
- **Pre-Save-Anti-Pattern-Check**: vor Memory-Save: echte Decision/Pattern (memorable) oder Beilaeufigkeit? Gegen etabliertes Pattern checken.
- **Past-Convention-Recall**: bei Phrasen wie "wir hatten das mal so" systematisch Memory + ggf. Repo-History durchsuchen, BEVOR raten.
- **Memory-Pointer**: Memory-Folder lebt unter `~/.claude/projects/<UE-Claude-Slug>/memory/MEMORY.md`. Isoliert von rbga-smart-core-Memory.
- **Memory-Hygiene**: bei MEMORY.md > 150 Zeilen oder > 50 Files Konsolidierung pruefen — obsolete archivieren, redundante zusammenfassen. Trigger-bedingt, nicht zwanghaft regelmaessig.

## H — Subagents

- **Verify-Subagent** bei substantieller Uncertainty (Decision oder Architektur) statt blinder Assertion. Nur bei echtem Bedarf, nicht reflexartig.
- **Explore-Subagent** bei breit-streuenden Code-Suchen statt N Grep-Calls im Hauptkontext.
- **Pre-Spawn-Permission-Audit**: vor Background-Subagent-Spawn `settings.json` `allow`-Liste pruefen (Subagent-Layer kann enger sein als Top-Level).
- **Frontload-Pattern**: parallele Research/Verify-Jobs gleichzeitig im Background spawnen, nicht sequentiell-deferred.

## I — Decision-Tracking

- **OPEN_DECISIONS.md** im Repo-Root als Live-Tracker. Claude pflegt proaktiv. Operator-Pending, Decided-Anker (mit Datum), Verify-Pending.
- **Status-Tags**: `[PENDING]` / `[DECIDED YYYY-MM-DD]` / `[VERIFY-OPEN]`. Decided wird nicht geloescht sondern bleibt als Anker.
- **Auto-Capture bei Operator-Major-Decision**: bei Architektur-/Scope-/Default-Decision schreibt Claude die als Decided-Block in OPEN_DECISIONS, ohne extra Save-Trigger.

## J — Build, Commit & Save

- **Auto-Build nach Plugin-Source-Edits**: nach jeder Edit-Runde an `Plugins/<Plugin>/Source/**` oder UE-Projekt-`Source/**` ruft Claude eigenmaechtig (keine Op-Frage) das MCP-Tool **`bridge_rebuild`** auf — der Bridge-Worker macht save→Editor-zu→`Build.bat`→Editor-auf→reinit→Toolsets nachladen, die MCP-Session ueberlebt ([[project-mcp-bridge-worker]], OPEN_DECISIONS D-14). Fallback ohne laufenden Broker: `Build.bat` manuell mit geschlossenem Editor ([[reference-oscbridge-build-commands]]). Bei reinen Memory-/Konventions-/Doku-Edits KEIN Build.
- **Milestone-Commit eigenmaechtig**: bei abgeschlossenen Convention-Updates / Memory-Audits / Skill-Vorlagen Commit ohne Operator-Trigger. Keine Mini-Commits pro Edit.
- **Commit-Message [semantic]**: Kurze Zusammenfassung + Kontext-Saetze + Anchor (z.B. `CLAUDE.md Sektion D done [convention]`).

## K — Permissions & Whitelist

### R/W per Pfad

| Pfad | Read | Write |
|---|---|---|
| `C:\Claude_Projects\UE-claude\` | ✓ | ✓ |
| `~/.claude/projects/<UE-Claude-Slug>/memory/` | ✓ | ✓ |
| UE-Projekt `Source/` | ✓ | Op-Pflicht-Frage |
| UE-Projekt `Content/` (`.uasset`/`.umap`) | ✗ | ✗ NIE direkt — nur via MCP-Tools |
| UE-Projekt `Config/` | ✓ | Op-Pflicht-Frage |
| UE-Projekt `.plastic/` / `.git/` | ✗ | ✗ |
| `C:\development\Epic Games\UE_5.8\Engine\` | ✓ | ✗ |
| Andere Projekte/Repos | ✗ | ✗ |

UE-Projekt-Pfad: `C:\development\Projects\MCP\` (Decided 2026-05-13, siehe OPEN_DECISIONS D-2).

### Bash-Whitelist

- `git status / log / diff / add / commit` im UE-Claude-Repo: auto-OK
- `git push`: Op-Pflicht-Frage (oder gar nicht falls Repo private)
- `cm` / `plastic`: gar nicht (Operator handhabt selbst)
- `rm` / `del` / `git reset --hard`: NIE ohne Op-OK
- `pip install` / Package-Install: NIE
- UnrealEditor-Launch/Stop: **Worker/Claude darf selbst** (via `bridge_rebuild` bzw. `Tools\mcp-bridge\lifecycle.py`), save-dirty-first — ersetzt alte „Operator startet selbst"-Notiz ([[feedback-editor-lifecycle-permission]])

### Security-Disziplin

- **Security-Changes Operator-Signoff**: Defender/Firewall/Permission/Network-Exposure/Credentials — IMMER Op-Pflicht-Frage.
- **Security-Workaround-Flagging-Pflicht**: bei Permission-Bypass/Validation-Skip/Trust-Boundary-Erweiterung explizit flaggen (Code-Comment + Antwort-Block). Claude darf den Workaround, MUSS aber transparent machen.
- **Cross-Project-Hygiene**: UE-Claude-Memory isoliert (eigener Slug), kein Pfad-Hardcoding zwischen Projekten, kein Auto-Edit auf andere Repos.

## L — Context-Window

- **Recall-Drop-Hinweis bei >300k absolute**: Anthropic-Benchmark zeigt Recall-Drop ab ~300k. Bei Erreichen: Awareness-Note "wir kommen in unscharfes Recall-Gebiet, neue Session waere sauberer". Kein Frage-Stop, nur Hinweis.

---

## Repo-Layout

```
C:\Claude_Projects\UE-claude\
├── CLAUDE.md           # diese Datei
├── OPEN_DECISIONS.md   # Live-Tracker
├── docs/               # on-demand (z.B. material-roadmap, anti-patterns)
└── skills/             # on-demand Workflow-Trigger
```

Memory: `~/.claude/projects/C--Claude_Projects-UE-claude/memory/MEMORY.md` (auto-loaded vom Harness).

## Quick-Pointers

- **Material-Authoring**: Plan-First, Param-Pattern bevorzugen (statt Constants), Eye-Test pro 2-3 Calls, Pause-Marker
- **Neue Domain**: `load_toolset` rufen, dann callen — keine Discovery-Rituale
- **Bulk / Iteration**: Programmatic-Toolset mit `get_execution_environment` Pre-Flight
- **Uncertainty**: Verify-Subagent statt Assertion
- **"Wir hatten das mal..."**: Memory + OPEN_DECISIONS durchsuchen, nicht raten
- **Mehr als 2-3 Tool-Calls**: HALT, Plan vorstellen
