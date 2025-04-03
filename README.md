# CalaveraEngine

> A custom game engine written in C++, based on TheCherno’s Hazel series.  
> This version is fully rebuilt and personalized by Jean Deck, as a learning and prototyping tool to explore low-level engine architecture.

---

## 📚 Context

This engine is based on the **Hazel Engine** by [TheCherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT).  
I followed the series until episode 69 (rendering 2D with camera and textures), and I plan to expand the engine with:

- New input systems
- Physics prototype
- Custom rendering layer
- Gameplay scripting and basic ECS
- Editor tools (future)

---

## ⚙️ Features implemented so far

✅ Application & Layer system  
✅ Event system (keyboard, mouse)  
✅ Logging with spdlog  
✅ Windowing (GLFW + Glad)  
✅ Renderer2D (OpenGL abstraction)  
✅ Batching + Textures + Shaders  
✅ Orthographic camera with movement  
✅ Basic profiling + debug overlays (in progress)

---

## 🛠️ Tech Stack

- C++17 (Visual Studio)
- GLFW, Glad, GLM
- spdlog
- OpenGL
- CMake (or SCons if tu as changé)

---

## 🚀 How to build

```bash
git clone https://github.com/JeanDeck/CalaveraEngine.git
cd CalaveraEngine
# Generate project with CMake or build with VS
