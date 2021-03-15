#ifndef PLANE_H
#define PLANE_H

#include "entity.h"

#include <qopengl.h>

class Plane : public Entity
{
public:
    Plane(float* speed);
    Plane(float* speed, GLUquadric* planeQuadric);
    ~Plane();
    void draw();
    float posZ();
private:
    int direction_;
    bool standAlone_;
    float* speed_;
    Velocity* vel_;
    GLUquadric* planeQuadric_ = nullptr;
};

class PlaneHolder
{
public:
    PlaneHolder(float* speed);
    ~PlaneHolder();

    void draw();
private:
    Plane* plane_=nullptr;
    GLUquadric* planeQuadric_ = nullptr;
    float* speed_;

};

#endif // PLANE_H
