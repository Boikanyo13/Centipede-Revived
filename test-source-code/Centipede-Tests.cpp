#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <windows.h>

#include <SFML\Graphics.hpp>

#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Player.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Constants.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\LazerShot.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Csegment.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\GameTypes.h"

/*
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Player.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Constants.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\LazerShot.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Csegment.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Centipede.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\SplashScreen.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameTypes.cpp"
*/
   
    float speed = 1.5f;
    
    /*
     * SCREEN WIDTH = 540.0f
     * SCREEN HEIGHT = 640.0f
     */

//Player Test cases

TEST_CASE("Check if player is at starting position"){
    
    auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
    CHECK( P1.getPosition() == PLAYER_START_POSTION);
    
    }
    
TEST_CASE("Player cannot be set outside of the game grid"){
    
    auto position = vector2D{ORIGINAL_SCREEN_WIDTH + 1.0f,ORIGINAL_SCREEN_HEIGHT + 1.0f};
    
    //Constructor
    CHECK_THROWS_AS(auto P1 = Player(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position,speed, ObjectID::PLAYER),ObjectOutOfBounds);
    
    auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION,speed, ObjectID::PLAYER};
    
    //setPostion method
    CHECK_THROWS_AS(P1.setPosition(position),ObjectOutOfBounds);
}

 
TEST_CASE("Player moves to the left direction"){
    
      auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
 
      //Expected Distance to be moved
      auto movement = vector2D(speed,0.0f);
    
      P1.Move(Direction::LEFT);
      
      CHECK(P1.getPosition() == (PLAYER_START_POSTION - movement));
      
    }
    
TEST_CASE("Player moves to the right direction"){
    
      auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
 
      //Expected Distance to be moved
      auto movement = vector2D(speed,0.0f);
    
      P1.Move(Direction::RIGHT);
      
      CHECK(P1.getPosition() == (PLAYER_START_POSTION + movement));
    }
    
TEST_CASE("Player moves up"){
    
      auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
 
      //Expected Distance to be moved
      auto movement = vector2D(0.0f,speed);
    
      P1.Move(Direction::UP);
      
      CHECK(P1.getPosition() == (PLAYER_START_POSTION - movement));
    
    }

TEST_CASE("Player moves down"){
    
      auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
 
      //Expected Distance to be moved
      auto movement = vector2D(0.0f,speed);
    
      P1.Move(Direction::DOWN);
      
      CHECK(P1.getPosition() == (PLAYER_START_POSTION + movement));
    
    }
    
   
TEST_CASE("Player does not go over Left window boundry"){
       
      auto newSpeed = 2*ORIGINAL_SCREEN_WIDTH;
    
     auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, newSpeed, ObjectID::PLAYER};
      
      //Expected Distance to be moved
      auto movement = vector2D{newSpeed,0.0f};
      
      P1.Move(Direction::LEFT);
      
      CHECK_FALSE(P1.getPosition() == (PLAYER_START_POSTION - movement) );
      CHECK(P1.getPosition().x() > 0);
    
    }

  
TEST_CASE("Player does not go over Right window boundry"){
    
      auto newSpeed = 2*ORIGINAL_SCREEN_WIDTH;
    
     auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, newSpeed, ObjectID::PLAYER};
      
      //Expected Distance to be moved
      auto movement = vector2D{newSpeed,0.0f};
      
      P1.Move(Direction::RIGHT);
      
      CHECK_FALSE(P1.getPosition() == (PLAYER_START_POSTION + movement) );
      CHECK(P1.getPosition().x() < ORIGINAL_SCREEN_WIDTH);
      
    }

TEST_CASE("Player does not go over Up window boundry"){
       
     auto newSpeed = 2*ORIGINAL_SCREEN_HEIGHT;
    
     auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, newSpeed, ObjectID::PLAYER};
      
      //Expected Distance to be moved
      auto movement = vector2D{0.0f,newSpeed};
      
      P1.Move(Direction::UP);
      
      CHECK_FALSE(P1.getPosition() == (PLAYER_START_POSTION - movement) );
      CHECK(P1.getPosition().y() > 0);
    
}
    

TEST_CASE("Player does not go over Down window boundry"){
    
     auto newSpeed = 2*ORIGINAL_SCREEN_HEIGHT;
    
     auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, newSpeed, ObjectID::PLAYER};
      
      //Expected Distance to be moved
      auto movement = vector2D{0.0f,newSpeed};
      
      P1.Move(Direction::UP);
      
      CHECK_FALSE(P1.getPosition() == (PLAYER_START_POSTION + movement) );
      CHECK(P1.getPosition().y() < ORIGINAL_SCREEN_HEIGHT);
}


    
    //LazerShot Tests
    
