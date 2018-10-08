#ifndef GAMEOBJECTCONTAINER_H
#define GAMEOBJECTCONTAINER_H
#include "GameObject.h"

#include <memory>
using std::shared_ptr;

/**
 * @class GameObjectContainer
 * @date 08/10/2018
 * @file GameObjectContainer.h
 * @brief This class is a blue print to containers of type GameObjects 
 */
class GameObjectContainer
{
public:
    /**
     * @brief Constructor
     * @param size of the container
     */
    GameObjectContainer(int size):size_{size}
    {}
    /**
     * @brief return segment of the gameObjectContainer
     * @param i iterator to container
     * @return ith segment of the container
     */
    virtual shared_ptr<GameObject> segment(int i) const = 0;
    /**
     * @brief Resize GameObject Container
     */
    virtual void reset() = 0;
    /**
     * @brief set size of GameObjectContainer
     * @param size of the container
     */
    void size(int size){size_ = size;}
    /**
     * @brief get size of GameObjectConatiner
     * @return size of the container
     */
    int size(){return size_;}
    /**
     * @brief Destroy the object
     */
    virtual ~GameObjectContainer(){};
    
private:
  //size of container
  int size_;
};

#endif // GAMEOBJECTCONTAINER_H
