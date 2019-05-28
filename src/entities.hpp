#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "wo2glib.hpp"
#include "wo2util.hpp"

#define FILL_COLOR  0
#define WHITE_COLOR 1
#define LINE_ONLY   2

class Entities{
    private:
        GLfloat posX, posY;
        GLfloat r, g, b;
        GLint polygon_type;

        // 0 = normal Color
        // 1 = White
        // 2 = line only
        GLint currentState = 0;

        void drawFill(void);
        void drawWhite(void);
        void drawLine(void);
    public:
        Entities(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLint);

        void draw(void);
        void changeBehavior(GLint behavior);
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
        case 0: // A square
            rect(posX, posY, 50, 50);
            break;
        case 1: // A circle
            circle(posX, posY, 100);
            break;
        case 2: // A pentagon
            poly(posX, posY, 50, 5, 1);
            break;
    }
}

void Entities::drawWhite(void){
    glColor3f(1, 1, 1);

    switch(polygon_type){
        default: break;
        case 0: // A square
            rect(posX, posY, 50, 50);
            break;
        case 1: // A circle
            circle(posX, posY, 100);
            break;
        case 2: // A pentagon
            poly(posX, posY, 50, 5, 0);
            break;
    }
}

void Entities::drawLine(void){
    glColor3f(1, 1, 1);

    switch(polygon_type){
        default: break;
        case 0: // A square
            rectm(posX, posY, 50, 50, GL_LINE_LOOP);
            break;
        case 1: // A circle
            circle(posX, posY, 100);
            break;
        case 2: // A pentagon
            polym(posX, posY, 50, 5, 0, GL_LINE_LOOP);
            break;
    }
}

void Entities::draw(void){
    switch(currentState){
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

void Entities::changeBehavior(GLint behavior){
    if(behavior == 0 || behavior == 1 || behavior == 2){
        currentState = behavior;
    } else {
        std::cerr << "ILLEGAL BEHAVIOR CHANGES, SKIPPING..." << std::endl;
    }
}

#endif