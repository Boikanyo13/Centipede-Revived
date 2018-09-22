#include "SplashScreen.h"

SplashScreen::SplashScreen(sf::RenderWindow& window):window_(window)
{
        //Get the file names
        auto fileNames = gamefile_.screenImages();
        gameFont.loadFromFile(gamefile_.font());
        gameText.setFont(gameFont);
        sf::Texture tempTexure; 

        //Load textures
        for(auto i = 0u; i< fileNames.size() ; i++){
            
            if(!tempTexure.loadFromFile(fileNames[i])) throw FileNotFound{};
             
                else 
                 
                    screenObjectTextures_.push_back(tempTexure);
        }

}

sf::RectangleShape SplashScreen::DrawScreenObject(const vector2D& size, const vector2D& position, ScreenObjectID ID){
    
    //create screen object
    auto  screenObject = sf::RectangleShape{sf::Vector2f(size.x(),size.y())};
    screenObject.setPosition(position.x() , position.y());
    screenObject.setTexture(&screenObjectTextures_[static_cast<int>(ID)]);
    //draw screen object
    window_.draw(screenObject);
    
    return screenObject;
}


void SplashScreen::OpeningScreen()
{
    //Background
    DrawScreenObject(vector2D{1080.0f, 750.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND1);
    //Start button
    auto startbutton = DrawScreenObject(vector2D{BUTTON_X_SIZE, BUTTON_Y_SIZE}, vector2D{START_X_POS, START_Y_POS}, ScreenObjectID::START);
    std::tie(a,b,c,d) = ButtonDimension(startbutton);
    //Help button
    auto helpbutton = DrawScreenObject(vector2D{BUTTON_X_SIZE, BUTTON_Y_SIZE}, vector2D{HELP_X_POS, HELP_Y_POS}, ScreenObjectID::HELP);
    std::tie(e,f,g,h) = ButtonDimension(helpbutton);
    //Logo
    DrawScreenObject( vector2D{540.0f, 450.0f},vector2D{0.0f,0.0f}, ScreenObjectID::LOGO);
     
}

std::tuple <float, float, float, float> SplashScreen::ButtonDimension(sf::RectangleShape button)
{
    auto a  =button.getPosition().x;
    auto b = button.getPosition().x + button.getSize().x ;
    auto c = button.getPosition().y;
    auto d = button.getPosition().y+ button.getSize().y;
    
    return std::make_tuple(a,b,c,d);
    
}

 void SplashScreen::HelpScreen()
 {
     //Background
    DrawScreenObject(vector2D{1080.0f, 750.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND1);
    
    //Text for instructions
    gameText.setFillColor(sf::Color::Red);
    gameText.setCharacterSize(25);
    gameText.setPosition(65, 100);
    gameText.setString(TEXT_1);
    
    //Back button
    auto backbutton = DrawScreenObject(vector2D{BUTTON_X_SIZE, BUTTON_Y_SIZE}, vector2D{BACK_X_POS, BACK_Y_POS}, ScreenObjectID::BACK);
    std::tie(q,r,w,t) = ButtonDimension(backbutton);
    window_.draw(gameText);
    
     }

ScreenObjectID SplashScreen::DetectButton()
{
    sf::Vector2i mousePos  = sf::Mouse::getPosition(window_);
    
    //For accurate button detection
    auto aspectRatioX = ORIGINAL_SCREEN_WIDTH/window_.getSize().x;
    auto aspectRatioY = ORIGINAL_SCREEN_HEIGHT/window_.getSize().y;
                
    
            if( (aspectRatioX*mousePos.x >= a)   && (aspectRatioX*mousePos.x <= b))  {
                    if((aspectRatioY*mousePos.y >= c) && (aspectRatioY*mousePos.y <= d )){
                        
                        return ScreenObjectID::START;       //start buttn
                    }
             }

            if( (aspectRatioX*mousePos.x >= e)   && (aspectRatioX*mousePos.x <= f))  {
                    if((aspectRatioY*mousePos.y >= g) && (aspectRatioY*mousePos.y <= h )){
                            
                        return ScreenObjectID::HELP;    //help button
                            
                    }
               }
               
              
               if( (aspectRatioX*mousePos.x >= q)   && (aspectRatioX*mousePos.x <= r))  {
                    if((aspectRatioY*mousePos.y >= w) && (aspectRatioY*mousePos.y <= t)) {
                       
                        return ScreenObjectID::BACK;    //back button
                    }
               }
               
  return ScreenObjectID::BACKGROUND1;
}

void SplashScreen::GameScreen(){
    
    //Background2
     DrawScreenObject(vector2D{1080.0f, 600.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND2);
     
    }
    
void SplashScreen::YouLoose(){
    
    //set the text for the game lost
    gameText.setFillColor(sf::Color::Red);
    gameText.setCharacterSize(45);
    gameText.setPosition(135, 210);
    gameText.setString(TEXT_2);
    window_.draw(gameText);
}

void SplashScreen::YouWin(){
    
    //Set text for game won
    gameText.setFillColor(sf::Color::Green);
    gameText.setCharacterSize(55);
    gameText.setPosition(150, 250);
    gameText.setString(TEXT_3);
    window_.draw(gameText);
    
}

SplashScreen::~SplashScreen()
{
}

