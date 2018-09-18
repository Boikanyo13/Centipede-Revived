#ifndef LAZERSHOT_H
#define LAZERSHOT_H
#include "GameObject.h"

class LazerShot: public GameObject{

public:
    LazerShot(const vector2D& size,const vector2D& position, float speed, ObjectID objectid);
    virtual void Move(Direction direction) override;
    void Load(const vector2D& pos);
    virtual ~LazerShot();

private:

};


#endif // LAZERSHOT_H
