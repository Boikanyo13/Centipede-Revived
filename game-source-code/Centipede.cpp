#include "Centipede.h"

Centipede::Centipede(int length):length_{length}{
    
    
    auto x_pos = CENTIPEDE_INIT_X ;
    auto y_pos = CENTIPEDE_INIT_Y ;
    numDeadSegments_ = 0;
    
    centipede.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},1.0f, ObjectID::CHEAD));
            y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    
    for (auto i = 0; i < length_ - 1; i++){
        
        
        centipede.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},1.0f, ObjectID::CENTIPEDE));
            
        y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    }
}

shared_ptr<CentiSegment> Centipede::centiSegment(int i)
{return centipede[i] ; }

int Centipede::length(){ return length_;}

void Centipede::Move(){
    
    for(auto i= 0; i < length_ ; i++){
        
        centipede[i]->Move();
    }
}

void Centipede::SegmentDestroyed(){
    
    numDeadSegments_++;
}

bool Centipede::isDead(){
    
    return (numDeadSegments_== length_);
    
}

Centipede::~Centipede(){}