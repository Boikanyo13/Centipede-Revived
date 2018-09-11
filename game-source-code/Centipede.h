#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include <SFML\Graphics.hpp>
#include "Csegment.h"

using  segments = std::vector<Csegment>;

class Centipede
{
public:
    Centipede(sf::Texture* texture, int length, float speed);
    ~Centipede();
    void Draw(sf::RenderWindow& window);
    int getLength() const;
    void Move();
private: 
     segments centipede;
     int length_;
     float speed_;
     

};

#endif // CENTIPEDE_H
