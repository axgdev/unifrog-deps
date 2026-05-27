# UniFrog Dependencies

This repository is intentionally small.

The `deps/<name>/<base>` branches are sparse snapshot branches for UniFrog
builds. They contain only the files needed by the default build, plus any small
UniFrog integration changes that belong with that dependency snapshot. They are
not full upstream mirrors and they should not carry upstream history by default.

Developers who want a full tree for a dependency should use the upstream URL and
ref recorded in `MANIFEST.tsv` or in UniFrog's `Makefile` and
`cores/manifest.mk`:

```sh
make setup DEP_SOURCE=upstream DEP_CHECKOUT=full DEP_DEPTH=0
```

Normal UniFrog builds can fetch the sparse snapshots directly:

```sh
make setup UNIFROG_DEPS_REPO_URL=git@github.com:axgdev/unifrog-deps.git
make setup-cores CORE_IDS="gpsp gambatte" \
  UNIFROG_DEPS_REPO_URL=git@github.com:axgdev/unifrog-deps.git
```

Branch policy:

- `main` is only this index and policy branch.
- `deps/*` branches are root commits containing sparse source snapshots.
- Do not force-push a published `deps/*` branch.
- Import a new `deps/<name>/<base>` branch when the upstream base or UniFrog
  integration changes.
- Keep upstream provenance in UniFrog's manifests rather than adding
  `upstream/*` mirror branches here.

