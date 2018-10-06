#include "SplashScreen.h"

SplashScreen::SplashScreen(shared_ptr<Display> display_ptr): 
window_{display_ptr->window()}
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
     window_->draw(screenObject);
    
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
    gameText.setCharacterSize(30);
    gameText.setPosition(70, 100);
    gameText.setString(TEXT_1);
    
    //Back button
    auto backbutton = DrawScreenObject(vector2D{BUTTON_X_SIZE, BUTTON_Y_SIZE}, vector2D{BACK_X_POS, BACK_Y_POS}, ScreenObjectID::BACK);
    std::tie(q,r,w,t) = ButtonDimension(backbutton);
    window_->draw(gameText);
    
     }

ScreenObjectID SplashScreen::DetectButton()
{
    sf::Vector2i mousePos  = sf::Mouse::getPosition(*window_);
    
    //For accurate button detection
    auto aspectRatioX = ORIGINAL_SCREEN_WIDTH/window_->getSize().x;
    auto aspectRatioY = ORIGINAL_SCREEN_HEIGHT/window_->getSize().y;
                
    
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

void SplashScreen::Pause(){
    
   if(blink_){  
 
    gameText.setCharacterSize(45);
    gameText.setFillColor(sf::Color::Yellow);
    gameText.setPosition(20.0f, 285.5f-2.5*35.0f);
    gameText.setString("\t\t   p a u s e d !");
    window_->draw(gameText);
    }
    
    blink_ = !blink_;
    
    gameText.setCharacterSize(35);
    gameText.setFillColor(sf::Color::Yellow);
    gameText.setPosition(20.0f, 285.5f-35.0f);
    gameText.setString("\np r e s s  r  t o  r e s u m e");
    window_->draw(gameText);
     
    gameText.setFillColor(sf::Color::Red);
    gameText.setPosition(-4.0f, 285.5f+17.5f);
    gameText.setString("\n\t\t\t\t p r e s s  Q  \n t o  q u i t to m a i n   m e n u");
    
    
    window_->draw(gameText);
    
    }

void SplashScreen::GameScreen(shared_ptr<Score> score_ptr, int lives){
    
    //Background2
    auto score_ = std::to_string(score_ptr->score());
    auto posX = 100.0f;
     DrawScreenObject(vector2D{1080.0f, 600.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND2);
     
      //Score
     for(auto i = 0; i< lives; i++)
     {  
        DrawScreenObject(vector2D{30.0f, 30.0f},vector2D{posX,5.0f}, ScreenObjectID::LIFE);
        posX+=25.0f;
     }
    
    //current score
    gameText.setFillColor(sf::Color::Green);
    gameText.setCharacterSize(20);
    gameText.setPosition(20.0f, 5.0f);
    gameText.setString(score_);
    window_->draw(gameText);
    
    //highscore
    auto scores = gamefile_.scorefile();
    auto highscore = std::to_string(scores[0]);
    gameText.setFillColor(sf::Color::Green);
    gameText.setPosition(220.0f, 5.0f);
    gameText.setString(highscore);
    window_->draw(gameText);
     
    }
    
void SplashScreen::YouLoose(int score){
    
   
     
     
     
    //Background2
    DrawScreenObject(vector2D{1080.0f, 600.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND2);
     //Back button
    auto backbutton = DrawScreenObject(vector2D{BUTTON_X_SIZE, BUTTON_Y_SIZE}, vector2D{BACK_X_POS, BACK_Y_POS}, ScreenObjectID::BACK);
    std::tie(q,r,w,t) = ButtonDimension(backbutton);
    //set the text for the game lost
    gameText.setFillColor(sf::Color::Red);
    gameText.setCharacterSize(55);
    gameText.setPosition(100, 110);
    gameText.setString(TEXT_2);
    window_->draw(gameText);
    HighScores(score);
    
}

void SplashScreen::YouWin(int score){
    
    //Background2
     DrawScreenObject(vector2D{1080.0f, 600.0f},vector2D{0.0f,0.0f}, ScreenObjectID::BACKGROUND2);
    //Set text for game won
    gameText.setFillColor(sf::Color::Green);
    gameText.setCharacterSize(55);
    gameText.setPosition(120, 110);
    gameText.setString(TEXT_3);
    window_->draw(gameText);
    
    HighScores(score);
}

void SplashScreen::HighScores(int score){
   
   auto score_ = std::to_string(score);
   auto highscores =  gamefile_.scorefile();
   gameText.setCharacterSize(30);
   auto  deltaY  = 0;
   gameText.setPosition(130, 170);
   gameText.setFillColor(sf::Color::Yellow);
   gameText.setString("\n Your score : "+ score_ +"\n" );
   window_->draw(gameText);
   gameText.setFillColor(sf::Color::Red);
    gameText.setPosition(160, 250);
   gameText.setString("HIGH SCORES");
   window_->draw(gameText);

  
   for(auto i = 0u; i < highscores.size(); i++ )
   {    deltaY +=40;
   
       if(score==highscores[i]){
           gameText.setFillColor(sf::Color::Yellow); 
       }
       else{
           gameText.setFillColor(sf::Color::Red);
        }
       gameText.setString(std::to_string(highscores[i]));
       gameText.setPosition(225, 260+deltaY);
       
        window_->draw(gameText);
   }
   
     
 }
 


