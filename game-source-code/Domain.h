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

/**
 * @class Domain 
 * @date 08/10/2018
 * @file Domain.h
 * @brief This class is where all the Logic objects interact
 */

class Domain
{
    
public:
    /**
     * @brief Constructor to Domain object
     * @param spaceship pointer to Spacship
     * @param spider pointer to Spider
     * @param centipede pointer to Centipede
     * @param mushroomfield pointer to MushroomField
     * @param score pointer to Score
     * @param scorpion pointer to Scorpion
     */
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
    /**
     * @brief update Logic
     */
    void update();
    /**
     * @brief shoot at enemy Objects
     * @param shoot boolean to activate shootig
     */
    void shoot(bool shoot);
    /**
     * @brief Handle shooting collisions
     */
    void handleShootingCollisions();
    /**
     * @brief handle GameObjects Collisions
     */
    void handleGameObjectCollisions();
    /**
     * @brief Handle the death of Game Objects
     */
    void deathHandler();
    /**
     * @brief Check if game is Over
     * @return return boolean indicating whether game is over or not
     */
    bool gameover(){return spaceship_ptr->isDead();}
    /**
     * @brief check if shooting is in progress
     * @return boolean indicating whether shooting is in progress or not
     */
    bool shootingInProgress(){return isShooting_;}
    /**
     * @brief reset all GameObjects
     */
    void masterReset();
    /**
     * @brief returns the state of game objects
     * @return a tuple of states
     */
    tuple<bool,bool,bool> states();
    /**
     * @brief destroy Domain object
     */
    ~Domain(){};
    
private:
   
    //Logic Objects
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
    //is ther shooting?
    bool isShooting_ = false;
 
};

#endif // DOMAIN_H
