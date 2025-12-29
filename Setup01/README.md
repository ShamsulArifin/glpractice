# glpractice

A small OpenGL practice project that demonstrates creating a window with GLFW, initializing GLEW, uploading a vertex buffer, and rendering a simple triangle. The repository includes a Visual Studio solution and a minimal example located in `OpenGL/src/Application.cpp`.

## Repository layout

- OpenGL/  
  - OpenGL.sln (solution)
  - OpenGL.vcxproj, OpenGL.vcxproj.filters
  - src/
    - Application.cpp — minimal example that creates a window and draws a triangle
- Dependencies/ — intended location for third-party binaries or libraries (not populated)

## What this example does

- Initializes GLFW for window/context creation.
- Initializes GLEW to access OpenGL functions.
- Creates a 640×480 window and prints the OpenGL version to stdout.
- Uploads vertex data (positions) to a GL_ARRAY_BUFFER.
- Configures a vertex attribute and draws a triangle using `glDrawArrays`.

This is purposely minimal and intended for learning basic buffer uploading and the render loop.

## Prerequisites

Windows (Visual Studio)
- Visual Studio 2017/2019/2022 (or equivalent MSVC toolchain).
- GLFW and GLEW libraries (headers and .lib). You can install these by a package manager (vcpkg/choco) or place them in the `Dependencies` folder and update project include/lib paths.

Linux / macOS
- Build tools: gcc / clang, make
- Development packages: GLFW and GLEW (for example, `libglfw3-dev`, `libglew-dev` on Debian/Ubuntu)
- X11 / GL development packages on Linux (if applicable)

Optional (recommended)
- vcpkg (Windows) — simplifies installing and integrating GLFW/GLEW.
- CMake — if you add a CMakeLists.txt later to support cross-platform builds.

## Build and run

### Windows (Visual Studio — recommended)
1. Open `OpenGL/OpenGL.sln` with Visual Studio.
2. Ensure the project is configured to find GLFW and GLEW header files and libraries:
   - Project → Properties → C/C++ → Additional Include Directories
   - Project → Properties → Linker → Additional Library Directories
   - Linker → Input → Additional Dependencies: add `glfw3.lib`, `glew32.lib`, and `opengl32.lib` as appropriate.
3. Build the solution (Debug/Release).
4. Run the resulting executable from Visual Studio or from the build output directory.

If you use vcpkg:
- Install packages: `vcpkg install glfw3 glew`
- Integrate with Visual Studio: `vcpkg integrate install` and ensure the project uses the vcpkg toolchain.

### Linux (example using g++)
1. Install dependencies (Debian/Ubuntu example):
   sudo apt update
   sudo apt install build-essential libglfw3-dev libglew-dev libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev libglu1-mesa-dev
2. From repository root, compile:
   g++ OpenGL/src/Application.cpp -o gl_example -lglfw -lGLEW -lGL -ldl -pthread
   (Depending on your system you may not need `-ldl` or `-pthread` flags.)
3. Run:
   ./gl_example

Note: The compile line is a minimal example and may need adjustments for your environment (include/library paths) if the libraries are not in standard locations.

## Common issues and troubleshooting

- "glewInit() failed" or unresolved OpenGL functions:
  - Ensure you call `glewInit()` after creating a valid OpenGL context (`glfwMakeContextCurrent(window)`).
  - Verify that the GLEW libraries and headers match your platform (static vs dynamic linking).
- Linker errors for `glfw`/`glew`:
  - Confirm the project links to the correct `.lib`/`.a` files and the library search paths are set.
- Window fails to create:
  - Check GLFW initialization return value and console messages. Ensure compatible GPU drivers are installed.

## Suggested next steps / improvements

- Add proper shader loading (vertex/fragment shader) instead of fixed-function attributes.
- Use Vertex Array Objects (VAOs) to encapsulate vertex attribute state.
- Add error checking and debug output (GLFW error callback, glGetError checks).
- Add a CMakeLists.txt to simplify cross-platform building.
- Add input handling and interaction examples (keyboard/mouse).
- Provide prebuilt binaries or include a small script to fetch and place dependencies into `Dependencies/`.

## Contributing

- If you have improvements, open an issue or submit a pull request.
- For build-related contributions, prefer adding CMake support and documented instructions so others can build the project on multiple platforms.


## A note on safety and environment

- This repository contains a minimal OpenGL example used for learning. When integrating third-party binaries, ensure the sources are trusted.
- If you plan to run or distribute binaries, ensure they are built against compatible system libraries and toolchains.
