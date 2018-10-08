#ifndef DOMAIN_H
#define DOMAIN_H
#include "Spaceship.h"
#include "Player.h"
#include "LazerShot.h"
#include "Constants.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "CollisionHandler.h"
#include "Mushroom.h"
#include "Spider.h"
#include "MushroomField.h"
#include "Scorpion.h"
#include "Timer.h"


#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <tuple>
using std::tie;
using std::tuple;

class Domain
{
    
public:

    Domain(shared_ptr<Spaceship> spaceship,shared_ptr<Spider> spider, 
    shared_ptr<Centipede> centipede,shared_ptr<MushroomField> mushroomfield, shared_ptr<Score> score, shared_ptr<Scorpion> scorpion):
    spaceship_ptr{spaceship},
    centipede_ptr{centipede},
    mushroomfield_ptr{mushroomfield},
    spider_ptr{spider},
    userinput_ptr{make_shared<UserInputs>()},
    player_ptr{make_shared<Player>(spaceship_ptr, userinput_ptr)},
    score_ptr{score},
    collision_ptr{make_shared<CollisionHandler>(score_ptr)},
    timer_ptr{make_shared<Timer>()},
    scorpion_ptr{scorpion}
    {}
    void update();
    void shoot(bool shoot);
    void handleShootingCollisions();
    void handleGameObjectCollisions();
    void deathHandler();
    bool gameover(){return spaceship_ptr->isDead();}
    bool shootingInProgress(){return isShooting_;}
    void masterReset();
    tuple<bool,bool,bool> states();
    ~Domain(){};
    
private:
   
    shared_ptr<Spaceship> spaceship_ptr;
    shared_ptr<Centipede> centipede_ptr;
    shared_ptr<MushroomField> mushroomfield_ptr;
    shared_ptr<Spider> spider_ptr;
    shared_ptr<UserInputs> userinput_ptr;
    shared_ptr<Player> player_ptr;
    shared_ptr<Score> score_ptr;
    shared_ptr<CollisionHandler> collision_ptr;
    shared_ptr<Timer> timer_ptr;
    shared_ptr<Scorpion> scorpion_ptr;
    
    bool isShooting_ = false;
 
};

#endif // DOMAIN_H
