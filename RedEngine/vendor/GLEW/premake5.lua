project "GLEW"
	kind "StaticLib"
	language "C"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"include/GL/**.h",
		"src/**.c"
	}

	includedirs {
		"include"
	}
	
	staticruntime "On"

	defines {
		"GLEW_STATIC"
	}