project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "On"
    
    targetdir ("%{wks.location}/bin/" .. outputdirname .. "/%{prj.name}")
    objdir ("%{wks.location}/bin/obj/" .. outputdirname .. "/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "on"
