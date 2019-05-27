#ifndef WO2GLIB_HPP
#define WO2GLIB_HPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

//--------------------------------------------- INITIALIZER HELPER
#define initGLWindow(width, height, name, switches) \
    glutInit(&argc, argv); \
    glutInitDisplayMode(switches); \
    glutInitWindowSize(width, height); \
    glutCreateWindow(name)

//--------------------------------------------- SHORTHAND FOR glBegin's MODE
#define S_POINT glBegin(GL_POINTS)
#define S_LINE glBegin(GL_LINES)
#define S_TRIANGLE glBegin(GL_TRIANGLE_FAN)
#define S_QUAD glBegin(GL_QUADS)
#define S_POLYGON glBegin(GL_POLYGON)

#define poly(x, y, size, sides, rotation) \
    float angleIncrement = 360.0f / sides; \
    angleIncrement *= M_PI / 180.0f; \
    glBegin(GL_TRIANGLE_FAN); \
        float angle = 0.0f; \
        for (size_t k = 0; k < sides; ++k) { \
            glVertex2f(x + (size * cos(angle + rotation)), y + (size * sin(angle + rotation))); \
            angle += angleIncrement; \
        } \
    glEnd(); \

//--------------------------------------------- PRIMITIVE 2D SHAPE
#define rect(x, y, width, height) \
    S_QUAD; \
        glVertex2f(x, y); glVertex2f(x + width, y); \
        glVertex2f(x + width, y + height); glVertex2f(x, y + height); \
    glEnd()

#define circle(x, y, radius) \
    glEnable(GL_POINT_SMOOTH); \
    glPointSize(radius); \
    glBegin(GL_POINTS); \
        glVertex2f(x, y); \
    glEnd()

#define line(x1, y1, x2, y2) \
    S_LINE; \
        glVertex2f(x1, y1); glVertex2f(x2, y2); \
    glEnd()


#endif // WO2GLIB_HPP