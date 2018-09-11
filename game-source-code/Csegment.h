#ifndef CSEGMENT_H
#define CSEGMENT_H
#include <SFML\Graphics.hpp>
#include "Constants.h"


/*This is the Centipede Segment Class*/

class Csegment
{
public:
       
    Csegment(sf::Texture* texture,sf::Vector2f InitPosition,sf::Vector2f size,float speed);
    //Draw the segment on the screen
    void Draw(sf::RenderWindow& window);
    //Get posotion of the Centipede Segment
    sf::Vector2f getPosition() const;
    //Move the Csegement
    void Move();
    ~Csegment();
    
private:
     //Called when centipede enters screen
     void Entrance();
     sf::RectangleShape body_;
     float speed_;
     //Check for foward movement
     bool forward_;
     //Check for upward movement
     bool up_;
};

#endif // CSEGMENT_H
