// globals.cpp
#include "../include/globals.h"

float characterPosX = 0.0f; // Initialize X position
float characterPosY = 0.0f; // Initialize Y position
float characterPosZ = 5.0f; // Initialize Z position
float deltaTime = 0.0f; // Initialize delta time

const int WIDTH = 800;
const int HEIGHT = 600;


glm::vec3 cameraFront(0.0f, 0.0f, -1.0f); // Initialize cameraFront to face forward initially