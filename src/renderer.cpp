#include <GL/gl.h>
#include "../include/renderer.h"

void drawFloor() {
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for the floor
    glBegin(GL_QUADS);
        glVertex3f(-10.0f, 0.0f, -10.0f);
        glVertex3f(10.0f, 0.0f, -10.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);
    glEnd();

    // Draw grid lines
    glColor3f(1.0f, 1.0f, 1.0f); // White color for grid lines
    glBegin(GL_LINES);
    for (float i = -10.0f; i <= 10.0f; i += 1.0f) {
        glVertex3f(i, 0.0f, -10.0f);
        glVertex3f(i, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, i);
        glVertex3f(10.0f, 0.0f, i);
    }
    glEnd();
}

