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
    spaceship_ptr_{spaceship_ptr}, userinput_ptr_{userinput_ptr}
    {}
    //Player moves the spaceship
    void Move();
    ~Player(){}
    
private:
    shared_ptr<Spaceship> spaceship_ptr_;
    shared_ptr<UserInputs> userinput_ptr_;
     

};

#endif // PLAYER_H
