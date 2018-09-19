#include "Display.h"


Display::Display(float screenWidth, float screenHeight):
screenWidth_(screenWidth),screenHeight_(screenHeight),
window_{sf::VideoMode(screenWidth_,screenHeight_),"Centipede Revived", sf::Style::Default}
{
    space = false;
    
    }

void Display::Events(){
    
           sf::Event event;
        
           while(window_.pollEvent(event)){
            
            if(event.type==sf::Event::Closed)  window_.close();
            
            if(event.type==sf::Event::Resized){
                
                //Set aspectRation when window is resized
                //aspectRatioX = ORIGINAL_SCREEN_WIDTH/window->getSize().x;
              //  aspectRatioY = ORIGINAL_SCREEN_HEIGHT/window->getSize().y;
                
                  //Above Boundary?
                  if(window_.getSize().x >= 1920.0f){
                      
                      window_.setSize(sf::Vector2u(1920.0f, window_.getSize().y));
                      }
                  if(window_.getSize().y >= 1080.0f){
                      
                      window_.setSize(sf::Vector2u(window_.getSize().y, 1080.0f));
                      }
            }
                //Shoot?
            if(event.type ==sf::Event::KeyPressed){
            
                    if(event.key.code== sf::Keyboard::Space) space = true;
            }
            
}
        

}

void Display::display(){
    
      window_.display();
      window_.clear();
      space = false;
    
}


void Display::drawObject(shared_ptr<GameObject> gameobject_ptr){
    

    auto gameobject_SFML = drawSprite(gameobject_ptr);
    
    sf::Texture objectTexture;
    
    //Does the file exist?
    if(!objectTexture.loadFromFile(gamefile_.image(gameobject_ptr->ID()))){
        
        throw FileNotFound{};
        
        };
        
    gameobject_SFML.setTexture(&objectTexture);
    
    
    window_.draw(gameobject_SFML);
}

void Display::drawLazerShot(shared_ptr<Player> player_ptr){
    
   auto lazershots =std::get<1>(player_ptr->firedLazerShot(0));
    
    for(auto i = 0; i < lazershots; i++){
       
       auto gameobject_SFML = drawSprite(std::get<0>(player_ptr->firedLazerShot(i)));
            gameobject_SFML.setFillColor(sf::Color::Yellow);
            window_.draw(gameobject_SFML);
       }
}

bool Display::isOpen() const
{
    
    return window_.isOpen();
    
    }

sf::RectangleShape Display::drawSprite(shared_ptr<GameObject> gameobject_ptr){
    
           auto  gameobject_SFML = sf::RectangleShape{sf::Vector2f(gameobject_ptr->getSize().x(),gameobject_ptr->getSize().y())};
           gameobject_SFML.setPosition(gameobject_ptr->getPosition().x(),gameobject_ptr->getPosition().y());
           gameobject_SFML.setOrigin(gameobject_SFML.getSize()/2.0f);
           return  gameobject_SFML;
    }

Display::~Display()
{
}

