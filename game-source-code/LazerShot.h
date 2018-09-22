#ifndef LAZERSHOT_H
#define LAZERSHOT_H
#include "GameObject.h"

class LazerShot: public GameObject{

public:
    LazerShot(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    //Load Lazershot to player
    void Load(const vector2D& pos);
    //Fire Lazershot
    void Fire();
    //destroy Lazershot
    virtual void reset() override;
    virtual ~LazerShot();

private:
     virtual void Move(Direction direction) override;
};


#endif // LAZERSHOT_H
