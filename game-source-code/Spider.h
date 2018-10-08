#ifndef SPIDER_H
#define SPIDER_H
#include "GameObject.h"

/**
 * @class Spider
 * @date 08/10/2018
 * @file Spider.h
 * @brief Derived from GameObject class, the models a Spider in 2D 
 */

class Spider: public GameObject{

public:
      /**
      * @brief Constructor of the Spider Class
      * @param size of the Spider
      * @param position of the Spider
      * @param speed of the Spider
      * @param objectid ID of the Spider
      */
      Spider(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
      GameObject{size,position,speed,objectid}
      {}
     /**
      * @brief Move Spider Across Screen
      */
     virtual void Move() override;
     /**
      * @brief Reset Spider to initial conditions
      */
     virtual void reset() override;
     /**
      * @brief Explode the spider
      */
     virtual void collisionResponse() override { setObjectID(ObjectID::EXPLOSION2); }
     /**
      * @brief Destroy the Object
      */
     virtual ~Spider(){};
     
private:

      /**
       * @brief For down movement
       */
      void moveDown();
      /**
       * @brief For up movement
       */
      void moveUp();
      /**
       * @brief Up movement left or right
       */
      void moveZig();
      /**
       * @brief Down movement left or right
       */
      void moveZag();
      
      //Spider Controllers
      bool zigzag_ = true;
      bool up_ = false;
};

#endif // SPIDER_H
