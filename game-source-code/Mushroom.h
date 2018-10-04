#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <memory>
#include "GameObject.h"
#include "Csegment.h"

class NonMovableObject{};

class Mushroom: public GameObject{
public:
    Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    //Take action if Mushroom is shot
    virtual void collisionResponse() override;
    //Return the number of lives the Mushroom has
    int lives() const {return lives_; }
    //Move function from parent
    virtual void Move() override{throw NonMovableObject{}; } 
    //Turn a CentiSegment into a Mushroom
    void transform(std::shared_ptr<CentiSegment> seg);
    //Reset Mushroom to intial conditions
    virtual void reset() override;
    virtual ~Mushroom(){}
    
private:
   
    int lives_ = 4;

};

#endif // MUSHROOM_H