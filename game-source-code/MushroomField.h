#ifndef MUSHROOMFIELD_H
#define MUSHROOMFIELD_H
#include "GameTypes.h"
#include "Mushroom.h"
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::shared_ptr;
using std::vector;

class MushroomField
{
public:
    MushroomField(int size);
    //Return a Mushroom at index i
    shared_ptr<Mushroom> mushroom(int i) const;
    //Transform centipe segment to Mushroom
    void transform(std::shared_ptr<CentiSegment> seg);
    //Return size of Field
    int size() const;
    //Regenerate field
    void reset();
    ~MushroomField();
    
private:
    //Generate random field of Mushrooms
    void generateField();
    
    int size_;
    int original_size_;
    vector<shared_ptr<Mushroom>> _mushrooms_ptr;
    vector<float> yPositions_;
    vector<float> xPositions_;
     
};

#endif // MUSHROOMFIELD_H
