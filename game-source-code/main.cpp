#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Constants.h"
#include "Csegment.h"
#include "Centipede.h"
#include "SplashScreen.h"
#include <memory>

int main(){
    
  //Game Window
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT),"Centipede Revived", sf::Style::Default);
    
    //Game Textures
    sf::Texture centiTexture;
    centiTexture.loadFromFile("centi2.png");
    sf::Texture playertexture;
    playertexture.loadFromFile("ship.png");
    
    //Game objects
     auto player = std::make_unique<Player>(&playertexture,0.5f);
     auto splashscreen = std::make_unique<SplashScreen>(*window);
     auto centipede = std::make_unique<Centipede>(&centiTexture,10, 0.5f);
    
    //Game Booleans
     auto isPlaying = false;
     auto shoot = false;
     auto leftClick = false;
     auto openingWindow = true;
     auto help =  false;
     auto back = false;
    
     auto aspectRatioX  = 1.0f;
     auto aspectRatioY = 1.0f;
    
   
    
   
     while(window->isOpen()){
        
        sf::Event event;
        
         while(window->pollEvent(event)){
            
             //End Game?
            if(event.type==sf::Event::Closed)  window->close();
            
            //Ensure window is not resized above boundaries
            if(event.type==sf::Event::Resized){
                
                //Set aspectRation when window is resized
                aspectRatioX = ORIGINAL_SCREEN_WIDTH/window->getSize().x;
                aspectRatioY = ORIGINAL_SCREEN_HEIGHT/window->getSize().y;
                
                  //Above Boundary?
                  if(window->getSize().x >= 1920.0f){
                      
                      window->setSize(sf::Vector2u(1920.0f, window->getSize().y));
                      }
                  if(window->getSize().y >= 1080.0f){
                      
                      window->setSize(sf::Vector2u(window->getSize().y, 1080.0f));
                      }
                }
                //Shoot?
               if(event.type ==sf::Event::KeyPressed){
            
                    if(event.key.code== sf::Keyboard::Space) shoot = true;
                }
                
                if(event.type == sf::Event::MouseButtonPressed){
                    if (event.mouseButton.button == sf::Mouse::Left)
                        leftClick = true;
                        
                }
   
        
         }
         
         //Display Opening window
         if(openingWindow)
         {
             splashscreen->OpeningScreen();
             window->display();
             window->clear();
             isPlaying = false;
             back = false;
             }
         
         //Check user input
         if(leftClick){
             
             openingWindow = false;
             //Get mouse coordinates
             sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
             //return the flag for the button selected
             auto ButtonNum = splashscreen->DetectButton(mousePos,aspectRatioY, aspectRatioX );
             
             //User wants to play
             if(ButtonNum == 1){ isPlaying = true;}
             
             //User needs help
              if(ButtonNum == 2){ help = true;}
              
              //User wants to go back to Opening window
               if(ButtonNum == 3){ back = true;}
                  
              leftClick = false;
             
              }
              
              //Display instructions
              if(help){
                   
                   
                  splashscreen->HelpScreen();
                  window->display();
                  window->clear();
                  isPlaying = false;
                  
                  if(back){
                     help = false;
                 openingWindow = true;
                  }
                
                  
              }
              
             //user is playong
              else if(isPlaying){             
                    //Player wants to shoot
                    if(shoot) player->Shoot();
                    shoot = false;
         
                    centipede->Move();
                    player->Move();
                    player->Draw(*window);
                    centipede->Draw(*window);
                    window->display();
                    window->clear();
               }
             
         
         }
         

         
         
     
    
    return EXIT_SUCCESS;

}