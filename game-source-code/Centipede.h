#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include "Csegment.h"
#include "GameTypes.h"
#include "GameObjectContainer.h"

#include <vector>
using std::vector;

#include <memory> 
using std::shared_ptr;

/**
 * @class Centipede
 * @date 08/10/2018
 * @file Centipede.h
 * @brief This class inherits from GameObjectContainer, the class forms a collection of CentiSegments that together make a Centipede
 */

class Centipede : public GameObjectContainer{
    
public:
    /**
     * @brief Constructor accepts length of the Centipede to be created
     */
    Centipede(int length);
    /**
     * @brief  Moves Centipede across screen
     */
    void Move();
    /**
     * @brief Returns the ith CentiSegment
     * @param i is the ith CentiSegment
     * @return shared pointer to the ith CentiSegment
     */
    virtual shared_ptr<GameObject> segment(int i) const override {return centipede_[i];}
    /**
     * @brief Count the number of destroyed CentiSegments
     */
    void SegmentDestroyed(){numDeadSegments_++;}
    /**
     * @brief checks if Centipede is dead
     * @return boolean 
     */
    bool isDead(){return (numDeadSegments_== size());}
    /**
     * @brief Reset centipede to initial conditions
     */
    virtual void reset() override;
    /**
     * @brief destroys the Centipede Objects
     */
    virtual ~Centipede(){};
    
    
private:
    
    /**
     * @brief reconstructs the Centipede to initial Conditions
     */
    void initialConditions();
    //CentiSegments making up the Centipede
    vector<shared_ptr <CentiSegment>> centipede_;
    //Count of dead CentiSegments
    int numDeadSegments_;
    
};

#endif // CENTIPEDE_H