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
    std::vector<string> images() const;
    //return Audio files corresponding to ObjectID
    string audio(ObjectID ID) const;
    //return Button files corresponding to ObjectID
    string button(ObjectID ID) const;
     //return Font files corresponding to ObjectID
    string font() const;
    void LoadFiles();
    ~GameFiles();

private:
    std::vector<string> images_;
 
};

#endif // GAMEFILES_H
