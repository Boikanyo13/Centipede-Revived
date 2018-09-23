#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <memory>



#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Player.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Constants.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\LazerShot.h"
#include "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Csegment.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\GameTypes.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\GameFiles.cpp"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Display.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Collider.cpp"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Score.h"
#include  "C:\Users\elias\Dropbox\YOS3\SM2\ELEN3009\Project\project-repo\game-source-code\Mushroom.h"

/*
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Player.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Constants.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\LazerShot.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Csegment.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Centipede.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\SplashScreen.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameTypes.cpp"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Display.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameFiles.cpp"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\GameObject.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Collider.h"
#include  "C:\Users\bvrad\Dropbox\Boikanyo\elen3009\PROJECT\2018-project-1386807-Radiokana-1427726-Sepuru\game-source-code\Score.cpp"*/
   
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
TEST_CASE("LazerShot cannot be set out of game grid Boundary"){
    
    auto position = vector2D{ORIGINAL_SCREEN_WIDTH + 1.0f,ORIGINAL_SCREEN_HEIGHT + 1.0f};
   
    CHECK_THROWS_AS(auto L1 = LazerShot(vector2D{5.0f,10.0f},position,speed, ObjectID::BULLET),ObjectOutOfBounds);
    
    }
     
 
TEST_CASE("LazerShot is loaded to the Player"){
        
         auto lazershot_pos = vector2D{0.0f,0.0f};
         auto L1 = LazerShot{vector2D{5.0f,10.0f},lazershot_pos,speed, ObjectID::BULLET};
         auto P1 = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
        
        CHECK_FALSE(L1.getPosition()==P1.getPosition());
        
        //Load Bullet to player
        L1.Load(P1.getPosition());
      
        CHECK(L1.getPosition()==P1.getPosition());
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


//LazerShot + Player Test

TEST_CASE("LazerShot is loaded onto the LazerShot Gun of the Player"){
    
    auto expectedLoadedShot = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},PLAYER_START_POSTION, 1.0f, ObjectID::BULLET);
    
     auto player = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
    
    //Load the Player's LazerGun three times
     player.load();
     player.load();
     player.load();
     
     auto expectedNoOfLazerShots = 3;   
     
     //All the lazershots are identical, choose the 1st one   
     auto loadedLazerShot =  std::get<0>(player.firedLazerShot(0));
     auto noOflazershots = std::get<1>(player.firedLazerShot(0));
     
     CHECK(loadedLazerShot->getPosition() == expectedLoadedShot->getPosition());
     CHECK(noOflazershots==expectedNoOfLazerShots );
     
}

TEST_CASE("Player Shoots LazerShots"){
    
    auto player = Player{vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},PLAYER_START_POSTION, speed, ObjectID::PLAYER};
     
    player.load();
    
    auto loadedLazerShot= std::get<0>(player.firedLazerShot(0));
    
    //LazerShot is loaded at Player
    CHECK(loadedLazerShot->getPosition()==player.getPosition());
    
    player.shoot();
   
    //LazerShot shoots up
    auto expectedPosition = vector2D{PLAYER_START_POSTION.x(),( PLAYER_START_POSTION.y()-loadedLazerShot->getSpeed())};
    
    CHECK(loadedLazerShot->getPosition()==expectedPosition); 
    
    }
    
//Centisegment TESTS

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
    
TEST_CASE("Check if length of centipede corresponds to the number of segments "){
        
    auto centipede = Centipede{CENTIPEDE_LENGTH};
    CHECK(centipede.length() == CENTIPEDE_LENGTH);
        
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
    
     auto collider = Collider{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f,100.0f - newSpeed};
     
     auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position1,newSpeed, ObjectID::BULLET);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
     
     CHECK_FALSE(collider.checkCollision(L1,Cs1));
     
     L1->Fire();
     
     CHECK(collider.checkCollision(L1,Cs1));
     
    }
    
TEST_CASE("Horizontal collision between two Gameobjects is detected"){
    
     auto collider = Collider{};
     auto newSpeed = 25.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position1, newSpeed, ObjectID::PLAYER);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
    
     
     CHECK_FALSE(collider.checkCollision(Cs1,P1));
     Cs1->Move();
     CHECK(collider.checkCollision(Cs1,P1));
    
    }
    
TEST_CASE("The other object dies after collision"){
    
     auto collider = Collider{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f,100.0f - newSpeed};
     
     auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position1,newSpeed, ObjectID::BULLET);
     auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position2,newSpeed, ObjectID::CENTIPEDE);
      
     CHECK_FALSE(Cs1->isDead());
     
     L1->Fire();
     //The second argument into the function is the other
     CHECK(collider.checkCollision(L1,Cs1));
     CHECK(Cs1->isDead());
     
} 

