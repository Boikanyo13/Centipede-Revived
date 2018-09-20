#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"
#include "Player.h"
#include <memory>
#include "Centipede.h"
using std::shared_ptr;

class Collider
{
public:

    void isTargetDestroyed(shared_ptr<Player> player_ptr, shared_ptr<Centipede> centipede_ptr);
    void isPlayerHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<Player> player_ptr);
    void checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr);
    
    ~Collider();
    
private:

  

};

#endif // COLLIDER_H
