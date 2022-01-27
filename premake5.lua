workspace "ReMaths"
	architecture "x64"
	startproject "ReMaths"
	configurations
	{
		"Debug", "Release", "Dist"  
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["googletest"] = "vendor/googletest/googletest"
IncludeDir["googlemock"] = "vendor/googletest/googlemock"

project "GoogleTest"
    kind "StaticLib"
    files 
    {
        "%{IncludeDir.googletest}/src/gtest-all.cc",
        "%{IncludeDir.googlemock}/src/gmock-all.cc" 
    }

    includedirs 
    { 
        "%{IncludeDir.googletest}/include", 
        "%{IncludeDir.googletest}",
        "%{IncludeDir.googlemock}/include", 
        "%{IncludeDir.googlemock}"
    }

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
        "include/**.h",
        "src/**.cpp",
        "tests/**.cpp"
    }

    includedirs
    {
        "include",
        "%{IncludeDir.googletest}/include",
        "%{IncludeDir.googlemock}/include"
    }

    links
    {
        "GoogleTest"
    }

	filter { "system:windows", "configurations:Debug"}
        systemversion "latest"
        runtime "Debug"
        symbols "on"
        buildoptions { "/MTd" }

    filter { "system:linux", "configurations:Debug"}
        systemversion "latest"
        links { "dl", "pthread" }