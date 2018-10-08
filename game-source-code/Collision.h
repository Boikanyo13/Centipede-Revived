#ifndef COLLISION_H
#define COLLISION_H
#include "GameObject.h"
#include "GameObjectContainer.h"

#include <memory>
using std::shared_ptr;

/**
 * @class Collision
 * @date 08/10/2018
 * @file Collision.h
 * @brief This class checks for collision between two GameObjects
 */

class Collision
{
public:
      /**
       * @brief checks if two GameObjects overlap
       * @param this_ptr the GameObject colliding 
       * @param other_ptr the GameObjects is colliding with
       * @return boolean signaling collision or not
       */
       bool checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr);
       /**
        * @brief Destroys the Collison object
        */
       ~Collision(){};

};

#endif // COLLISION_H
