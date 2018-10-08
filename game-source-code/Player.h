#include "UserInputs.h"
#include "Spaceship.h"
#include <memory>
#ifndef PLAYER_H
#define PLAYER_H

using std::shared_ptr;

/**
 * @class Player
 * @date 08/10/2018
 * @file Player.h
 * @brief This class is responsible for controlling the Player
 */

class Player
{
public:

    /**
     * @brief Player Constructor
     * @param spaceship_ptr to be controlled
     * @param userinput_ptr inputs from the user
     */
    Player(shared_ptr<Spaceship> spaceship_ptr , shared_ptr<UserInputs> userinput_ptr): 
    _spaceship_ptr{spaceship_ptr}, _userinput_ptr{userinput_ptr}
    {}
    /**
     * @brief Player moves the spaceship
     */
    void Move();
    /**
     * @brief move Spaceship to the left
     */
    void moveSpaceshipLeft();
     /**
     * @brief move Spaceship to the right
     */
    void moveSpaceshipRight();
     /**
     * @brief move Spaceship up
     */
    void moveSpaceshipUp();
     /**
     * @brief move Spaceship down
     */
    void moveSpaceshipDown();
    /**
     * @brief collsion response
     * @param collision boolean
     */
    void mushroomCollision(bool collision);
    /**
     * @brief Destructor
     */
    ~Player(){}
    
private:
    //Spaceship pointer
    shared_ptr<Spaceship> _spaceship_ptr;
    //UserInputs pointer
    shared_ptr<UserInputs> _userinput_ptr;
};

#endif // PLAYER_H
