#ifndef MUSHROOMFIELD_H
#define MUSHROOMFIELD_H
#include "GameTypes.h"
#include "Mushroom.h"
#include "GameObjectContainer.h"
#include <cstdlib>
#include <ctime>

#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;
/**
 * @class MushroomField
 * @date 08/10/2018
 * @file MushroomField.h
 * @brief This class is responsible for randomly generating a field Mushrooms on Game Play
 */

class MushroomField: public GameObjectContainer
{

public:
    /**
     * @brief Constructor
     * @param size of the MushroomField
     */
    MushroomField(int size);
    /**
     * @brief Return a Mushroom at index i
     * @param i iteratotr to container
     * @return segment of the MushroomField
     */
    virtual shared_ptr<GameObject> segment(int i) const override{ return _mushrooms_ptr[i];};
    /**
     * @brief Transform centipe segment to Mushroom
     * @param centiSeg_ptr the corresponding CentiSegment to be transformed
     */
    void transform(std::shared_ptr<GameObject> centiSeg_ptr);
    /**
     * @brief Regenerate field
     */
    virtual void reset() override;
    /**
     * @brief Destroy the MushroomField Object
     */
    virtual ~MushroomField(){};
    
private:
    /**
     * @brief Generate random field of Mushrooms
     */
    void generateField();
    
    //Original size of the field
    int original_size_;
    //Mushrooms
    vector<shared_ptr<Mushroom>> _mushrooms_ptr;
    //All possible positions
    vector<float> yPositions_;
    vector<float> xPositions_;
     
};

#endif // MUSHROOMFIELD_H
