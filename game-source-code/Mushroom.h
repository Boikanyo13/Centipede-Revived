#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <memory>
#include "GameObject.h"
#include "Csegment.h"

class NonMovableObject{};

/**
 * @class Mushroom
 * @date 08/10/2018
 * @file Mushroom.h
 * @brief Derived from GameObject, the class models the representation of a Mushroom object in the Game Space
 */

class Mushroom: public GameObject{
public:
    /**
      * @brief Constructor of the Mushroom Class
      * @param size of the Mushroom
      * @param position of the Mushroom
      * @param speed of the Mushroom
      * @param objectid ID of the Mushroom
      */
    Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    /**
     * @brief Take action if Mushroom is shot
     */
    virtual void collisionResponse() override;
    /**
     * @brief Return the number of lives the Mushroom has
     * @return number of lives
     */
    int lives() const {return lives_; }
    /**
     * @brief Move function from parent
     */
    virtual void Move() override{throw NonMovableObject{}; } 
    /**
     * @brief Reset Mushroom to intial conditions
     */
    virtual void reset() override;
    /**
     * @brief Destroy Mushroom Object
     */
    virtual ~Mushroom(){}
    
private:
    //Numner of lives
    int lives_ = 4;

};

#endif // MUSHROOM_H