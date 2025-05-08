# Calavera Engine

> A modular game engine prototype written in modern C++17, built from scratch as part of a learning journey inspired by TheCherno’s "Game Engine" YouTube series.  
> Designed and developed as a personal deep-dive into low-level rendering, architecture, and system design.

---

## 📚 Project Overview

Calavera is a **fully custom game engine** designed to learn and replicate the core systems behind modern engines like Unity or Unreal — but at a lower level and in C++.

This version of the engine implements a **clean, layered architecture** and introduces the foundational systems required to scale toward a real-time 2D/3D engine:
- Windowing
- Logging
- Event handling
- Rendering context (OpenGL)
- Abstraction layers (RendererAPI, buffers, shaders)
- Immediate-mode GUI (ImGui)
- Modular layer stack

The code is clean, documented, and intentionally paused at a stable milestone — focusing on quality and deep understanding over feature creep.

---

## ✅ Implemented Features

- **Entry Point abstraction**  
  `EntryPoint.h`, `CreateApplication()`

- **Layer system with overlays**  
  `LayerStack`

- **Event System**  
  Keyboard, mouse, window and app events with dispatcher logic

- **Window abstraction**  
  Implemented via GLFW

- **Input polling abstraction**  
  Keyboard and mouse input handled with platform-independent layer

- **Logging system**  
  Based on spdlog with macro helpers

- **OpenGL Renderer abstraction**:
  - Vertex & Index Buffers
  - Vertex Array abstraction
  - `RendererAPI` interface (OpenGL backend)
  - `RenderCommand` (static rendering façade)

- **Graphics context abstraction**  
  Implemented via `OpenGLContext`

- **Shader pipeline**  
  Manual loading, compiling, binding and uniform management

- **ImGui integration**  
  Immediate-mode GUI overlay via `ImGuiLayer`

---

## 📂 Project Structure

    CalaveraEngine/
    ├── Calavera/                # Static engine library
    │   ├── src/
    │   │   ├── Calavera/       # Core engine modules (Events, Renderer, Layers, etc.)
    │   │   └── Platform/       # Platform-specific backends (Windows, OpenGL, etc.)
    │   ├── vendor/             # GLFW, Glad, spdlog, ImGui, GLM
    │   └── ...
    ├── Sandbox/                # Test application using the engine
    │   └── src/
    ├── vendor/                 # Premake5 only
    ├── generate_project.bat    # Script to generate the Visual Studio solution
    ├── .gitignore
    ├── premake5.lua            # Root build script (Premake)
    └── README.md

---

## 🧱 Technologies Used

| Component         | Description                                                |
|------------------|------------------------------------------------------------|
| ⚙️ C++17          | Core language for the entire engine (statically typed, high-performance) |
| 🧱 Premake5       | Lightweight build configuration tool (multi-project setup) |
| 🪟 GLFW           | Window and input handling                                  |
| 🔌 Glad           | OpenGL function loader                                     |
| 🧮 GLM            | Math library for vectors, matrices, and transforms         |
| 🖼️ OpenGL         | Graphics rendering backend (3.3 core profile)              |
| 📊 spdlog         | Logging library for debugging and runtime info             |
| 🖱️ ImGui          | Immediate-mode GUI for overlays and debugging tools        |
| 💻 Visual Studio 2022 | Main development environment on Windows              |

---

## 🚀 Build Instructions

1. **Clone the repository**:

       git clone https://github.com/JeanDeck/CalaveraEngine.git
       cd CalaveraEngine

2. **Generate the Visual Studio solution** using the batch file at the root:

       generate_project.bat

3. **Open the solution**:

       CalaveraEngine.sln

4. **Build the solution** in Visual Studio 2022 (Debug or Release, x64)

---

## 🎯 Why This Project?

This engine is not meant to be a full-fledged game engine. It’s a **proof of understanding** — a demonstration of:
- How rendering APIs like OpenGL are abstracted
- How engines isolate platform-specific code
- How modular systems (layers, events, logs) are built from the ground up
- How to structure a real C++ project with modern practices (PCH, premake, submodules, etc.)

It’s also a **tool for technical interviews**, especially for positions like **engine programmer**, **tools developer**, or **graphics developer**.

---

## 📌 Next Steps (paused for now)

This engine is currently paused at a clean milestone.  
Future extensions may include:
- Orthographic camera system
- Texture rendering
- Renderer2D
- Framebuffer support
- Physics experiments
- Editor GUI

But the current state is already sufficient for demonstrating real engine development skills.

---

## 📃 License

This project is for personal learning purposes and not intended for commercial use.  
The code is based in part on Hazel (© TheCherno), used here for educational purposes.
