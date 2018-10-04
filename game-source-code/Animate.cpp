#include "Animate.h"

Animate::Animate(shared_ptr<Display> display_ptr): 
window_ptr_(display_ptr->window())
{
    auto file = gamefile_.objectImages();
    auto size = file.size();
    
    //Load object files
    for(auto i = 0u; i < size; i++){
        
        sf::Texture temp;
        if(!temp.loadFromFile(file[i])){
            throw FileNotFound{};
            
            };
        textures_.push_back(temp);
    
        }
}

void Animate::animate(shared_ptr<GameObject> gameobject_ptr){
    
    if(!gameobject_ptr->isDead()){
        
        auto gameobject_anim = createSprite(gameobject_ptr);
        
        gameobject_anim.setTexture(&textures_[static_cast<int>(gameobject_ptr->ID())]);
        window_ptr_->draw(gameobject_anim);
    }
}


void Animate::animate(shared_ptr<GameObjectContainer> gameObjectContainer_ptr){
    
    for(auto i = 0; i < gameObjectContainer_ptr->size(); i++){
         
         animate(gameObjectContainer_ptr->segment(i));
        }
}

void Animate::animateLazerShots(shared_ptr<Spaceship> spaceship_ptr){
    
   auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
    
    for(auto i = 0; i < lazershots; i++){
       
       animate(std::get<0>(spaceship_ptr->firedLazerShot(i)));
       }
}

sf::RectangleShape Animate::createSprite(shared_ptr<GameObject> gameobject_ptr){
    
    auto  gameobject_SFML = sf::RectangleShape{sf::Vector2f(gameobject_ptr->getSize().x(),gameobject_ptr->getSize().y())};
    gameobject_SFML.setPosition(gameobject_ptr->getPosition().x(),gameobject_ptr->getPosition().y());
    gameobject_SFML.setOrigin(gameobject_SFML.getSize()/2.0f);
    
    return  gameobject_SFML;
}

