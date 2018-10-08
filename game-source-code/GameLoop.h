#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Spaceship.h"
#include "Player.h"
#include "LazerShot.h"
#include "Display.h"
#include "Constants.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "CollisionHandler.h"
#include "Mushroom.h"
#include "Spider.h"
#include "SplashScreen.h"
#include "Animate.h"
#include "MushroomField.h"
#include "Domain.h"
#include <windows.h>

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::make_unique;
using std::unique_ptr;

class GameLoop
{
public:
    GameLoop();
    //play game
    void PlayGame();
    //Show the opening window
    void Opening();
    //pause game
    void pause();
    //The entire game
    void CentipedeGame();
    //show instructions window
    void Help();
    //show game over window
    void GameOver();
    ~GameLoop(){};
    
private:
    
    //Draw all the GameObjects
    void render();
    shared_ptr<Spaceship> spaceship_ptr;
    shared_ptr<Display> display_ptr;
    shared_ptr<UserInputs> userinput_ptr;
    shared_ptr<Player> player_ptr;
    shared_ptr<Score> score_ptr;
    shared_ptr<Centipede> centipede_ptr;
    shared_ptr<MushroomField> mushroomfield_ptr;
    shared_ptr<Spider> spider_ptr;
    shared_ptr<SplashScreen> splashscreen_ptr;
    shared_ptr<Animate> animate_ptr;
    shared_ptr<Scorpion> scorpion_ptr;
    shared_ptr<Domain> domain_ptr;
   
    

    bool shooting_;
    bool isPlaying_ = false;
    bool gameOver_ = false;
    bool help_ = false;
    bool opening_ =true;
    bool pause_  = false;
    bool reset_ = true;

};

#endif // GAMELOOP_H
