# Orphan-Asset-Detection (Native-Approach)

Best-Practice fuer "finde Assets in Folder X, die NICHT von Level Y referenziert werden".

## Anti-Patterns (NICHT machen)

### 1. Per-Actor-Loop ueber Level-Actors

```python
for actor in find_actors(class=StaticMeshActor):
    sm = get_properties(actor.smc, ["staticMesh"])
    referenced.add(sm)
```

**Warum schlecht**: 3000+ Actors x 1+ tool-call = 3000+ MCP-Roundtrips. Crash-Risiko bei groesseren Mengen, Editor-Hang, Time-Cost. Bestaetigt durch Crash 2026-05-13.

### 2. Per-Asset-Delete-Loop

```python
for sm in all_sms:
    if not get_referencers(sm):
        delete(sm)  # <-- jedes Delete triggert AssetRegistry-Update + File-I/O + SCM-Hook
```

**Warum schlecht**: Auch wenn MCP-Roundtrips gebatcht sind (eine `execute_tool_script` ruft alle Deletes sequenziell), blockiert jeder Delete UE's Main-Thread fuer Asset-Registry-Update + File-I/O + ggf. Plastic-SCM-Hook. Bei 700+ Orphans freezed der Editor (Halb-Dead-State, nicht clickbar). Bestaetigt durch Crash 2026-05-13 zweite Iteration.

**Heuristik**: > ~50 Deletes in einer Script-Sequenz vermeiden. Stattdessen Chunks von 25-50 mit Operator-Eye-Test dazwischen, ODER native UI nutzen.

## Native-Approach (AssetRegistry)

AssetRegistry liest in-memory Index der `.uasset`-Header. Package-Ebene, nicht Instance-Ebene. Sekunden statt Minuten/Crash.

```python
import json

def safe_call(toolset, tool, args):
    r, e = execute_tool(toolset, tool, json.dumps(args))
    return json.loads(r)["returnValue"] if not e else None

def run():
    level_pkg = "/Game/LED_Wall"
    folder = "/Game/Geometry/"
    sm_class = {"refPath": "/Script/Engine.StaticMesh"}

    # 1. Transitive Dependencies vom Level (rekursiv durch Dep-Tree)
    referenced = set()
    stack = [level_pkg]
    while stack:
        p = stack.pop()
        if p in referenced: continue
        referenced.add(p)
        deps = safe_call(
            "toolset_registry.toolsets.core.asset.AssetTools",
            "get_dependencies", {"asset_path": p}) or []
        for d in deps:
            path = d.get("refPath") if isinstance(d, dict) else d
            if path: stack.append(path)

    # 2. Alle SMs im Folder
    all_sms = safe_call(
        "toolset_registry.toolsets.core.asset.AssetTools",
        "find_assets",
        {"folder_path": folder, "asset_type": sm_class,
         "name": "", "recursive": True}) or []

    # 3. Diff
    def norm(p):
        if "." in p:
            head, _, tail = p.partition(".")
            if head.endswith("/" + tail): return head
        return p

    referenced_norm = {norm(p) for p in referenced}
    orphans = [(x.get("refPath") if isinstance(x, dict) else x)
               for x in all_sms]
    orphans = [p for p in orphans if norm(p) not in referenced_norm]

    return {"orphans": orphans, "count": len(orphans)}
```

## World-Partition-Hinweis

Falls Level World-Partition ist: External Actors (`.../_ExternalActors/...`) und External Objects (`.../_ExternalObjects/...`) muessen mit-traversiert werden. Rekursiver `get_dependencies`-Walk (siehe oben) macht das automatisch wenn die Externals als Dependencies des Level-Packages registriert sind. Falls nicht: ExternalActors-Folder explizit in `stack` einfuegen.

## Selection in Content Browser

Nach Diff: `EditorAppToolset.SelectAssets({"assetPaths": orphans})`. Argument-Groesse: bei 3000+ Pfaden im Plain-JSON ~250kB - sollte gehen, ist aber Crash-Risiko-Verdaechtig. Bei Sorge: chunken (500er Batches) oder Collection erstellen statt selektieren.

## Verwandte Workflows

- **Asset Audit Window** (`Tools -> Audit Assets`): zeigt Asset-Liste mit Total-Usage/Reference-Count. Filter auf Refs=0 + Multi-Select + Delete in einem Rutsch. **Bevorzugter Native-Workflow** wenn UI-OK.
- **Reference Viewer "Make Collection With Referencers"**: semi-nativ UI-Workflow auf Level, dann manuell invertieren. Praktisch fuer < 100 Assets.
- **ProjectCleaner Plugin** (Marketplace, ashe23): UI-Variante, deckt mehr als nur Level-Diff ab.

## Empfehlung Decision-Matrix

| Anzahl Orphans | Best-Approach |
|---|---|
| < 25 | Script in einem Rutsch (read + delete) |
| 25-100 | Script-Chunks oder Asset Audit UI |
| 100-1000 | **Asset Audit UI** (multi-select + delete) ODER Script-Chunks zu je 25-50 |
| > 1000 | Asset Audit UI, ProjectCleaner-Plugin, oder Migration-Strategie |

**Plastic-SCM-Hinweis**: Wenn das Projekt Plastic-SCM (`cm`) nutzt, triggern Deletes SCM-Operations, die Main-Thread weiter blockieren. Plastic-Status pre-Check + Operator-Sign-off vor Bulk-Delete.

## Quellen

- Recherche-Subagent 2026-05-13 (verified)
- [Reference Viewer Docs](https://dev.epicgames.com/documentation/en-us/unreal-engine/reference-viewer-in-unreal-engine)
- [AssetRegistry Python API](https://dev.epicgames.com/documentation/en-us/unreal-engine/python-api/class/AssetRegistry)
