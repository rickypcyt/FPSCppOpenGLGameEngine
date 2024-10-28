#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/movement.h"
#include "../include/globals.h"

// Movement constants
struct MovementConstants {
    static constexpr float JUMP_HEIGHT = 5.0f;
    static constexpr float GRAVITY = 20.0f;         // Adjusted gravity for better feel
    static constexpr float GROUND_LEVEL = 0.0f;
    static constexpr float AIR_CONTROL = 0.5f;       // Reduced air control for more realistic jumps
    static constexpr float ACCELERATION = 0.0f;      // Instantaneous acceleration
    static constexpr float DECELERATION = 0.0f;      // Instantaneous deceleration
    static constexpr float INITIAL_JUMP_VELOCITY = 8.0f; // Adjusted for more height
};

// Movement state
struct MovementState {
    bool isJumping = false;
    float verticalVelocity = 0.0f;
    
    // Input state
    bool moveForward = false;
    bool moveBackward = false;
    bool moveLeft = false;
    bool moveRight = false;
};

static MovementState moveState;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_W: moveState.moveForward = true; break;
            case GLFW_KEY_S: moveState.moveBackward = true; break;
            case GLFW_KEY_A: moveState.moveLeft = true; break;
            case GLFW_KEY_D: moveState.moveRight = true; break;
            case GLFW_KEY_SPACE: 
                // Only jump if we're grounded
                if (characterPosY <= MovementConstants::GROUND_LEVEL) {
                    moveState.isJumping = true;
                    moveState.verticalVelocity = MovementConstants::INITIAL_JUMP_VELOCITY;
                }
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
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
    if (moveState.isJumping) {
        moveState.verticalVelocity -= MovementConstants::GRAVITY * deltaTime;
        characterPosY += moveState.verticalVelocity * deltaTime;

        // Land if below ground level
        if (characterPosY <= MovementConstants::GROUND_LEVEL) {
            characterPosY = MovementConstants::GROUND_LEVEL;
            moveState.verticalVelocity = 0.0f;
            moveState.isJumping = false;
        }
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

    // Normalize direction and remove vertical component
    if (glm::length(moveDirection) > 0.0f) {
        moveDirection = glm::normalize(moveDirection);
        moveDirection.y = 0.0f; // Prevent vertical movement
    }

    // Apply movement
    float speed = moveSpeed; // Adjust as needed
    characterPosX += moveDirection.x * speed * deltaTime;
    characterPosZ += moveDirection.z * speed * deltaTime;

    // Update jumping logic
    updateJump(deltaTime);
}
