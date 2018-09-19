#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <vector>
#include "Csegment.h"
#include "GameTypes.h"
#include <memory>

using std::vector; 
using std::shared_ptr;
 

class Centipede{
    
public:
    Centipede(int length);
    void Move();
    int length(){ return length_;}
    shared_ptr<CentiSegment> centiSegment(int i){return centipede[i] ; }
    ~Centipede();
    
private:
    //segment centipede;
    vector<shared_ptr <CentiSegment>> centipede;
    int length_;
};

#endif // CENTIPEDE_H