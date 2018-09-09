#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Constants.h"
#include <memory>

int main(){
    
  
    auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT),"Centipede Revived", sf::Style::Default);
    sf::Texture playertexture;
    playertexture.loadFromFile("ship.png");
    
    auto player = std::make_unique<Player>(&playertexture,0.5f);
    
     while(window->isOpen()){
        
        sf::Event event;
        
         while(window->pollEvent(event)){
            
             //End Game?
            if(event.type==sf::Event::Closed)  window->close();
            
            //Ensure window is not resized above boundaries
            if(event.type==sf::Event::Resized){
                
                  //Above Boundary?
                  if(window->getSize().x >= 1920.0f){
                      
                      window->setSize(sf::Vector2u(1920.0f, window->getSize().y));
                      }
                  if(window->getSize().y >= 1080.0f){
                      
                      window->setSize(sf::Vector2u(window->getSize().y, 1080.0f));
                      }
                }
         }
         
         player->Move();
         player->Draw(*window);
         window->display();
         window->clear();
         
         
     }
    
    return EXIT_SUCCESS;

}