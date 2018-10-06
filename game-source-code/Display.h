#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "UserInputs.h"

using std::shared_ptr;
using std::make_shared;

class Display
{
public:
    Display(float screenWidth, float ScreenHeight);
    //Display drawn object on display
    void display();
    //Check for the press of space key
    bool spaceKey(){return space_;}
    //Poll for events
    void Events(shared_ptr<UserInputs> userinput_ptr);
    //Check if Display is Open
    bool isOpen() const{return window_->isOpen();}
    //Check if mouse is clicked on the left side
    bool leftClick(){return leftClick_;}
    //Clear the window
    void clearDisplay(){ window_->clear();}
    //return window
    shared_ptr<sf::RenderWindow> window(){return window_;}
    ~Display(){}
    
private:

    float screenWidth_;
    float screenHeight_;
    bool space_ = false;
    bool leftClick_ = false;
    bool delay = false;
    bool delay2 = false;
    shared_ptr<sf::RenderWindow> window_;
};


#endif // DISPLAY_H