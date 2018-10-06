#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameObject.h"
#include "Spaceship.h"
#include "MushroomField.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "Score.h"
#include "Spider.h"
#include "Player.h"
#include "Collision.h"

#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_unique;

class CollisionHandler
{
public:
    CollisionHandler(shared_ptr<Score> score_ptr):
    _score_ptr{score_ptr},
    _collision_ptr{std::make_unique<Collision>()}
    {}
    //Collider(){}
    //Handle LazerShot and Centipede Collisons
    void targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr);
    //Handle Centipede and Spaceship Collison
    void spaceshipHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<Spaceship> spaceship_ptr);
    //Handle Centipede and Mushroom collission
    void mushroomHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<MushroomField> mushroom_ptr);
    //Handle Mushroom Bullet Collision
    void mushroomShot(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr);
    //Handle Spaceship mushroom collision
    void spaceshipCollision(shared_ptr<Spaceship> spaceship_ptr,shared_ptr<MushroomField> mushroom_ptr, shared_ptr<Player> player_ptr);
    //Handle Collision between Spider and Spaceship
    void spaceshipHit(shared_ptr<Spider> spider_ptr, shared_ptr<Spaceship> spaceship_ptr);
    //Handle Spider Mushroom Collision
    void mushroomDestroyed(shared_ptr<GameObject> gameObject_ptr,shared_ptr<GameObjectContainer> gameObjectContainer_ptr);
    //Handle spider Lazershot Collison
    void targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Spider> spider_ptr);
    ~CollisionHandler(){};
    
private:
   
    shared_ptr<Score> _score_ptr;
    unique_ptr<Collision> _collision_ptr;
};

#endif // COLLIDER_H