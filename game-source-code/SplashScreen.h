#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include <tuple>

class SplashScreen
{
public:
    
    
    SplashScreen(sf::RenderWindow& window);
    ~SplashScreen();
    //Draws the opening screen 
    void OpeningScreen();
    //Draws the helpscreen
    void HelpScreen();
    //Draws the game over screen
    void GameOver();
    //Detects which button in the screen is being pressed
    int DetectButton(sf::Vector2i mousePos, float aspectRatioY, float aspectRatioX);
   
private:

    //Gets dimensions  of the buttons
   std::tuple <float, float, float, float> ButtonDimension (sf::RectangleShape button);
   sf::RenderWindow& window_;
   //These are the variables that represent the dimensions of each button
   float a, b, c,d;    //start button
   float e,f,g,h;      //help button
   float q,r,y,t;      //back button
   sf::Font gamefont;
   sf::Text gametext;
  

};

#endif // SPLASHSCREEN_H
