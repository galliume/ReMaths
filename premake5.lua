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

project "GoogleTest"
    kind "StaticLib"
    files 
    {
        "%{IncludeDir.googletest}/src/gtest-all.cc",
    }

    includedirs 
    { 
        "%{IncludeDir.googletest}/include", 
        "%{IncludeDir.googletest}"        
    }

    filter { "system:windows", "configurations:Debug"}
        systemversion "latest"
        runtime "Debug"
        symbols "on"
        buildoptions { "/MTd" }

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