#include "Collider.h"


void Collider::isTargetDestroyed(shared_ptr<Player> player_ptr, shared_ptr<Centipede> centipede_ptr)
{
      
     auto lazershots =std::get<1>(player_ptr->firedLazerShot(0));
     
    
     for(auto i = 0; i < lazershots; i++){
       
         for(auto j = 0; j < centipede_ptr->length(); j++){
         
             if(checkCollision(std::get<0>(player_ptr->firedLazerShot(i)),centipede_ptr->centiSegment(j))){
                  
                  if(j < centipede_ptr->length() - 1)
                  (centipede_ptr->centiSegment(j+1))->head();
                  
                 }
         
         }
       }
    
    
   
}

void Collider::isPlayerHit( shared_ptr<Centipede> centipede_ptr,shared_ptr<Player> player_ptr){
    
    
     
     for(auto i = 0; i < centipede_ptr->length(); i++){
            
          if(checkCollision(centipede_ptr->centiSegment(i),player_ptr))
                player_ptr->explode();
         }
    
   
    }


bool Collider::checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr){
    
     auto deltaX = abs(other_ptr->getPosition().x() - this_ptr->getPosition().x());
     auto deltaY = abs(other_ptr->getPosition().y() - this_ptr->getPosition().y());
    
     auto halfX = abs( other_ptr->getSize().x()/2.0f + this_ptr->getSize().x()/2.0f);
     auto halfY = abs( other_ptr->getSize().y()/2.0f + this_ptr->getSize().y()/2.0f);    
     

     if(deltaX <= halfX && deltaY <= halfY && !this_ptr->isDead() && !other_ptr->isDead()){
          
         other_ptr->updateState(State::DEAD);
         
        if(this_ptr->ID()==ObjectID::BULLET){
             this_ptr->updateState(State::DEAD);
             }
      
          return true;
         }
   return false;
    
}

Collider::~Collider()
{
    
    
}

