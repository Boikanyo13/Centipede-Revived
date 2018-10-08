#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <memory>



/*#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Spaceship.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Constants.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\LazerShot.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Csegment.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\GameTypes.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\GameFiles.cpp"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Display.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\CollisionHandler.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Score.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Mushroom.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\MushroomField.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Spider.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Player.cpp"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\UserInputs.cpp"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Collision.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Timer.h"

*/

#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Spaceship.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Constants.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\LazerShot.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Csegment.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Centipede.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\SplashScreen.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameTypes.cpp"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Display.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameFiles.cpp"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameObject.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\MushroomField.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Mushroom.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Score.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\CollisionHandler.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Collision.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Player.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Timer.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Scorpion.h"

    float speed = 1.5f;
    
    /*
     * SCREEN WIDTH = 540.0f
     * SCREEN HEIGHT = 640.0f
     */

//Spaceship Test cases

TEST_CASE("Check if Spaceship is at starting position"){
    
    auto spaceship = Spaceship{vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP};
    CHECK( spaceship.getPosition() == SPACESHIP_START_POSTION);
    
    }
    
TEST_CASE("Spaceship cannot be set outside of the game grid"){
    
    auto position = vector2D{ORIGINAL_SCREEN_WIDTH + 1.0f,ORIGINAL_SCREEN_HEIGHT + 1.0f};
    
    //Constructor
    CHECK_THROWS_AS(auto spaceship = Spaceship(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position,speed, ObjectID::SPACESHIP),ObjectOutOfBounds);
    
    auto spaceship = Spaceship{vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION,speed, ObjectID::SPACESHIP};
    
    //setPostion method
    CHECK_THROWS_AS(spaceship.setPosition(position),ObjectOutOfBounds);
}

 
TEST_CASE("Spaceship moves to the left direction"){
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
 
      //Expected Distance to be moved
      auto movement = vector2D(speed,0.0f);
      
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
    
      player.moveSpaceshipLeft();
      
      CHECK(spaceship->getPosition() == (SPACESHIP_START_POSTION - movement));
      
    }
    
TEST_CASE("Spaceship moves to the right direction"){
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
      
      //Expected Distance to be moved
      auto movement = vector2D(speed,0.0f);
    
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
    
      player.moveSpaceshipRight();
      
      CHECK(spaceship->getPosition() == (SPACESHIP_START_POSTION + movement));
    }
    
TEST_CASE("Spaceship moves up"){
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
 
      //Expected Distance to be moved
      auto movement = vector2D(0.0f,speed);
       
       
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
    
      player.moveSpaceshipUp();
   
      
      CHECK(spaceship->getPosition() == (SPACESHIP_START_POSTION - movement));
    
    }

TEST_CASE("Spaceship moves down"){
    
        auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
 
      //Expected Distance to be moved
      auto movement = vector2D(0.0f,speed);
    
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
    
      player.moveSpaceshipDown();
      
      CHECK(spaceship->getPosition() == (SPACESHIP_START_POSTION + movement));
    
    }
    
   
TEST_CASE("Spaceship does not go over Left window boundry"){
       
      auto newSpeed = 2*ORIGINAL_SCREEN_WIDTH;
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
      
      //Expected Distance to be moved
      auto movement = vector2D{newSpeed,0.0f};
      
     //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
      player.moveSpaceshipLeft();
      
      CHECK_FALSE(spaceship->getPosition() == (SPACESHIP_START_POSTION - movement) );
      CHECK(spaceship->getPosition().x() > 0);
    
    }

  
TEST_CASE("Spaceship does not go over Right window boundry"){
    
      auto newSpeed = 2*ORIGINAL_SCREEN_WIDTH;
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
      
      //Expected Distance to be moved
      auto movement = vector2D{newSpeed,0.0f};
      
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
      player.moveSpaceshipRight();
      
      CHECK_FALSE(spaceship->getPosition() == (SPACESHIP_START_POSTION + movement) );
      CHECK(spaceship->getPosition().x() < ORIGINAL_SCREEN_WIDTH);
      
    }

