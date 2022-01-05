project "opengl_project"
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "Off"

   systemversion "latest"

   targetdir ("%{wks.location}/bin/" .. outputdirname .. "/%{prj.name}")
   objdir ("%{wks.location}/bin/obj/" .. outputdirname .. "/%{prj.name}")

   files { "src/**.h", "src/**.cpp" }

   defines
   {
      "OPNGL_BUILD_DLL",
      "GLFW_INCLUDE_NONE",
      "_CRT_SECURE_NO_WARNINGS"
   }

   includedirs
   {
      "lib/spdlog/include",
      "lib/GLAD/include",
      "lib/GLFW/include"      
   }

   links
   {
      "glad",
      "GLFW",
		"opengl32.lib"
   }

   postbuildcommands
   {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdirname .. "/Sandbox") 
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
		runtime "Debug"
		symbols "on"

   filter "configurations:Release"
      defines { "NDEBUG" }
      runtime "Release"
      optimize "on"
