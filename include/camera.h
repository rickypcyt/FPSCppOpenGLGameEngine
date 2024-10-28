#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/quaternion.hpp>
#include <array>
#include <cmath>

class FPSCamera {
private:
    // Camera state
    glm::vec3 position;
    float pitch;
    float yaw;
    
    // Cached vectors
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    
    // Constants
    static constexpr float PI = 3.14159265358979323846f;
    static constexpr float MIN_PITCH = -89.0f * PI / 180.0f;
    static constexpr float MAX_PITCH = 89.0f * PI / 180.0f;
    
    // Helper functions
    void updateVectors();

public:
    FPSCamera(const glm::vec3& pos = glm::vec3(0.0f), float pitchDeg = 0.0f, float yawDeg = 0.0f);
    
    glm::mat4 getViewMatrix() const;
    glm::mat4 getViewMatrixQuaternion() const;
    
    void setPosition(const glm::vec3& pos);
    void setRotation(float pitchDeg, float yawDeg);
    void rotate(float deltaPitch, float deltaYaw);
    void move(const glm::vec3& offset);
    
    glm::vec3 getPosition() const;
    glm::vec3 getForward() const;
    glm::vec3 getRight() const;
    glm::vec3 getUp() const;
    float getPitch() const;
    float getYaw() const;
    
    std::array<glm::vec4, 6> getFrustumPlanes(const glm::mat4& projection) const;
};

// Declare as inline to prevent multiple definition errors
inline glm::mat4 FPSViewRH(glm::vec3 eye, float pitchDeg, float yawDeg) {
    static FPSCamera camera;
    camera.setPosition(eye);
    camera.setRotation(pitchDeg, yawDeg);
    return camera.getViewMatrix();
}