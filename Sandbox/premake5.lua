project "Sandbox"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "On"

   targetdir ("%{wks.location}/bin/" .. outputdirname .. "/%{prj.name}")
   objdir ("%{wks.location}/bin/obj/" .. outputdirname .. "/%{prj.name}")

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "%{wks.location}/opengl_project/lib/spdlog/include",
      "%{wks.location}/opengl_project/src",
      "%{wks.location}/opengl_project/lib/GLAD/include",
      "%{wks.location}/opengl_project/lib/GLFW/include"
   }

   links { "opengl_project" }

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
