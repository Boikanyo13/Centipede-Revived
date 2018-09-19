#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"
#include "GameObject.h"
#include "LazerShot.h"
#include <memory>
#include <vector>



class Player: public GameObject{
public:

    Player(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    virtual void Move(Direction direction) override;
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const;
    //Load the LazerShot gun of the Player
    void load();
    //Fire at the at the target
    void shoot();
    virtual ~Player();
    
private:

   void moveLeft();
   void moveRight();
   void moveUp();
   void moveDown();
   int noOfLazerShots_;
   std::vector<std::shared_ptr<LazerShot>> lazerShotsGun_;

};


#endif // PLAYER_H
