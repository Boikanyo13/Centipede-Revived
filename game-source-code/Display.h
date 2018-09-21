#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameFiles.h"
#include "Player.h"
#include "Centipede.h"
using std::shared_ptr;

class FileNotFound{};

class Display
{
public:
    Display(float screenWidth, float ScreenHeight);
    //Display drawn object on display
    void display();
    bool spaceKey(){return space;}
    void Events();
    //Draw GameObjects on Display
    void drawObject(shared_ptr<GameObject> gameobject_ptr);
    //Check if Display is Open
    bool isOpen() const;
    //Draw fired Lazershots
    void drawLazerShot(shared_ptr<Player> player_ptr);
    //Draw Centipede
    void drawCentipede(shared_ptr<Centipede> centi_ptr);
    ~Display();
    
private:

    sf::RectangleShape drawSprite(shared_ptr<GameObject> gameobject_ptr);
    float screenWidth_;
    float screenHeight_;
    bool space;
    sf::RenderWindow window_;
    GameFiles gamefile_;  //ptr_;
    std::vector<sf::Texture> textures_;

};
