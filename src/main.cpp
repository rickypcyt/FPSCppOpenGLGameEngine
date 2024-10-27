#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <thread>
#include "../include/renderer.h"
#include "../include/movement.h"
#include "../include/globals.h"

float lastFrameTime = 0.0f;

const int TARGET_FPS = 60;
const float FRAME_DURATION = 1000.0f / TARGET_FPS; // in milliseconds

void displayFPS(float fps) {
    std::ostringstream oss;
    oss << "FPS: " << fps;
    std::cout << oss.str() << std::endl;
}

using namespace std::chrono;
high_resolution_clock::time_point lastTime = high_resolution_clock::now();
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

    setupProjection(); // Set up projection once during initialization

    high_resolution_clock::time_point lastFrameTimePoint = high_resolution_clock::now();

    while (!glfwWindowShouldClose(window)) {
        auto currentFrameTimePoint = high_resolution_clock::now();
        duration<float> elapsedTime = currentFrameTimePoint - lastFrameTimePoint;
        float elapsedMillis = elapsedTime.count() * 1000.0f;

        // Frame rate cap logic
        if (elapsedMillis >= FRAME_DURATION) {
            lastFrameTimePoint = currentFrameTimePoint;

            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrameTime;
            lastFrameTime = currentFrame;

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Update view transformation only when necessary
            glLoadIdentity();
            gluLookAt(characterPosX, 1.0f, characterPosZ,
                      characterPosX, 1.0f, characterPosZ - 1.0f,
                      0.0f, 1.0f, 0.0f);

            drawFloor(); // Draw the floor
            updateMovement(); // Update movement based on input

            frameCount++;

            // Get the current time
            auto currentTime = high_resolution_clock::now();
            duration<float> deltaTimeFPS = currentTime - lastTime;

            // Update FPS every second
            if (deltaTimeFPS.count() >= 1.0f) {
                fps = frameCount;
                frameCount = 0;
                lastTime = currentTime;
                displayFPS(fps);
            }

            glfwSwapBuffers(window);
        } else {
            // Sleep for the remaining time to achieve the target frame duration
            std::this_thread::sleep_for(milliseconds(static_cast<int>(FRAME_DURATION - elapsedMillis)));
        }

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
