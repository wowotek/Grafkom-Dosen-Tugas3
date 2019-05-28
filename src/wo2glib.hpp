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

#define rect(x, y, width, height) \
    S_QUAD; \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()

#define rectm(x, y, width, height, mode) \
    glBegin(mode); \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()

#define circle(x, y, radius) \
    glEnable(GL_POINT_SMOOTH); \
    glPointSize(radius); \
    glBegin(GL_POINTS); \
        glVertex2f(x, y); \
    glEnd(); \
    glPointSize(1);

#define poly(x, y, size, sides, rotation) \
    float angleIncrement = (360.0f / sides) * M_PI / 180.0f; \
    glBegin(GL_TRIANGLE_FAN); \
        float angle = 0.0f + rotation; \
        for (size_t _k = 0; _k < sides; ++_k) { \
            glVertex2f(x + (size * cos(angle)), y + (size * sin(angle))); \
            angle += angleIncrement; \
        } \
    glEnd(); \

#define polym(x, y, size, sides, rotation, mode) \
    float _angleIncrement = 360.0f / sides; \
    _angleIncrement *= M_PI / 180.0f; \
    glBegin(mode); \
        float _angle = 0.0f + rotation; \
        for (size_t k = 0; k < sides; ++k) { \
            glVertex2f(x + (size * cos(_angle)), y + (size * sin(_angle))); \
            _angle += _angleIncrement; \
        } \
    glEnd(); \

#endif // WO2GLIB_HPP