#include "Player.h"
#include "LazerShot.h"
#include "Display.h"
#include "Constants.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "Collider.h"
#include <memory>

#include <iostream>


int main(){
    
    
    
    
    auto shooting = false;
    
    auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE ,PLAYER_Y_SIZE},PLAYER_START_POSTION, 1.0f, ObjectID::PLAYER);
    auto D1 = std::make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    auto userInput = std::make_shared<UserInputs>();
    
    
    auto C1 = std::make_shared<Centipede>(20);
    
 
    auto Coll_Player = std::make_shared<Collider>();
   
    
    while(D1->isOpen()){
        
        
         D1->Events();
         
         if(userInput->pressedKey()==Key::UP){
             
             P1->Move(Direction::UP);
             }
        if(userInput->pressedKey()==Key::DOWN){
             
              P1->Move(Direction::DOWN);
            }
          if(userInput->pressedKey()==Key::LEFT){
             
             P1->Move(Direction::LEFT);
             }
         if(userInput->pressedKey()==Key::RIGHT){
             
             P1->Move(Direction::RIGHT);
         }
    
         C1->Move();
        
        if(D1->spaceKey()){
            
            P1->load();
            shooting = true;
           
            }
         P1->shoot();
          
         
        // Coll_Player->isPlayerHit(P1,C1);
         if(shooting){
         D1->drawLazerShot(P1);
         

         
     
         Coll_Player->isTargetDestroyed(P1,C1);
         
         }
         
         Coll_Player->isPlayerHit(C1,P1);
         if(!P1->isDead())
         D1->drawObject(P1);
         
         D1->drawCentipede(C1);
         D1->display();
         
        

        
        }
     
    
return 0;

}