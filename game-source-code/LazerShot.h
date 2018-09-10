#ifndef LAZERSHOT_H
#define LAZERSHOT_H
#include <SFML/Graphics.hpp>
#include "constants.h"

class LazerShot
{
public:
   
    LazerShot(sf::Color color, sf::Vector2f size, float speed);
    //Load the Player with the lazershot
    void Load(const sf::Vector2f& pos);
    //Fire the lazershot at a target
    void Fire();
    //Draw the lazershot on the screen
    void Draw(sf::RenderWindow & window);
    //Get position of the LazerShot
    sf::Vector2f getPosition() const;
    ~LazerShot();
    
private:
   sf::RectangleShape body_;
   float speed_;

};

#endif // LAZERSHOT_H
