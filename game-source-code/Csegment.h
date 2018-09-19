#ifndef CSEGMENT_H
#define CSEGMENT_H
#include "GameObject.h"
#include "Constants.h"

class CentiSegment: public GameObject{
public:
    
    CentiSegment(const vector2D& size, const vector2D& position, float speed, ObjectID objectid);
    void Move();
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