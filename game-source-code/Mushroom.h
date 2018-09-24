#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <memory>
#include "GameObject.h"
#include "Csegment.h"

class NonMovableObject{};

class Mushroom: public GameObject{
public:
    Mushroom(const vector2D& size, const vector2D& position, float speed, ObjectID objectid);
    //Take action if Mushroom is shot
    void shot();
    //Return the number of lives the Mushroom has
    int lives() const;
    //Move function from parent
    virtual void Move(Direction direction) override;
    //Turn a CentiSegment into a Mushroom
    void transform(std::shared_ptr<CentiSegment> seg);
    //Reset Mushroom to intial conditions
    virtual void reset() override;
    virtual ~Mushroom();
    
private:
   
    int lives_;

};

#endif // MUSHROOM_H