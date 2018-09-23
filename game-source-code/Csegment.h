#ifndef CSEGMENT_H
#define CSEGMENT_H
#include "GameObject.h"
#include "Constants.h"

class CentiSegment: public GameObject{
public:
    
    CentiSegment(const vector2D& size, const vector2D& position, float speed, ObjectID objectid);
    //Move the CentiSegment across the screen
    void Move();
    //set the CentiSegment to head;
    void head();
    //Check if it is head
    bool isHead() const;
    //set the centipede segment to its inital conditions
    virtual void reset() override;
    //Take action if hits a mushroom
    void mushroomHit();
    //Destructor
    virtual ~CentiSegment();
    
private:

    virtual void Move(Direction direction) override;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void entrance();
    bool forward_;
    bool up_;
    bool atBoundry_;
    };


#endif // CSEGMENT_H