#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"
#include "Player.h"
#include <memory>
#include "Centipede.h"
#include "Score.h"

using std::shared_ptr;

class Collider
{
public:
    Collider(shared_ptr<Score> score_ptr);
    Collider(){}
    //Check if LazerShot hits Centipede
    void isTargetDestroyed(shared_ptr<Player> player_ptr, shared_ptr<Centipede> centipede_ptr);
    //Check if Centipede hits player
    void isPlayerHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<Player> player_ptr);
    //Check Collison of gameObjects
    bool checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr);
    
    ~Collider();
    
private:
    shared_ptr<Score> _score_ptr;
  

};

#endif // COLLIDER_H
