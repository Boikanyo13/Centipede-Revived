#ifndef CSEGMENT_H
#define CSEGMENT_H
#include "GameObject.h"
#include "Constants.h"

/**
 * @class CentiSegment
 * @date 08/10/2018
 * @file Csegment.h
 * @brief This class models the attributes and behaviour of a segment of a Centiped. The Class inherits GameObject
 */

class CentiSegment: public GameObject{
public:
    /**
     * @brief Constructor of CentiSegment
     * @param size of the CentiSegment
     * @param position of the CentiSegment
     * @param speed of the CentiSegment
     * @param objectid ID of the CentiSegment
     */
    CentiSegment(const vector2D& size, const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
   /**
    * @briefMove the CentiSegment across the screen
    */
    virtual void Move() override;
    /**
     * @brief set the centipede segment to its inital conditions
     */
    virtual void reset() override{};
     /**
      * @brie Take action if hits a mushroom
      */
    virtual void collisionResponse() override;
    /**
     * @brief Destroy the CentiSegment
     */
    virtual ~CentiSegment(){}
    
private:
     /**
      * @brief Move CentiSegment Left
      */
    void moveLeft();
    /**
     * @brief Move CentiSegment Right
     */
    void moveRight();
    /**
     * @brief Move CentiSegment Up
     */
    void moveUp();
    /**
     * @brief Move CentiSegment Down
     */
    void moveDown();
    /**
     * @brief entrance Movement
     */
    void entrance();
    
    //Controller Booleans
    bool forward_ = true;
    bool up_ = false;
    bool atBoundry_ = false;
    };


#endif // CSEGMENT_H