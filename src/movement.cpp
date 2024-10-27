#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include <ostream>
#include "../include/movement.h"
#include "../include/globals.h"

// Movement speed and direction variables
GLfloat moveSpeed = 5.0f;
GLfloat moveSpeedX = 0.0f;
GLfloat moveSpeedY = 0.0f;

// Jump variables
bool isJumping = false; 
GLfloat jumpHeight = 5.0f; 
GLfloat verticalVelocity = 0.0f;

// Window dimensions
const GLint WIDTH = 800;   
const GLint HEIGHT = 600; 

// Key callback function for handling keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_W) {
            moveSpeedY = -moveSpeed;
        } else if (key == GLFW_KEY_S) {
            moveSpeedY = moveSpeed;
        } else if (key == GLFW_KEY_A) {
            moveSpeedX = -moveSpeed;
        } else if (key == GLFW_KEY_D) {
            moveSpeedX = moveSpeed;
        } else if (key == GLFW_KEY_SPACE && !isJumping) {
            std::cout << "Jump initiated!" << std::endl;
            isJumping = true;
            verticalVelocity = jumpHeight;
        } else if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W || key == GLFW_KEY_S) {
            moveSpeedY = 0.0f;
        }
        if (key == GLFW_KEY_A || key == GLFW_KEY_D) {
            moveSpeedX = 0.0f;
        }
    }
}

// Mouse callback function for handling mouse input
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    // Implement mouse movement handling if needed
}

void updateMovement() {
    // Horizontal movement based on input
    characterPosX += moveSpeedX * deltaTime; 
    characterPosZ += moveSpeedY * deltaTime;

    // Vertical movement (jumping logic)
    if (isJumping) {
        characterPosY += verticalVelocity * deltaTime; // Update vertical position
        verticalVelocity -= 9.81f * deltaTime; // Apply gravity

        // Check if the character has landed
        if (characterPosY <= 0.0f) {
            characterPosY = 0.0f; // Reset to ground level
            isJumping = false; // Reset jump state
            verticalVelocity = 0.0f; // Reset vertical velocity
        }
    } else {
        characterPosY = 0.0f; // Ensure the character stays grounded
    }
}


