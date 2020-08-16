# Revery Minimal Template

This is a minimal Revery application to get you started.

## Prerequisites

See the [requirements for building Revery](https://github.com/revery-ui/revery/wiki/Building-&-Installing)

## Getting started

```
# Clone the repository
git clone https://github.com/revery-ui/revery-quick-start

# Go into the repository
cd revery-quick-start

# Install dependencies
esy install

# Build dependencies
esy build
```

> **NOTE:** The first build will take a while - building the OCaml compiler and dependencies takes time! Subsequent builds, though, should be very fast.

Once built, the application binary will be in the `_build/install/default/bin` - you can run it like:

- `_build/install/default/bin/App`

or using esy with the script specified in [package.json](package.json#L8):

- `esy start`

## What are all these files?

The most important files are:

- [`src/App.re`](./src/App.re) - This is the core application code, responsible for **creating a window** and **rendering**.

A Revery application also needs the following files:

- [`package.json`](package.json) - [esy configuration](https://esy.sh/docs/en/configuration.html) - lists the Reason/OCaml dependencies.
- `dune` / `dune-project` - build configuration files used by [Dune](https://dune.readthedocs.io/en/latest/).
- `.opam` - metadata used by the build system.

## Releasing

To create packages for distribution, follow these steps:

- `npm install -g revery-packager`

From the `revery-quick-start` folder, run:

- `revery-packager`

Once complete, there will be application packages available in the `_release` folder.

## Resources

- Check out the [Reason-documentation](https://reasonml.org) to learn more about Reason
- Visit the Reason [Discord-channel](https://discordapp.com/invite/reasonml) and say hi!

## License

[MIT License](LICENSE)
