workspace "Glue"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Glue/vendor/GLFW/include"
IncludeDir["Glad"] = "Glue/vendor/Glad/include"
IncludeDir["ImGui"] = "Glue/vendor/imgui"
IncludeDir["glm"] = "Glue/vendor/glm"

include "Glue/vendor/GLFW"
include "Glue/vendor/Glad"
include "Glue/vendor/imgui"

project "Glue"
	location "Glue"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gluepch.h"
	pchsource "Glue/src/gluepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLUE_PLATFORM_WINDOWS",
			"GLUE_BUILD_DLL",
			"GLUE_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines "GLUE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLUE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GLUE_DIST"
		runtime "Release"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Glue/vendor/spdlog/include",
		"Glue/vendor/imgui",
		"%{IncludeDir.glm}",
		"Glue/src"
	}

	links
	{
		"Glue"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLUE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GLUE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLUE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GLUE_DIST"
		runtime "Release"
		symbols "on"