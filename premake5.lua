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
IncludeDir["ImGui"] = "Axiom/vendor/imgui"
IncludeDir["glm"] = "Axiom/vendor/glm"
IncludeDir["stb_image"] = "Axiom/vendor/stb_image"

include "Axiom/vendor/imgui"
include "Axiom/vendor/GLFW"
include "Axiom/vendor/Glad"

project "Axiom"
    location "Axiom"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "axpch.h"
    pchsource "Axiom/src/axpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.h",
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
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
    }

    links 
    { 
        "GLFW",
        "ImGui",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "AX_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }
        
    filter "configurations:Debug"
        defines "AX_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AX_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AX_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Axiom/vendor/spdlog/include",
        "Axiom/src",
        "Axiom/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Axiom",
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "AX_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AX_DEBUG"
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
