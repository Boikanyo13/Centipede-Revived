#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameTypes.h"
#include "Constants.h"


class ObjectOutOfBounds{};
/**
 * @class GameObject 
 * @author bvrad
 * @date 08/10/2018
 * @file GameObject.h
 * @brief This is the parent to all of the gameObject, it models an entity in a 2D space
 */
class GameObject
{
public:
    /**
     * @brief Ensures the creation of a GameObjec
     * @param position
     */
    GameObject(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    /**
     * @brief set Position of object in the Game
     * @param position of the object
     */
    void setPosition(const vector2D& position);
    /**
     * @brief set the size of the object
     * @param size of the GameObject
     */
    void setSize(const vector2D& size){size_ = size;}
    /**
     * @brief set moving speed of the object
     * @param speed of the GameObject
     */
    void setSpeed(float speed){speed_ = speed;}
    /**
     * @brief set the object ID
     * @param oID ID of the Object
     */
    void setObjectID(ObjectID oID){objectID_ = oID;}
    /**
     * @brief Indicate current state of object in the game(dead or alive?)
     * @param state of the GameObject
     */
    void updateState(State state);
    /**
     * @brief Move the object in the window
     */
    virtual void Move() = 0;
    
    /**
     * @brief Check the existance of the object in the Game
     * @return boolean isDead
     */
    bool isDead() const {return isDead_;}
    /**
     * @brief Get speed of the object
     * @return speed of the object
     */
    float getSpeed() const {return speed_;}
    /**
     * @brief Get position of the object
     * @return position of the GameObject
     */
    vector2D getPosition() const {return position_;}
    /**
     * @brief Get size of the object
     * @return size of object
     */
    vector2D getSize() const {return size_;}
    /**
     * @brief get ID of the object
     * @return ID of the object
     */
    ObjectID ID() const{return objectID_;}
    /**
     * @brief Reset object to inital conditions
     */
    virtual void reset() = 0;
    /**
     * @brief Action taken on collision
     */
    virtual void collisionResponse() = 0;
    /**
     * @brief destroy game object
     */
    virtual ~GameObject(){};

private:
    //GameObject Properties
    vector2D size_;
    vector2D position_;
    float speed_;
    ObjectID objectID_;
    bool isDead_;
};

#endif // GAMEOBJECT_H
