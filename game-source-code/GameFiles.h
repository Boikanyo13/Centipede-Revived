#ifndef GAMEFILES_H
#define GAMEFILES_H
#include "GameTypes.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
using std::string;

class FileNotFound{};

/**
 * @class GameFiles
 * @date 08/10/2018
 * @file GameFiles.h
 * @brief  Database for all the game's classes
 */
class GameFiles
{
public:
   /**
    * @brief default constructor
    */
    GameFiles();
    /**
     * @brief returns object images files
     * @return vector of objectImages
     */
     std::vector<string> objectImages() const;
    /**
     * @brief return screen images files
     * @return vector of screenImages
     */
    std::vector<string> screenImages() const;
    /**
     * @brief return Font files corresponding to ObjectID
     * @return game font file
     */
    string font() const;
    /**
     * @brief  return the previous high scores
     * @return vector of top 5 scores
     */
    std::vector<int> scorefile();
     /**
      * @brief store the high scores
      * @param score to be store in the highscore file
      */
    void scorefile(std::vector<int> score);
    ~GameFiles();

private:
    //Game Files
    std::vector<string> objectImages_;
    std::vector<string> screenImages_;
};

#endif // GAMEFILES_H
