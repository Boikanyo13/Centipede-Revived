#include "Collider.h"

Collider::Collider(shared_ptr<Score> score_ptr):_score_ptr{score_ptr}{

 }

void Collider::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr)
{
      
     auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
    
     for(auto i = 0; i < lazershots; i++){
       
         for(auto j = 0; j < centipede_ptr->size(); j++){
         
             if(checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),centipede_ptr->segment(j))){
                  
                 //Increase the number of destroyed  segment 
                  centipede_ptr->SegmentDestroyed();
                  
                  //make the previous segment head if the one before it is destroyed
                  if((j < centipede_ptr->size() - 1)){
                  
                      (centipede_ptr->segment(j+1))->setObjectID(ObjectID::CHEAD);
                  
                  }
                  
                 if(centipede_ptr->segment(j)->ID()==ObjectID::CHEAD){
                         //Update Score
                       _score_ptr->centiheadDestroyed();
                 }
                  else{  //Transform the shot centipede into a Mushroom
                         mushroom_ptr->transform(centipede_ptr->segment(j));
                         //Update Score
                        _score_ptr->centibodyDestroyed();}
                     
                     }
         
         }
       }
    
}

void Collider::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Spider> spider_ptr){
    
     auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
     for(auto i = 0; i < lazershots; i++){
         
         if(checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),spider_ptr)){
             //Add to score
             _score_ptr->spiderDestroyed();
             //Explode the spider
             spider_ptr->collisionResponse();
             }
     }

}

void Collider::mushroomDestroyed(shared_ptr<GameObject> gameObject_ptr,shared_ptr<GameObjectContainer> gameObjectContainer_ptr){
    
    for(auto i = 0; i <gameObjectContainer_ptr->size(); i++){
           
          //Mushroom dies if collides with Spider
          if(checkCollision( gameObject_ptr, gameObjectContainer_ptr->segment(i))){
              gameObjectContainer_ptr->segment(i)->collisionResponse();
          }
        }

}


void Collider::spaceshipHit(shared_ptr<Spider> spider_ptr, shared_ptr<Spaceship> spaceship_ptr)
{
   if(checkCollision(spider_ptr,spaceship_ptr)){
               
                //spaceship loses life if collides with a Spider
              if(!(spaceship_ptr->ID()==ObjectID::EXPLOSION))
                      spaceship_ptr->lostLife();
                  
                //Explode the spaceship
                 spaceship_ptr->collisionResponse();
       }
       
   
}

void Collider::mushroomShot(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
    
     for(auto i = 0; i < lazershots; i++){
         
         for(auto j = 0; j < mushroom_ptr->size(); j++){
             
              if(checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),mushroom_ptr->segment(j))){
                     //Flag the mushroom as being shot
                     mushroom_ptr->segment(j)->collisionResponse();
                     //Update Score
                     _score_ptr->mushroomDestroyed();
              
              }
             }
         }
}


void Collider::spaceshipCollision(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr, shared_ptr<Player> player_ptr){
    

    for(auto i = 0; i < mushroom_ptr->size(); i++){
         
          //Restrict spaceship from moving to the direction of the Collision
          if(checkCollision(spaceship_ptr,mushroom_ptr->segment(i))){
              //spaceship_ptr->mushroomCollision(true,key);
              player_ptr->mushroomCollision(true);
               break;
          }
          
            
        }
 
}

void Collider::mushroomHit(shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    for(auto i = 0; i < mushroom_ptr->size(); i++){
       
        for(auto j = 0; j < centipede_ptr->size(); j++){
             
            //Change Centiped direction if hits a mushroom
            if(checkCollision(centipede_ptr->segment(j),mushroom_ptr->segment(i)))
                     centipede_ptr->segment(j)->collisionResponse();     
           
           }
       
       }
    
}

void Collider::spaceshipHit( shared_ptr<Centipede> centipede_ptr,shared_ptr<Spaceship> spaceship_ptr){
    
    
     
     for(auto i = 0; i < centipede_ptr->size(); i++){
            
          if(checkCollision(centipede_ptr->segment(i),spaceship_ptr)){
           
                //spaceship looses a life if hit
                if(!(spaceship_ptr->ID()==ObjectID::EXPLOSION))
                      spaceship_ptr->lostLife();
                  
                //Explode the spaceship
                 spaceship_ptr->collisionResponse();
          }
         }
    
   
    }


bool Collider::checkCollision(shared_ptr<GameObject> this_ptr, shared_ptr<GameObject> other_ptr){
    
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

Collider::~Collider()
{
    
    
}

