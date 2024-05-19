include "./Build/premake/premake_customization/solution_items.lua"

workspace "Table"
	architecture "x86_64"
	startproject "Table-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Table/vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Table/vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/Table/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Table/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Table/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Table/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Table/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Table/vendor/Imguizmo"
IncludeDir["Box2D"] = "%{wks.location}/Table/vendor/Box2D/include"

group "Dependencies"
	include "Build/premake"
	include "Table/vendor/Box2D"
	include "Table/vendor/GLFW"
	include "Table/vendor/GLAD"
	include "Table/vendor/imgui"
	include "Table/vendor/yaml-cpp"
group ""

include "Table"
include "Card"
include "Table-Editor"

