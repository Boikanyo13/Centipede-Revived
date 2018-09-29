#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameTypes.h"
#include "Constants.h"


class ObjectOutOfBounds{};

class GameObject
{
public:
    GameObject(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    //set Position of object in the Game
    void setPosition(const vector2D& position);
    //set the size of the object
    void setSize(const vector2D& size){size_ = size;}
    //set moving speed of the object
    void setSpeed(float speed){speed_ = speed;}
    //set the object ID
    void setObjectID(ObjectID oID){objectID_ = oID;}
    //Indicate current state of object in the game(dead or alive?)
    void updateState(State state);
    //Move the object in the window
    virtual void Move(Direction direction) = 0;
    //Check the existance of the object in the Game
    bool isDead() const {return isDead_;}
    //Get speed of the object
    float getSpeed() const {return speed_;}
    //Get position of the object
    vector2D getPosition() const {return position_;}
    //Get size of the object
    vector2D getSize() const {return size_;}
    //get ID of the object
    ObjectID ID() const{return objectID_;}
    //Reset object to inital conditions
    virtual void reset() = 0;
    virtual ~GameObject(){};

private:
    vector2D size_;
    vector2D position_;
    float speed_;
    ObjectID objectID_;
    bool isDead_;
};

#endif // GAMEOBJECT_H
