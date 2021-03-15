#ifndef DATATYPES_H
#define DATATYPES_H

#include <GL/glu.h>


class Position
{
public:
    Position();
    Position(float x, float y, float z);

    void setPosition(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float x();
    float y();
    float z();

private:
    float x_;
    float y_;
    float z_;
};

class Rotation
{
public:
    Rotation();
    Rotation(float rotX, float rotY,float rotZ);

    void setRotation(float rotX, float rotY,float rotZ);
    void setRotX(float rotX);
    void setRotY(float rotY);
    void setRotZ(float rotZ);

    float rotX();
    float rotY();
    float rotZ();

private:
    float rotX_;
    float rotY_;
    float rotZ_;
};

class Velocity
{
public:
    Velocity();
    Velocity(float vX, float vY,float vZ);

    void setVelocity(float vX, float vY,float vZ);
    void setVX(float rotX);
    void setVY(float rotY);
    void setVZ(float rotZ);

    float vX();
    float vY();
    float vZ();

private:
    float vX_;
    float vY_;
    float vZ_;
};

class Color
{
public:
    Color();
    Color(float red, float green,float blue);

    void setColor(float red, float green,float blue);
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);

    float red();
    float green();
    float blue();

private:
    float r_;
    float g_;
    float b_;
};

class BoxHitBox
{
public:

    BoxHitBox(Position minPos, Position maxPos);
    BoxHitBox(float minX,float maxX,float minY,float maxY,float minZ,float maxZ);

    bool collision(BoxHitBox hitbox);

    Position min();
    Position max();

private:
    Position min_;
    Position max_;

};

class MaterialProperty
{
public:
    MaterialProperty(GLfloat p1=0.f, GLfloat p2=0.f, GLfloat p3=0.f, GLfloat p4=1.f){values_[0]=p1;values_[1]=p2;values_[2]=p3;values_[3]=p4;};

    void set(float p1, float p2, float p3, float p4){values_[0]=p1;values_[1]=p2;values_[2]=p3;values_[3]=p4;};

    GLfloat* get(){return(values_);};
    GLfloat* getFirst(){return(&values_[0]);};

private:
    GLfloat values_[4];
};
class Material
{
public:
    Material(MaterialProperty ambient=MaterialProperty(0.2,0.2,0.2,1.),MaterialProperty diffuse=MaterialProperty(0.8,0.8,0.8,1.),MaterialProperty specular=MaterialProperty(0.,0.,0.,1.),MaterialProperty emission=MaterialProperty(0.,0.,0.,1.))
    {
        ambient_=ambient;
        diffuse_=diffuse;
        specular_=specular;
        emission_=emission;
    };

public:
    MaterialProperty ambient_;
    MaterialProperty diffuse_;
    MaterialProperty specular_;
    MaterialProperty emission_;
};
#endif // DATATYPES_H
