#ifndef GAMEOBJECTCONTAINER_H
#define GAMEOBJECTCONTAINER_H
#include "GameObject.h"

#include <memory>
using std::shared_ptr;

class GameObjectContainer
{
public:
    GameObjectContainer(int size):size_{size}
    {}
    //return segment of the gameObjectContainer
    virtual shared_ptr<GameObject> segment(int i) const = 0;
    //Resize GameObject Container
    virtual void reset() = 0;
    //set size of GameObjectContainer
    void size(int size){size_ = size;}
    //get size of GameObjectConatiner
    int size(){return size_;}
    virtual ~GameObjectContainer(){};
    
private:
  int size_;
};

#endif // GAMEOBJECTCONTAINER_H
