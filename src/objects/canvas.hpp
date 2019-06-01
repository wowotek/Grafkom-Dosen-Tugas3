#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <iostream>
#include "../util/wo2glib.hpp"
#include "../util/wo2util.hpp"

class Canvas {
    private:
        std::vector<vec2f> coordinates;
    
    public:
        Canvas();
        void add_coordinate(vec2f);
        void pop_coordinate();
        void draw(void);
};

#endif