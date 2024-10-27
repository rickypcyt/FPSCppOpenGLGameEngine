#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <GLFW/glfw3.h>

// External variables for movement speeds
extern GLfloat moveSpeed;   
extern GLfloat moveSpeedX;  
extern GLfloat moveSpeedY;  

// Jump variables
extern bool isJumping;  // Track whether the character is currently jumping
extern GLfloat jumpHeight; // Maximum height of the jump
extern GLfloat verticalVelocity; // Current vertical velocity

// Window dimensions (defined elsewhere)
extern const GLint WIDTH;   
extern const GLint HEIGHT;  

extern float characterPosX, characterPosY, characterPosZ; // Define in a shared header
extern float deltaTime;
extern float moveSpeed; // Ensure it's also declared here
extern bool isJumping;
extern float verticalVelocity;


// Function declarations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void updateMovement();
void updateCamera();

#endif // MOVEMENT_H
