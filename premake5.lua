workspace "Calavera"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Calavera/vendor/GLFW/include"
IncludeDir["Glad"] = "Calavera/vendor/Glad/include"
IncludeDir["ImGui"] = "Calavera/vendor/imgui"
IncludeDir["glm"] = "Calavera/vendor/glm"
IncludeDir["stb_image"] = "Calavera/vendor/stb_image"

group "Dependencies"
	include "Calavera/vendor/GLFW"
	include "Calavera/vendor/Glad"
	include "Calavera/vendor/imgui"
group ""

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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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

project "Calavera-Editor"
	location "Calavera-Editor"
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