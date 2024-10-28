#ifndef RENDERER_H
#define RENDERER_H

#include <GL/gl.h>
#include "stb_image.h"

// Function to draw the floor
void drawFloor();

// Function to load a texture
GLuint loadTexture(const char* filepath);

#endif // RENDERER_H
