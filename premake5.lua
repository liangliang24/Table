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
IncludeDir["glm"] = "Table/vendor/glm"

group "Dependencies"
	include "Table/vendor/GLFW"
	include "Table/vendor/GLAD"
	include "Table/vendor/imgui"

group ""

project "Table"
	location "Table"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")
	
	pchheader "tpch.h"
	pchsource "Table/src/tpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
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
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
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
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS",
			"TABLE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		--buildoptions "/MDd"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		--buildoptions "/MD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		--buildoptions "/MD"
		runtime "Release"
		optimize "on"

	--使用多线程运行库
	--filters { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"

project "Card"
	location "Card"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Table/src",
		"Table/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Table"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		--buildoptions "/MDd"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		--buildoptions "/MD"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		--buildoptions "/MD"
		runtime "Release"
		optimize "on"