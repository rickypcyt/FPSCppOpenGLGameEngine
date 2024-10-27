#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "../include/movement.h"
#include "../include/globals.h"

// Movement speed and direction variables
float moveSpeed = 5.0f; // Changed from GLfloat to float
float moveSpeedX = 0.0f;
float moveSpeedY = 0.0f;

// Jump variables
bool isJumping = false; 
float jumpHeight = 5.0f; 
float verticalVelocity = 0.0f;

// Key callback function for handling keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_W) {
            moveSpeedY = -moveSpeed; // Move forward
        } else if (key == GLFW_KEY_S) {
            moveSpeedY = moveSpeed; // Move backward
        } else if (key == GLFW_KEY_A) {
            moveSpeedX = -moveSpeed; // Strafe left
        } else if (key == GLFW_KEY_D) {
            moveSpeedX = moveSpeed; // Strafe right
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

void updateMovement() {
    // Ensure these variables are declared in globals.h
    characterPosX += (cameraFront.x * moveSpeedX + cameraFront.z * moveSpeedY) * deltaTime;
    characterPosZ += (cameraFront.z * moveSpeedX - cameraFront.x * moveSpeedY) * deltaTime;

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