/*TEST_CASE("Check if LazerShot is loaded to the Player"){
        
        auto L1 = LazerShot{sf::Color::Red,sf::Vector2f(3.0f,7.0f), 0.6f};
        auto P1 = Player{nullptr,speed};
        
        CHECK_FALSE(L1.getPosition()==P1.getPosition());
        L1.Load(P1.getPosition());
      
        CHECK(L1.getPosition()==P1.getPosition());
    }

TEST_CASE("Check if LazerShot is fired"){
    
    auto L1 = LazerShot{sf::Color::Red,sf::Vector2f(3.0f,7.0f), speed};
    auto initialPos = L1.getPosition();
    
    L1.Fire();
    
    //Expected Movement
    auto movement = sf::Vector2f(0.0f,speed);
  
    CHECK(L1.getPosition()==initialPos-movement);
    
    }
    */
    
/* Csegment TESTS*/

/*TEST_CASE("Check if Csegment is on the set Initialised Position"){
    
    auto initialPos = sf::Vector2f(ORIGINAL_SCREEN_WIDTH/2, 0.0f);
    
    auto Cs1 = Csegment{nullptr,initialPos,sf::Vector2f{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},speed};
    
    CHECK(Cs1.getPosition()==initialPos);
    
    }
    
TEST_CASE("Check if Csegment moves"){
    
    auto initialPos = sf::Vector2f(ORIGINAL_SCREEN_WIDTH/2.0f, 40.0f);
    auto Cs1 = Csegment{nullptr,initialPos,sf::Vector2f{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},speed};
    
    
    Cs1.Move();
    
    //Expected Movement is foward due to the nature of its position
    auto movement = sf::Vector2f(speed, 0.0f);
    
    CHECK(Cs1.getPosition()==initialPos+movement);
    
    }
    
TEST_CASE("Check if Centipede segment moves one row down at boundary"){
    
    auto Cs1_Ycoord = 40.0f;
    auto initialPos = sf::Vector2f(ORIGINAL_SCREEN_WIDTH-CENTIPEDE_X_SIZE/2.0f,Cs1_Ycoord);
    auto Cs1 = Csegment{nullptr,initialPos,sf::Vector2f{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},speed};
    
    Cs1.Move();
   
    //Expected movement at boundary is one row down
    auto Y_movement = CENTIPEDE_Y_SIZE + Cs1_Ycoord;
    
    CHECK(Cs1.getPosition().y==Y_movement);
         

    }
    
TEST_CASE("Check if Centipede segment changes direction at turn"){
    
   
    auto Cs1_Ycoord = 40.0f;
    //Initial Position at boundary
    auto initialPos = sf::Vector2f(ORIGINAL_SCREEN_WIDTH-CENTIPEDE_X_SIZE,Cs1_Ycoord);
    auto Cs1 = Csegment{nullptr,initialPos,sf::Vector2f{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},speed};
    
    Cs1.Move();
    
    //Position at turn
    auto posAtTurn = Cs1.getPosition();
     
    //Move after turn
    Cs1.Move();
    
    //Expected movement is to the opposite direction
    auto movement = -sf::Vector2f(speed, 0.0f);
    
    CHECK(Cs1.getPosition()==posAtTurn + movement);
    
    
    }
    
    //Centipede Tests
    
TEST_CASE("Check if length of centipede corresponds to the number of segments "){
        
    auto centipede = Centipede{nullptr, 10, speed};
    CHECK(centipede.getLength() == 10);
        
    }
        */

    //Vector2D Tests
    
TEST_CASE("Check if x and y are set correctly"){
    
    auto Vector2D = vector2D{6.0f,10.0f};
    CHECK(Vector2D.x() == 6.0f);
    CHECK(Vector2D.y() == 10.0f);
}

TEST_CASE("vector2D containing the same x and y values are equal"){
    
    auto V1 = vector2D{19.0f,18.0f};
    auto V2 = vector2D{19.0f,18.0f};
    
    CHECK(V1==V2);
    
    }

TEST_CASE("Check if operator + returns correct answer"){
    
    auto Vector2D_1 = vector2D{6.0f,10.0f};
    auto Vector2D_2 = vector2D{12.0f,3.0f};
    auto answer(Vector2D_1 + Vector2D_2 ); 
    
    CHECK(answer.x() == 18.0f);
    CHECK(answer.y() == 13.0f); 
}

TEST_CASE("Check if operator - returns correct answer"){
    
    
    auto Vector2D_1 = vector2D{18.0f,10.0f};
    auto Vector2D_2 = vector2D{12.0f,3.0f};
    auto answer(Vector2D_1 - Vector2D_2 ); 
    
    CHECK(answer.x() == 6.0f);
    CHECK(answer.y() == 7.0f); 
}