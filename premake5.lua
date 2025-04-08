workspace "Calavera"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Calavera/vendor/GLFW/include"
IncludeDir["Glad"] = "Calavera/vendor/Glad/include"
IncludeDir["ImGui"] = "Calavera/vendor/imgui"
IncludeDir["glm"] = "Calavera/vendor/glm"

include "Calavera/vendor/GLFW"
include "Calavera/vendor/Glad"
include "Calavera/vendor/imgui"

project "Calavera"
	location "Calavera"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cvpch.h"
	pchsource "Calavera/src/cvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CV_PLATFORM_WINDOWS",
			"CV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CV_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Calavera/vendor/spdlog/include",
		"Calavera/src",
		"Calavera/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Calavera"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CV_DIST"
		runtime "Release"
		optimize "on"