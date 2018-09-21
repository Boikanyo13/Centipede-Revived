#ifndef GAMEFILES_H
#define GAMEFILES_H
#include "GameTypes.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using std::string;

class GameFiles
{
public:
    GameFiles();
    //return Image files corresponding to ObjectID
    std::vector<string> objectImages() const;
    //return Audio files corresponding to ObjectID
    string audio(ObjectID ID) const;
    //return Button files corresponding to ObjectID
    std::vector<string> screenImages() const;
     //return Font files corresponding to ObjectID
    string font() const;
    ~GameFiles();

private:
    std::vector<string> objectImages_;
    std::vector<string> screenImages_;
    
 
};

#endif // GAMEFILES_H
