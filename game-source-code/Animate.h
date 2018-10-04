#ifndef ANIMATE_H
#define ANIMATE_H
#include "Display.h"
#include "GameObject.h"
#include "GameFiles.h"
#include "GameObjectContainer.h"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

class Animate
{
public:

    Animate(shared_ptr<Display> display_ptr);
    //Draw the object
    void animate(shared_ptr<GameObject> gameobject_ptr);
    void animate(shared_ptr<GameObjectContainer> gameObjectContainer_ptr);
    void animateLazerShots(shared_ptr<Spaceship> spaceship_ptr);
    ~Animate(){}
    
private:
    sf::RectangleShape createSprite(shared_ptr<GameObject> gameobject_ptr);
    shared_ptr<sf::RenderWindow> window_ptr_;
    GameFiles gamefile_;
    vector<sf::Texture> textures_;
};

#endif // ANIMATE_H
