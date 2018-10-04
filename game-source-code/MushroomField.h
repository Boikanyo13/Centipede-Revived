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


class MushroomField: public GameObjectContainer
{

public:
    MushroomField(int size);
    //Return a Mushroom at index i
    virtual shared_ptr<GameObject> segment(int i) const override{ return _mushrooms_ptr[i];};
    //Transform centipe segment to Mushroom
    void transform(std::shared_ptr<GameObject> centiSeg_ptr);
    //Regenerate field
    virtual void reset() override;
    virtual ~MushroomField(){};
    
private:
    //Generate random field of Mushrooms
    void generateField();
    
   // int size_;
    int original_size_;
    vector<shared_ptr<Mushroom>> _mushrooms_ptr;
    vector<float> yPositions_;
    vector<float> xPositions_;
     
};

#endif // MUSHROOMFIELD_H
