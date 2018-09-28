#include "Display.h"


Display::Display(float screenWidth, float screenHeight):
screenWidth_(screenWidth),screenHeight_(screenHeight),
window_{sf::VideoMode(screenWidth_,screenHeight_),"Centipede Revived", sf::Style::Default},
splashscreen_{window_}
{ 
    window_.setFramerateLimit(600);
    space_ = false;
    leftClick_ = false;
    delay = false;
    delay2 = false;
    
    auto textures = gamefile_.objectImages();
    auto size = textures.size();
    
    //Load object files
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
            
                    if(event.key.code== sf::Keyboard::Space) space_ = true;
            }
            
            //Mouse clicked on left?
            if(event.type == sf::Event::MouseButtonPressed){
                    if (event.mouseButton.button == sf::Mouse::Left)
                        leftClick_ = true;
                        
                }
            
        }
        

}



void Display::display(){
    
      window_.display();
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

void Display::drawCentipede(shared_ptr<Centipede> centi_ptr){
      
      for (auto i = 0; i < centi_ptr->length() ; i++){
        
      drawObject(centi_ptr->centiSegment(i));

      }
}

void Display::drawMushroomField(shared_ptr<MushroomField> mushroom_ptr){
    
    for(auto i = 0; i <  mushroom_ptr->size(); i++){
         
         drawObject(mushroom_ptr->mushroom(i));
        }
}


void Display::drawObject(shared_ptr<GameObject> gameobject_ptr){
    
    if(!gameobject_ptr->isDead()){
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
       case ObjectID::CHEAD:
             gameobject_SFML.setTexture(&textures_[3]);
            break;
        case ObjectID::EXPLOSION:
              gameobject_SFML.setTexture(&textures_[4]);
              delay = true;
              break;
        case ObjectID::MUSHROOM:
              gameobject_SFML.setTexture(&textures_[5]);
              break;
         case ObjectID::MUSHROO:
              gameobject_SFML.setTexture(&textures_[6]);
              break;
        case ObjectID::MUSHRO:
              gameobject_SFML.setTexture(&textures_[7]);
              break;
        case ObjectID::MUSHR:
              gameobject_SFML.setTexture(&textures_[8]);
              break;
        case ObjectID::SPIDER:
              gameobject_SFML.setTexture(&textures_[9]);
              break;
         case ObjectID::EXPLOSION2:
              gameobject_SFML.setTexture(&textures_[10]);
              delay2 = true;
              break;        
            
        default:

        break;
    
    }
  
    window_.draw(gameobject_SFML);}
    else{
        //Do nothing
        
        }
    
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

void Display::openingWindow(){
    
    splashscreen_.OpeningScreen();
    
    }

void Display::helpWindow(){
    
    splashscreen_.HelpScreen();
    }

void Display::gameWindow(shared_ptr<Score> score_ptr, int lives){
    splashscreen_.GameScreen(score_ptr->score(), lives);
    }
    
Display::~Display()
{
}

