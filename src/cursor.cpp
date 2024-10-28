#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/cursor.h"
#include "../include/globals.h"

float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    static double lastX = WIDTH / 2.0;
    static double lastY = HEIGHT / 2.0;

    double xoffset = xpos - lastX; // Calculate x offset
    double yoffset = lastY - ypos; // Calculate y offset (reverse the y-axis)
    lastX = xpos;
    lastY = ypos;

    const float mouseScaleFactor = 0.1f; // Adjust this factor for finer control

yaw += xoffset * sensitivity * mouseScaleFactor;
pitch += yoffset * sensitivity * mouseScaleFactor;


    // Constrain pitch to avoid flipping the camera
    if (pitch > 89.0f) {
        pitch = 89.0f;
    }
    if (pitch < -89.0f) {
        pitch = -89.0f;
    }

    // Update the camera direction based on yaw and pitch
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}
