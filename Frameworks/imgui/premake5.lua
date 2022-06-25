project "ImGui"
	location ("../%{rootDirs.Sources}/ImGui")
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../%{rootDirs.Builds}/Output/%{outputDirs.ImGui}")
	objdir ("../%{rootDirs.Builds}/Intermediate/%{outputDirs.ImGui}")

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
	}

    filter "system:windows"
            systemversion "latest"
            
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        
    filter "configurations:Release"
        runtime "Release"
        optimize "on"