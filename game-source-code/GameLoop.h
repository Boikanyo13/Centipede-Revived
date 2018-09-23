#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Player.h"
#include "LazerShot.h"
#include "Display.h"
#include "Constants.h"
#include "UserInputs.h"
#include "Centipede.h"
#include "Collider.h"
#include "Mushroom.h"
#include "MushroomField.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

class GameLoop
{
public:
    GameLoop();
    //play game
    void PlayGame();
    //Show the opening window
    void Opening();
    //The entire game
    void CentipedeGame();
    //show instructions window
    void Help();
    //show game over window
    void GameOver();
    ~GameLoop();
    
private:
    shared_ptr<Player> player_ptr;
    shared_ptr<Display> display_ptr;
    shared_ptr<UserInputs> userinput_ptr;
    shared_ptr<Score> score_ptr;
    shared_ptr<Centipede> centipede_ptr;
    shared_ptr<MushroomField> mushroomfield_ptr;
    shared_ptr<Collider> collision_ptr;

    bool shooting_;
    bool isPlaying_;
    bool gameOver_ ;
    bool help_;
    bool opening_ ;



};

#endif // GAMELOOP_H
