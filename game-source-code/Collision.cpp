#include "Collision.h"

bool Collision::checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr){
    
     auto deltaX = abs(other_ptr->getPosition().x() - this_ptr->getPosition().x());
     auto deltaY = abs(other_ptr->getPosition().y() - this_ptr->getPosition().y());
    
     auto halfX = abs( other_ptr->getSize().x()/2.0f + this_ptr->getSize().x()/2.0f);
     auto halfY = abs( other_ptr->getSize().y()/2.0f + this_ptr->getSize().y()/2.0f);    
     

     if(deltaX <= halfX && deltaY <= halfY && !this_ptr->isDead() && !other_ptr->isDead()){
          
         if((other_ptr->ID() == ObjectID::CENTIPEDE) || (other_ptr->ID() == ObjectID::CHEAD))
              other_ptr->updateState(State::DEAD);
         
        if(this_ptr->ID()==ObjectID::BULLET){
             this_ptr->updateState(State::DEAD);
             }
      
          return true;
         }
   return false;
    
    }