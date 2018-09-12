#include "SplashScreen.h"


using  buttonTexture = sf::Texture;
using Button = sf::RectangleShape;

/*SplashScreen::SplashScreen(sf::RenderWindow& window):window_(window)
{

}*/

void SplashScreen::OpeningScreen()
{
    //Start button
    buttonTexture startTexture;
    startTexture.loadFromFile("start2.png");
    auto startButton = Button{sf::Vector2f(100.0f, 50.0f)};
    startButton.setPosition(220,330);
    startButton.setTexture(&startTexture);
    std::tie(a,b,c,d) = ButtonDimension(startButton);
    
    //Help button
    buttonTexture helpTexture;
    helpTexture.loadFromFile("redhelp.png");
    auto helpButton = Button{sf::Vector2f(100.0f, 50.0f)};
    helpButton.setPosition(220,420);
    helpButton.setTexture(&helpTexture);
    
    //GameFont
    gameFont.loadFromFile("basson.ttf");
    gameText.setFont(gameFont);
    gameText.setCharacterSize(45);
    gameText.setPosition(100,200);
    gameText.setString("Centipede \nRevived!");
    gameText.setFillColor(sf::Color::Red);
    
    //Draw to window
     window_.draw(startButton);
     window_.draw(helpButton);
     window_.draw(gameText);
     
}

std::tuple <float, float, float, float> SplashScreen::ButtonDimension(Button button)
{
    auto a  =button.getPosition().x;
    auto b = button.getPosition().x + button.getSize().x ;
    auto c = button.getPosition().y;
    auto d = button.getPosition().y+ button.getSize().y;
    
    return std::make_tuple(a,b,c,d);
    
}

int SplashScreen::DetectButton(sf::Vector2i mousePos, float aspectRatioY, float aspectRatioX) 
{
    auto startButtonFlag = 1;
    auto helpButtonFlag = 2;
    auto backButtonFlag = 3;
    
            if( (aspectRatioX*mousePos.x >= a)   && (aspectRatioX*mousePos.x <= b))  {
                    if((aspectRatioY*mousePos.y >= c) && (aspectRatioY*mousePos.y <= d )){
                        
                        return startButtonFlag;       //start buttn
               }
             }

            if( (aspectRatioX*mousePos.x >= e)   && (aspectRatioX*mousePos.x <= f))  {
                 if((aspectRatioY*mousePos.y >= g) && (aspectRatioY*mousePos.y <= h )){
                            
                          return helpButtonFlag;    //help button
                            
                        }
               }
               
               
               if( (aspectRatioX*mousePos.x >= q)   && (aspectRatioX*mousePos.x <= r))  {
                    if((aspectRatioY*mousePos.y >= y) && (aspectRatioY*mousePos.y <= t)) {
                        
                        return backButtonFlag  ;    //back button
                        }
               }
 return 0;
}



SplashScreen::~SplashScreen()
{
}

