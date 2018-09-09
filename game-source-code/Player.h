#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <memory>


class Player
{
public:

    Player(sf::Texture* texture, float speed);
    //Move the player across the window
    void Move();
    //Draw the player on the window
    void Draw(sf::RenderWindow& window);
    //Set moving speed of player
    void setSpeed(float speed);
    //Set size of player
    void setSize(const sf::Vector2f& size);
    //Set texture of player
    void setTexture(sf::Texture* texture);
    //Check position of player
    sf::Vector2f getPosition();
    ~Player();

private:
    sf::RectangleShape body_;
    float speed_;
  
};

#endif // PLAYER_H
