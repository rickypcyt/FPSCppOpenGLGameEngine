#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>
#include "../include/movement.h"
#include "../include/globals.h"

// Movement constants
struct MovementConstants {
    static constexpr float JUMP_HEIGHT = 5.0f;
    static constexpr float GRAVITY = 15.0f;         // Increased gravity for better feel
    static constexpr float GROUND_LEVEL = 0.0f;
    static constexpr float AIR_CONTROL = 0.7f;
    static constexpr float ACCELERATION = 20.0f;
    static constexpr float DECELERATION = 25.0f;
    static constexpr float INITIAL_JUMP_VELOCITY = 7.0f; // Initial upward velocity
};

// Movement state
struct MovementState {
    bool isJumping = false;
    bool wasGrounded = true;
    float verticalVelocity = 0.0f;
    float currentSpeed = 0.0f;
    glm::vec3 velocity = glm::vec3(0.0f);
    
    // Input state
    bool moveForward = false;
    bool moveBackward = false;
    bool moveLeft = false;
    bool moveRight = false;
};

static MovementState moveState;

float lerp(float start, float end, float t) {
    return start + t * (end - start);
}

float applyMovementSmoothing(float currentSpeed, float targetSpeed, float deltaTime) {
    float acceleration = (targetSpeed != 0.0f) ? MovementConstants::ACCELERATION : MovementConstants::DECELERATION;
    return lerp(currentSpeed, targetSpeed, 1.0f - std::exp(-acceleration * deltaTime));
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_W: moveState.moveForward = true; break;
            case GLFW_KEY_S: moveState.moveBackward = true; break;
            case GLFW_KEY_A: moveState.moveLeft = true; break;
            case GLFW_KEY_D: moveState.moveRight = true; break;
            case GLFW_KEY_SPACE: 
                // Only trigger jump if we're on the ground
                if (characterPosY <= MovementConstants::GROUND_LEVEL) {
                    moveState.isJumping = true;
                    moveState.verticalVelocity = MovementConstants::INITIAL_JUMP_VELOCITY;
                    std::cout << "Jump initiated! Velocity: " << moveState.verticalVelocity << std::endl;
                }
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
            case GLFW_KEY_EQUAL:
                if (mods & GLFW_MOD_CONTROL) {
                    sensitivity += 0.01f;
                    std::cout << "Mouse sensitivity increased to: " << sensitivity << std::endl;
                }
                break;
            case GLFW_KEY_MINUS:
                if (mods & GLFW_MOD_CONTROL) {
                    sensitivity = std::max(0.01f, sensitivity - 0.01f);
                    std::cout << "Mouse sensitivity decreased to: " << sensitivity << std::endl;
                }
                break;
        }
    } else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_W: moveState.moveForward = false; break;
            case GLFW_KEY_S: moveState.moveBackward = false; break;
            case GLFW_KEY_A: moveState.moveLeft = false; break;
            case GLFW_KEY_D: moveState.moveRight = false; break;
        }
    }
}

void updateJump(float deltaTime) {
    // Apply gravity when in air
    if (characterPosY > MovementConstants::GROUND_LEVEL || moveState.verticalVelocity > 0) {
        moveState.verticalVelocity -= MovementConstants::GRAVITY * deltaTime;
        characterPosY += moveState.verticalVelocity * deltaTime;
        
        // Debug output for jump physics
        if (moveState.isJumping) {
            std::cout << "Jump Height: " << characterPosY << " Velocity: " << moveState.verticalVelocity << std::endl;
        }
    }

    // Ground collision check
    if (characterPosY <= MovementConstants::GROUND_LEVEL) {
        characterPosY = MovementConstants::GROUND_LEVEL;
        moveState.verticalVelocity = 0.0f;
        moveState.isJumping = false;
    }
}

void updateMovement(float deltaTime) {
    // Calculate movement direction
    glm::vec3 moveDirection(0.0f);
    
    if (moveState.moveForward) moveDirection += cameraFront;
    if (moveState.moveBackward) moveDirection -= cameraFront;
    
    // Calculate right vector for strafing
    glm::vec3 right = glm::normalize(glm::cross(cameraFront, glm::vec3(0.0f, 1.0f, 0.0f)));
    if (moveState.moveRight) moveDirection += right;
    if (moveState.moveLeft) moveDirection -= right;

    // Normalize direction and calculate movement
    if (glm::length(moveDirection) > 0.0f) {
        moveDirection = glm::normalize(moveDirection);
        
        // Remove vertical component from movement
        moveDirection.y = 0.0f;
        moveDirection = glm::normalize(moveDirection);
    }

    // Apply movement speed and air control
    float targetSpeed = glm::length(moveDirection) * moveSpeed;
    if (characterPosY > MovementConstants::GROUND_LEVEL) {
        targetSpeed *= MovementConstants::AIR_CONTROL;
    }

    // Update horizontal movement
    moveState.currentSpeed = applyMovementSmoothing(moveState.currentSpeed, targetSpeed, deltaTime);
    glm::vec3 finalVelocity = moveDirection * moveState.currentSpeed;
    
    // Update position
    characterPosX += finalVelocity.x * deltaTime;
    characterPosZ += finalVelocity.z * deltaTime;

    // Handle jumping and vertical movement
    updateJump(deltaTime);
}