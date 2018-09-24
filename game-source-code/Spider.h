#ifndef SPIDER_H
#define SPIDER_H
#include "GameObject.h"

class Spider: public GameObject{

 public:
      Spider(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
     //Move Spider Across Screen
     void Move();
     //Reset Spider to initial consitions
     virtual void reset() override;
     void explode();
     virtual ~Spider();
     
private:

      virtual void Move(Direction direction) override;
      void moveDown();
      void moveUp();
      void moveZig();
      void moveZag();
      
      bool zigzag_;
      bool up_;
};

#endif // SPIDER_H
