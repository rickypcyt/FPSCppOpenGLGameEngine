#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/cursor.h"
#include "../include/globals.h"

// Camera direction angles
float yaw = -90.0f; // Facing forward initially
float pitch = 0.0f;
float lastX = WIDTH / 2.0f; // Start with the cursor in the center
float lastY = HEIGHT / 2.0f;
bool firstMouse = true; // To prevent sudden camera jumps on the first frame

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false; // Set to false after first usage to avoid jump
    }

    // Calculate offsets
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Inverted Y-axis
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // Adjust this sensitivity value
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    // Update yaw and pitch
    yaw += xoffset;
    pitch += yoffset;

    // Constrain pitch to prevent flipping
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    // Calculate the new front vector based on yaw and pitch
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}
