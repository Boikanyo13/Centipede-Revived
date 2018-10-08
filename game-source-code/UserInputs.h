#ifndef USERINPUTS_H
#define USERINPUTS_H
#include <SFML/Graphics.hpp>

enum class Key{LEFT,RIGHT,UP,DOWN,SPACE,OTHERS,PAUSE,RESUME,ESC,QUIT};
/**
 * @class UserInputs
 * @date 08/10/2018
 * @file UserInputs.h
 * @brief Responsible for Handling user inputs
 */
class UserInputs
{
public:
   /**
    * @brief Constructor
    * @return 
    */
    UserInputs(){};
    /**
     * @brief Return Pressed Key
     * @return pressed Key
     */
    Key pressedKey();
    /**
     * @brief Destructor
     */
    ~UserInputs(){};

};

#endif // USERINPUTS_H
