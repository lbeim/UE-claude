# Permissions & Whitelist (Volldetail)

On-demand-Referenz zu CLAUDE.md §K. Bei Permission-/Pfad-/Security-Frage hier nachschlagen; die kompakten Always-On-Guardrails stehen in `CLAUDE.md`.

## R/W per Pfad

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

UE-Projekt-Pfad: `C:\development\Projects\MCP\` (Single-Level `MCP.uproject`, Content/BP-Projekt ohne `Source/`; **via Plastic SCM / Gluon versioniert, nicht git** — `Saved/` ist transient/ignored, durable Notizen daraus ins UE-claude-git ziehen; Decided 2026-05-13).

## Bash-Whitelist

- `git status / log / diff / add / commit` im UE-Claude-Repo: auto-OK
- `git push`: Op-Pflicht-Frage (oder gar nicht falls Repo private)
- `cm` / `plastic`: gar nicht (Operator handhabt selbst)
- `rm` / `del` / `git reset --hard`: NIE ohne Op-OK
- `pip install` / Package-Install: NIE
- UnrealEditor-Launch/Stop: **Worker/Claude darf selbst** (via `bridge_rebuild` bzw. `Tools\mcp-bridge\lifecycle.py`), save-dirty-first — ersetzt alte „Operator startet selbst"-Notiz ([[feedback-editor-lifecycle-permission]])

## Security-Disziplin

- **Security-Changes Operator-Signoff**: Defender/Firewall/Permission/Network-Exposure/Credentials — IMMER Op-Pflicht-Frage.
- **Security-Workaround-Flagging-Pflicht**: bei Permission-Bypass/Validation-Skip/Trust-Boundary-Erweiterung explizit flaggen (Code-Comment + Antwort-Block). Claude darf den Workaround, MUSS aber transparent machen.
- **Cross-Project-Hygiene**: UE-Claude-Memory isoliert (eigener Slug), kein Pfad-Hardcoding zwischen Projekten, kein Auto-Edit auf andere Repos.
