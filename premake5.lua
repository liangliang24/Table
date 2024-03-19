workspace "Table"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Table"
	location "Table"
	kind "SharedLib"

	language "C++"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS",
			"TABLE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .."/Card")
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		optimize "On"

	--使用多线程运行库
	--filters { "system:windows", "configurations:Release"}
	--	buildoptions "/MT"

project "Card"
	location "Card"
	kind "ConsoleApp"

	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TABLE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TABLE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "TABLE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TABLE_DIST"
		optimize "On"