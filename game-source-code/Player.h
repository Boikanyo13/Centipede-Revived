#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"
#include "GameObject.h"


class Player: public GameObject{
public:
    
    Player(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    virtual void Move(Direction direction) override;
    virtual ~Player();
    
private:
   void moveLeft();
   void moveRight();
   void moveUp();
   void moveDown();

};


#endif // PLAYER_H
