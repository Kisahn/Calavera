include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Calavera"
	architecture "x86_64"
	startproject "Calavera-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Calavera/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Calavera/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Calavera/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Calavera/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Calavera/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Calavera/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Calavera/vendor/GLFW"
	include "Calavera/vendor/Glad"
	include "Calavera/vendor/imgui"
group ""

include "Calavera"
include "Sandbox"
include "Calavera-Editor"