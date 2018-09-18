#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Constants.h"
#include "Csegment.h"
#include "Centipede.h"
#include "SplashScreen.h"
#include <memory>
#include <SFML/Audio.hpp>


int main(){
    
  //Game Window
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT),"Centipede Revived", sf::Style::Default);
    
   

}