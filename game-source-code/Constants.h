#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "GameTypes.h"
#include <string>

const auto ORIGINAL_SCREEN_WIDTH = 540.0f;
const auto ORIGINAL_SCREEN_HEIGHT = 640.0f;

//Centipede dimensions
const auto CENTIPEDE_X_SIZE = 20.0f;
const auto CENTIPEDE_Y_SIZE= 20.0f;
const auto PLAYER_X_SIZE= 20.0f;
const auto PLAYER_Y_SIZE = 20.0f;
const auto PLAYER_SIZE = vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE};
const auto PLAYER_START_POSTION = vector2D{280.0f,620.0f};
const auto CENTIPEDE_LENGTH = 13;
const auto CENTIPEDE_INIT_X = ORIGINAL_SCREEN_WIDTH/2.0f;
const auto CENTIPEDE_INIT_Y = 0.0f;
const auto MUSHROOM_SIZE = vector2D{20.0f,20.0f};
const auto SPIDER_INIT_POSITION =  vector2D{11.0f, 440.0f};
const auto SPIDER_SIZE = vector2D{25.0f,25.0f};
const auto SPIDER_SPEED = 0.3f;
const auto CENTIPEDE_SPEED = 1.5f;
const auto BULLET_SIZE = vector2D{2.0f,10.0f};
const auto PLAYER_SPEED = 1.0f;

//Button dimensions
const auto BUTTON_X_SIZE = 100.0f;
const auto BUTTON_Y_SIZE = 50.0f;
const auto START_X_POS = 220.0f;
const auto START_Y_POS = 390.0f;
const auto HELP_X_POS = START_X_POS;
const auto HELP_Y_POS  = 460.0f;
const auto BACK_X_POS = START_X_POS;
const auto BACK_Y_POS =  520.0f ;

const auto TEXT_1 = "Instructions \n \n \n To Shoot: space \n \n Move Up: Up Arrow \n \n Move Down: Down Arrow \n \n Move Left: Left Arrow \n \n Move Right: Right Arrow";
const auto TEXT_2 = "You Loose!";
const auto TEXT_3 = "You Win!";

#endif // CONSTANTS_H