# CMakeAppTemplate
## Table of Contents
- [What is this?](#what-is-this?)
- [Prerequisites](#prerequisites)
- [Dependencies](#dependencies)
- [Clone](#clone)
- [Updating if the submodules have changed](#updating-if-the-submodules-have-changed)
- [Configure and Build](#configure-and-build)
- [Getting Started](#getting-started)

## What is this?
This is an app template to setup using a graphics backend. It ships with ImGui out of the box and (will) allow you 
to switch backend depending on your needs. Currently it only supports OpenGL but this will give more flexibility 
compared to my old app framework. It will enable you to configure your project with things that you might need 
without the hassle of setting it all up, e.g. a renderer, test projects, logging etc.

## Prerequisites
- CMake

## Dependencies
These dependencies are imported in via git submodules to make it easier to integrate, without having to have package 
management setup. The dependent libraries used are:
- spdlog (logging)
- glm (math)
- glad (OpenGL graphics loading)
- glfw (window creation and management)
- Vulkan (future support)
- DirectX (future support)
- ImGui (UI)

## Clone
For a new clone
```
git clone --recursive https://github.com/pmann84/CMakeAppTemplate.git
```
For an already cloned repo
```
git clone https://github.com/pmann84/CMakeAppTemplate.git
cd CMakeOpenGlImGuiTemplate
git submodule update --init --recursive
```
## Updating if the submodules have changed
```
git submodule update --remote
```

## Configure and Build
First do an out of source build by configuring the build scripts
```
cd CMakeAppTemplate
mkdir out
cd out
cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON ..
```
Then build
```
cd out 
cmake --build . --config Debug
```

## Getting Started
To start going with app development you can use the stub app in the `app` directory. The `BasicApp` class gives you 
an idea of how to go about starting your first app. You only need implement the `OnUpdate` and `OnUiRender` 
functions. These run every frame, and you can use to update whatever state you need.

You can hook into the window, key and mouse events by overriding the member functions on the base class, the 
following are provided as virtual functions
```c++
virtual void OnKeyPressed(const KeyPressedEvent&)
virtual void OnWindowClose(const WindowCloseEvent&)
virtual void OnWindowResize(const WindowResizeEvent&)
virtual void OnCharPressed(const TextInputEvent&)
virtual void OnMouseButton(const MouseEvent&)
virtual void OnScroll(const ScrollEvent&)
virtual void OnCursorPosChanged(const CursorPosChangedEvent&)
```