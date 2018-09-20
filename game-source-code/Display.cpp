#include "Display.h"


Display::Display(float screenWidth, float screenHeight):
screenWidth_(screenWidth),screenHeight_(screenHeight),
window_{sf::VideoMode(screenWidth_,screenHeight_),"Centipede Revived", sf::Style::Default}
{
    space = false;
   
    auto textures = gamefile_.images();
    auto size = textures.size();
    
    for(auto i = 0u; i < size; i++){
        
        sf::Texture temp;
        if(!temp.loadFromFile(textures[i])){
            throw FileNotFound{};
            
            };
        textures_.push_back(temp);
    
        }
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

void Display::drawCentipede(shared_ptr<Centipede> centi_ptr){
      
      for (auto i = 0; i < centi_ptr->length() ; i++){
        
    if(!centi_ptr->centiSegment(i)->isDead()){
      drawObject(centi_ptr->centiSegment(i));
    }
      }
}


void Display::drawObject(shared_ptr<GameObject> gameobject_ptr){
    

    auto gameobject_SFML = drawSprite(gameobject_ptr);
        
  switch(gameobject_ptr->ID()){    
        
     case ObjectID::BULLET:
            gameobject_SFML.setTexture(&textures_[1]);
            break;
        
        case ObjectID::PLAYER:
            gameobject_SFML.setTexture(&textures_[0]);
            break;
        case ObjectID::CENTIPEDE:
            gameobject_SFML.setTexture(&textures_[2]);
             break;
       
            
        default:

        break;
    
    }
  
    window_.draw(gameobject_SFML);
}

void Display::drawLazerShot(shared_ptr<Player> player_ptr){
    
   auto lazershots =std::get<1>(player_ptr->firedLazerShot(0));
    
    for(auto i = 0; i < lazershots; i++){
       
       drawObject(std::get<0>(player_ptr->firedLazerShot(i)));
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

