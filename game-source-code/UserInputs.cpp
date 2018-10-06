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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
         return Key::PAUSE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
         return Key::RESUME;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
         return Key::ESC;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
         return Key::QUIT;
    else{
        return  Key::OTHERS;
        }
         
    }
