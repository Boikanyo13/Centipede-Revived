/*#include "Centipede.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include "Csegment.h


Centipede::Centipede(sf::Texture* texture,int length = 8, float speed = 0.2f):length_(length),speed_(speed)
{ 
    float Yposition = 0.0f;
    auto radius=sf::Vector2f{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE};
    
    //set the position of the head
    auto InitPosition = sf::Vector2f(ORIGINAL_SCREEN_WIDTH/2.0f, Yposition);
    
    //create the centipede
    for(auto i = 0; i<=length_; i++){
        
        
        centipede.push_back(Csegment{texture,InitPosition,radius,speed_});
        
        //set the position of the Centipede segments
        InitPosition.y -= 1.2f*radius.y;
        
    }
}


void Centipede::Move()
{  
     for(auto i = 0; i <= length_ ; i++){
         centipede[i].Move();
     }
     
}

void Centipede::Draw(sf::RenderWindow& window)
{
        for(auto i = 0; i<= length_; i++){
           
            centipede[i].Draw(window);
        }
    
}

int Centipede::getLength() const
{
    return length_;
    
}


Centipede::~Centipede()
{
}

*/