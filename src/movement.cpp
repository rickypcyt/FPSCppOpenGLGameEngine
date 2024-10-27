#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "../include/movement.h"
#include "../include/globals.h" // Include the globals header

// Movement speed and direction variables
float moveSpeed = 5.0f; // Changed from GLfloat to float
float moveSpeedX = 0.0f; // Forward/Backward movement
float moveSpeedY = 0.0f; // Left/Right movement

// Jump variables
bool isJumping = false; 
float jumpHeight = 5.0f; 
float verticalVelocity = 0.0f;

// Key callback function for handling keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_W) {
            moveSpeedX = moveSpeed; // Move forward
        } else if (key == GLFW_KEY_S) {
            moveSpeedX = -moveSpeed; // Move backward
        } else if (key == GLFW_KEY_A) {
            moveSpeedY = -moveSpeed; // Strafe left
        } else if (key == GLFW_KEY_D) {
            moveSpeedY = moveSpeed; // Strafe right
        } else if (key == GLFW_KEY_SPACE && !isJumping) {
            std::cout << "Jump initiated!" << std::endl;
            isJumping = true;
            verticalVelocity = jumpHeight;
        } else if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        } else if (key == GLFW_KEY_EQUAL && (mods & GLFW_MOD_CONTROL)) { // Control + +
            sensitivity += 0.01f; // Increase sensitivity
            std::cout << "Mouse sensitivity increased to: " << sensitivity << std::endl;
        } else if (key == GLFW_KEY_MINUS && (mods & GLFW_MOD_CONTROL)) { // Control + -
            sensitivity = std::max(0.01f, sensitivity - 0.01f); // Decrease sensitivity but not below 0.01
            std::cout << "Mouse sensitivity decreased to: " << sensitivity << std::endl;
        }
    }

    if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W || key == GLFW_KEY_S) {
            moveSpeedX = 0.0f; // Stop forward/backward movement
        }
        if (key == GLFW_KEY_A || key == GLFW_KEY_D) {
            moveSpeedY = 0.0f; // Stop left/right movement
        }
    }
}

void updateMovement() {
    // Apply movement speed in the direction the camera is facing
    characterPosX += cameraFront.x * moveSpeedX * deltaTime;
    characterPosZ += cameraFront.z * moveSpeedX * deltaTime;

    // Strafe left/right
    characterPosX += moveSpeedY * deltaTime;

    // Jump physics
    if (isJumping) {
        verticalVelocity -= 9.81f * deltaTime; // Gravity
        characterPosY += verticalVelocity * deltaTime;

        // Reset jump when touching ground (Y = 0)
        if (characterPosY <= 0.0f) {
            characterPosY = 0.0f;
            isJumping = false;
            verticalVelocity = 0.0f; // Reset velocity
        }
    }
}
