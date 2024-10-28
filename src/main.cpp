#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <thread>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/renderer.h"
#include "../include/movement.h"
#include "../include/globals.h"
#include "../include/cursor.h"
#include <GL/freeglut.h> // Include this for text rendering

float lastFrameTime = 0.0f;
float lastTime = 0.0f; // Declare lastTime here
const float TARGET_FPS = 60.0f;
const float FRAME_DURATION = 1000.0f / TARGET_FPS; // in milliseconds

void displayFPS(float fps) {
    std::ostringstream oss;
    oss << "FPS: " << fps;
    std::cout << oss.str() << std::endl;
}

using namespace std::chrono;
int frameCount = 0;
float fps = 0.0f;

void setupProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)1920 / (float)1080, 0.1f, 100.0f); // Aspect ratio set to 1920:1080
    glMatrixMode(GL_MODELVIEW);
}


void renderText(const std::string& text, float x, float y) {
    glRasterPos2f(x, y); // Position for rendering
    for (char c : text) {
        // Use bitmap font to render each character
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Error initializing GLFW\n";
        return -1;
    }

    // Get the primary monitor
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    // Create a fullscreen window
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "MyOpenGLGame", monitor, NULL);    
    if (!window) {
        std::cerr << "Error creating GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 1920, 1080); // Adjust the viewport to match the window size

    glfwMakeContextCurrent(window);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error initializing GLEW\n";
        return -1;
    }

    // Initialize FreeGLUT
    int argc = 0;
    char** argv = nullptr;
    glutInit(&argc, argv); // Initialize FreeGLUT

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    
    // Lock the cursor
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    setupProjection(); // Set up projection once during initialization

    high_resolution_clock::time_point lastFrameTimePoint = high_resolution_clock::now();

    // Inside your main loop
    while (!glfwWindowShouldClose(window)) {
        auto frameStartTime = high_resolution_clock::now();

        // Frame timing logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrameTime;
        lastFrameTime = currentFrame;

        // Clear buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Camera setup
        glm::vec3 cameraPosition = glm::vec3(characterPosX, characterPosY + 1.5f, characterPosZ);
        glm::vec3 cameraTarget = cameraPosition + cameraFront;
        gluLookAt(
            cameraPosition.x, cameraPosition.y, cameraPosition.z,
            cameraTarget.x, cameraTarget.y, cameraTarget.z,
            0.0f, 1.0f, 0.0f
        );

        // Draw scene
        drawFloor();
        updateMovement(deltaTime); // This will now move based on camera direction

        // FPS display logic
        frameCount++;
        if (glfwGetTime() - lastTime >= 1.0) {
            fps = frameCount; // Update fps with the frame count
            displayFPS(fps); // Log FPS to console
            frameCount = 0;
            lastTime += 1.0;
        }

        // Render the FPS in the left corner
        std::ostringstream fpsStream;
        fpsStream << "FPS: " << fps; // Use updated fps value
        renderText(fpsStream.str(), -0.9f, 0.9f); // Adjust x, y as needed

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Frame capping logic
        auto frameEndTime = high_resolution_clock::now();
        duration<float, std::milli> frameDuration = frameEndTime - frameStartTime;

        if (frameDuration.count() < FRAME_DURATION) {
            std::this_thread::sleep_for(milliseconds(static_cast<int>(FRAME_DURATION - frameDuration.count())));
        }
    }

    // Clean up
    glfwTerminate();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    return 0;
}
