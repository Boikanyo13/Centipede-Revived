#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameFiles.h"
#include "Spaceship.h"
#include "Centipede.h"
#include "SplashScreen.h"
#include "MushroomField.h"
#include <unistd.h>

using std::shared_ptr;

class Display
{
public:
    Display(float screenWidth, float ScreenHeight);
    //Display drawn object on display
    void display();
    bool spaceKey(){return space_;}
    void Events();
    //Draw GameObjects on Display
    void drawObject(shared_ptr<GameObject> gameobject_ptr);
    //Check if Display is Open
    bool isOpen() const;
    //Draw fired Lazershots
    void drawLazerShot(shared_ptr<Spaceship> spaceship_ptr);
    //Draw Centipede
    void drawCentipede(shared_ptr<Centipede> centi_ptr);
    //Draw Mushroom Field
    void drawMushroomField(shared_ptr<MushroomField> mushroom_ptr);
    //Display opening window
    void openingWindow();
    //Check if mouse is clicked on the left side
    bool leftClick(){return leftClick_;}
    //Clear the window
    void clearDisplay(){ window_.clear();}
    //Display help window
    void helpWindow();
    //Displays the background of the game window
    void gameWindow(shared_ptr<Score> score_ptr, int lives);
    SplashScreen splashscreen(){return splashscreen_;};
    ~Display();
    
private:

    sf::RectangleShape drawSprite(shared_ptr<GameObject> gameobject_ptr);
    float screenWidth_;
    float screenHeight_;
    bool space_, leftClick_;
    bool delay;
    bool delay2;
    sf::RenderWindow window_;
    GameFiles gamefile_; 
    std::vector<sf::Texture> textures_;
    SplashScreen splashscreen_;

};
