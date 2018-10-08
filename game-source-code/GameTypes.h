#ifndef GAMETYPES_H
#define GAMETYPES_H

enum class Direction{UP,DOWN,LEFT,RIGHT,UNKNOWN};
enum class ObjectID{SPACESHIP,BULLET,CENTIPEDE,CHEAD,EXPLOSION,MUSHROOM,MUSHROO,MUSHRO,MUSHR,SPIDER,EXPLOSION2,SCORPION_L,SCORPION_R};
enum class State{ALIVE, DEAD};


/**
 * @class vector2D
 * @date 08/10/2018
 * @file GameTypes.h
 * @brief This vector mimics a 2D vector that takes in an x and y value for
           representation of game objects in a 2D space.
 */
class vector2D
{
public:
    /**
     * @brief Default Constructor
     */
    vector2D(); 
    /**
     * @brief Constructor
     */
    vector2D(float x, float y);
    /**
     * @brief return vaue of x
     * @return value of x
     */
    float x() const; 
    /**
     * @brief returns value of y
     * @return value of y
     */
    float y() const; 
     /**
      * @brief sets the value of X
      * @param x value
      */
    void setX(float x); 
      /**
       * @brief sets y 
       * @param y value to be set
       */
    void setY(float y);
    /**
     * @brief overloading of == operator
     * @param other vector2D to be compared
     */
    bool operator ==(const vector2D& other) const;
    /**
     * @brief overloading of addition operator
     * @param other vector2D to be added
     */
    vector2D operator +(const vector2D & other) const;   
    /**
     * @brief  Overload subtraction operator
     * @param other vector2D to be subtracted
     */
    vector2D operator -(const vector2D& other) const; 
     /**
      * Destructor
      */
    ~vector2D();
     
private:
 float x_; //first element of vector2D
 float y_; //Second element of vector2D

};

#endif // GAMETYPES_H
