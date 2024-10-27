#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <thread>

#include "../include/renderer.h"
#include "../include/movement.h"
#include "../include/globals.h"
#include "../include/cursor.h"

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
    gluPerspective(45.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Error initializing GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MyOpenGLGame", NULL, NULL);
    if (!window) {
        std::cerr << "Error creating GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error initializing GLEW\n";
        return -1;
    }

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
        updateMovement(); // This will now move based on camera direction

        // FPS display logic
        frameCount++;
        if (glfwGetTime() - lastTime >= 1.0) {
            displayFPS(frameCount);
            frameCount = 0;
            lastTime += 1.0;
        }

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
