#ifndef CSEGMENT_H
#define CSEGMENT_H
#include "GameObject.h"
#include "Constants.h"

class CentiSegment: public GameObject{
public:
    
    CentiSegment(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    //Move the CentiSegment across the screen
    virtual void Move() override;
    //set the CentiSegment to head;
    void head() {setObjectID(ObjectID::CHEAD);}
    //Check if it is head
    bool isHead() const {return (ID()==ObjectID::CHEAD);}
    //set the centipede segment to its inital conditions
    virtual void reset() override{};
    //Take action if hits a mushroom
    void mushroomHit();
    //Destructor
    virtual ~CentiSegment(){}
    
private:

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void entrance();
    bool forward_ = true;
    bool up_ = false;
    bool atBoundry_ = false;
    };


#endif // CSEGMENT_H