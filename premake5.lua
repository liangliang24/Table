include "./Build/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "Build/premake"
	include "Table/vendor/Box2D"
	include "Table/vendor/GLFW"
	include "Table/vendor/GLAD"
	include "Table/vendor/imgui"
	include "Table/vendor/yaml-cpp"
group ""

group "Core"
	include "Table"
	include "Table-ScriptCore"
group ""

group "Tools"
	include "Table-Editor"
group ""

group "Misc"
	include "Card"
group ""

