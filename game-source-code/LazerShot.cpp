#include "LazerShot.h"
#include <iostream>


LazerShot::LazerShot(sf::Color color, sf::Vector2f size, float speed):speed_(speed){
    
    body_.setSize(size);
    body_.setFillColor(color);
    body_.setOrigin(size/2.0f);
    }
    
    
void LazerShot::Fire(){
    
    auto deltaTime = 0.0f;
    deltaTime = sf::Clock().restart().asSeconds();
    deltaTime = 1.0f;
     //Move the bullet upright
    body_.move(0.0f, -speed_*deltaTime);
    
    }

void LazerShot::Draw(sf::RenderWindow & window){
    
    window.draw(body_);
    
    }


void LazerShot::Load(const sf::Vector2f& pos){
    
    //Set the position of the lazershot to that of the player
    body_.setPosition(pos);
    
    } 

sf::Vector2f LazerShot::getPosition() const
{
    return body_.getPosition();
    }

LazerShot::~LazerShot()
{
}

