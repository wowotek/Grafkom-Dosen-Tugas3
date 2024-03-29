#include "canvas.hpp"

void Canvas::draw(void){
    for(size_t i=0; i<coordinates.size(); i++){
        glColor3f(1, 1, 1);
        point(coordinates[i].x, coordinates[i].y);
    }
}

void Canvas::add_coordinate(vec2f current_Coordinate){
    for(size_t i = 0; i<coordinates.size(); i++){
        if(current_Coordinate.x == coordinates[i].x && current_Coordinate.y == coordinates[i].y){
            return; // CHECK IF THIS SPECIFIC COORDINATES IS EXIST
        }
    }

    coordinates.push_back(current_Coordinate);
}

void Canvas::print_all_coordinate(void){
    for(size_t i=0; i<coordinates.size(); i++){
        std::cout << coordinates[i].x << ", ";
        std::cout << coordinates[i].y << std::endl;
    }
}