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
const auto PLAYER_START_POSTION = vector2D{280.0f,620.0f};
const auto CENTIPEDE_LENGTH = 10;
const auto CENTIPEDE_INIT_X = ORIGINAL_SCREEN_WIDTH/2.0f;
const auto CENTIPEDE_INIT_Y = 0.0f;

const std::string PLAYER_TEXTURE = "ship.png";
const std::string CENTI_BODY = "centi2.png";
const std::string LAZER_TEXTURE = "lazershot.png";

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
const auto TEXT_2 = "GAME OVER!! \n \n You Loose";

#endif // CONSTANTS_H