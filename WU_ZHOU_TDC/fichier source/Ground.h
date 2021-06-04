#ifndef GROUND_H
#define GROUND_H
#include <qopengl.h>
#include <QImage>
#include <GL/glu.h>
#include <QDebug>

/*
 * Cette classe vise à dessiner des éléments liés à la terre
 * et à gérer la lumière ambiante et les textures d'objets.
*/
class Ground // auteurs : WU & ZHOU
{
//    Q_OBJECT;
public:

    Ground();// Constructeur
    ~Ground();// Destructeur
    void Display();// Methode d'affichage

    void resetPos();//Réinitialiser la position
    void move();//changer la position
    void reinitial();//Réinitialiser tout les values de Ground
    void changeState(bool pause);//Modifiez s'il faut arrêter l'état.
    void addOil();//Vérifiez s'il faut faire le plein

private:
    GLuint* textures_=nullptr;
    QImage texture_road_;
    QImage texture_grass_;
    QImage texture_sky_;
    QImage texture_fuel_;
    GLUquadric* quadrique_ = nullptr;

    float fuel_pos_ = -198.5f;
    float pos_ = 0.0f;
    bool pause_ = false;
    bool addOil_ = false;

};
#endif // GROUND_H
