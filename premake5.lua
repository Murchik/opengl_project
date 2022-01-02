workspace "opengl_project"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdirname = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "opengl_project"
   location "opengl_project"   
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "On"
   systemversion "latest"

   defines { "OPNGL_BUILD_DLL" }

   targetdir ("bin/" .. outputdirname .. "/%{prj.name}")
   objdir ("bin/obj/" .. outputdirname .. "/%{prj.name}")

   files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

   includedirs { "%{prj.name}/lib/spdlog/include" }

   postbuildcommands 
   { 
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdirname .. "/Sandbox") 
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "Sandbox"
   location "Sandbox"   
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "On"
   systemversion "latest"

   targetdir ("bin/" .. outputdirname .. "/%{prj.name}")
   objdir ("bin/obj/" .. outputdirname .. "/%{prj.name}")

   files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

   includedirs
   { 
      "opengl_project/lib/spdlog/include",
      "opengl_project/src"
   }

   links { "opengl_project" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
