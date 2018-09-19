#include "UserInputs.h"



Key UserInputs::pressedKey(){
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        return Key::LEFT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
         return Key::RIGHT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
         return Key::UP;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
         return Key::DOWN;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
         return Key::SPACE;
    else{
        return  Key::OTHERS;
        }
         
    }
