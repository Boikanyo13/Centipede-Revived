#include "Collider.h"

Collider::Collider(shared_ptr<Score> score_ptr):_score_ptr{score_ptr}{

 }

void Collider::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr)
{
      
     auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
    
     for(auto i = 0; i < lazershots; i++){
       
         for(auto j = 0; j < centipede_ptr->length(); j++){
         
             if(checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),centipede_ptr->centiSegment(j))){
                  
                 //Increase the number of destroyed  segment 
                  centipede_ptr->SegmentDestroyed();
                  
                  //make the previous segment head if the one before it is destroyed
                  if((j < centipede_ptr->length() - 1)){
                  
                      (centipede_ptr->centiSegment(j+1))->head();
                  
                  }
                  
                 if(centipede_ptr->centiSegment(j)->isHead()){
                         //Update Score
                       _score_ptr->centiheadDestroyed();
                 }
                  else{  //Transform the shot centipede into a Mushroom
                         mushroom_ptr->transform(centipede_ptr->centiSegment(j));
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
             spider_ptr->explode();
             }
     }

}

void Collider::mushroomDestroyed(shared_ptr<Spider> spider_ptr,shared_ptr<MushroomField> mushroom_ptr){
    
    for(auto i = 0; i < mushroom_ptr->size(); i++){
           
          //Mushroom dies if collides with Spider
          if(checkCollision(spider_ptr,mushroom_ptr->mushroom(i))){
              mushroom_ptr->mushroom(i)->updateState(State::DEAD);
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
                 spaceship_ptr->explode();
       }
       
   
}

void Collider::mushroomShot(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
    
     for(auto i = 0; i < lazershots; i++){
         
         for(auto j = 0; j < mushroom_ptr->size(); j++){
             
              if(checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),mushroom_ptr->mushroom(j))){
                     //Flag the mushroom as being shot
                     mushroom_ptr->mushroom(j)->shot();
                     //Update Score
                     _score_ptr->mushroomDestroyed();
              
              }
             }
         }
}


void Collider::spaceshipCollision(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr, Key key){
    

    for(auto i = 0; i < mushroom_ptr->size(); i++){
         
          //Restrict spaceship from moving to the direction of the Collision
          if(checkCollision(spaceship_ptr,mushroom_ptr->mushroom(i))){
              spaceship_ptr->mushroomCollision(true,key);
               break;
          }
          else{ spaceship_ptr->mushroomCollision(false,key);}
            
        }
 
}

void Collider::mushroomHit(shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    for(auto i = 0; i < mushroom_ptr->size(); i++){
       
        for(auto j = 0; j < centipede_ptr->length(); j++){
             
            //Change Centiped direction if hits a mushroom
            if(checkCollision(centipede_ptr->centiSegment(j),mushroom_ptr->mushroom(i)))
                     centipede_ptr->centiSegment(j)->mushroomHit();     
           
           }
       
       }
    
}

void Collider::spaceshipHit( shared_ptr<Centipede> centipede_ptr,shared_ptr<Spaceship> spaceship_ptr){
    
    
     
     for(auto i = 0; i < centipede_ptr->length(); i++){
            
          if(checkCollision(centipede_ptr->centiSegment(i),spaceship_ptr)){
           
                //spaceship looses a life if hit
                if(!(spaceship_ptr->ID()==ObjectID::EXPLOSION))
                      spaceship_ptr->lostLife();
                  
                //Explode the spaceship
                 spaceship_ptr->explode();
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

