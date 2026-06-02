# OPEN DECISIONS — UE-Claude

Vorwärts-Backlog: **nur offene Items**. Erledigtes lebt im git log (`git log --oneline`), nicht hier. Status: `[PENDING]` / `[VERIFY-OPEN]`.

---

## Operator-Pending

- **D-1 Pulse-Trial-Gaps** `[VERIFY-OPEN]` — Material-Authoring-Trial mit Epic MaterialTools fahren, dann die 5 Hard-Gaps + 3 Schnittstellen-Findings (Pulse-Trial 2026-05-12) gegen den aktuellen Epic-Plugin-Stand re-evaluieren, bevor sie als Memory/Doc landen. Kriterium: allgemeine Relevanz UND echte Friction. Quelle: `rbga-smart-core` Memory `project_material_authoring_vision`.
- **D-3 Inline-STOP** `[PENDING]` — Soft-STOP ("STOP/halt/warte" im Text) zusätzlich zu Ctrl+C aktivieren? Aktuell deaktiviert. Mit dem CLAUDE.md-Abbau ersatzlos schließbar, falls kein Bedarf.
- **D-12 OSCBridge Editor-Mode-Cycle-Noise** `[PENDING]` — Receiver durchläuft Stop/Destroy/Start-Cycles bei Map-Load + `SE_EADDRINUSE` nach PIE-End. Funktional ok (Stream läuft), nur Log-Noise. Fix wenn's nervt: World-Type-Filter strenger / `SE_EADDRINUSE`-Retry mit Backoff / `OnConstruction`-Re-Entry-Guard.

## Verify-Open — Code grün, Operator-Eye-Test offen

- **D-13 PulseKit Radial-Puls** (`f2ef18b`) — offen: (a) BASS-Eye-Test im Play/nDisplay, (b) Multi-Mesh-Preview + `BP_PulseField`-`TargetSurfaces`-Liste in LED_Ndisplay neu füllen, (c) Default-Spline über die Wand, (d) low/mid/high + weitere Report-Kanäle anschließen ([[reference-osc-mod-channel-map]], `docs/pulsekit-channel-map.md`).
- **D-14 Bridge-Worker Adoption** (`d5f92e6`) — `start-bridge.cmd` dauerhaft laufen lassen + Claude einmal neu → Robustheit dauerhaft live. Optional: Boot-Autostart, SSE-Live-Progress.
- **D-15 OSC-Gradient-Atlas** (`be51989`) — §A+§B grün; offen §C: Dashboard fortlaufende stateIds + RT auf 256×N (`AtlasHeight`=N) / Niagara `DataInterfaceTexture` auf GPU-Emitter / saubere MaterialFunction aus `OSCGradientAtlasSample` / Material+Niagara-Eye-Test.

## Backlog — unscheduled

- OSCBridge: Session Record/Replay, Data-Asset-basierte Binding-Tables, zeit-korrektes (DeltaTime-)Smoothing. (Reste aus D-6/D-7.)

---

*Erledigte Decisions → git log. Anker: D-0 Epic-MCP-Pivot (`6cf84c5`) · D-5 OSCBridge-Plugin (`d1e0444`) · D-6 Phase-2 (`22c7b63`) · D-7 Phase-3 (`de0283c`) · D-8 Hz/Jitter (`2f42fc5`) · D-9/D-10/D-11 Editor-Mode+Tags grün (`7690810`) · D-13 (`f2ef18b`) · D-14 (`d5f92e6`) · D-15 (`be51989`).*