TEST_CASE("Spaceship does not go over Up window boundry"){
       
     auto newSpeed = 2*ORIGINAL_SCREEN_HEIGHT;
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
      
      //Expected Distance to be moved
      auto movement = vector2D{0.0f,newSpeed};
      
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
      player.moveSpaceshipUp();
      
      CHECK_FALSE(spaceship->getPosition() == (SPACESHIP_START_POSTION - movement) );
      CHECK(spaceship->getPosition().y() > 0);
    
}
    

TEST_CASE("Spaceship does not go over Down window boundry"){
    
     auto newSpeed = 2*ORIGINAL_SCREEN_HEIGHT;
    
      auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP);
      
      //Expected Distance to be moved
      auto movement = vector2D{0.0f,newSpeed};
      
      //Player controlls the Spaceship
      auto player = Player{spaceship,nullptr};
      player.moveSpaceshipDown();
      
      CHECK_FALSE(spaceship->getPosition() == (SPACESHIP_START_POSTION + movement) );
      CHECK(spaceship->getPosition().y() < ORIGINAL_SCREEN_HEIGHT);
}


//LazerShot Tests
TEST_CASE("LazerShot cannot be set out of game grid Boundary"){
    
    auto position = vector2D{ORIGINAL_SCREEN_WIDTH + 1.0f,ORIGINAL_SCREEN_HEIGHT + 1.0f};
   
    CHECK_THROWS_AS(auto L1 = LazerShot(vector2D{5.0f,10.0f},position,speed, ObjectID::BULLET),ObjectOutOfBounds);
    
    }
     
 
TEST_CASE("LazerShot is loaded to the Spaceship"){
        
         auto lazershot_pos = vector2D{0.0f,0.0f};
         auto L1 = LazerShot{vector2D{5.0f,10.0f},lazershot_pos,speed, ObjectID::BULLET};
         auto spaceship = Spaceship{vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP};
        
        CHECK_FALSE(L1.getPosition()==spaceship.getPosition());
        
        //Load Bullet to Spaceship
        L1.Load(spaceship.getPosition());
      
        CHECK(L1.getPosition()==spaceship.getPosition());
    }
    

TEST_CASE("LazerShot is fired"){
    
    auto lazershot_pos = vector2D{20.0f,20.0f};
    auto L1 = LazerShot{vector2D{5.0f,10.0f},lazershot_pos,speed, ObjectID::BULLET};
    auto initialPos = L1.getPosition();
    
    L1.Fire();
    
    //Expected Movement
    auto movement = vector2D{0.0f,speed};
  
    CHECK(L1.getPosition()==initialPos-movement);
    
    }


TEST_CASE("LazerShot is allowed to go over UP game grid boundry"){
    
    auto lazershot_pos = vector2D{20.0f,0.0f};
    auto L1 = LazerShot{vector2D{5.0f,10.0f},lazershot_pos,speed, ObjectID::BULLET};
    CHECK_NOTHROW(L1.Fire());
}


//LazerShot + Spaceship Test

TEST_CASE("LazerShot is loaded onto the LazerShot Gun of the Spaceship"){
    
    auto expectedLoadedShot = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},SPACESHIP_START_POSTION, 1.0f, ObjectID::BULLET);
    
     auto spaceship = Spaceship{vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP};
    
    //Load the Spaceship's LazerGun three times
     spaceship.load();
     spaceship.load();
     spaceship.load();
   
     
     auto expectedNoOfLazerShots = 3;   
     
     //All the lazershots are identical, choose the 1st one   
     auto loadedLazerShot =  std::get<0>(spaceship.firedLazerShot(0));
     auto noOflazershots = std::get<1>(spaceship.firedLazerShot(0));
     
     CHECK(loadedLazerShot->getPosition() == expectedLoadedShot->getPosition());
     CHECK(noOflazershots==expectedNoOfLazerShots );
     
}

TEST_CASE("Spaceship Shoots LazerShots"){
    
    auto spaceship = Spaceship{vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},SPACESHIP_START_POSTION, speed, ObjectID::SPACESHIP};
     
   spaceship.load();
    
    auto loadedLazerShot= std::get<0>(spaceship.firedLazerShot(0));
    
    //LazerShot is loaded at Spaceship
    CHECK(loadedLazerShot->getPosition()==spaceship.getPosition());
    
   spaceship.shoot();
   
    //LazerShot shoots up
    auto expectedPosition = vector2D{SPACESHIP_START_POSTION.x(),( SPACESHIP_START_POSTION.y()-loadedLazerShot->getSpeed())};
    
    CHECK(loadedLazerShot->getPosition()==expectedPosition); 
    
    }
    
