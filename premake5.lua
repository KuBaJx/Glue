workspace "Glue"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Glue"
	location "Glue"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
			"GLUE_PLATFORM_WINDOWS",
			"GLUE_BUILD_DLL"
		}

		postbuildcommands
		{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GLUE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLUE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GLUE_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Glue/src"
	}

	links
	{
		"Glue"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLUE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GLUE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GLUE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GLUE_DIST"
		optimize "On"