IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Table/vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Table/vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/Table/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Table/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Table/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Table/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/Table/vendor/mono/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Table/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Table/vendor/Imguizmo"
IncludeDir["Box2D"] = "%{wks.location}/Table/vendor/Box2D/include"

LibraryDir = {}
LibraryDir["mono"] = "%{wks.location}/Table/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"