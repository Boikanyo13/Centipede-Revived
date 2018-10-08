#include "GameLoop.h"
#include <iostream>

GameLoop::GameLoop():
spaceship_ptr{make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE ,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, SPACESHIP_SPEED, ObjectID::SPACESHIP)},
display_ptr{make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT)},
userinput_ptr{make_shared<UserInputs>()},
player_ptr{make_shared<Player>(spaceship_ptr, userinput_ptr)},
score_ptr{make_shared<Score>()},
centipede_ptr{make_shared<Centipede>(CENTIPEDE_LENGTH)},
mushroomfield_ptr{make_shared<MushroomField>(50)},
spider_ptr{make_shared<Spider>(SPIDER_SIZE,SPIDER_INIT_POSITION,SPIDER_SPEED,ObjectID::SPIDER)},
splashscreen_ptr{make_shared<SplashScreen>(display_ptr)},
animate_ptr{make_shared<Animate>(display_ptr)},
scorpion_ptr{make_shared<Scorpion>(SCORPION_SIZE,SCORPION_INIT_POSITION_L,SCORPION_SPEED,ObjectID::SCORPION_L)},
domain_ptr{make_shared<Domain>(spaceship_ptr,spider_ptr,centipede_ptr,mushroomfield_ptr,score_ptr,scorpion_ptr)}
{}

void GameLoop::Opening(){
    
         display_ptr->clearDisplay();
         splashscreen_ptr->OpeningScreen();
         isPlaying_ = false;
         help_ = false;
         reset_ = true;
         
         //Detect which button is pressed on the opening window
         if(display_ptr->leftClick()){
             
             //Play the game
             if(splashscreen_ptr->DetectButton() == ScreenObjectID::START){
                 isPlaying_ = true;
                  opening_ = false;
                
                 }
             //Show instructions window
             if(splashscreen_ptr->DetectButton() == ScreenObjectID::HELP){
                  help_ = true;
                 opening_ = false;
                 
                }
         }
         
        display_ptr->display();
        
}

void GameLoop::PlayGame(){
    
        display_ptr->clearDisplay();
        splashscreen_ptr->GameScreen(score_ptr, spaceship_ptr->Lives());
        
        domain_ptr->update();
        domain_ptr->handleGameObjectCollisions();
    
        
        domain_ptr->shoot(display_ptr->spaceKey());
  
        if(domain_ptr->shootingInProgress()){
                
                 domain_ptr->handleShootingCollisions();
                     
                 animate_ptr->animateLazerShots(spaceship_ptr);
            }
            
        display_ptr->delayer(domain_ptr->states());
        
        if((std::get<0>(domain_ptr->states())||std::get<1>(domain_ptr->states()) )&& !domain_ptr->gameover()){
              splashscreen_ptr->getReady();
              
            }
       
        render();
        
        display_ptr->display();
        
        
        domain_ptr->deathHandler();
      
            
          if(domain_ptr->gameover()){
               isPlaying_ = false;
               gameOver_ = true;
              
              }
         // Pause?
          if(userinput_ptr->pressedKey()==Key::PAUSE){
              pause_ = true;
              isPlaying_ = false;
          }
    }


void GameLoop::CentipedeGame(){
    
    while(display_ptr->isOpen()){
         
        display_ptr->Events(userinput_ptr);
        
        if(opening_)
            Opening();
        
        else if(isPlaying_)
            PlayGame();
        
        else if(help_)
            Help();
        
        else if(gameOver_)
            GameOver();
        else if(pause_){
            pause();
            }
         
    }
    
    
}
void GameLoop::Help(){
    
        display_ptr->clearDisplay();
        splashscreen_ptr->HelpScreen();
        
          //detect if back button is pressed in help window  
        if(display_ptr->leftClick()){
                  
                if(splashscreen_ptr->DetectButton() == ScreenObjectID::BACK){
                  opening_ = true;
                  help_ = false;
                 }
                 
            }
        display_ptr->display();
        
}

void GameLoop::GameOver(){

        //Show game over window with the current score and high scores
     
        display_ptr->clearDisplay();
        splashscreen_ptr->YouLoose(score_ptr->score());
         
         
       //Only perform these actions once;
        if(reset_){   
            score_ptr->updateHighscore();
         }
                   
        reset_ = false;  
        
        spaceship_ptr->reset();
        mushroomfield_ptr->reset();
        centipede_ptr->reset();
        spider_ptr->reset();
   
         
        //Check for left click
        if(display_ptr->leftClick()){
    
            if(splashscreen_ptr->DetectButton() == ScreenObjectID::BACK){
                    opening_ = true;
                    gameOver_ =  false;
                    score_ptr->reset(); 
                 }
        }
        display_ptr->display();
}

void GameLoop::pause(){

    isPlaying_ = false;
    
    display_ptr->clearDisplay();
    splashscreen_ptr->GameScreen(score_ptr, spaceship_ptr->Lives());
    splashscreen_ptr->Pause();
   
    display_ptr->display();
   
    
    if(userinput_ptr->pressedKey()==Key::RESUME){
        
        isPlaying_ = true;
        pause_ = false;
    }
    else if(userinput_ptr->pressedKey()==Key::QUIT){
        
        domain_ptr->masterReset();
        opening_ = true;
        pause_ = false;
        }
}

void GameLoop::render(){
    
    animate_ptr->animate(mushroomfield_ptr);
    animate_ptr->animate(spider_ptr);
    animate_ptr->animate(spaceship_ptr);
    animate_ptr->animate(centipede_ptr);
    animate_ptr->animate(scorpion_ptr);
    
    }

