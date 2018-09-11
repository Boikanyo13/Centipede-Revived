#include "Csegment.h"

Csegment::Csegment(sf::Texture* texture,sf::Vector2f InitPosition, sf::Vector2f size, float speed):speed_(speed)
{
   
    body_.setSize(size);
    body_.setFillColor(sf::Color::Green);
    body_.setPosition(InitPosition.x, InitPosition.y);
    body_.setTexture(texture);
    body_.setOrigin(size/2.0f);
    forward_ = true;
    up_ = false;
}

void Csegment::Entrance(){

        body_.move(0.0f,speed_);
}    

void Csegment::Move(){
    
  if(body_.getPosition().y <= body_.getSize().y){  Entrance(); }
   else{
    
   //Move segment  one row up or down if it is at right boundry
    if(body_.getPosition().x >= (ORIGINAL_SCREEN_WIDTH  - body_.getSize().x)){
        
        forward_ = false;
        
        if(!up_) body_.move(0.0f,body_.getSize().y);
        else body_.move(0.0f, - body_.getSize().y);
    }
    //Move segment  one row up or down if boundry at left boundry
    else if( body_.getPosition().x <= body_.getSize().x/2.0f){
        
        forward_ = true;
        if(!up_) body_.move(0.0f, body_.getSize().y);
        else body_.move(0.0f, -body_.getSize().y);
    }
    
    //Move segment left or right  depending on current direction
    if(forward_) body_.move(speed_, 0.0f);
    else body_.move(-speed_, 0.0f);
    
    if(body_.getPosition().y >= (ORIGINAL_SCREEN_HEIGHT -body_.getSize().y/2.0f)) up_ = true;
   else if (body_.getPosition().y <= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)) up_ = false;
    
    }
    
    }

sf::Vector2f Csegment::getPosition() const
{
    return body_.getPosition();
    }
    
void Csegment::Draw(sf::RenderWindow& window){
    
    window.draw(body_);
    }
    
Csegment::~Csegment()
{
}