//Centisegment TESTS
TEST_CASE("Centisegment's postion can be  be set outside of the top boundary but no doew"){
    
    auto outofVerticalBoundsPosition1 = vector2D{100.0f, 2*ORIGINAL_SCREEN_WIDTH};
    auto outofVerticalBoundsPosition2 = vector2D{100.0f,-89.0f};
    
    //Check constructor
    CHECK_THROWS_AS(auto Cs1 = CentiSegment(CENTIPEDE_SIZE,outofVerticalBoundsPosition1,speed, ObjectID::CENTIPEDE),ObjectOutOfBounds);
    CHECK_NOTHROW(auto Cs1 = CentiSegment(CENTIPEDE_SIZE,outofVerticalBoundsPosition2,speed, ObjectID::CENTIPEDE));
    
     //Check setPosition function
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},vector2D(ORIGINAL_SCREEN_WIDTH/2, 0.0f),speed, ObjectID::CENTIPEDE};
    
    
    CHECK_THROWS_AS(Cs1.setPosition(outofVerticalBoundsPosition1), ObjectOutOfBounds);
    CHECK_NOTHROW(Cs1.setPosition(outofVerticalBoundsPosition2));


}
    

    
TEST_CASE("CSegment's position cannot be set outside of the game grid left and right boundaries(X-boundaries)"){
    
    
    auto outofHorizontalBoundsPosition1 = vector2D{2*ORIGINAL_SCREEN_WIDTH,100.0f};
    auto outofHorizontalBoundsPosition2 = vector2D{-89.0f,100.0f};
    
    //Check Constructor
    CHECK_THROWS_AS(auto Cs1 = CentiSegment(CENTIPEDE_SIZE,outofHorizontalBoundsPosition1,speed, ObjectID::CENTIPEDE),ObjectOutOfBounds);
   CHECK_THROWS_AS(auto Cs1 = CentiSegment(CENTIPEDE_SIZE,outofHorizontalBoundsPosition2,speed, ObjectID::CENTIPEDE), ObjectOutOfBounds);
    
    //Check setPosition function
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},vector2D{ORIGINAL_SCREEN_WIDTH/2, 0.0f},speed, ObjectID::CENTIPEDE};
    
     CHECK_THROWS_AS(Cs1.setPosition(outofHorizontalBoundsPosition1),ObjectOutOfBounds);
     CHECK_THROWS_AS(Cs1.setPosition(outofHorizontalBoundsPosition2),ObjectOutOfBounds);
}



TEST_CASE("Csegment is on the set Initialised Position"){
    
    auto initialPos = vector2D(ORIGINAL_SCREEN_WIDTH/2, 0.0f);
    
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},initialPos ,speed, ObjectID::CENTIPEDE};
    
    CHECK(Cs1.getPosition()==initialPos);
    
    }


TEST_CASE("Centisegment moves"){
    
    auto initialPos = vector2D(ORIGINAL_SCREEN_WIDTH/2, 50.0f);
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},initialPos ,speed, ObjectID::CENTIPEDE};
    
    
    Cs1.Move();
    
    //Expected Movement is foward due to the nature of its position
    auto movement = vector2D(Cs1.getSpeed(), 0.0f);
    
    CHECK(Cs1.getPosition()==initialPos+movement);
    
    }
    
TEST_CASE("Check if Centipede segment moves one row down at boundary"){
    
    auto Cs1_Ycoord = 40.0f;
    //Boundary coordinate
    auto initialPos = vector2D(ORIGINAL_SCREEN_WIDTH-CENTIPEDE_X_SIZE/2.0f,Cs1_Ycoord);
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},initialPos ,speed, ObjectID::CENTIPEDE};
    
    Cs1.Move(); //This move flags the CentiSegment to move down on the next attempt of move
    
    Cs1.Move(); //This is the next move
   
    //Expected movement at boundary is one row down (40+20 = 60)
    auto Y_movement = CENTIPEDE_Y_SIZE + Cs1_Ycoord;
    
    CHECK(Cs1.getPosition().y()==Y_movement);

    }
 
