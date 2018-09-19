/*#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <SFML\Graphics.hpp>
#include "Csegment.h"

using  segments = std::vector<Csegment>;

class Centipede
{
public:

    Centipede(sf::Texture* texture, int length, float speed);
    ~Centipede();
    //Draw the centipede on the window
    void Draw(sf::RenderWindow& window);
    //Get the length of the centipede
    int getLength() const;
    //Move the centipede across the window
    void Move();
    
private: 

     //This is a vector of type Csegment.
     //The centipede is a vector of Csegment objects.
     segments centipede;
     int length_;
     float speed_;
     

};

#endif // CENTIPEDE_H
*/