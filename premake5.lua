workspace "ClosingIn"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ClosingIn"
	location "ClosingIn"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "ClosingIn/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src/",
	}

	libdirs
	{
	}

	links
	{
	}

	postbuildcommands
	{
	}

	filter "system:windows"
		defines "SR_WINDOWS"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		optimize "On"
		