#include "Centipede.h"

Centipede::Centipede(int length):GameObjectContainer{length}{
    
    initialConditions();
    
}


void Centipede::Move(){
    
    for(auto i= 0; i != size() ; i++){
        
        centipede_[i]->Move();
    }
}


void Centipede::initialConditions(){
    
    auto x_pos = CENTIPEDE_INIT_X ;
    auto y_pos = CENTIPEDE_INIT_Y ;
    numDeadSegments_ = 0;
    
    centipede_.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},SPACESHIP_SPEED, ObjectID::CHEAD));
            y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    
    for (auto i = 0; i != size() - 1; i++){
        
        
        centipede_.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},SPACESHIP_SPEED, ObjectID::CENTIPEDE));
            
        y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    }
    
}

void Centipede::reset(){
    
    //clear the vector 
    centipede_.erase(centipede_.begin(), centipede_.end());    
    initialConditions();
    
    }
