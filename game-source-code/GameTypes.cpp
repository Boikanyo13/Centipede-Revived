#include "GameTypes.h"


vector2D::vector2D(float x, float y):x_(x),y_(y){}

void vector2D::setX(float x){ x_ =  x; }

void vector2D::setY(float y){ y_ =  y; }

float vector2D::x() const { return x_;}

float vector2D::y() const { return y_;}

vector2D vector2D::operator +(const vector2D & other){
    
    return(vector2D{x_+other.x(),y_+other.y()});
    }

vector2D vector2D::operator -(const vector2D & other){
    
    return(vector2D{x_-other.x(),y_-other.y()});
    }
    
vector2D::~vector2D(){}