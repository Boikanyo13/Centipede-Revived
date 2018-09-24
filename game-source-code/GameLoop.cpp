#include "GameLoop.h"

GameLoop::GameLoop():
player_ptr{make_shared<Player>(vector2D{PLAYER_X_SIZE ,PLAYER_Y_SIZE},PLAYER_START_POSTION, 1.0f, ObjectID::PLAYER)},
display_ptr{make_shared<Display>(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT)},
userinput_ptr{make_shared<UserInputs>()},
score_ptr{make_shared<Score>()},
centipede_ptr{make_shared<Centipede>(CENTIPEDE_LENGTH)},
mushroomfield_ptr{make_shared<MushroomField>(25)},
collision_ptr{make_shared<Collider>(score_ptr)},
spider_ptr{make_shared<Spider>(SPIDER_SIZE,SPIDER_INIT_POSITION,SPIDER_SPEED,ObjectID::SPIDER)}
{
    shooting_ = false;
    isPlaying_ = false;
    help_ = false;
    opening_ = true;
    gameOver_ = false;
    
}

void GameLoop::Opening(){
    
         display_ptr->clearDisplay();
         display_ptr->openingWindow();
         isPlaying_ = false;
         help_ = false;
         
         //Detect which button is pressed on the opening window
         if(display_ptr->leftClick()){
             
             //Play the game
             if(display_ptr->splashscreen().DetectButton() == ScreenObjectID::START){
                 isPlaying_ = true;
                  opening_ = false;
                
                 }
             //Show instructions window
             if(display_ptr->splashscreen().DetectButton() == ScreenObjectID::HELP){
                  help_ = true;
                 opening_ = false;
                 
                }
         }
         
        display_ptr->display();
           
    
}

void GameLoop::PlayGame(){
    
        display_ptr->clearDisplay();
        display_ptr->gameWindow(score_ptr, player_ptr->Lives());
        display_ptr->drawMushroomField(mushroomfield_ptr);
          
        //Keys to play the game
         if(userinput_ptr->pressedKey()==Key::UP){
             
             player_ptr->Move(Direction::UP);
             }
        if(userinput_ptr->pressedKey()==Key::DOWN){
             
              player_ptr->Move(Direction::DOWN);
            }
          if(userinput_ptr->pressedKey()==Key::LEFT){
             
             player_ptr->Move(Direction::LEFT);
             }
         if(userinput_ptr->pressedKey()==Key::RIGHT){
             
             player_ptr->Move(Direction::RIGHT);
            }
        
        //move the centipede across the screen
        centipede_ptr->Move();
        
        spider_ptr->Move();
        
        collision_ptr->mushroomDestroyed(spider_ptr,mushroomfield_ptr);
        
        collision_ptr->playerHit(spider_ptr,player_ptr);
         
         //detect if the centipede collides with a mushroom
        collision_ptr->mushroomHit(centipede_ptr,mushroomfield_ptr);
        
        //detect if a player collides with a mushroom
        collision_ptr->playerCollision(player_ptr,mushroomfield_ptr,userinput_ptr->pressedKey());
       
       
        if(display_ptr->spaceKey() && !player_ptr->isDead() && !(player_ptr->ID()==ObjectID::EXPLOSION)){
            
            player_ptr->load();
            shooting_ = true;
           
            }
            
         player_ptr->shoot();
          
         if(shooting_ && !player_ptr->isDead()){
             
            display_ptr->drawLazerShot(player_ptr);
            collision_ptr->mushroomShot(player_ptr,mushroomfield_ptr);  
            collision_ptr->targetDestroyed(player_ptr,centipede_ptr,mushroomfield_ptr);
         }
         
         collision_ptr->playerHit(centipede_ptr,player_ptr);
         display_ptr->drawObject(spider_ptr);
         display_ptr->drawObject(player_ptr);
         display_ptr->drawCentipede(centipede_ptr);
         display_ptr->display();
         
         //player explodes if hit
         if(player_ptr->ID() == ObjectID::EXPLOSION){
             
             player_ptr->reset();
             centipede_ptr->reset();
             spider_ptr->reset();
             shooting_ = false;
             }
         
        /* if(centipede_ptr->isDead()){
             
             player_ptr->reset();
             centipede_ptr->reset();
             mushroomfield_ptr->reset();
             usleep(2000000);
             
             }*/
         
         //End game if player is dead
          if( player_ptr->isDead() ||  centipede_ptr->isDead()){
              isPlaying_ = false;
              gameOver_ = true;
              shooting_ = false;
           
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
        display_ptr->helpWindow();
            
          //detect if back button is pressed in help window  
        if(display_ptr->leftClick()){
                  
                if(display_ptr->splashscreen().DetectButton() == ScreenObjectID::BACK){
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
         
        if(player_ptr->isDead()) 
            display_ptr->splashscreen().YouLoose(score_ptr->score());

        else {
           display_ptr->splashscreen().YouWin(score_ptr->score());
        }
                
        player_ptr->reset();
        mushroomfield_ptr->reset();
        display_ptr->display();
        usleep(3000000);
              
        gameOver_ = false;
        opening_ = true;
        centipede_ptr->reset();
        player_ptr->Lives(3);
        player_ptr->setObjectID(ObjectID::PLAYER);
        player_ptr->updateState(State::ALIVE);
        score_ptr->reset(); 

            
}
GameLoop::~GameLoop()
{
}

