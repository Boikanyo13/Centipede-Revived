#include "Display.h"


Display::Display(float screenWidth, float screenHeight):
screenWidth_(screenWidth),screenHeight_(screenHeight),
window_{make_shared<sf::RenderWindow>(sf::VideoMode(screenWidth_,screenHeight_),"Centipede Revived!", sf::Style::Default)}
{ 
    window_->setFramerateLimit(600);
}

void Display::Events(shared_ptr<UserInputs> userinput_ptr){
    
           sf::Event event;
        
           while(window_->pollEvent(event)){
            
            if(event.type==sf::Event::Closed)  window_->close();
            
            if(event.type==sf::Event::Resized){
                

              
                  //Above Boundary?
                  if(window_->getSize().x >= 1920.0f){
                      
                      window_->setSize(sf::Vector2u(1920.0f, window_->getSize().y));
                      }
                  if(window_->getSize().y >= 1080.0f){
                      
                      window_->setSize(sf::Vector2u(window_->getSize().y, 1080.0f));
                      }
            }
                //Shoot?
            
            if(userinput_ptr->pressedKey()==Key::SPACE){
                space_ = true;
                }
            if(userinput_ptr->pressedKey()==Key::ESC){
                window_->close();
                }
            //Mouse clicked on left?
            if(event.type == sf::Event::MouseButtonPressed){
                    if (event.mouseButton.button == sf::Mouse::Left)
                        leftClick_ = true;
                        
                }
            
        }
        

}



void Display::display(){
    
      window_->display();
      space_ = false;
      leftClick_ = false;
      
      if(delay){
          usleep(500000);
          delay = false;
      }
      if(delay2){
          usleep(100000);
          delay2 = false;
          }
}


