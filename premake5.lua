workspace "Axiom"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Axiom/vendor/GLFW/include"
IncludeDir["Glad"] = "Axiom/vendor/Glad/include"

include "Axiom/vendor/GLFW"
include "Axiom/vendor/Glad"

project "Axiom"
    location "Axiom"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "axpch.h"
    pchsource "Axiom/src/axpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links 
	{ 
		"GLFW",
        "Glad",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "AX_PLATFORM_WINDOWS",
            "AX_BUILD_DLL",
            "_WINDLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        
    filter "configurations:Debug"
        defines {"AX_DEBUG", "AX_ENABLE_ASSERTS"}
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "AX_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "AX_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Axiom/vendor/spdlog/include",
        "Axiom/src"
    }

    links
    {
        "Axiom"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "AX_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
		defines "AX_DEBUG"
        staticruntime "off"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AX_RELEASE"
        staticruntime "off"
        runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AX_DIST"
		staticruntime "off"
        runtime "Release"
		optimize "On"

