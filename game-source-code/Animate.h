#ifndef ANIMATE_H
#define ANIMATE_H
#include "Display.h"
#include "GameObject.h"
#include "GameFiles.h"
#include "Spaceship.h"
#include "GameObjectContainer.h"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

/**
 * @class Animate
 * @date 08/10/2018
 * @file Animate.h
 * @brief This class is used to draw all game entities onto the screen
 */


class Animate
{
public:
     /**
        Accepts display_ptr to use its window to draw on
      */
    Animate(shared_ptr<Display> display_ptr);
    /**
     * @brief Draws GameObject's subclasses via dynamic binding
     * @param gameobject_ptr is the pointer to the GameObject that is to be animated
     */
    void animate(shared_ptr<GameObject> gameobject_ptr);
    /**
     * @brief Draws GameObjectContainer's subclasses via dynamic binding
     * @param gameObjectContainer_ptr is the pointer to the GameObjectContainer that is to be animated
     */
    void animate(shared_ptr<GameObjectContainer> gameObjectContainer_ptr);
    /**
     * @brief Draws LazerShots fired by the player
     * @param spaceship_ptr is the pointer to the Spaceship object that is firing the LazerShots
     */
    void animateLazerShots(shared_ptr<Spaceship> spaceship_ptr);
    /**
     * @brief Destroys the Animate object when it goes out of scope 
     * 
     */
    ~Animate(){}
    
private:
     /**
      * @brief creates sprites of objects to be drawn
      * @param gameobject_ptr pointer to the objects that is going to be created
      * @return sprite that represents the GameObject in SFML
      */
      sf::RectangleShape createSprite(shared_ptr<GameObject> gameobject_ptr);
      //Shared pointer to the window
      shared_ptr<sf::RenderWindow> window_ptr_;
      //Acces to textures from the data layer
      GameFiles gamefile_;
      //Textures to be assigned to different GameObjects
      vector<sf::Texture> textures_;
};

#endif // ANIMATE_H
