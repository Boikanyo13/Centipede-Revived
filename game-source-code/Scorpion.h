#ifndef SCORPION_H
#define SCORPION_H
#include "GameObject.h"

class Scorpion : public GameObject
{
public:
    Scorpion(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    //Take action if Scorpion is shot
    virtual void collisionResponse() override;
    //Move function from parent
    virtual void Move() override;
    //Reset Scorpion to intial conditions
    virtual void reset() override;
    virtual ~Scorpion(){}

private:
    void moveLeft();
    void moveRight();
    void rightReset();
    void leftReset();
    bool forward_ = true;

};

#endif // SCORPION_H
