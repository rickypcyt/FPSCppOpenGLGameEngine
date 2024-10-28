#include "../include/PhysicsSystem.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>

void PhysicsSystem::initialize() {
    position = {0.0f, 0.0f, 5.0f};
    velocity = {0.0f};
}

void PhysicsSystem::update(float deltaTime) {
    if (isJumping) {
        velocity.y -= properties.gravity * deltaTime;
        position += velocity * deltaTime;
        if (position.y <= properties.groundLevel) {
            position.y = properties.groundLevel;
            velocity.y = 0.0f;
            isJumping = false;
        }
    }
}

void PhysicsSystem::jump() {
    if (isGrounded()) {
        velocity.y += properties.jumpForce;
        isJumping = true;
    }
}

void PhysicsSystem::move(const glm::vec3& direction, float deltaTime) {
    glm::vec3 movement = direction * properties.moveSpeed * deltaTime;
    position += movement;
}
