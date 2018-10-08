#ifndef SCORPION_H
#define SCORPION_H
#include "GameObject.h"

/**
 * @class Scorpion
 * @date 08/10/2018
 * @file Scorpion.h
 * @brief Derived from GameObject class, the Scorpion class models the representation of a Scorpion in 2D
 */

class Scorpion : public GameObject
{
public:
   /**
      * @brief Constructor of the Scorpion Class
      * @param size of the Scorpion
      * @param position of the Scorpion
      * @param speed of the Scorpion
      * @param objectid ID of the Scorpion
      */
    Scorpion(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    /**
     * @brief Take action if Scorpion is shot
     */
    virtual void collisionResponse() override;
    /**
     * @brief Move function from parent
     */
    virtual void Move() override;
    /**
     * @brief Reset Scorpion to intial conditions
     */
    virtual void reset() override;
    /**
     * @brief Destroy the Scorpion Object
     
     */
    virtual ~Scorpion(){}

private:
    /**
     * @brief move Scorpion to the left direction
     */
    void moveLeft();
     /**
     * @brief move Scorpion to the right direction
     */
    void moveRight();
     /**
     * @brief reset the scorpion to start at the right
     */
    void rightReset();
    /**
     * @brief reset the scorpion to start at the left
     */
    void leftReset();
    //controller Boolean
    bool forward_ = true;

};

#endif // SCORPION_H
