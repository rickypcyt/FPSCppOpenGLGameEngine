#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 FPSViewRH(glm::vec3 eye, float pitch, float yaw) {
    // Calculate the cosine and sine of the pitch and yaw angles
    float cosPitch = cos(pitch);
    float sinPitch = sin(pitch);
    float cosYaw = cos(yaw);
    float sinYaw = sin(yaw);

    // Calculate the forward (z) direction based on yaw and pitch
    glm::vec3 zaxis = glm::normalize(glm::vec3(sinYaw * cosPitch, -sinPitch, cosYaw * cosPitch));
    // Calculate the right (x) direction
    glm::vec3 xaxis = glm::normalize(glm::vec3(cosYaw, 0, -sinYaw));
    // Calculate the up (y) direction using the cross product to ensure orthogonality
    glm::vec3 yaxis = glm::normalize(glm::cross(zaxis, xaxis));

    // Construct the view matrix
    glm::mat4 viewMatrix = {
        glm::vec4(xaxis, 0.0f),  // Right
        glm::vec4(yaxis, 0.0f),  // Up
        glm::vec4(zaxis, 0.0f),   // Forward
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f) // Last row for the homogeneous coordinate
    };

    // Translate the view matrix by the eye position
    // Note: This translates the world coordinates to camera space
    viewMatrix[3] = glm::vec4(-glm::dot(xaxis, eye), -glm::dot(yaxis, eye), -glm::dot(zaxis, eye), 1.0f);

    return viewMatrix;
}
