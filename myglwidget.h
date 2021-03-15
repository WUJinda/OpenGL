#include "Keyboard.h"
#include "Car.h"
#include "Ground.h"
#include "Sign.h"

#include "plane.h"

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <vector>
#include <qpainter.h>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    ~MyGLWidget();


protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'éclairage
    void lightGL();

    // Fonction d'affichage
    //void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent* event);

    // Fonction de gestion d'interactions clavier
    void keyReleaseEvent(QKeyEvent* event);

    // Fonction d'affichage du hud
    void paintEvent(QPaintEvent *event);

private:

    float* speed_;
    float record_;
    Keyboard * keyboard_=nullptr;
    Player * player_=nullptr;
    OppCarVector* oppCars_;
    Ground * ground_=nullptr;
    Sign * sign_=nullptr;

    PlaneHolder * plane_=nullptr;


    QTimer * timer_=nullptr;

private slots:
    void refresh();

    void clearGL();

};
