#include "DataTypes.h"

// Position

Position::Position()
{
    x_=0.f;
    y_=0.f;
    z_=0.f;
}

Position::Position(float x, float y, float z)
{
    x_=x;
    y_=y;
    z_=z;
}

void Position::setPosition(float x, float y, float z)
{
    x_=x;
    y_=y;
    z_=z;
}

void Position::setX(float x)
{
    x_=x;
}

void Position::setY(float y)
{
    y_=y;
}
void Position::setZ(float z)
{
    z_=z;
}

float Position::x()
{
    return(x_);
}

float Position::y()
{
    return(y_);
}

float Position::z()
{
    return(z_);
}

// Rotation

Rotation::Rotation()
{
    rotX_=0.f;
    rotY_=0.f;
    rotZ_=0.f;
}

Rotation::Rotation(float rotX, float rotY,float rotZ)
{
    rotX_=rotX;
    rotY_=rotY;
    rotZ_=rotZ;
}

void Rotation::setRotation(float rotX, float rotY,float rotZ)
{
    rotX_=rotX;
    rotY_=rotY;
    rotZ_=rotZ;
}

void Rotation::setRotX(float rotX)
{
    rotX_=rotX;
}

void Rotation::setRotY(float rotY)
{
    rotY_=rotY;
}

void Rotation::setRotZ(float rotZ)
{
    rotZ_=rotZ;
}

float Rotation::rotX()
{
    return(rotX_);
}

float Rotation::rotY()
{
    return(rotY_);
}

float Rotation::rotZ()
{
    return(rotZ_);
}

// Velocity

Velocity::Velocity()
{
    vX_=0.f;
    vY_=0.f;
    vZ_=0.f;
}

Velocity::Velocity(float vX, float vY,float vZ)
{
    vX_=vX;
    vY_=vY;
    vZ_=vZ;
}

void Velocity::setVelocity(float vX, float vY,float vZ)
{
    vX_=vX;
    vY_=vY;
    vZ_=vZ;
}

void Velocity::setVX(float vX)
{
    vX_=vX;
}

void Velocity::setVY(float vY)
{
    vY_=vY;
}

void Velocity::setVZ(float vZ)
{
    vZ_=vZ;
}

float Velocity::vX()
{
    return(vX_);
}

float Velocity::vY()
{
    return(vY_);
}

float Velocity::vZ()
{
    return(vZ_);
}

// Color

Color::Color()
{
    r_=0.f;
    g_=0.f;
    b_=0.f;
}

Color::Color(float red, float green, float blue)
{
    r_=red;
    g_=green;
    b_=blue;
}

void Color::setColor(float red, float green, float blue)
{
    r_=red;
    g_=green;
    b_=blue;
}

void Color::setRed(float red)
{
    r_=red;
}

void Color::setGreen(float green)
{
    g_=green;
}

void Color::setBlue(float blue)
{
    b_=blue;
}

float Color::red()
{
    return(r_);
}

float Color::green()
{
    return(g_);
}

float Color::blue()
{
    return(b_);
}

// SquareHitBox

BoxHitBox::BoxHitBox(Position minPos, Position maxPos)
{
    if (minPos.x()>maxPos.x()) {
        minPos.setX(minPos.x()+maxPos.x());
        maxPos.setX(minPos.x()-maxPos.x());
        minPos.setX(minPos.x()-maxPos.x());
    }
    if (minPos.y()>maxPos.y()) {
        minPos.setY(minPos.y()+maxPos.y());
        maxPos.setY(minPos.y()-maxPos.y());
        minPos.setY(minPos.y()-maxPos.y());
    }
    if (minPos.z()>maxPos.z()) {
        minPos.setZ(minPos.z()+maxPos.z());
        maxPos.setZ(minPos.z()-maxPos.z());
        minPos.setZ(minPos.z()-maxPos.z());
    }
    min_=minPos;
    max_=maxPos;
};

BoxHitBox::BoxHitBox(float minX,float maxX,float minY,float maxY,float minZ,float maxZ){
    if (minX>maxX) {
        minX=minX+maxX;
        maxX=minX-maxX;
        minX=minX-maxX;
    }
    if (minY>maxY) {
        minY=minY+maxY;
        maxY=minY-maxY;
        minY=minY-maxY;
    }
    if (minZ>maxZ) {
        minZ=minZ+maxZ;
        maxZ=minZ-maxZ;
        minZ=minZ-maxZ;
    }

    min_=Position(minX,minY,minZ);
    max_=Position(maxX,maxY,maxZ);
};

Position BoxHitBox::min()
{
    return(min_);
}

Position BoxHitBox::max()
{
    return(max_);
}
bool BoxHitBox::collision(BoxHitBox hitbox){
    Position objMin=hitbox.min();
    Position objMax=hitbox.max();

    //return(min_.z()<objMax.z());

    return(
        max_.x()>objMin.x() && min_.x()<objMax.x()
        && max_.y()>objMin.y() && min_.y()<objMax.y()
        && max_.z()>objMin.z() && min_.z()<objMax.z()
    );
};