TEST_CASE("Check if Centipede segment changes direction at turn"){
    
   
    auto Cs1_Ycoord = 40.0f;
    //Initial Position at boundary
    auto initialPos = vector2D{ORIGINAL_SCREEN_WIDTH-CENTIPEDE_X_SIZE/2.0f,Cs1_Ycoord};
    auto Cs1 = CentiSegment{vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},initialPos ,speed, ObjectID::CENTIPEDE};;
    
    Cs1.Move();
    Cs1.Move();
    
    //Position at turn
    auto posAtTurn = Cs1.getPosition();
     
    //Move after turn
    Cs1.Move();
    
    //Expected movement is to the opposite direction
    auto movement = vector2D(speed, 0.0f);
    
    CHECK(Cs1.getPosition()==posAtTurn - movement);
    
    
    }
    
    //Centipede Tests
    
TEST_CASE("Check if size of centipede corresponds to the number of segments "){
        
    auto centipede = Centipede{CENTIPEDE_LENGTH};
    CHECK(centipede.size() == CENTIPEDE_LENGTH);
        
    }

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

//Collision Tests

TEST_CASE("Vertical Collision between two GameObject is detected"){
    
     auto collision = Collision{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f,100.0f - newSpeed};
     
     auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position1,newSpeed, ObjectID::BULLET);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
     
     CHECK_FALSE(collision.checkCollision(L1,Cs1));
     
     L1->Fire();
     
     CHECK(collision.checkCollision(L1,Cs1));
     
    }
    
TEST_CASE("Horizontal collision between two Gameobjects is detected"){
    
     auto collision = Collision{};
     auto newSpeed = 25.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position1, newSpeed, ObjectID::SPACESHIP);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
    
     
     CHECK_FALSE(collision.checkCollision(Cs1,spaceship));
     Cs1->Move();
     CHECK(collision.checkCollision(Cs1,spaceship));
    
    }
    
TEST_CASE("The other object dies after collision"){
    
     auto collision = Collision{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f,100.0f - newSpeed};
     
     auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position1,newSpeed, ObjectID::BULLET);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
      
     CHECK_FALSE(Cs1->isDead());
     
     L1->Fire();
     //The second argument into the function is the other
     CHECK(collision.checkCollision(L1,Cs1));
     CHECK(Cs1->isDead());
     
} 

TEST_CASE("Dead object cannot collide"){
    
     auto collision = Collision{};
    auto position = vector2D{250.0f,100.0f};
   
   //Objects at the same place
    auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position,speed, ObjectID::BULLET);
    auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position,speed, ObjectID::CENTIPEDE);
    
    CHECK(collision.checkCollision(Cs1,L1));

    Cs1->updateState(State::DEAD);
    
    CHECK_FALSE(collision.checkCollision(Cs1,L1));
    
}  

TEST_CASE("Spaceship looses life if hit"){
 
     auto collision = std::make_shared<CollisionHandler>(nullptr);
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
     auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position1, newSpeed, ObjectID::SPACESHIP);
     auto centipede = std::make_shared<Centipede>(1);
     centipede->segment(0)->setPosition(position2);
     
     //Spaceship has 3 lives initially
      spaceship->Lives(3);
      
     CHECK(spaceship->Lives()==3);
     
     centipede->Move();
     
     collision->spaceshipHit(centipede,spaceship);
     
     CHECK(spaceship->Lives()==2);
    
}


TEST_CASE("Spaceship explodes if hit"){
    
     auto collision = std::make_shared<CollisionHandler>(nullptr);
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
     auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position1, newSpeed, ObjectID::SPACESHIP);
      spaceship->Lives(3);
     auto centipede = std::make_shared<Centipede>(1);
     
     //set the centipede ready for collision
     centipede->segment(0)->setPosition(position2);
     
    //Collide the centipede with the Spaceship
     centipede->Move();
     collision->spaceshipHit(centipede,spaceship);
     
    
     CHECK(spaceship->ID() == ObjectID::EXPLOSION);
    
}