TEST_CASE("Dead object cannot collide"){
    
     auto collider = Collider{};
    auto position = vector2D{250.0f,100.0f};
   
   //Objects at the same place
    auto L1 = std::make_shared<LazerShot>(vector2D{5.0f,10.0f},position,speed, ObjectID::BULLET);
    auto Cs1 = std::make_shared<CentiSegment>(vector2D{CENTIPEDE_X_SIZE,CENTIPEDE_Y_SIZE},position,speed, ObjectID::CENTIPEDE);
    
    CHECK(collider.checkCollision(Cs1,L1));

    //Cs1->updateState(State::DEAD);
    
    CHECK_FALSE(collider.checkCollision(Cs1,L1));
    
}  

TEST_CASE("Player looses life if hit"){
    
     auto collider = Collider{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
     auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position1, newSpeed, ObjectID::PLAYER);
     auto centipede = std::make_shared<Centipede>(1);
     centipede->centiSegment(0)->setPosition(position2);
     
     //Player has 3 lives initially
      P1->Lives(3);
      
     CHECK(P1->Lives()==3);
     
     centipede->Move();
     
     collider.isPlayerHit(centipede,P1);
     
     CHECK(P1->Lives()==2);
    
}


TEST_CASE("Player explodes if hit"){
    
     auto collider = Collider{};
     auto newSpeed = 20.0f;
     auto position1 = vector2D{250.0f,100.0f};
     auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
     auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position1, newSpeed, ObjectID::PLAYER);
      P1->Lives(3);
     auto centipede = std::make_shared<Centipede>(1);
     
     //set the centipede ready for collision
     centipede->centiSegment(0)->setPosition(position2);
     
    //Collide the centipede with the player
     centipede->Move();
     collider.isPlayerHit(centipede,P1);
     
    
     CHECK(P1->ID() == ObjectID::EXPLOSION);
    
}

TEST_CASE("Player  is declared dead if number of lives is 0"){
    
    auto collider = Collider{};
    auto newSpeed = 20.0f;
    auto position1 = vector2D{250.0f,100.0f};
    auto position2 = vector2D{250.0f - newSpeed,100.0f};
     
    auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position1, newSpeed, ObjectID::PLAYER);
    //set number of lives to zero
    P1->Lives(1);
    auto centipede = std::make_shared<Centipede>(1);
    
    //set the centipede ready for collision
    centipede->centiSegment(0)->setPosition(position2);
    
    //Collide the centipede with the player
    centipede->Move();
    collider.isPlayerHit(centipede,P1);
  
    CHECK(P1->Lives() == 0);
    CHECK(P1->isDead());
     
}


TEST_CASE("Centipede is dead if all CentiSegments are destroyed"){
    
    auto score = std::make_shared<Score>();
    auto collider = Collider{score};
    auto newSpeed = 20.0f;
    
    auto position1 = vector2D{250.0f ,120.0f- newSpeed};
    auto position2 = vector2D{250.0f,120.0f};
    
    auto centipede = std::make_shared<Centipede>(1);
    //Set the position just next to the LazerShot
    centipede->centiSegment(0)->setPosition(position1);

     
    auto P1 = std::make_shared<Player>(vector2D{PLAYER_X_SIZE,PLAYER_Y_SIZE},position2, newSpeed, ObjectID::PLAYER);
    //Load Lazershot
    P1->load();
    //Set the LazerShot speed
    std::get<0>(P1->firedLazerShot(0))->setSpeed(newSpeed);
    //Fire Lazershot at target
    P1->shoot();
        
     collider.isTargetDestroyed(P1,centipede);
    
    
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

//Mushroom Test
TEST_CASE("Mushroom cannot move"){
    
    auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
   
    CHECK_THROWS_AS(M1.Move(Direction::UP),NonMovableObject);
    

    }
    
TEST_CASE("Mushroom loses life if shot"){
    
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
       //Mushroom has 4 lives initially
      CHECK(M1.lives()==4);
      M1.shot();
      CHECK(M1.lives()==3);
    
    }
    
TEST_CASE("Mushroom chips if shot"){
    
     
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
     
      M1.shot();
      CHECK(M1.ID()==ObjectID::MUSHROO);
      M1.shot();
     CHECK(M1.ID()==ObjectID::MUSHRO);
    
    
    }

TEST_CASE("If number of lives is zero Mushroom is Dead"){
    
     
     auto M1 = Mushroom{vector2D{20.0f,20.0f},vector2D{100.0f,240.0f}, 0.0f, ObjectID::MUSHROOM};
     
     //Simulate the Mushroom being shot 3 times
     M1.shot();
     CHECK_FALSE(M1.isDead());
     M1.shot();
     M1.shot();
     M1.shot();
     
     CHECK(M1.lives()==0);
     CHECK(M1.isDead());
    
    }