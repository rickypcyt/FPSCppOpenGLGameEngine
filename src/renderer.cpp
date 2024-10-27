#include <GL/gl.h>
#include "../include/renderer.h"

void drawFloor() {
    // Draw the floor
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for the floor
    glBegin(GL_QUADS);
        glVertex3f(-10.0f, 0.0f, -10.0f);
        glVertex3f(10.0f, 0.0f, -10.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);
    glEnd();

    // Draw grid lines on the floor
    glColor3f(1.0f, 1.0f, 1.0f); // White color for grid lines
    glBegin(GL_LINES);
    for (float i = -10.0f; i <= 10.0f; i += 1.0f) {
        glVertex3f(i, 0.0f, -10.0f);
        glVertex3f(i, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, i);
        glVertex3f(10.0f, 0.0f, i);
    }
    glEnd();

    // Draw a wall for reference
    glColor3f(0.7f, 0.3f, 0.3f); // Reddish color for the wall
    glBegin(GL_QUADS);
        glVertex3f(-1.0f, 0.0f, -5.0f);  // Bottom left
        glVertex3f(1.0f, 0.0f, -5.0f);   // Bottom right
        glVertex3f(1.0f, 3.0f, -5.0f);   // Top right
        glVertex3f(-1.0f, 3.0f, -5.0f);  // Top left
    glEnd();
}
