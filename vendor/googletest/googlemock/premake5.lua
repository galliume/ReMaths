project "GoogleMock"
    kind "StaticLib"
    language "C++"
    cppdialect "C++11"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "include/gmock/gmock.h",
    }
    
    includedirs
	{
        "src",
    }

	filter "system:windows"
        buildoptions { "-std=c11", "-lgdi32" }
        systemversion "latest"
        staticruntime "on"
        
    filter "system:linux"
        buildoptions { "-std=c11" }
        systemversion "latest"
        staticruntime "on"

        links { "dl", "pthread" }
