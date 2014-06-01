solution "pong"
	configurations { "release", "debug" }
	warnings "Extra"

	project "stb"
		kind "StaticLib"
		language "c"
		files { "libs/**.c" }
		filter "configurations:debug"
			defines { "DEBUG" }
			flags { "symbols" }
			optimize "Off"
		filter "configurations:release"
			defines { "NDEBUG" }
			optimize "On"
		filter "system:windows" 
			targetdir "bin/win32"
			objdir "obj/win32"
		filter "system:linux" 
			targetdir "bin/lib64inux"
			objdir "obj/linux"
	
	project "pong"
		kind "ConsoleApp"
		language "c++"
		flags { "FatalWarnings" }
		links { "SDL2", "SDL2_mixer", "stb" }

		files { "src/**.cpp", "src/**.hpp" }
		includedirs { "src", "libs/include" }

		filter "configurations:debug"
			defines { "DEBUG" }
			flags { "symbols" }
			optimize "Off"

		filter "configurations:release"
			defines { "NDEBUG" }
			optimize "On"

		filter "system:windows"
			links { "mingw32", "SDL2main" }
			targetdir "bin/win32"
			objdir "obj/win32"

		filter "system:linux"
			targetdir "bin/linux"
			objdir "obj/linux"
			buildoptions { "-std=c++11" }