TEST_CASE("Spaceship  is declared dead if number of lives is 0"){
    
    auto collision = std::make_shared<CollisionHandler>(nullptr);
    auto newSpeed = 20.0f;
    auto position1 = vector2D{250.0f,100.0f};
    auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
    auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position1, newSpeed, ObjectID::SPACESHIP);
    //set number of lives to zero
    spaceship->Lives(1);
    auto centipede = std::make_shared<Centipede>(1);
    
    //set the centipede ready for collision
    centipede->segment(0)->setPosition(position2);
    
    //Collide the centipede with the Spaceship
    centipede->Move();
    collision->spaceshipHit(centipede,spaceship);
  
    CHECK(spaceship->Lives() == 0);
    CHECK(spaceship->isDead());
     
}


TEST_CASE("Centipede is dead if all CentiSegments are destroyed"){
    
    auto score = std::make_shared<Score>();
    auto collision = std::make_shared<CollisionHandler>(score);
    auto newSpeed = 20.0f;
    
    auto position1 = vector2D{250.0f ,120.0f- newSpeed};
    auto position2 = vector2D{250.0f,120.0f};
    
    auto centipede = std::make_shared<Centipede>(1);
    //Set the position just next to the LazerShot
    centipede->segment(0)->setPosition(position1);
     
    auto mushroom_field = std::make_shared<MushroomField>(1);
     
    auto spaceship = std::make_shared<Spaceship>(vector2D{SPACESHIP_X_SIZE,SPACESHIP_Y_SIZE},position2, newSpeed, ObjectID::SPACESHIP);
    //Load Lazershot
    spaceship->load();
    //Set the LazerShot speed
    std::get<0>(spaceship->firedLazerShot(0))->setSpeed(newSpeed);
    //Fire Lazershot at target
    spaceship->shoot();
        
     collision->targetDestroyed(spaceship,centipede,mushroom_field);
    
    
    CHECK(centipede->isDead());
    
}

//Score tests

TEST_CASE("Score increases by 100 if head of centipede is shot"){
    auto score_ = Score{};
    
    CHECK(score_.score() == 0);
    score_.centiheadDestroyed();
    CHECK(score_.score() == 100);
    
}

TEST_CASE("Score increases by 10 if body of centipede is shot"){
    auto score_ = Score{};
    
    CHECK(score_.score() == 0);
    score_.centibodyDestroyed();
    CHECK(score_.score() == 10);
    
}

TEST_CASE("Score increases by 1 if mushroom is shot"){
    auto score_ = Score{};
    
    CHECK(score_.score() == 0);
    score_.mushroomDestroyed();
    CHECK(score_.score() == 1);
    
}

//Mushroom Tests


