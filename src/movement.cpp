#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <cmath>
#include "../include/movement.h"
#include "../include/globals.h"

GLfloat moveSpeed = 5.0f;
GLfloat moveSpeedX = 0.0f;
GLfloat moveSpeedY = 0.0f;
const GLint WIDTH = 800;
const GLint HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) {
        moveSpeedY = -moveSpeed;
    } else if (key == GLFW_KEY_S) {
        moveSpeedY = moveSpeed;
    } else if (key == GLFW_KEY_A) {
        moveSpeedX = -moveSpeed;
    } else if (key == GLFW_KEY_D) {
        moveSpeedX = moveSpeed;
    } else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    // Handle mouse input here if needed
}

void updateMovement() {
    characterPosX += moveSpeedX * deltaTime;
    characterPosZ += moveSpeedY * deltaTime;

    // Reset movement after updating
    moveSpeedX = 0.0f;
    moveSpeedY = 0.0f;
}
