workspace "Table"
	architecture "x86_64"
	startproject "Card"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Table/vendor/GLFW/include"
IncludeDir["GLAD"] = "Table/vendor/GLAD/include"
IncludeDir["ImGui"] = "Table/vendor/imgui"
IncludeDir["glm"] = "Table/vendor/glm"
IncludeDir["stb_image"] = "Table/vendor/stb_image"
IncludeDir["entt"] = "Table/vendor/entt/include"

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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
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

project "Table-Editor"
	location "Table-Editor"
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Table"
	}

	filter "system:windows"
		systemversion "latest"

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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Table"
	}

	filter "system:windows"
		systemversion "latest"

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