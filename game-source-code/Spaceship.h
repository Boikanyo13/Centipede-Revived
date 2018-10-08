#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Constants.h"
#include "GameObject.h"
#include "UserInputs.h"
#include "LazerShot.h"
#include <memory>
#include <vector>

/**
 * @class Spaceship
 * @date 08/10/2018
 * @file Spaceship.h
 * @brief This class is derived from the GameObject class and models the Spaceship in a 2D space
 */

class Spaceship: public GameObject{
public:
   /**
      * @brief Constructor of the Spaceship Class
      * @param size of the Spaceship
      * @param position of the Spaceship
      * @param speed of the Spaceship
      * @param objectid ID of the Spaceship
      */
    Spaceship(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    /**
     * @brief Game Object moves is not used for Spaceship
     */
    virtual void Move() override{};
    /**
     * @brief Return fired lazer shot
     * @param i iterator to LazerShots Container
     * @return  LazerShot
     */
    std::tuple<std::shared_ptr<LazerShot>,int> firedLazerShot(int i) const{return std::tie(lazerShotsGun_[i], noOfLazerShots_);}
    /**
     * @brief Load the LazerShot gun of the Spaceship
     */
    void load();
    /**
     * @brief Fire at the at the target
     */
    void shoot();
    /**
     * @brief Explode the Spaceship
     */
    virtual void collisionResponse() override;
    /**
     * @brief Decreement the number of lives
     */
    void lostLife();
    /**
     * @brief Get number of lives
     * @return numver of lives 
     */
    int Lives(){ return lives_;}
    /**
     * @brief Set Number of lives
     * @param lives is the number of lives to be set
     */
    void Lives(int lives){lives_ = lives;}
    /**
     * @brief Reset Spaceship to inital conditions
     */
    virtual void reset() override;
    /**
     * @brief Destructor
     */
    virtual ~Spaceship(){}
    
private:
   //Lives
   int lives_ = 3;
   //Number of fired LazerShots
   int noOfLazerShots_ = 0;
   //LazerShots
   std::vector<std::shared_ptr<LazerShot>> lazerShotsGun_;

};


#endif // SPACESHIP_H
