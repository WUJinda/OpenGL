#ifndef SIGN_H
#define SIGN_H

#include "entity.h"

#include <qopengl.h>

class Sign : Entity
{
public:
    Sign(float* sign);
    ~Sign();
    void draw();
private:
    float* speed_;
    GLUquadric* signQuadric_ = nullptr;
};

#endif // SIGN_H
