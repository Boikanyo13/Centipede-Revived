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
    void Move();
    int length();
    shared_ptr<CentiSegment> centiSegment(int i);
    void SegmentDestroyed();
    bool isDead();
    ~Centipede();
    
    
private:
    
    vector<shared_ptr <CentiSegment>> centipede;
    int length_;
    int numDeadSegments_;
};

#endif // CENTIPEDE_H