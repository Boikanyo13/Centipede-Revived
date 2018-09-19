#include "Centipede.h"

Centipede::Centipede(int length):length_{length}{
    
    
    auto x_pos = CENTIPEDE_INIT_X ;
    auto y_pos = CENTIPEDE_INIT_Y ;
    for (auto i = 0; i <= length_; i++){
        
        
        centipede.push_back(std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE, CENTIPEDE_Y_SIZE},
            vector2D{x_pos, y_pos},1.0f, ObjectID::CENTIPEDE));
            
        y_pos -= 1.2*CENTIPEDE_Y_SIZE;
    }
}

void Centipede::Move(){
    
    for(auto i= 0; i <= CENTIPEDE_LENGTH ; i++){
        
        centipede[i]->Move();
    }
}

Centipede::~Centipede(){}