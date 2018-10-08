#include "CollisionHandler.h"

void CollisionHandler::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr)
{
      
     auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
    
     for(auto i = 0; i < lazershots; i++){
       
         for(auto j = 0; j < centipede_ptr->size(); j++){
         
             if(_collision_ptr->checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),centipede_ptr->segment(j))){
                  
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

void CollisionHandler::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Spider> spider_ptr){
    
     auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
     for(auto i = 0; i < lazershots; i++){
         
         if(_collision_ptr->checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),spider_ptr)){
             //Add to score
             _score_ptr->spiderDestroyed();
             //Explode the spider
             spider_ptr->collisionResponse();
             }
     }

}

void CollisionHandler::mushroomDestroyed(shared_ptr<GameObject> gameObject_ptr,shared_ptr<GameObjectContainer> gameObjectContainer_ptr){
    
    for(auto i = 0; i <gameObjectContainer_ptr->size(); i++){
           
          //Mushroom dies if collides with Spider
          if(_collision_ptr->checkCollision( gameObject_ptr, gameObjectContainer_ptr->segment(i))){
              gameObjectContainer_ptr->segment(i)->collisionResponse();
          }
        }

}


void CollisionHandler::spaceshipHit(shared_ptr<Spider> spider_ptr, shared_ptr<Spaceship> spaceship_ptr)
{
   if(_collision_ptr->checkCollision(spider_ptr,spaceship_ptr)){
               
                //spaceship loses life if collides with a Spider
              if(!(spaceship_ptr->ID()==ObjectID::EXPLOSION))
                      spaceship_ptr->lostLife();
                  
                //Explode the spaceship
                 spaceship_ptr->collisionResponse();
}
       
   
}

void CollisionHandler::mushroomShot(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
    
     for(auto i = 0; i < lazershots; i++){
         
         for(auto j = 0; j < mushroom_ptr->size(); j++){
             
              if(_collision_ptr->checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),mushroom_ptr->segment(j))){
                     //Flag the mushroom as being shot
                     mushroom_ptr->segment(j)->collisionResponse();
                     //Update Score
                     _score_ptr->mushroomDestroyed();
              
              }
             }
         }
}


void CollisionHandler::spaceshipCollision(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<MushroomField> mushroom_ptr, shared_ptr<Player> player_ptr){
    

    for(auto i = 0; i < mushroom_ptr->size(); i++){
         
          //Restrict spaceship from moving to the direction of the Collision
          if(_collision_ptr->checkCollision(spaceship_ptr,mushroom_ptr->segment(i))){
              //spaceship_ptr->mushroomCollision(true,key);
              player_ptr->mushroomCollision(true);
               break;
          }
          
            
        }
 
}

void CollisionHandler::mushroomHit(shared_ptr<Centipede> centipede_ptr, shared_ptr<MushroomField> mushroom_ptr){
    
    for(auto i = 0; i < mushroom_ptr->size(); i++){
       
        for(auto j = 0; j < centipede_ptr->size(); j++){
             
            //Change Centiped direction if hits a mushroom
            if(_collision_ptr->checkCollision(centipede_ptr->segment(j),mushroom_ptr->segment(i)))
                     centipede_ptr->segment(j)->collisionResponse();     
           
           }
       
       }
    
}

void CollisionHandler::spaceshipHit(shared_ptr<Centipede> centipede_ptr,shared_ptr<Spaceship> spaceship_ptr){
    
      for(auto i = 0; i < centipede_ptr->size(); i++){
            
          if(_collision_ptr->checkCollision(centipede_ptr->segment(i),spaceship_ptr)){
           
                //spaceship looses a life if hit
                if(!(spaceship_ptr->ID()==ObjectID::EXPLOSION))
                      spaceship_ptr->lostLife();
                  
                //Explode the spaceship
                 spaceship_ptr->collisionResponse();
          }
         }
}


void CollisionHandler::targetDestroyed(shared_ptr<Spaceship> spaceship_ptr, shared_ptr<Scorpion> scorpion_ptr){
    
    
       auto lazershots =std::get<1>(spaceship_ptr->firedLazerShot(0));
     
     for(auto i = 0; i < lazershots; i++){
         
         if(_collision_ptr->checkCollision(std::get<0>(spaceship_ptr->firedLazerShot(i)),scorpion_ptr)){
             //Add to score
             _score_ptr->scorpionDestroyed();
             //Explode the spider
             scorpion_ptr->collisionResponse();
             }
     }
    
    
    }
