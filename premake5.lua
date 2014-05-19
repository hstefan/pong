solution "pong"
	configurations { "release", "debug" }

	flags { "FatalWarnings" }
	warnings "Extra"
	targetdir "bin"

	project "pong"
		kind "ConsoleApp"
		language "c++"
		files { "src/**.cpp", "src/**.hpp", "src/**.c", "src/**.cpp" }
		includedirs { "src" }

		configuration "debug"
			defines { "DEBUG" }
			flags { "symbols" }
			optimize "Off"

		configuration "release"
			defines { "NDEBUG" }
			optimize "On"

		configuration "windows"
			links { "mingw32", "SDL2main" }
			targetdir "bin/win32"
			objdir "obj/win32"

		configuration "linux"
			targetdir "bin/linux"
			objdir "obj/linux"

		configuration "gmake"
			buildoptions { "-std=c++11", "-Wall"}
			links { "SDL2", "SDL2_mixer" }
