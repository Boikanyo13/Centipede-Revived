#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"
#include "Player.h"
#include "MushroomField.h"
#include "UserInputs.h"
#include <memory>
#include "Centipede.h"
#include "Score.h"
#include "Spider.h"

using std::shared_ptr;

class Collider
{
public:
    Collider(shared_ptr<Score> score_ptr);
    Collider(){}
    //Handle LazerShot and Centipede Collisons
    void targetDestroyed(shared_ptr<Player> player_ptr, shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr);
    //Handle Centipede and Player Collison
    void playerHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<Player> player_ptr);
    //Check Collison of gameObjects
    bool checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr);
    //Handle Centipede and Mushroom collission
    void mushroomHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<MushroomField> mushroom_ptr);
    //Handle Mushroom Bullet Collision
    void mushroomShot(shared_ptr<Player> player_ptr, shared_ptr<MushroomField> mushroom_ptr);
    //Handle Player mushroom collision
    void playerCollision(shared_ptr<Player> player_ptr,shared_ptr<MushroomField> mushroom_ptr,Key key);
    //Handle Collision between Spider and Player
    void playerHit(shared_ptr<Spider> spider_ptr, shared_ptr<Player> player_ptr);
    //Handle Spider Mushroom Collision
    void mushroomDestroyed(shared_ptr<Spider> spider_ptr,shared_ptr<MushroomField> mushroom_ptr);
    //Handle spider Lazershot Collison
    void targetDestroyed(shared_ptr<Player> player_ptr, shared_ptr<Spider> spider_ptr);
    ~Collider();
    
private:
    shared_ptr<Score> _score_ptr;

  

};

#endif // COLLIDER_H
