#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Score.h"
#include "GameTypes.h"
#include "GameFiles.h"
#include "Display.h"
#include <tuple>
#include <memory>
#include <vector>

enum class ScreenObjectID{START, HELP, BACK, EXIT, LOGO, BACKGROUND1, BACKGROUND2, LIFE};
//class FileNotFound{};


class SplashScreen
{
public:
    
    
    SplashScreen(shared_ptr<Display> display_ptr);
    //Draws the opening screen 
    void OpeningScreen();
    //Draws the helpscreen
    void HelpScreen();
    //Draws the game over screen
    void YouLoose(int score);
    //Draws the Background of the gamescreen
    void GameScreen(shared_ptr<Score> score_ptr, int lives);
    //Pause Message
    void Pause();
    //In between Message
    void getReady();
    //Detects which button in the screen is being pressed
    ScreenObjectID DetectButton();
    ~SplashScreen(){}
   
private:

    //Gets dimensions  of the buttons
   std::tuple <float, float, float, float> ButtonDimension (sf::RectangleShape button);
   shared_ptr<sf::RenderWindow> window_;
   //Makes buttons
   sf::RectangleShape DrawScreenObject(const vector2D& size,const vector2D& position, ScreenObjectID ID);
   //Draws high scores
    void HighScores(int score);
   //Stores button textures
   std::vector<sf::Texture> screenObjectTextures_;
   //These are the variables that represent the dimensions of each button
   float a, b, c,d;    //start button
   float e,f,g,h;      //help button
   float q,r,w,t;      //back button
   sf::Font gameFont;
   sf::Text gameText;
   
   bool blink_ = true;
   
   GameFiles gamefile_;
  

};

#endif // SPLASHSCREEN_H
