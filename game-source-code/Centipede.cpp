#include "Centipede.h"

Centipede::Centipede(int length):length_{length}{
    
    initialConditions();
    
}

shared_ptr<CentiSegment> Centipede::centiSegment(int i)
{return centipede_[i] ; }

int Centipede::length(){ return length_;}

void Centipede::Move(){
    
    for(auto i= 0; i < length_ ; i++){
        
        centipede_[i]->Move();
    }
}

void Centipede::SegmentDestroyed(){
    
    numDeadSegments_++;
}

bool Centipede::isDead(){
    
    return (numDeadSegments_== length_);
    
}

void Centipede::initialConditions(){
    
    auto x_pos = CENTIPEDE_INIT_X ;
    auto y_pos = CENTIPEDE_INIT_Y ;
    numDeadSegments_ = 0;
    
    centipede_.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},1.0f, ObjectID::CHEAD));
            y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    
    for (auto i = 0; i < length_ - 1; i++){
        
        
        centipede_.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},1.0f, ObjectID::CENTIPEDE));
            
        y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    }
    
}

void Centipede::reset(){
    
    //clear the vector 
    centipede_.erase(centipede_.begin(), centipede_.end());
    initialConditions();
    }
    
Centipede::~Centipede(){}