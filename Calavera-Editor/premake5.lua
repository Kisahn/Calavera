project "Calavera-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Calavera/vendor/spdlog/include",
		"%{wks.location}/Calavera/src",
		"%{wks.location}/Calavera/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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