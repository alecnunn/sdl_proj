solution "MyApp"
    configurations { "Debug", "Release" }
    project "MyApp"
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
        defines { "NDEBUG" }
        targetdir "release"
