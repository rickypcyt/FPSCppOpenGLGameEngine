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

double lastTime =0.0f;

const int TARGET_FPS = 60;
const float FRAME_DURATION = 1000.0f / TARGET_FPS; // in milliseconds

void displayFPS(float fps) {
    std::ostringstream oss;
    oss << "FPS: " << fps;
    std::cout << oss.str() << std::endl;
}

using namespace std::chrono;
high_resolution_clock::time_point lastTimeClock = high_resolution_clock::now();
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

    // Rendering loop
    // Rendering loop
while (!glfwWindowShouldClose(window)) {
    // Start measuring frame time
    auto frameStartTime = high_resolution_clock::now();

    // Frame timing logic to calculate deltaTime if using a non-fixed approach
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrameTime;
    lastFrameTime = currentFrame;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Camera position (adjusted for a smoother view)
    gluLookAt(
        characterPosX, 1.5f + characterPosY, characterPosZ + 5.0f, // Position slightly above and behind the character
        characterPosX, 1.0f + characterPosY, characterPosZ,        // Look toward where the character is facing
        0.0f, 1.0f, 0.0f                                          // Up direction
    );

    // Draw scene
    drawFloor();
    updateMovement();

    // Display FPS every second
    frameCount++;
    if (glfwGetTime() - lastTime >= 1.0) {
        displayFPS(frameCount);
        frameCount = 0;
        lastTime += 1.0;
    }

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();

    // Measure the elapsed frame time and cap at 60 FPS
    auto frameEndTime = high_resolution_clock::now();
    duration<float, std::milli> frameDuration = frameEndTime - frameStartTime;

    if (frameDuration.count() < FRAME_DURATION) {
        std::this_thread::sleep_for(milliseconds(static_cast<int>(FRAME_DURATION - frameDuration.count())));
    }
}



    glfwTerminate();
    return 0;
}
