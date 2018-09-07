solution "sdl_app"
    configurations { "Debug", "Release" }
    project "sdl_app"
    kind "ConsoleApp"
    language "C"
    files {
        "src/**.c"
    }

    includedirs { "include" }
    links { "m", "SDL2" }

    configuration "Debug"
        defines { "DEBUG" }
        targetdir "debug"

    configuration "Release"
        targetdir "release"
