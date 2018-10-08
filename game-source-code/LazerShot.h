#ifndef LAZERSHOT_H
#define LAZERSHOT_H
#include "GameObject.h"

/**
 * @class LazerShot
 * @date 08/10/2018
 * @file LazerShot.h
 * @brief Derived from GameObject class, it models a LazerShot in the Game space
 */

class LazerShot: public GameObject{

public:
     /**
      * @brief Constructor of the LazerShot Class
      * @param size of the LazerShots
      * @param position of the LazerShot
      * @param speed of the LazerShot
      * @param objectid ID of the LazerShot
      */
    LazerShot(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    /**
     * @brief Load Lazershot to player
     * @param position of the Player
     */
    void Load(const vector2D& position) {setPosition(position);}
    /**
     * @brief move the Lazershot
     */
    virtual void Move() override;
    /**
     * @brief move the Lazershot
     */
    void Fire();
    /**
     * @brief destroy Lazershot
     */
    virtual void reset() override {updateState(State::DEAD);}
    /**
     * @brief Collision response of LazerShoot
     */
    virtual void collisionResponse() override{updateState(State::DEAD);}
    /**
     * @brief Destroy LazerShot
     */
    virtual ~LazerShot(){}
     
};


#endif // LAZERSHOT_H
