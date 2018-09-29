#ifndef SPIDER_H
#define SPIDER_H
#include "GameObject.h"

class Spider: public GameObject{

 public:
      Spider(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
      GameObject{size,position,speed,objectid}
      {}
     //Move Spider Across Screen
     virtual void Move() override;
     //Reset Spider to initial conditions
     virtual void reset() override;
     //Explode the player
     void explode(){ setObjectID(ObjectID::EXPLOSION2); }
     virtual ~Spider(){};
     
private:

      //For down movement
      void moveDown();
      //For up movement
      void moveUp();
      //Up movement left or right
      void moveZig();
      //Down movement left or right
      void moveZag();
      
      bool zigzag_ = true;
      bool up_ = false;
};

#endif // SPIDER_H
