#ifndef CAR_H
#define CAR_H
#include <qopengl.h>
#include <GL/glu.h>
#include <QTime>

/*
 * Cette classe vise à dessiner les véhicules
 * et les éléments associés contrôlés par le joueur.
*/

class Car // auteurs : WU & ZHOU
{

public:

    Car();// Constructeur
    ~Car();// Destructeur
    void Display();// Methode d'affichage
    void reinitial();// Methode d'initialisation
    void consumeOil();// Methode de Consommation d'essence
    int getOil() {return oil_;};//Obtenir la quantité de carburant actuelle
    void setOil(int oil){oil_ = oil;};//Régler la quantité de carburant

private:
    GLUquadric* quadrique_ = nullptr;
    QTime beaconTimer_;
    int oil_;
};
#endif // CAR_H
