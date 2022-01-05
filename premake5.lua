workspace "opengl_project"
   architecture "x64"
   configurations { "Debug", "Release" }
   startproject "Sandbox"

outputdirname = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
   include "opengl_project/lib/GLAD"
	include "opengl_project/lib" -- GLFW premake file
group ""

include "opengl_project"
include "Sandbox"

