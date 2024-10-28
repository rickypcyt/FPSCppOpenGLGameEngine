#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/cursor.h"
#include "../include/globals.h"

float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += glm::radians(xoffset);
    pitch += glm::radians(yoffset);

    if (pitch > glm::radians(89.0f)) pitch = glm::radians(89.0f);
    if (pitch < glm::radians(-89.0f)) pitch = glm::radians(-89.0f);

    glm::vec3 direction;
    direction.x = cos(yaw) * cos(pitch);
    direction.y = sin(pitch);
    direction.z = sin(yaw) * cos(pitch);
    cameraFront = glm::normalize(direction);
}
