# About

Screenshot

![Alt text](https://www.dropbox.com/s/c84c16b7iroj3jd/screenshot.png)

This project was created from my SDL2 Template repository, using pieces from my personal Game Engine.
It would not take much to make this project work for:
* iOS
* tvOS
* Android
* Windows
* Emscripten


There are the following targets:
* SDLSkeleton - Windows application.
* clang-format - If you do not like how I formatted my code, edit: `.clang-format` and run this.
* SDLSkeleton-documentation - generate documentation using doxygen
* SDLSkeleton-static - create a static library of the source.
* SDLSkeleton-test-framework - test the framework library using GoogleTest and GoogleMock
* SDLSkeleton-test-static - test the static library using GoogleTest and GoogleMock
* SDLSkeletonFramework  - create a framework of the source.

# Repositoy

Please note that the project has submodules.
`git clone --recursive git@github.com:njligames/DSS_source.git`

# Creating Project

From the root directory, run: `./macOS` and then open: `open .build_macOS/SDLSkeleton.xcodeproj/`

# Running the Project

Run the SDLSkeleton target.

The project was run with these settings:
```
GL_VERSION = 2.1 ATI-3.2.24
GL_VENDOR = ATI Technologies Inc.
GL_RENDERER = AMD Radeon Pro 560 OpenGL Engine
```

# Extra Features
*  OpenGL instancing
*  Multithreaded Curl
*  Lighting
*  Fog
*  OBJ file loader
*  Rim Lighting
*  Loading Screen.
*  Dynamic URL.

