#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <vector>
#include "Csegment.h"
#include "GameTypes.h"
#include <memory>
#include <iostream>
using std::vector; 
using std::shared_ptr;
 

class Centipede{
    
public:
    Centipede(int length);
    //Move Centipede across screen
    void Move();
    //Return length of Centipede
    int length(){return length_;};
    //Return the ith CentiSegment
    shared_ptr<CentiSegment> centiSegment(int i){return centipede_[i];};
    //Count the number of destroyed CentiSegments
    void SegmentDestroyed(){numDeadSegments_++;}
    //is The Centipede dead?
    bool isDead(){return (numDeadSegments_== length_);};
    //Reset centipede to initial conditions
    void reset();
    ~Centipede(){};
    
    
private:
    void initialConditions();
    vector<shared_ptr <CentiSegment>> centipede_;
    int length_;
    int numDeadSegments_;
    
};

#endif // CENTIPEDE_H