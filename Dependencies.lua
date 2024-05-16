

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Table/vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Table/vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/Table/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Table/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Table/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Table/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Table/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Table/vendor/Imguizmo"
IncludeDir["shaderc"] = "%{VULKAN_SDK}/Include/shaderc"
IncludeDir["SPIRV_Cross"] = "%{VULKAN_SDK}/Include/spirv-cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_TOOLS_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"