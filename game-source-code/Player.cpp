#include "Player.h"


Player::Player(sf::Texture* texture, float speed):speed_(speed){
     
     auto size = sf::Vector2f(PLAYER_X_SIZE,PLAYER_Y_SIZE);
     body_.setTexture(texture);
     body_.setSize(size);
     body_.setOrigin(size/2.0f);
     body_.setPosition(sf::Vector2f(280.0f,620.0f));
    
    }
    
void Player::Move(){
    
    auto deltaTime = 0.0f;
    deltaTime = sf::Clock().restart().asSeconds();
    deltaTime = 1.0f;
    
    //Left Move
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                
                //Check if at boundary
                if(body_.getPosition().x >= (0 + body_.getSize().x/2.0f )){
                    body_.move(-speed_*deltaTime,0.0f);
                }
                
                if(body_.getPosition().x < (0 + body_.getSize().x/2.0f))
                 body_.setPosition(body_.getSize().x/2.0f,body_.getPosition().y);
    }
    
    //Move Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                
                //Check if at boundary
                if(body_.getPosition().x <= (ORIGINAL_SCREEN_WIDTH - body_.getSize().x/2.0f)){
                    body_.move(speed_*deltaTime,0.0f);
                }
                
                if(body_.getPosition().x > (ORIGINAL_SCREEN_WIDTH - body_.getSize().x/2.0f))
                  body_.setPosition((ORIGINAL_SCREEN_WIDTH - body_.getSize().x/2.0f),body_.getPosition().y);
                
    }
       
    //Move Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
             
            //Check if at boundary
            if(body_.getPosition().y >= 2.0f*(ORIGINAL_SCREEN_HEIGHT/3)){
                
                body_.move(0.0f,-speed_*deltaTime);
                
                if(body_.getPosition().y < 2.0f*(ORIGINAL_SCREEN_HEIGHT/3))
                   body_.setPosition(body_.getPosition().x,2.0f*(ORIGINAL_SCREEN_HEIGHT/3));
            }
    }
        
    //Move Down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
             
            //Check if at boundary
            if(body_.getPosition().y <= (ORIGINAL_SCREEN_HEIGHT -body_.getSize().y/2.0f)){
                
                body_.move(0.0f,speed_*deltaTime);
            }
            
            if(body_.getPosition().y > (ORIGINAL_SCREEN_HEIGHT -body_.getSize().y/2.0f))
                body_.setPosition(body_.getPosition().x,(ORIGINAL_SCREEN_HEIGHT -body_.getSize().y/2.0f));
            
    }
        
}


void Player::Shoot(){
    
    lazershots.push_back(LazerShot{sf::Color::Yellow,sf::Vector2f(3.0f,7.0f), 0.5f});
    lazershots[noOfLazerShots].Load(body_.getPosition());
    noOfLazerShots++;
    

}

void Player::Draw(sf::RenderWindow & window){
     
     window.draw(body_);
     
      for(auto i = 0; i < noOfLazerShots; i++){          

           lazershots[i].Fire();
           lazershots[i].Draw(window);
         }
         
     
}

void Player::setSpeed(float speed){
    speed_= speed;
    
    }

void Player::setSize(const sf::Vector2f& size){
    
    body_.setSize(size);
    
    };
    
void Player::setTexture(sf::Texture* texture){
    
    body_.setTexture(texture);
    };
    

sf::Vector2f Player::getPosition(){
    
    return body_.getPosition();
    }

Player::~Player()
{
}

