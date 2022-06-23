
-- Directories

outputDirs = {}
outputDirs["Engine"] = "PieEngine/%{cfg.buildcfg}"
outputDirs["Sandbox"] = "Sandbox/%{cfg.buildcfg}"
outputDirs["GLFW"] = "GLFW/%{cfg.buildcfg}"

rootDirs = {}
rootDirs["Builds"] = "../Builds"
rootDirs["Frameworks"] = "../Frameworks"
rootDirs["Sources"] = "../Sources"

engineDirs = {}
engineDirs["Root"] = "%{rootDirs.Sources}/PieEngine"
engineDirs["App"] = "%{rootDirs.Sources}/PieEngine/App"
engineDirs["Core"] = "%{rootDirs.Sources}/PieEngine/Core"
engineDirs["Events"] = "%{rootDirs.Sources}/PieEngine/Events"
engineDirs["Foundation"] = "%{rootDirs.Sources}/PieEngine/Foundation"
engineDirs["Platforms"] = "%{rootDirs.Sources}/PieEngine/Platforms"

sandboxDirs = {}
sandboxDirs["Root"] = "%{rootDirs.Sources}/Sandbox"
sandboxDirs["Logs"] = "%{rootDirs.Sources}/Sandbox/logs"

workspace "PieEngine"
    location ("%{rootDirs.Sources}")
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }


-- Include directories relative to root folder (solution directory)
includeDirs = {}
includeDirs["GLFW"] = "%{rootDirs.Frameworks}/glfw/include"
-- includeDirs["Glad"] = "PieEngine/ThirdParty/Glad/include"
-- includeDirs["ImGui"] = "PieEngine/ThirdParty/imgui"
-- includeDirs["glm"] = "PieEngine/ThirdParty/glm"
-- includeDirs["stb_image"] = "PieEngine/ThirdParty/stb_image"

include "../Frameworks/glfw"
-- include "PieEngine/ThirdParty/Glad"
-- include "PieEngine/ThirdParty/imgui"

project "PieEngine"
    location ("%{rootDirs.Sources}/PieEngine")
    kind "SharedLib"
    -- kind "StaticLib"
    language "C++"
    -- cppdialect "C++17"
    -- staticruntime "on"

    targetdir ("%{rootDirs.Builds}/Output/%{outputDirs.Engine}")
    objdir ("%{rootDirs.Builds}/Intermediate/%{outputDirs.Engine}")

    pchheader "Pie.h"
    pchsource "%{engineDirs.Root}/Pie.cpp"

    files
    {
        "%{engineDirs.Root}/**.h",
        "%{engineDirs.Root}/**.cpp",
        "%{engineDirs.App}/**.h",
        "%{engineDirs.App}/**.cpp",
        "%{engineDirs.Core}/**.h",
        "%{engineDirs.Core}/**.cpp",
        "%{engineDirs.Events}/**.h",
        "%{engineDirs.Events}/**.cpp",
        "%{engineDirs.Foundation}/**.h",
        "%{engineDirs.Foundation}/**.cpp",
        "%{engineDirs.Platforms}/**.h",
        "%{engineDirs.Platforms}/**.cpp",
        "%{engineDirs.Platforms}/Windows/**.h",
        "%{engineDirs.Platforms}/Windows/**.cpp"
        -- "%{prj.name}/ThirdParty/stb_image/**.h",
        -- "%{prj.name}/ThirdParty/stb_image/**.cpp",
        -- "%{prj.name}/ThirdParty/glm/glm/**.hpp",
        -- "%{prj.name}/ThirdParty/glm/glm/**.inl"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{engineDirs.Root}",
        "%{engineDirs.App}",
        "%{engineDirs.Core}",
        "%{engineDirs.Events}",
        "%{engineDirs.Foundation}",
        "%{engineDirs.Platforms}",
        "%{rootDirs.Frameworks}/spdlog/include",
        "%{includeDirs.GLFW}"
        -- "%{includeDirs.Glad}",
        -- "%{includeDirs.ImGui}",
        -- "%{includeDirs.glm}",
        -- "%{includeDirs.stb_image}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
        -- "Glad",
        -- "ImGui",
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} %{prj.location}../../Builds/Output/%{outputDirs.Sandbox}")
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "WIN_API",
            "BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    
    filter "configurations:Debug"
        defines "PIE_DEBUG"
        runtime "Debug"
        -- buildoptions "/MDd"
        symbols "on"
    
    filter "configurations:Release"
        defines "PIE_RELEASE"
        runtime "Release"
        -- buildoptions "/MD"
        optimize "on"
    
    filter "configurations:Distribution"
        defines "PIE_DISTRIBUTION"
        runtime "Debug"
        -- buildoptions "/MD"
        optimize "on"

project "Sandbox"
    location ("%{rootDirs.Sources}/Sandbox")
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{rootDirs.Builds}/Output/%{outputDirs.Sandbox}")
    objdir ("%{rootDirs.Builds}/Intermediate/%{outputDirs.Sandbox}")

    files
    {
        "%{sandboxDirs.Root}/**.h",
        "%{sandboxDirs.Root}/**.cpp",
        "%{sandboxDirs.Logs}/**.txt"
    }

    includedirs
    {
        "%{engineDirs.Root}",
        "%{rootDirs.Frameworks}/spdlog/include"
        -- "%{includeDirs.glm}"
    }

    links
    {
        "PieEngine"
    }

    filter "system:windows"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "WIN_API"
        }
    
    filter "configurations:Debug"
        defines "PIE_DEBUG"
        runtime "Debug"
        -- buildoptions "/MDd"
        symbols "on"
    
    filter "configurations:Release"
        defines "PIE_RELEASE"
        runtime "Release"
        -- buildoptions "/MD"
        optimize "on"
    
    filter "configurations:Distribution"
        defines "PIE_DISTRIBUTION"
        runtime "Debug"
        -- buildoptions "/MD"
        optimize "on"