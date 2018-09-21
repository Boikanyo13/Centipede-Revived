#include "Player.h"
#include "LazerShot.h"
#include "Display.h"
#include "Constants.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "Collider.h"
#include <memory>

int main(){
    
    
    
    
    auto shooting = false;
    auto isPlaying = false;
    auto help = false;
    auto opening = true;
    
    
    auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE ,PLAYER_Y_SIZE},PLAYER_START_POSTION, 1.0f, ObjectID::PLAYER);
    auto D1 = std::make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    auto userInput = std::make_shared<UserInputs>();
    
    
    auto C1 = std::make_shared<Centipede>(17);
    
 
    auto Coll_Player = std::make_shared<Collider>();
   
    
    while(D1->isOpen()){
        
        
         D1->Events();
         
         
         
         if(opening){
         
         D1->clearDisplay();
         D1->openingWindow();
         isPlaying = false;
         help = false;
         
         if(D1->leftClick()){
             
             
             if(D1->splashscreen().DetectButton() == ScreenObjectID::START){
                 isPlaying = true;
                  opening = false;
                
                 }
             
             if(D1->splashscreen().DetectButton() == ScreenObjectID::HELP){
                  help = true;
                 opening = false;
                 
                
                 }
         }
            D1->display();
           
             
             }
             
             
         
         if(isPlaying){
          D1->clearDisplay();
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
        
        if(D1->spaceKey() && !P1->isDead()){
            
            P1->load();
            shooting = true;
           
            }
         P1->shoot();
          
        
         if(shooting && !P1->isDead()){
             
         D1->drawLazerShot(P1);
         
         Coll_Player->isTargetDestroyed(P1,C1);
         
         }
         
         Coll_Player->isPlayerHit(C1,P1);
       
         D1->drawObject(P1);
         
         D1->drawCentipede(C1);
         
         D1->display();
        
        }
        
        if(help){
            
            D1->clearDisplay();
            D1->helpWindow();
            
            
            if(D1->leftClick()){
                  
                
            if(D1->splashscreen().DetectButton() == ScreenObjectID::BACK){
                  opening = true;
                 }
                 
            }
            D1->display();
            
            }
     
    }
return 0;

}