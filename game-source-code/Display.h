#ifndef DISPLAY_H
#define DISPLAY_H


#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "UserInputs.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <tuple>
using std::tuple;
using std::tie;

/**
 * @class Display
 * @date 08/10/2018
 * @file Display.h
 * @brief Renders the GameObject onto the screen
 */

class Display
{
public:
    /**
     * @brief initialize the Display
     */
    Display(float screenWidth, float ScreenHeight);
    /**
     * @brief Display drawn object on display
     */
    void display();
    /**
     * @brief Check for the press of space key
     * @return boolean signaling for the press of the space key
     */
    bool spaceKey(){return space_;}
    /**
     * @brief Poll for events
     * @param userinput_ptr inputs from the user
     */
    void Events(shared_ptr<UserInputs> userinput_ptr);
     /**
      * @brief Check if Display is Open
      * @return boolean signaling whether window is open or not
      */
    bool isOpen() const{return window_->isOpen();}
    /**
     * @brief Check if mouse is clicked on the left side
     * @return boolean signaling whether a mouse is clicked on the left or not
     */
    bool leftClick(){return leftClick_;}
    /**
     * @brief  Clear the window
     */
    void clearDisplay(){ window_->clear();}
    /**
     * @brief return a shared pointer to the window
     * @return shared pointer to the window
     */
    shared_ptr<sf::RenderWindow> window(){return window_;}
    /**
     * @brief Receives flags from the game logic to delay
     * @param delays tuple of flags
     */
    void delayer(tuple<bool,bool,bool> delays){tie(explosion1_,centiDeath_,explosion2_) = delays;};
    /**
     * @return destroy the Display
     */
    ~Display(){}
    
private:
     
    //Window dimensions
    float screenWidth_;
    float screenHeight_;
    //Controller Booleans
    bool space_ = false;
    bool leftClick_ = false;
    bool explosion1_ = false;
    bool explosion2_ = false;
    bool centiDeath_ = false;
    //The Window
    shared_ptr<sf::RenderWindow> window_;
};


#endif // DISPLAY_H