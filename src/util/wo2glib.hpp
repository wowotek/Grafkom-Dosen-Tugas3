#ifndef WO2GLIB_HPP
#define WO2GLIB_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

//--------------------------------------------- INTERNAL DEFINITION
#define DEFAULT_POINT_SIZE 1
#define DEFAULT_WINDOW_POS_X 0
#define DEFAULT_WINDOW_POS_Y 0

//--------------------------------------------- INITIALIZER HELPER
#define initGLWindow(width, height, posX, posY, window_name, display_mode_switches) \
    glutInit(&argc, argv); \
    glutInitDisplayMode(display_mode_switches); \
    glutInitWindowSize(width, height); \
    glutInitWindowPosition(posX, posY); \
    glutCreateWindow(window_name)

//--------------------------------------------- SHORTHAND FOR glBegin's MODE
#define S_POINT glBegin(GL_POINTS)
#define S_LINE glBegin(GL_LINES)
#define S_TRIANGLE glBegin(GL_TRIANGLE_FAN)
#define S_QUAD glBegin(GL_QUADS)
#define S_POLYGON glBegin(GL_POLYGON)

//--------------------------------------------- PRIMITIVE 2D SHAPE
#define line(x1, y1, x2, y2) \
    S_LINE; \
        glVertex2f(x1, y1); glVertex2f(x2, y2); \
    glEnd()

inline __attribute__((__always_inline__)) void
rect (float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

/*
inline __attribute_noinline__ void
rect (float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}
*/
/*
#define rect(x, y, width, height) \
    S_QUAD; \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()
*/

#define rectm(x, y, width, height, mode) \
    glBegin(mode); \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()

void polym(GLfloat x, GLfloat y, GLfloat size, GLfloat sides, GLfloat rotation, GLenum SHAPE_MODE){
    float angleIncrement = (360.0f / sides) * M_PI / 180.0f;
    glBegin(SHAPE_MODE);
        float angle = 0.0f - rotation;
        for (size_t _k = 0; _k < sides; ++_k) {
            glVertex2f(x + (size * cos(angle)), y + (size * sin(angle)));
            angle += angleIncrement;
        }
    glEnd();
}

#define poly(x, y, size, sides, rotation) \
    polym(x, y, size, sides, rotation, GL_TRIANGLE_FAN)

#define circlem(x, y, radius, SHAPE_MODE) \
    polym(x, y, radius, 720, 0, SHAPE_MODE)

#define circle(x, y, radius) \
    poly(x, y, radius, 32, 0)

//--------------------------------------------- Vectors


#endif