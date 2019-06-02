#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <iostream>
#include "../util/wo2glib.hpp"
#include "../util/wo2util.hpp"

class Entities{
    private:
        GLfloat posX, posY;
        GLfloat r, g, b;
        GLfloat size;

        // 0 = Square
        // 1 = Circle
        // 2 = Pentagon
        GLint polygon_type;

        // 0 = normal Color
        // 1 = White
        // 2 = line only
        GLint fillState = 0;

        // true = Clock-Wise
        // false = Counter-Clock-Wise
        GLboolean rotationDirection = true;
        GLfloat rotation = 0;

        void drawFill(void);
        void drawWhite(void);
        void drawLine(void);

    public:
        Entities(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLint);

        void draw(void);
        void update(void);

        void changeFillType(GLint);
        void changeRotationDirection(GLboolean);
};

#endif