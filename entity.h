#ifndef ENTITY_H
#define ENTITY_H

#include "DataTypes.h"

class Entity
{
public:
    Entity();
    ~Entity();

protected:
    Position* pos_=nullptr;
};

#endif // ENTITY_H
