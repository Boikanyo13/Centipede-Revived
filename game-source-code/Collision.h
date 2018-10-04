#ifndef COLLISION_H
#define COLLISION_H
#include "GameObject.h"
#include "GameObjectContainer.h"

#include <memory>
using std::shared_ptr;

class Collision
{
public:
    
     bool checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr);
    ~Collision(){};

};

#endif // COLLISION_H
