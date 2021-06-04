#ifndef OPPCARS_H
#define OPPCARS_H

#include <qopengl.h>
#include <GL/glu.h>
#include <time.h>
#include <vector>

using namespace std;
class OppCars
{
public:
    OppCars();// Constructeur
    ~OppCars();// Destructeur

    void Display();// Methode d'affichage
    void updateZ();// Mettre à jour l'emplacement
    float getZ();// Obtenez la coordonnée z
    float getX();// Obtenez la coordonnée x
    void changeState(bool b);// Modifiez s'il faut arrêter l'état.

private:
    float posX_ = 0.f;
    float posY_ = 0.f;
    float posZ_ = -198.5f;
    float length_ = 250.f;
    bool pause_ = false;

    GLUquadric* quadrique_ = nullptr;
};

class OppCarVector{
public:
    vector<OppCars*> cars_;

    OppCarVector();// Constructeur
    OppCarVector(OppCars* car);// Constructeur avec parametres
    ~OppCarVector();// Destructeur

    void changeState(bool b); // Modifiez s'il faut arrêter l'état.
    void moveOut();// La méthode de contrôle de la voiture opposée pour sortir de la frontière.
    void Display();// Methode d'affichage
    void erase(unsigned int);//Relâchez la voiture du côté opposé qui sort de la frontière.
};

#endif // OPPCARS_H
