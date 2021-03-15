#include "entity.h"

#include <qopengl.h>
#include <vector>

// Classe dediee pour la gestion de la voiture
class Car : public Entity
{
public:
    Car();
    Car(float colorR, float colorG, float colorB);
    ~Car();

    Position getPosition();
    BoxHitBox hitbox();

protected:

    void drawCar();
    void drawWheel();

    Velocity* vel_;
    Rotation* rot_;
    Color* color_;

private :
    GLUquadric* wheelQuadric_ = nullptr;
};

class Player : public Car
{
public:
    Player();
    ~Player();

    void draw();
    void beacon();
    void left();
    void right();

private:
    short beaconTimer_;
    void updatePos();
};

class OpposingCar : public Car
{
public:
    OpposingCar(float* speed);
    ~OpposingCar();

    void draw();

private:
    float* speed_;
    void updatePos();
};

class OppCarVector{
public:
    std::vector<OpposingCar*> cars_;

    OppCarVector();
    OppCarVector(OpposingCar* car);
    ~OppCarVector();

    int clearOutOfBounds();
    void draw();
    void erase(unsigned int);
};
