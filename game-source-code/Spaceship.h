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
    virtual void Move() override{};
    //move spaceship
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    //Return fired lazer shot
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const{return std::tie(lazerShotsGun_[i], noOfLazerShots_);}
    //Load the LazerShot gun of the Spaceship
    void load();
    //Fire at the at the target
    void shoot();
    //Explode the Spaceship
    void explode(){setObjectID(ObjectID::EXPLOSION);}
    //Decreement the number of lives
    void lostLife();
    //Get number of lives
    int Lives(){ return lives_;}
    //Set Number of lives
    void Lives(int lives){lives_ = lives;}
    //Reset Spaceship to inital conditions
    virtual void reset() override;
    //Take action if there is a mushroomhit
    void mushroomCollision(bool collision,Key key);
    //Destructor
    virtual ~Spaceship(){}
    
private:

   bool left_ = true;
   bool right_ = true;
   bool up_ = true;
   bool down_ = true;
   int tempSpeed_;
   int lives_ = 3;
   int noOfLazerShots_ = 0;
   std::vector<std::shared_ptr<LazerShot>> lazerShotsGun_;

};


#endif // SPACESHIP_H
