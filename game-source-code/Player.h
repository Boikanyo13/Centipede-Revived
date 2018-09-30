#include "UserInputs.h"
#include "Spaceship.h"
#include <memory>
#ifndef PLAYER_H
#define PLAYER_H

using std::shared_ptr;

class Player
{
public:
    Player(shared_ptr<Spaceship> spaceship_ptr , shared_ptr<UserInputs> userinput_ptr): 
    _spaceship_ptr{spaceship_ptr}, _userinput_ptr{userinput_ptr}
    {}
    //Player moves the spaceship
    void Move();
    //Sub Move functions
    void moveSpaceshipLeft();
    void moveSpaceshipRight();
    void moveSpaceshipUp();
    void moveSpaceshipDown();
    //Collision Handler
    void mushroomCollision(bool collision);
    //Destructor
    ~Player(){}
    
private:

    shared_ptr<Spaceship> _spaceship_ptr;
    shared_ptr<UserInputs> _userinput_ptr;
};

#endif // PLAYER_H
