#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"
#include "GameObject.h"
#include "UserInputs.h"
#include "LazerShot.h"
#include <memory>
#include <vector>



class Player: public GameObject{
public:

    Player(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    virtual void Move(Direction direction) override;
    //Return fired lazer shot
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const;
    //Load the LazerShot gun of the Player
    void load();
    //Fire at the at the target
    void shoot();
    //Explode the player
    void explode();
    //Decreement the number of lives
    void lostLife();
    //Get number of lives
    int Lives();
    //Set Number of lives
    void Lives(int lives);
    //Reset player to inital conditions
    virtual void reset() override;
    //Take action if there is a mushroomhit
    void mushroomCollision(bool collision,Key key);
    //Destructor
    virtual ~Player();
    
private:

   void moveLeft();
   void moveRight();
   void moveUp();
   void moveDown();
   bool left_;
   bool right_;
   bool up_;
   bool down_;
   int tempSpeed_;
   int lives_;
   int noOfLazerShots_;
   std::vector<std::shared_ptr<LazerShot>> lazerShotsGun_;

};


#endif // PLAYER_H
