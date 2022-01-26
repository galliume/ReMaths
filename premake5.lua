workspace "ReMaths"
	architecture "x64"
	startproject "ReMaths"
	configurations
	{
		"Debug", "Release", "Dist"  
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["googletest"] = "vendor/googletest/googletest/include"
IncludeDir["googlemock"] = "vendor/googletest/googlemock/include"

project "ReMaths"
    location ""
    kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "include/*.h",
        "src/*.cpp",
    }
    
    includedirs
    {
        "include",
        "vendor/googletest/googletest",
        "vendor/googletest/googletest/googletest",
        "%{IncludeDir.googletest}",
        "%{IncludeDir.googlemock}",
    }

    links
    {
        "GoogleTest", "GoogleMock"
    }

	filter { "system:windows", "configurations:Debug"}
        systemversion "latest"
        runtime "Debug"
        symbols "on"
        buildoptions { "/MTd" }

    filter { "system:linux", "configurations:Debug"}
        systemversion "latest"
        links { "dl", "pthread" }