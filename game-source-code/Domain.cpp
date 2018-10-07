#include "Domain.h"


void Domain::update(){
    

     if(timer_ptr->elapsedTime()==0){
         timer_ptr->start();
         }
         
         
     player_ptr->Move();
     centipede_ptr->Move();
     spaceship_ptr->shoot();
     
     timer_ptr->end();
     
     if(!spider_ptr->isDead() && timer_ptr->elapsedTime() >= 3.5){
         
        spider_ptr->Move();
         }
}
    
void Domain::shoot(bool shoot){
    
    if(shoot && !spaceship_ptr->isDead() && !(spaceship_ptr->ID()==ObjectID::EXPLOSION)){
            
            spaceship_ptr->load();
            isShooting_ = true;
          
            }
}

void Domain::handleShootingCollisions(){
    
    spaceship_ptr->shoot();
    
    if(!spaceship_ptr->isDead()){
             
            collision_ptr->mushroomShot(spaceship_ptr,mushroomfield_ptr);  
            collision_ptr->targetDestroyed(spaceship_ptr,centipede_ptr,mushroomfield_ptr);
            collision_ptr->targetDestroyed(spaceship_ptr,spider_ptr);
         }
}

void Domain::handleGameObjectCollisions(){
    
        collision_ptr->mushroomDestroyed(spider_ptr,mushroomfield_ptr);
        
        collision_ptr->spaceshipHit(spider_ptr,spaceship_ptr);
         
         //detect if the centipede collides with a mushroom
        collision_ptr->mushroomHit(centipede_ptr,mushroomfield_ptr);
        
        //detect if a spaceship collides with a mushroom
        collision_ptr->spaceshipCollision(spaceship_ptr,mushroomfield_ptr,player_ptr);
        
         collision_ptr->spaceshipHit(centipede_ptr,spaceship_ptr);
}

void Domain::deathHandler(){
    
    if(spaceship_ptr->ID() == ObjectID::EXPLOSION){
             
          if(spaceship_ptr->Lives())
                spaceship_ptr->reset();
             
             centipede_ptr->reset();
             spider_ptr->reset();
             timer_ptr->reset();
             isShooting_ = false;
             }
    
      //Revive the Spider if Shot   
       if(spider_ptr->ID()==ObjectID::EXPLOSION2){
              spider_ptr->reset();
              timer_ptr->reset();
              }
              
      if(centipede_ptr->isDead()){
             
             spaceship_ptr->reset();
             centipede_ptr->reset();
             mushroomfield_ptr->reset();
             isShooting_ = false;
             
            }
    
}

tuple<bool,bool,bool> Domain::states(){
    
    auto spaceshipExplosion = (spaceship_ptr->ID()==ObjectID::EXPLOSION)&&(!spaceship_ptr->isDead());
    auto spiderExplosion = (spider_ptr->ID() == ObjectID::EXPLOSION2);
    auto centipedDeath = centipede_ptr->isDead();
    return tie(spaceshipExplosion,centipedDeath,spiderExplosion);
    }

void Domain::masterReset(){
    
        spaceship_ptr->reset();
        mushroomfield_ptr->reset();
        centipede_ptr->reset();
        score_ptr->reset();
        spaceship_ptr->Lives(3);

    }