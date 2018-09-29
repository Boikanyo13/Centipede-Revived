#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "constants.h"
#include "GameObject.h"
#include "UserInputs.h"
#include "LazerShot.h"
#include <memory>
#include <vector>



class Spaceship: public GameObject{
public:

    Spaceship(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    virtual void Move(Direction direction) override;
    //Return fired lazer shot
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const;
    //Load the LazerShot gun of the Spaceship
    void load();
    //Fire at the at the target
    void shoot();
    //Explode the Spaceship
    void explode();
    //Decreement the number of lives
    void lostLife();
    //Get number of lives
    int Lives();
    //Set Number of lives
    void Lives(int lives);
    //Reset Spaceship to inital conditions
    virtual void reset() override;
    //Take action if there is a mushroomhit
    void mushroomCollision(bool collision,Key key);
    //Destructor
    virtual ~Spaceship();
    
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


#endif // SPACESHIP_H
