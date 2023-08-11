# What is this?
This is an app template to setup using a graphics backend. It ships with ImGui out of the box and (will) allow you 
to switch backend depending on your needs. Currently it only supports OpenGL but this will give more flexibility 
compared to my old app framework. It will enable you to configure your project with things that you might need 
without the hassle of setting it all up, e.g. a renderer, test projects, logging etc.

# Prerequisites
- CMake

# Dependencies
These dependencies are imported in via git submodules to make it easier to integrate, without having to have package 
management setup. The dependent libraries used are:
- spdlog (logging)
- glm (math)
- glad (OpenGL graphics loading)
- glfw (window creation and management)
- Vulkan (future support)
- DirectX (future support)
- ImGui (UI)

# Clone
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
# Updating if the submodules have changes
```
git submodule update --remote
```

# Configure and Build
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