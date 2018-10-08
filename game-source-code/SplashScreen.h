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

/**
 * @class SplashScreen
 * @author bvrad
 * @date 08/10/2018
 * @file SplashScreen.h
 * @brief This class presents the userInterface  of the Game
 */


class SplashScreen
{
public:
    
    
    SplashScreen(shared_ptr<Display> display_ptr);
    /**
     * @brief Draws the opening screen 
     */
    void OpeningScreen();
    /**
     * @brief Draws the helpscreen
     */
    void HelpScreen();
    /**
     * @brief Draws the game over screen
     * @param score to be drawn on the window
     */
    void YouLoose(int score);
    /**
     * @brief Draws the Background of the gamescreen
     * @param score_ptr to be drawn to window
     * @param lives to be drawn to window
     */
    void GameScreen(shared_ptr<Score> score_ptr, int lives);
    /**
     * @brief Pause Message
     */
    void Pause();
    /**
     * @brief In between Message
     */
    void getReady();
    /**
     * @brief Detects which button in the screen is being pressed
     * @return ID of Button
     */
    ScreenObjectID DetectButton();
    ~SplashScreen(){}
   
private:

    /**
     * @brief Gets dimensions  of the buttons
     * @param button to be drawn
     * @return button dimensions
     */
   std::tuple <float, float, float, float> ButtonDimension (sf::RectangleShape button);
   //Window
   shared_ptr<sf::RenderWindow> window_;
   /**
    * @brief Makes buttons
    * @param size of button
    * @param position of button
    * @param ID of button
    * @return created sf::Rectangle button
    */
    sf::RectangleShape DrawScreenObject(const vector2D& size,const vector2D& position, ScreenObjectID ID);
    /**
     * @brief Draws high scores
     * @param score to be drawn
     */
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
   //Where files are obtained
   GameFiles gamefile_;
  

};

#endif // SPLASHSCREEN_H
