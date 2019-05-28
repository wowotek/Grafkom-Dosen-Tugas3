#include <iostream>
#include "wo2glib.hpp"
#include "wo2util.hpp"

void renderDisplay(void);

int main(int argc, char ** argv){
    initGLWindow(640, 480, 3840, 0, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB);
    
    glutDisplayFunc(renderDisplay);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    
    glutMainLoop();

    return 0;
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    poly(300, 250, 200, 5, 1);

    glutSwapBuffers();
}