#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "GameTypes.h"
#include <string>


/**
 * @date 08/10/18
 * @file Constants.h
 * @brief The file contains all constanst used in the Game
*/
const auto ORIGINAL_SCREEN_WIDTH = 540.0f;
const auto ORIGINAL_SCREEN_HEIGHT = 640.0f;

//Centipede dimensions
const auto CENTIPEDE_X_SIZE = 20.0f;
const auto CENTIPEDE_Y_SIZE= 20.0f;
const auto CENTIPEDE_SIZE = vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE};
const auto SPACESHIP_X_SIZE= 20.0f;
const auto SPACESHIP_Y_SIZE = 20.0f;
const auto SPACESHIP_SIZE = vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE};
const auto SPACESHIP_START_POSTION = vector2D{280.0f,620.0f};
const auto CENTIPEDE_LENGTH = 13;
const auto CENTIPEDE_INIT_X = ORIGINAL_SCREEN_WIDTH/2.0f;
const auto CENTIPEDE_INIT_Y = 0.0f;
const auto MUSHROOM_SIZE = vector2D{16.0f,16.0f};
const auto SPIDER_INIT_POSITION =  vector2D{-15.0f, 440.0f};
const auto SPIDER_SIZE = vector2D{25.0f,25.0f};
const auto SPIDER_SPEED = 0.3f;
const auto CENTIPEDE_SPEED = 1.0f;
const auto BULLET_SIZE = vector2D{2.0f,10.0f};
const auto SPACESHIP_SPEED = 1.0f;
const auto SCORPION_SIZE = vector2D{40.0f,40.0f};
const auto SCORPION_SPEED = 0.2f;
const auto SCORPION_INIT_POSITION_L = vector2D{-35.0f, 320.0f};
const auto SCORPION_INIT_POSITION_R= vector2D{1.10*ORIGINAL_SCREEN_WIDTH, 320.0f};


//Button dimensions
const auto BUTTON_X_SIZE = 100.0f;
const auto BUTTON_Y_SIZE = 50.0f;
const auto START_X_POS = 220.0f;
const auto START_Y_POS = 390.0f;
const auto HELP_X_POS = START_X_POS;
const auto HELP_Y_POS  = 460.0f;
const auto BACK_X_POS = START_X_POS;
const auto BACK_Y_POS =  520.0f ;

const auto TEXT_1 = "Instructions \n \n To Shoot:  Space \n Move Up:  Up Arrow \n Move Down:  Down Arrow \n Move Left:  Left Arrow \n Move Right:  Right Arrow \n Pause:  Press P \n Resume:  Press R ";
const auto TEXT_2 = "You Loose!";
const auto TEXT_3 = "You Win!";

#endif // CONSTANTS_H