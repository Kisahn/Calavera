workspace "Calavera"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Calavera"
	location "Calavera"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cvpch.h"
	pchsource "Calavera/src/cvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CV_PLATFORM_WINDOWS",
			"CV_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CV_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CV_DIST"
		symbols "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Calavera/src"
	}

	links
	{
		"Calavera"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CV_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CV_DIST"
		symbols "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }