#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Constants.h"
#include "GameObject.h"
#include "UserInputs.h"
#include "LazerShot.h"
#include <memory>
#include <vector>

class Spaceship: public GameObject{
public:

    Spaceship(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    //Game Object moves is not used for Spaceship
    virtual void Move() override{};
    //Return fired lazer shot
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const{return std::tie(lazerShotsGun_[i], noOfLazerShots_);}
    //Load the LazerShot gun of the Spaceship
    void load();
    //Fire at the at the target
    void shoot();
    //Explode the Spaceship
    virtual void collisionResponse() override;
    //Decreement the number of lives
    void lostLife();
    //Get number of lives
    int Lives(){ return lives_;}
    //Set Number of lives
    void Lives(int lives){lives_ = lives;}
    //Reset Spaceship to inital conditions
    virtual void reset() override;
    //Destructor
    virtual ~Spaceship(){}
    
private:

   int lives_ = 3;
   int noOfLazerShots_ = 0;
   std::vector<std::shared_ptr<LazerShot>> lazerShotsGun_;

};


#endif // SPACESHIP_H
