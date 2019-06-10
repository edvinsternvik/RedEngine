workspace "RedEngine"
	architecture "x64"
	startproject "RedGame"

	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "RedEngine/vendor/GLEW"
include "RedEngine/vendor/GLFW"

project "RedEngine"
	location "RedEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "off"
	cppdialect "C++17"
	defines "GLEW_STATIC"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp"
	}

	includedirs {
		"RedEngine/src",
		"RedEngine/vendor",
		"RedEngine/vendor/GLEW/include",
		"RedEngine/vendor/GLFW/include"
	}

	links {
		"GLEW",
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
		defines "RED_ENGINE_DEBUG"
		runtime "Debug"

	filter "configurations:Release"
		optimize "On"
		runtime "Release"

	filter "configurations:Dist"
		optimize "On"
		runtime "Release"

project "RedGame"
	location "RedGame"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"
	cppdialect "C++17"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"RedEngine/vendor",
		"RedEngine/src",
		"RedEngine/vendor/GLEW/include",
		"RedEngine/vendor/GLFW/include"
	}

	links {
		"RedEngine",
		"GLFW",
		"GLEW"
	}

	filter "system:linux"
		linkoptions { "-lX11", "-ldl", "-lGL", "-lpthread" }

	filter "configurations:Debug"
		symbols "On"
		defines "RED_ENGINE_DEBUG"
		runtime "Debug"

	filter "configurations:Release"
		optimize "On"
		runtime "Release"

	filter "configurations:Dist"
		optimize "On"
		runtime "Release"