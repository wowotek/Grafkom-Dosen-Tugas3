#include <iostream>
#include "wo2glib.hpp"
#include "wo2util.hpp"

#include "entities.hpp"

void renderDisplay(void);
void init(void);
void updateScreen(GLint);

Entities   persegi(160, 240, 1, 0, 0, 0);
Entities lingkaran(320, 240, 0, 1, 0, 1);
Entities segi_lima(480, 240, 0, 0, 1, 2);

int main(int argc, char ** argv){
    initGLWindow(640, 480, 2880, 540, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB);
    init();

    segi_lima.changeRotationDirection(false);

    glutMainLoop();

    return 0;
}

void init(void){
    glutDisplayFunc(renderDisplay);
    updateScreen(TO_FPS(120));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void updateScreen(GLint time){
    persegi.update();
    lingkaran.update();
    segi_lima.update();

    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    persegi.draw();
    lingkaran.draw();
    segi_lima.draw();

    glutSwapBuffers();
}   