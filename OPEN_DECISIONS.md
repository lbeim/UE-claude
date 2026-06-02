# OPEN DECISIONS — UE-Claude

Vorwärts-Backlog: **nur offene Items**. Erledigtes lebt im git log (`git log --oneline`), nicht hier. Status: `[PENDING]` / `[VERIFY-OPEN]`.

---

## Operator-Pending

- **D-1 Pulse-Trial-Gaps** `[VERIFY-OPEN]` — Material-Authoring-Trial mit Epic MaterialTools fahren, dann die 5 Hard-Gaps + 3 Schnittstellen-Findings (Pulse-Trial 2026-05-12) gegen den aktuellen Epic-Plugin-Stand re-evaluieren, bevor sie als Memory/Doc landen. Kriterium: allgemeine Relevanz UND echte Friction. Quelle: `rbga-smart-core` Memory `project_material_authoring_vision`.
- **D-3 Inline-STOP** `[PENDING]` — Soft-STOP ("STOP/halt/warte" im Text) zusätzlich zu Ctrl+C aktivieren? Aktuell deaktiviert. Mit dem CLAUDE.md-Abbau ersatzlos schließbar, falls kein Bedarf.
- **D-12 OSCBridge Editor-Mode-Cycle-Noise** `[PENDING]` — Receiver durchläuft Stop/Destroy/Start-Cycles bei Map-Load + `SE_EADDRINUSE` nach PIE-End. Funktional ok (Stream läuft), nur Log-Noise. Fix wenn's nervt: World-Type-Filter strenger / `SE_EADDRINUSE`-Retry mit Backoff / `OnConstruction`-Re-Entry-Guard.

## Verify-Open — Code grün, Operator-Eye-Test offen

- **D-13 PulseKit-Tuning** (`f2ef18b` + 2026-06-02-Rebuild, grün, noch nicht committed/eye-getestet) `[VERIFY-OPEN]` — Offen: (a) Effekt **viel dezenter** (Wand ~20 m, darf nicht überwältigen); (b) **Spline über die GANZE Wand** (X −650…+650, Z 100…605; aktuell links-mittig); (c) **significance scharf** (CS erzwingt noch `bAutoFirePreview=true`); (d) später Licht + Muster. Detail [[project-pulsekit-radial-pulse]]. (Shader-Teil → D-16.)
- **D-14 Bridge-Worker Adoption** (`d5f92e6`) — `start-bridge.cmd` dauerhaft laufen lassen + Claude einmal neu → Robustheit dauerhaft live. Optional: Boot-Autostart, SSE-Live-Progress.
- **D-16 Shader-Refactor + Graph-Reader** (2026-06-02, grün+gespeichert) `[VERIFY-OPEN]` — M_RadialPulse Custom-Node = 3 Outputs (Emissive/WPO/BaseColor, WPO entkoppelt), 12 tote Nodes raus (69→57); eigenes Graph-Reader-Toolset gebaut [[reference-mcp-material-connection-read-gap]]. Offen: BaseColor verdrahten · Helligkeits-Boden auf Emissive · Rotations-Regler · Param-Gruppen. Detail [[project-pulsekit-radial-pulse]], [[feedback-direct-fast-shader-iteration]]. (Color/Atlas = Operator-Domäne.)
- **D-15 OSC-Gradient-Atlas** (`be51989` + 2026-06-02 Persistenz/Naming) `[VERIFY-OPEN]` — §A+§B grün; Modell B + self-healing Persistenz (überlebt Crash, „auto-repainted 12 rows" verifiziert) + 12 Demo-MIs benannt (`MI_Atlas_<col>_Solid|Grad`). Offen: C++-Button „Generate State Instances"; §C Niagara `DataInterfaceTexture` / MaterialFunction + Eye-Test. Detail [[reference-oscbridge-atlas-persistence]]. (C++/Renames noch nicht committed.)

## Backlog — unscheduled

- OSCBridge: Session Record/Replay, Data-Asset-basierte Binding-Tables, zeit-korrektes (DeltaTime-)Smoothing. (Reste aus D-6/D-7.)

---

*Erledigte Decisions → git log. Anker: D-0 Epic-MCP-Pivot (`6cf84c5`) · D-5 OSCBridge-Plugin (`d1e0444`) · D-6 Phase-2 (`22c7b63`) · D-7 Phase-3 (`de0283c`) · D-8 Hz/Jitter (`2f42fc5`) · D-9/D-10/D-11 Editor-Mode+Tags grün (`7690810`) · D-13 (`f2ef18b`) · D-14 (`d5f92e6`) · D-15 (`be51989`).*
