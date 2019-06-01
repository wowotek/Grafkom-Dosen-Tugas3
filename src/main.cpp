#include "objects/entities.cpp"

void renderDisplay(void);
void init(void);
void updateScreen(GLint);

Entities   persegi(-0.75, 0, 0.25, 1, 0, 0, 0);
Entities lingkaran(0, 0, 0.25, 0, 1, 0, 1);
Entities segi_lima(0.75, 0, 0.25, 0, 0, 1, 2);

#define WIDTH 640
#define HEIGHT 480

float aspect = 1.0; 

int main(int argc, char ** argv){
    initGLWindow(WIDTH, HEIGHT, 2880, 540, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB);
    aspect = WIDTH/HEIGHT;

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
    gluOrtho2D(-aspect, aspect, -1.0, 1.0);
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
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    aspect = (float)width / (float)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-aspect, aspect, -1.0, 1.0);

    persegi.draw();
    lingkaran.draw();
    segi_lima.draw();

    glutSwapBuffers();
}   