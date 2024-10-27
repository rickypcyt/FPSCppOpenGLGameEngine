#ifndef GLOBALS_H
#define GLOBALS_H

#include <glm/glm.hpp>

extern float characterPosX;
extern float characterPosY;
extern float characterPosZ;
extern float deltaTime;

extern const int WIDTH;
extern const int HEIGHT;

extern glm::vec3 cameraFront; // Camera front vector
extern float sensitivity; // Mouse sensitivity

#endif // GLOBALS_H
