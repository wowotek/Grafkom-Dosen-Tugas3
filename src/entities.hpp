#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <iostream>
#include "wo2glib.hpp"
#include "wo2util.hpp"

class Entities{
    private:
        GLfloat posX, posY;
        GLfloat r, g, b;

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
        Entities(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLint);

        void draw(void);
        void update(void);

        void changeFillType(GLint);
        void changeRotationDirection(GLboolean);
};

Entities::Entities(GLfloat initPosX, GLfloat initPosY, GLfloat initR, GLfloat initG, GLfloat initB, GLint POLYGON_TYPE){
    posX = initPosX;
    posY = initPosY;

    r = initR;
    g = initG;
    b = initB;

    polygon_type = POLYGON_TYPE;
}

void Entities::drawFill(void){
    glColor3f(r, g, b);

    switch(polygon_type){
        default: break;
        case 0:
            poly(posX, posY, 50, 4, rotation);
            break;
        case 1:
            poly(posX, posY, 50, 1500, rotation);
            break;
        case 2:
            poly(posX, posY, 50, 5, rotation);
            break;
    }
}

void Entities::drawWhite(void){
    glColor3f(1, 1, 1);

    switch(polygon_type){
        default: break;
        case 0:
            poly(posX, posY, 50, 4, rotation);
            break;
        case 1:
            poly(posX, posY, 50, 1500, rotation);
            break;
        case 2:
            poly(posX, posY, 50, 5, rotation);
            break;
    }
}

void Entities::drawLine(void){
    glColor3f(1, 1, 1);

    switch(polygon_type){
        default: break;
        case 0:
            polym(posX, posY, 50, 4, rotation, GL_LINE_LOOP);
            break;
        case 1:
            polym(posX, posY, 50, 1500, rotation, GL_LINE_LOOP);
            break;
        case 2:
            polym(posX, posY, 50, 5, rotation, GL_LINE_LOOP);
            break;
    }
}

void Entities::draw(void){
    switch(fillState){
        default: break;
        case 0:
            drawFill();
            break;
        case 1:
            drawWhite();
            break;
        case 2:
            drawLine();
            break;
    }
}

void Entities::update(void){
    if(rotationDirection == true){
        rotation += 0.01f;
    } else {
        rotation -= 0.01f;
    }

    if(rotation >= 360.0f || rotation <= -360.0f){
        rotation = 0.0f;
    }
}

void Entities::changeFillType(GLint fillType){
    if(fillType == 0 || fillType == 1 || fillType == 2){
        fillState = fillType;
    } else {
        std::cout << "ILLEGAL BEHAVIOR CHANGES, SKIPPING..." << std::endl;
        fflush(stdout);
    }
}

void Entities::changeRotationDirection(GLboolean rotDirection){
    rotationDirection = rotDirection;
}

#endif