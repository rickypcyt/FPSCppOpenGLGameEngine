#ifndef GLOBALS_H
#define GLOBALS_H

#include <glm/glm.hpp>

extern const int WIDTH;   // Set your desired width
extern const int HEIGHT;  // Set your desired height

extern float characterPosX; // X position of the character
extern float characterPosY; // Y position of the character
extern float characterPosZ; // Z position of the character
extern float deltaTime; // Time since last frame

extern glm::vec3 cameraFront; // Declare cameraFront as an external variable

#endif // GLOBALS_H