TEST_CASE("Mushroom's Position cannot be set outside of the game grid X-boundaries"){
    
    auto outofHorizontalBoundsPosition1 = vector2D{2*ORIGINAL_SCREEN_WIDTH,100.0f};
    auto outofHorizontalBoundsPosition2 = vector2D{-89.0f,100.0f};
    
    //Check constructor
    CHECK_THROWS_AS(auto M1 = Mushroom(MUSHROOM_SIZE,outofHorizontalBoundsPosition1, 0.0f, ObjectID::MUSHROOM);, ObjectOutOfBounds);
    CHECK_THROWS_AS( auto M1 = Mushroom(MUSHROOM_SIZE,outofHorizontalBoundsPosition2, 0.0f, ObjectID::MUSHROOM);, ObjectOutOfBounds);
    
     //Check setPosition function
    auto M1 = Mushroom{MUSHROOM_SIZE,vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
    
    CHECK_THROWS_AS(M1.setPosition(outofHorizontalBoundsPosition1), ObjectOutOfBounds);
    CHECK_THROWS_AS(M1.setPosition(outofHorizontalBoundsPosition2), ObjectOutOfBounds);

}

    
TEST_CASE("Mushroom's Position cannot be set outside of the game grid Y-boundaries"){
    
    
    auto outofVerticalBoundsPosition1 = vector2D{100.0f,2*ORIGINAL_SCREEN_HEIGHT};
    auto outofVerticalBoundsPosition2 = vector2D{100.0f,-89.0f};
    
  //Check constructor
    CHECK_THROWS_AS(auto M1 = Mushroom(MUSHROOM_SIZE,outofVerticalBoundsPosition1 , 0.0f, ObjectID::MUSHROOM);, ObjectOutOfBounds);
    CHECK_THROWS_AS( auto M1 = Mushroom(MUSHROOM_SIZE,outofVerticalBoundsPosition2, 0.0f, ObjectID::MUSHROOM);, ObjectOutOfBounds);
    
     //Check setPosition function
    auto M1 = Mushroom{MUSHROOM_SIZE,vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
    
    CHECK_THROWS_AS(M1.setPosition(outofVerticalBoundsPosition1), ObjectOutOfBounds);
    CHECK_THROWS_AS(M1.setPosition(outofVerticalBoundsPosition2), ObjectOutOfBounds);


}




TEST_CASE("Mushroom cannot move"){
    
    auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
   
    CHECK_THROWS_AS(M1.Move(),NonMovableObject);
    

    }
    
TEST_CASE("Mushroom loses life if shot"){
    
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
       //Mushroom has 4 lives initially
      CHECK(M1.lives()==4);
      M1.collisionResponse();
      CHECK(M1.lives()==3);
    
    }
    
TEST_CASE("Mushroom chips if shot"){
    
     
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
     
      M1.collisionResponse();
      CHECK(M1.ID()==ObjectID::MUSHROO);
      M1.collisionResponse();
     CHECK(M1.ID()==ObjectID::MUSHRO);
    
    
    }

TEST_CASE("If number of lives is zero Mushroom is Dead"){
    
     
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
     //Simulate the Mushroom being shot 3 times
     M1.collisionResponse();
     CHECK_FALSE(M1.isDead());
     M1.collisionResponse();
     M1.collisionResponse();
     M1.collisionResponse();
     
     CHECK(M1.lives()==0);
     CHECK(M1.isDead());
    
    }
    
//Spider Tests
TEST_CASE("Spider Moves"){
    
    
    auto S1 = Spider{SPIDER_SIZE,SPIDER_INIT_POSITION,speed,ObjectID::SPIDER};
    S1.Move();
    S1.Move();
    CHECK_FALSE(S1.getPosition()==SPIDER_INIT_POSITION);
    
    }

TEST_CASE("Spider's Position cannot be set outside of the game grid Y-boundaries"){
    
    auto outofVerticalBoundsPosition1 = vector2D{100.0f, 2*ORIGINAL_SCREEN_WIDTH};
    auto outofVerticalBoundsPosition2 = vector2D{100.0f,-89.0f};
    
    //Check constructor
    CHECK_THROWS_AS(auto spider = Spider(SPIDER_SIZE,outofVerticalBoundsPosition1,speed,ObjectID::SPIDER), ObjectOutOfBounds);
    CHECK_THROWS_AS(auto spider = Spider(SPIDER_SIZE,outofVerticalBoundsPosition2,speed,ObjectID::SPIDER), ObjectOutOfBounds);
    
     //Check setPosition function
    auto S1 =  Spider{SPIDER_SIZE,SPIDER_INIT_POSITION,speed,ObjectID::SPIDER};
    
    CHECK_THROWS_AS(S1.setPosition(outofVerticalBoundsPosition1), ObjectOutOfBounds);
    CHECK_THROWS_AS(S1.setPosition(outofVerticalBoundsPosition2), ObjectOutOfBounds);


}
    

    
TEST_CASE("Spider's position can be set outside of the game grid X-boundaries"){
    
    
    auto outofHorizontalBoundsPosition1 = vector2D{2*ORIGINAL_SCREEN_WIDTH,100.0f};
    auto outofHorizontalBoundsPosition2 = vector2D{-89.0f,100.0f};
    
    //Check Constructor
    CHECK_NOTHROW(auto spider = Spider(SPIDER_SIZE,outofHorizontalBoundsPosition1,speed,ObjectID::SPIDER));
    CHECK_NOTHROW(auto spider = Spider(SPIDER_SIZE,outofHorizontalBoundsPosition2,speed,ObjectID::SPIDER));
    
    //Check setPosition function
    auto S1 =  Spider{SPIDER_SIZE,SPIDER_INIT_POSITION,speed,ObjectID::SPIDER};
    
    CHECK_NOTHROW(S1.setPosition(outofHorizontalBoundsPosition1));
    CHECK_NOTHROW(S1.setPosition(outofHorizontalBoundsPosition2));


}

//Timer Tests

TEST_CASE("Timer is initialised at zero seconds"){
    
    auto timer = Timer{};
    
    CHECK(timer.elapsedTime()==0.0f);

    }

TEST_CASE("Timer returns elapsed time code ran"){
    
    auto timer = Timer{};
    
    timer.start();
    //simulate 0.1 second
    usleep(100000);
    timer.end();
    auto runTime = timer.elapsedTime();
    CHECK(runTime >= 0.1);
    CHECK(runTime < 0.105);
    
    }

TEST_CASE("Timer can be reset"){
    
    auto timer = Timer{};
    
    timer.start();
    //simulate 0.01 second
    usleep(10000);
    timer.end();
    timer.reset();
    auto runTime = timer.elapsedTime();
    CHECK(runTime ==0 );
    
    }

//Scorpion Tests

TEST_CASE("scorpion Moves"){
    
    auto scorpion = Scorpion{SCORPION_SIZE,SCORPION_INIT_POSITION_L,SCORPION_SPEED, ObjectID::SCORPION_R};
    scorpion.Move();
    
    CHECK(scorpion.getPosition() ==  (SCORPION_INIT_POSITION_L + vector2D{SCORPION_SPEED,0.0f}));
   
    }
    
TEST_CASE("Scorpion can be set outside Horizontal Boundries"){
    
    auto outofHorizontalBoundsPosition1 = vector2D{2*ORIGINAL_SCREEN_WIDTH,100.0f};
    auto outofHorizontalBoundsPosition2 = vector2D{-89.0f,100.0f};
    
    //Check Constructor
    CHECK_NOTHROW(auto scorpion = Scorpion(SCORPION_SIZE,outofHorizontalBoundsPosition1,SCORPION_SPEED, ObjectID::SCORPION_R));
    CHECK_NOTHROW(auto scorpion = Scorpion(SCORPION_SIZE,outofHorizontalBoundsPosition2,SCORPION_SPEED, ObjectID::SCORPION_R));
    
    //Check setPosition function
    auto scorpion = Scorpion{SCORPION_SIZE,SCORPION_INIT_POSITION_L,SCORPION_SPEED, ObjectID::SCORPION_R};
    
    CHECK_NOTHROW(scorpion.setPosition(outofHorizontalBoundsPosition1));
    CHECK_NOTHROW(scorpion.setPosition(outofHorizontalBoundsPosition2));


    }

TEST_CASE("Scorpion cannot be set outside Vertical Boundries"){
    
    auto outofVerticalBoundsPosition1 = vector2D{100.0f, 2*ORIGINAL_SCREEN_WIDTH};
    auto outofVerticalBoundsPosition2 = vector2D{100.0f,-89.0f};
    
    //Check constructor
    CHECK_THROWS_AS(auto scorpion = Scorpion(SCORPION_SIZE,outofVerticalBoundsPosition1,SCORPION_SPEED, ObjectID::SCORPION_R), ObjectOutOfBounds);
    CHECK_THROWS_AS(auto scorpion = Scorpion(SCORPION_SIZE,outofVerticalBoundsPosition2,SCORPION_SPEED, ObjectID::SCORPION_R), ObjectOutOfBounds);
    
   //Check setPosition function
    auto scorpion = Scorpion{SCORPION_SIZE,SCORPION_INIT_POSITION_L,SCORPION_SPEED, ObjectID::SCORPION_R};
    
    CHECK_THROWS_AS(scorpion.setPosition(outofVerticalBoundsPosition1), ObjectOutOfBounds);
    CHECK_THROWS_AS(scorpion.setPosition(outofVerticalBoundsPosition2), ObjectOutOfBounds);
    
    }

TEST_CASE("Scorpion changes direction if Out of Horizontal Boundries"){
    
    auto edgePosition = vector2D{1.2*ORIGINAL_SCREEN_WIDTH, 20.0f};
    auto scorpion = Scorpion{SCORPION_SIZE,edgePosition,SCORPION_SPEED, ObjectID::SCORPION_L};
    scorpion.Move();
   
    CHECK(scorpion.ID() == ObjectID::SCORPION_R);
    
    }
    
TEST_CASE("Scorpion changes direction if reset"){
    
    auto scorpion = Scorpion{SCORPION_SIZE,SCORPION_INIT_POSITION_R,SCORPION_SPEED, ObjectID::SCORPION_L};
   
    scorpion.reset();
    CHECK(scorpion.ID() == ObjectID::SCORPION_R);
    
    }
    
    