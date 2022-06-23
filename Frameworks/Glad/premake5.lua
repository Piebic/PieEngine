project "Glad"
    location ("../%{rootDirs.Sources}/Glad")
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir ("%{rootDirs.Builds}/Output/%{outputDirs.GLAD}")
    objdir ("%{rootDirs.Builds}/Intermediate/%{outputDirs.GLAD}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c",
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
            systemversion "latest"
            
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        
    filter "configurations:Release"
        runtime "Release"
        optimize "on"