#include "canvas.hpp"

Canvas::Canvas(){

}

void Canvas::draw(void){
    for(size_t i=0; i<coordinates.size(); i++){
        point(coordinates[i].x, coordinates[i].y);
    }
}

void Canvas::add_coordinate(vec2f current_Coordinate){
    coordinates.push_back(current_Coordinate);
}