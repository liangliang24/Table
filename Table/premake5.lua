project "Table"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/".. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/".. outputdir .. "/%{prj.name}")
	
	pchheader "tpch.h"
	pchsource "src/tpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
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