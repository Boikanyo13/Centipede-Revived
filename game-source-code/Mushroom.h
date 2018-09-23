#ifndef MUSHROOM_H
#define MUSHROOM_H
#include "GameObject.h"

class NonMovableObject{};

class Mushroom: public GameObject{
public:
    Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid);
    void shot();
    int lives() const;
    virtual void Move(Direction direction) override;
    virtual void reset() override;
    ~Mushroom();
    
private:
   
    int lives_;

};

#endif // MUSHROOM_H