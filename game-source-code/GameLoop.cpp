#include "GameLoop.h"

GameLoop::GameLoop():
spaceship_ptr{make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE ,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, SPACESHIP_SPEED, ObjectID::SPACESHIP)},
display_ptr{make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT)},
userinput_ptr{make_shared<UserInputs>()},
player_ptr{make_shared<Player>(spaceship_ptr, userinput_ptr)},
score_ptr{make_shared<Score>()},
centipede_ptr{make_shared<Centipede>(CENTIPEDE_LENGTH)},
mushroomfield_ptr{make_shared<MushroomField>(50)},
collision_ptr{make_shared<CollisionHandler>(score_ptr)},
spider_ptr{make_shared<Spider>(SPIDER_SIZE,SPIDER_INIT_POSITION,SPIDER_SPEED,ObjectID::SPIDER)},
splashscreen_ptr{make_shared<SplashScreen>(display_ptr)},
animate_ptr{make_shared<Animate>(display_ptr)}
{   
    shooting_ = false;
    isPlaying_ = false;
    help_ = false;
    opening_ = true;
    gameOver_ = false;
    
}

void GameLoop::Opening(){
    
         display_ptr->clearDisplay();
         splashscreen_ptr->OpeningScreen();
         isPlaying_ = false;
         help_ = false;
         
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
        animate_ptr->animate(mushroomfield_ptr);
          
        //move the spaceship
        player_ptr->Move();
            
        
        //move the centipede across the screen
        centipede_ptr->Move();
        
        spider_ptr->Move();
        
        collision_ptr->mushroomDestroyed(spider_ptr,mushroomfield_ptr);
        
        collision_ptr->spaceshipHit(spider_ptr,spaceship_ptr);
         
         //detect if the centipede collides with a mushroom
        collision_ptr->mushroomHit(centipede_ptr,mushroomfield_ptr);
        
        //detect if a spaceship collides with a mushroom
        collision_ptr->spaceshipCollision(spaceship_ptr,mushroomfield_ptr,player_ptr);
       
       
        if(display_ptr->spaceKey() && !spaceship_ptr->isDead() && !(spaceship_ptr->ID()==ObjectID::EXPLOSION)){
            
            spaceship_ptr->load();
            shooting_ = true;
           
            }
            
         spaceship_ptr->shoot();
          
         if(shooting_ && !spaceship_ptr->isDead()){
             
            animate_ptr->animateLazerShots(spaceship_ptr);
            collision_ptr->mushroomShot(spaceship_ptr,mushroomfield_ptr);  
            collision_ptr->targetDestroyed(spaceship_ptr,centipede_ptr,mushroomfield_ptr);
            collision_ptr->targetDestroyed(spaceship_ptr,spider_ptr);
         }
         
         collision_ptr->spaceshipHit(centipede_ptr,spaceship_ptr);
         animate_ptr->animate(spider_ptr);
         animate_ptr->animate(spaceship_ptr);
         animate_ptr->animate(centipede_ptr);
         display_ptr->display();
         
         //spaceship explodes if hit
         if(spaceship_ptr->ID() == ObjectID::EXPLOSION){
             
             spaceship_ptr->reset();
             centipede_ptr->reset();
             spider_ptr->reset();
             shooting_ = false;
             }
         
         if(centipede_ptr->isDead()){
             
             spaceship_ptr->reset();
             centipede_ptr->reset();
             mushroomfield_ptr->reset();
              usleep(20000);
            shooting_ = false;
             
             }
         
         //End game if spaceship is dead
          if( spaceship_ptr->isDead() ||  centipede_ptr->isDead()){
              isPlaying_ = false;
              gameOver_ = true;
              shooting_ = false;
           
              }
           //Revive the Spider if Shot   
          if(spider_ptr->ID()==ObjectID::EXPLOSION2){
              
              spider_ptr->reset();
              }
    
}

void GameLoop::CentipedeGame(){
    
    while(display_ptr->isOpen()){
         
        display_ptr->Events();
        
        if(opening_)
            Opening();
        
        else if(isPlaying_)
            PlayGame();
        
        else if(help_)
            Help();
        
        else if(gameOver_)
            GameOver();
         
    }
    
    
}
void GameLoop::Help(){
    
        display_ptr->clearDisplay();
        splashscreen_ptr->HelpScreen();
        
          //detect if back button is pressed in help window  
        if(display_ptr->leftClick()){
                  
                if(splashscreen_ptr->DetectButton() == ScreenObjectID::BACK){
                  opening_ = true;
                 }
                 
            }
        display_ptr->display();
        
}

void GameLoop::GameOver(){

        //Show game over window with the current score and high scores
        score_ptr->updateHighscore();
        display_ptr->clearDisplay();
        isPlaying_ = false;
         
        if(spaceship_ptr->isDead()) 
          splashscreen_ptr->YouLoose(score_ptr->score());

        else {
        
            splashscreen_ptr->YouWin(score_ptr->score());
        }
                
        spaceship_ptr->reset();
        mushroomfield_ptr->reset();
        display_ptr->display();
        usleep(3000000);
              
        gameOver_ = false;
        opening_ = true;
        centipede_ptr->reset();
        spaceship_ptr->Lives(3);
        spaceship_ptr->setObjectID(ObjectID::SPACESHIP);
        spaceship_ptr->updateState(State::ALIVE);
        score_ptr->reset(); 

            
}
GameLoop::~GameLoop()
{
}

