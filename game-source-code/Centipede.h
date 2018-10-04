#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include "Csegment.h"
#include "GameTypes.h"
#include "GameObjectContainer.h"

#include <vector>
using std::vector;

#include <memory> 
using std::shared_ptr;
 

class Centipede : public GameObjectContainer{
    
public:
    Centipede(int length);
    //Move Centipede across screen
    void Move();
    //Return the ith CentiSegment
    virtual shared_ptr<GameObject> segment(int i) const override {return centipede_[i];}
    //Count the number of destroyed CentiSegments
    void SegmentDestroyed(){numDeadSegments_++;}
    //is The Centipede dead?
    bool isDead(){return (numDeadSegments_== size());}
    //Reset centipede to initial conditions
    virtual void reset() override;
    ~Centipede(){};
    
    
private:
    
    void initialConditions();
    vector<shared_ptr <CentiSegment>> centipede_;
    int numDeadSegments_;
    
};

#endif // CENTIPEDE_H