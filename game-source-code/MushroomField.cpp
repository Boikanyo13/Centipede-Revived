#include "MushroomField.h"

MushroomField::MushroomField(int size):GameObjectContainer{size}
{
     //Fill the vectors with all the possible positions
    for(auto i = 0.0f; i < 29.0f; i++){
        
        yPositions_.push_back(20.0f*(i+2.0f));
        
        if(i<25)  
        xPositions_.push_back(20.0f*(i+1.0f));
       
       }
       
      original_size_ = size;
      generateField();
}

void MushroomField::reset(){
    
    if(_mushrooms_ptr.size()> 0)
       _mushrooms_ptr.erase(_mushrooms_ptr.begin(), _mushrooms_ptr.end());  
       
    size(original_size_);
    generateField();
}

void MushroomField::generateField(){
    
    
    srand(time(0));
    auto randy = 0;
    auto randx = 0;
    
     
   for(auto i = 0; i <  size(); i++){
        
       //Acces at random indices
        randx = rand()%25;
        randy = rand()%29;
        
        _mushrooms_ptr.push_back(std::make_shared<Mushroom>(vector2D{MUSHROOM_SIZE},vector2D{xPositions_[randx],yPositions_[randy]},0.0f,ObjectID::MUSHROOM));
     
        }

    }

void MushroomField::transform(std::shared_ptr<GameObject> centiSeg_ptr){
    
    _mushrooms_ptr.push_back(std::make_shared<Mushroom>(vector2D{MUSHROOM_SIZE},centiSeg_ptr->getPosition(),0.0f,ObjectID::MUSHROOM));
    
    auto newSize = size();
    newSize++;
    size(newSize);
}


