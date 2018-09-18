#include "Display.h"


Display::Display(float screenWidth, float screenHeight):
screenWidth_(screenWidth),screenHeight_(screenHeight),
window_{sf::VideoMode(screenWidth_,screenHeight_),"Centipede Revived", sf::Style::Default}
{}
    
void Display::display(){
    
           sf::Event event;
        
           while(window_.pollEvent(event)){
            
            if(event.type==sf::Event::Closed)  window_.close();
            
            }
        
          window_.display();
          window_.clear();
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

