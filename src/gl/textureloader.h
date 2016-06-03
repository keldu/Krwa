#pragma once



#include "GL/glew.h"
#include "GLFW/glfw3.h"


GLuint loadPNG(const char *png_file_path);
GLuint loadBMP(const char * imagepath);
GLuint loadDDS(const char * imagepath);
GLuint loadDATA(const char* imagepath);
