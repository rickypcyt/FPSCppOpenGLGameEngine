#include "../include/camera.h"

void FPSCamera::updateVectors() {
    // Ensure pitch is constrained
    pitch = glm::clamp(pitch, MIN_PITCH, MAX_PITCH);
    
    // Calculate the forward vector
    float cosPitch = std::cos(pitch);
    float sinPitch = std::sin(pitch);
    float cosYaw = std::cos(yaw);
    float sinYaw = std::sin(yaw);
    
    forward = glm::normalize(glm::vec3(
        sinYaw * cosPitch,
        -sinPitch,
        cosYaw * cosPitch
    ));
    
    // Calculate right vector using world up (0,1,0)
    right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    
    // Calculate up vector to ensure orthogonality
    up = glm::normalize(glm::cross(right, forward));
}

FPSCamera::FPSCamera(const glm::vec3& pos, float pitchDeg, float yawDeg)
    : position(pos)
    , pitch(pitchDeg * PI / 180.0f)
    , yaw(yawDeg * PI / 180.0f) {
    updateVectors();
}

glm::mat4 FPSCamera::getViewMatrix() const {
    glm::mat4 viewMatrix(1.0f);
    
    viewMatrix[0][0] = right.x;
    viewMatrix[1][0] = right.y;
    viewMatrix[2][0] = right.z;
    
    viewMatrix[0][1] = up.x;
    viewMatrix[1][1] = up.y;
    viewMatrix[2][1] = up.z;
    
    viewMatrix[0][2] = forward.x;
    viewMatrix[1][2] = forward.y;
    viewMatrix[2][2] = forward.z;
    
    viewMatrix[3][0] = -glm::dot(right, position);
    viewMatrix[3][1] = -glm::dot(up, position);
    viewMatrix[3][2] = -glm::dot(forward, position);
    
    return viewMatrix;
}

glm::mat4 FPSCamera::getViewMatrixQuaternion() const {
    glm::quat rotation = glm::quat(glm::vec3(pitch, yaw, 0.0f));
    glm::mat4 rotationMatrix = glm::mat4_cast(rotation);
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -position);
    return rotationMatrix * translationMatrix;
}

void FPSCamera::setPosition(const glm::vec3& pos) {
    position = pos;
}

void FPSCamera::setRotation(float pitchDeg, float yawDeg) {
    pitch = pitchDeg * PI / 180.0f;
    yaw = yawDeg * PI / 180.0f;
    updateVectors();
}

void FPSCamera::rotate(float deltaPitch, float deltaYaw) {
    pitch += deltaPitch * PI / 180.0f;
    yaw += deltaYaw * PI / 180.0f;
    updateVectors();
}

void FPSCamera::move(const glm::vec3& offset) {
    position += right * offset.x + up * offset.y + forward * offset.z;
}

glm::vec3 FPSCamera::getPosition() const { return position; }
glm::vec3 FPSCamera::getForward() const { return forward; }
glm::vec3 FPSCamera::getRight() const { return right; }
glm::vec3 FPSCamera::getUp() const { return up; }
float FPSCamera::getPitch() const { return pitch * 180.0f / PI; }
float FPSCamera::getYaw() const { return yaw * 180.0f / PI; }

std::array<glm::vec4, 6> FPSCamera::getFrustumPlanes(const glm::mat4& projection) const {
    glm::mat4 viewProj = projection * getViewMatrix();
    std::array<glm::vec4, 6> planes;
    
    planes[0] = glm::vec4(viewProj[3] + viewProj[0]);  // Left
    planes[1] = glm::vec4(viewProj[3] - viewProj[0]);  // Right
    planes[2] = glm::vec4(viewProj[3] + viewProj[1]);  // Bottom
    planes[3] = glm::vec4(viewProj[3] - viewProj[1]);  // Top
    planes[4] = glm::vec4(viewProj[3] + viewProj[2]);  // Near
    planes[5] = glm::vec4(viewProj[3] - viewProj[2]);  // Far
    
    for (auto& plane : planes) {
        float len = glm::length(glm::vec3(plane));
        if (len > 0.0f) {
            plane /= len;
        }
    }
    
    return planes;
}