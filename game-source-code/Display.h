#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameFiles.h"
using std::shared_ptr;

class FileNotFound{};

class Display
{
public:
    Display(float screenWidth, float ScreenHeight);
    //Display drawn object on display
    void display();
    //Draw GameObjects on Display
    void drawObject(shared_ptr<GameObject> gameobject_ptr);
    //Check if Display is Open
    bool isOpen() const;
    ~Display();
    
private:

    sf::RectangleShape drawSprite(shared_ptr<GameObject> gameobject_ptr);
    float screenWidth_;
    float screenHeight_;
    sf::RenderWindow window_;
    GameFiles gamefile_;

};
