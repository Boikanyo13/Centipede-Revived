#ifndef GAMEFILES_H
#define GAMEFILES_H
#include "GameTypes.h"
#include <string>
using std::string;

class GameFiles
{
public:
  //  GameFiles();
    //return Image files corresponding to ObjectID
    string image(ObjectID ID) const;
    //return Audio files corresponding to ObjectID
    string audio(ObjectID ID) const;
    //return Button files corresponding to ObjectID
    string button(ObjectID ID) const;
     //return Font files corresponding to ObjectID
    string font() const;
    ~GameFiles();

};

#endif // GAMEFILES_H
