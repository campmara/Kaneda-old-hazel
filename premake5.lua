workspace "Kaneda"
    architecture "x64"
    
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kaneda"
    location "Kaneda"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/external/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "K_PLATFORM_WINDOWS",
            "K_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "K_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "K_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "K_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Kaneda/external/spdlog/include",
        "Kaneda/src"
    }

    links {
        "Kaneda"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "K_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "K_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "K_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "K_DIST"
        optimize "On"