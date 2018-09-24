#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <memory>
#include "GameObject.h"
#include "Csegment.h"

class NonMovableObject{};

class Mushroom: public GameObject{
public:
    Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid);
    void shot();
    int lives() const;
    virtual void Move(Direction direction) override;
    void transform(std::shared_ptr<CentiSegment> seg);
    virtual void reset() override;
    ~Mushroom();
    
private:
   
    int lives_;

};

#endif // MUSHROOM_H