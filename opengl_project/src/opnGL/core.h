#pragma once

/*
    A macro that helps in importing/exporting things
    depending on where it is used.

    The definition of "OPENGL_BUILD_DLL" is defined in the
    definitions of the "opengl_project" preprocessor, but
    not in the projects that use it
*/
#ifdef OPNGL_BUILD_DLL
    #define OPNGL_API __declspec(dllexport)
#else
    #define OPNGL_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
