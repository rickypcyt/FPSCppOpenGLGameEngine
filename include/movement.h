#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <GLFW/glfw3.h>

extern GLfloat moveSpeed;
extern GLfloat moveSpeedX;
extern GLfloat moveSpeedY;
extern const GLint WIDTH; // Declaration only
extern const GLint HEIGHT; // Declaration only

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void updateMovement();
void updateCamera();

#endif // MOVEMENT_H
