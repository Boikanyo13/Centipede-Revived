#ifndef GAMETYPES_H
#define GAMETYPES_H

enum class Direction{UP,DOWN,LEFT,RIGHT,UNKNOWN};
enum class ObjectID{SPACESHIP,BULLET,CENTIPEDE,CHEAD,EXPLOSION,MUSHROOM,MUSHROO,MUSHRO,MUSHR,SPIDER,EXPLOSION2};
enum class State{ALIVE, DEAD};

//This vector mimics a 2D vector that takes in an x and y value for
//representation of game objects in a 2D space.
 
class vector2D
{
public:
    vector2D(); 
    vector2D(float x, float y);
    float x() const;   //returns x
    float y() const;   //returns y
    void setX(float x);   
    void setY(float y);
    bool operator ==(const vector2D& other) const;
    vector2D operator +(const vector2D & other) const;   //Overload addition operator
    vector2D operator -(const vector2D& other) const;    //Overload subtraction operator
    ~vector2D();
     
private:
 float x_; //first element of vector2D
 float y_; //Second element of vector2D

};

#endif // GAMETYPES_H
