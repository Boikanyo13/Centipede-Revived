#include "GameObject.h"

GameObject::GameObject(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):size_{size},position_{position}{
    
    speed_ = speed;
    
    }
    
void GameObject::setPosition(const vector2D& position){
    
    position_ = position;
    }
 
void GameObject::setSize(const vector2D& size){
    
    size_ = size;
    }
    
void GameObject::setSpeed(float speed){
    
    speed_ = speed;
    
    }
    
void GameObject::setObjectID(ObjectID oID){
    
    objectID_ = oID;
    
    }
    
void GameObject::updateState(State state){
    
    switch(state){
        
        case State::DEAD:
            isDead_ = true;
            break;
        case State::ALIVE:
            isDead_ = false;
            break;
        default:
             break; 
        }
    
    
    }
    
bool GameObject::isDead() const{
    
    return isDead_;
    };

float GameObject::getSpeed() const{
    
    return speed_;
    }

vector2D GameObject::getPosition() const{
    
    return position_;
    }

vector2D GameObject::getSize() const{
    
    return size_;
    }
    
ObjectID GameObject::ID() const{
    
    return objectID_;
    }

GameObject::~GameObject(){}

