workspace "Table"
	architecture "x64"
	startproject "Card"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Table/vendor/GLFW/include"
IncludeDir["GLAD"] = "Table/vendor/GLAD/include"
IncludeDir["ImGui"] = "Table/vendor/imgui"

group "Dependencies"
	include "Table/vendor/GLFW"
	include "Table/vendor/GLAD"
	include "Table/vendor/imgui"

group ""

project "Table"
	location "Table"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")
	
	pchheader "tpch.h"
	pchsource "Table/src/tpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS",
			"TABLE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Card/\"")
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		--buildoptions "/MDd"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		--buildoptions "/MD"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		--buildoptions "/MD"
		runtime "Release"
		optimize "On"

	--ʹ�ö��߳����п�
	--filters { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"

project "Card"
	location "Card"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Table/vendor/spdlog/include",
		"Table/src"
	}

	links
	{
		"Table"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		--buildoptions "/MDd"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		--buildoptions "/MD"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		--buildoptions "/MD"
		runtime "Release"
		optimize "On"