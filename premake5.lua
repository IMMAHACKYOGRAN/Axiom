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

project "Axiom"
    location "Axiom"
    kind "SharedLib"
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
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "AX_PLATFORM_WINDOWS",
            "AX_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        
    filter "configurations:Debug"
        defines "AX_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AX_DIST"
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
            "AX_PLATFORM_WINDOWS",
            "_MBCS"
        }

        filter "configurations:Debug"
            defines "AX_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "AX_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "AX_DIST"
            optimize "On"

