#ifndef LAZERSHOT_H
#define LAZERSHOT_H
#include "GameObject.h"

class LazerShot: public GameObject{

public:
    LazerShot(const vector2D& size,const vector2D& position, float speed, ObjectID objectid):
    GameObject{size,position,speed,objectid}
    {}
    //Load Lazershot to player
    void Load(const vector2D& position) {setPosition(position);}
    //move the Lazershot
    virtual void Move() override;
    //Fire Lazershot
    void Fire();
    //destroy Lazershot
    virtual void reset() override {updateState(State::DEAD);}
    virtual ~LazerShot(){}
     
};


#endif // LAZERSHOT_H
