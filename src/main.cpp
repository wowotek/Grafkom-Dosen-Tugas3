#include <iostream>
#include "wo2glib.hpp"
#include "wo2util.hpp"

#include "entities.hpp"

void renderDisplay(void);
void init(void);

Entities shape1(100, 100, 1, 0, 0, 2);

int main(int argc, char ** argv){
    initGLWindow(640, 480, 2880, 540, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB);
    init();
    shape1.changeBehavior(2);
    glutMainLoop();

    return 0;
}

void init(void){
    glutDisplayFunc(renderDisplay);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    shape1.draw();

    glColor3f(1, 0, 0);
    poly(300, 250, 200, 150000, 1);

    glutSwapBuffers();
}