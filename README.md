# glpractice

A collection of small projects, experiments and exercises for learning and practicing graphics programming (OpenGL / shader programming / related topics). This repository contains example code, demos, and notes intended to help iterate on rendering techniques and helper utilities.

> If something in this README does not match the repository contents, please open an issue or submit a pull request to update the details.

## Table of contents

- [About](#about)
- [Repository layout](#repository-layout)
- [Prerequisites](#prerequisites)
- [Building and running](#building-and-running)
- [Common patterns and tips](#common-patterns-and-tips)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## About

This repo is intended as a personal playground for graphics programming. It is organized as a set of independent exercises/demos — each folder is (or should be) a standalone example showing a specific concept such as creating a window and GL context, loading shaders, rendering basic geometry, texturing, lighting, or other techniques.

Use the examples to reproduce results, experiment with parameters, and learn incremental steps in graphics development.

## Repository layout

Top-level folders usually include:

- docs/ — notes, references, or write-ups for experiments (if present)
- examples/ or projects/ — individual demos and exercises (each subfolder is a project)
- libs/ or third_party/ — third-party libraries bundled for convenience (if present)
- shaders/ — shared shader code that multiple examples may include
- tools/ — utility scripts for building, generating assets, or running tests

Note: Directory names may vary. Inspect the repository root to see current folders and update this section accordingly.

## Prerequisites

Typical requirements for running the examples (adjust according to each example's README):

- Git
- A C/C++ toolchain (gcc/clang or MSVC) for native examples
- CMake (recommended) or the build system used by a specific example
- OpenGL development headers and libraries, plus a window/context library such as GLFW or SDL
- GL loader (GLAD/GL3W) or GLEW if used by examples
- For examples written in other languages: the corresponding runtime (Python, JavaScript/Node, etc.)

Install the relevant packages for your platform (package manager instructions vary by OS). Check the per-example README files for exact dependencies.

## Building and running

General workflow (native/CMake examples):

1. Clone the repository:
   ```
   git clone https://github.com/ShamsulArifin/glpractice.git
   cd glpractice
   ```

2. Create a build directory and run CMake:
   ```
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```

3. Run an example binary:
   ```
   ./examples/some_example    # path depends on repo layout and platform
   ```

If an example uses a different build system or scripting language, follow the README inside that example's directory for exact commands.

## Common patterns and tips

- Look for a per-example README — that file usually contains exact build commands and dependency instructions.
- When adding new examples:
  - Keep them self-contained (document dependencies and build steps).
  - Prefer CMake targets (or the project's chosen build system) so examples can be built consistently.
- Keep shader files under a `shaders/` directory or next to the example that uses them.
- Use relative paths for loading assets so examples work when run from the build directory.

## Contributing

Contributions are welcome. Suggested workflow:

1. Fork the repository and create a branch for your change.
2. Add or update an example and include a README for the example describing:
   - purpose of the example
   - dependencies
   - build and run instructions
3. Run and verify your example on at least one platform, and ensure it does not break existing examples.
4. Open a pull request with a clear description of the changes.

If you plan to add third-party code, prefer adding as a submodule or referencing external dependencies rather than copying large vendor files into the repository.

## License

This repository does not specify a license. If you want to reuse or contribute code, please request the repository owner to add a license. To apply a license yourself, add a LICENSE file to the repository root and reference it here.

## Contact

Repository owner: ShamsulArifin

If you find issues or have suggestions, please open an issue in the repository. If you intend to make larger changes, please open a discussion or draft a pull request first so we can coordinate.
