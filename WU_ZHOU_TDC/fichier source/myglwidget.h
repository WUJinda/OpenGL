#include "Car.h"
#include "Ground.h"
#include "oppcars.h"
#include "dialog.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>

/*
 * Cette classe vise à afficher des éléments tels que les véhicules,
 * le ciel et la terre dans la scène opengl, et exécute la logique de
 * contrôle de la scène rafraîchissante en surveillant les événements
 * de la souris et du clavier.
*/

class MyGLWidget : public QOpenGLWidget // auteurs : WU & ZHOU
{
    Q_OBJECT
public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    ~MyGLWidget();

    void updateMove(int move);// Fonction de changement de mouvement en détectant les poings
    void detectCollision();//Fonction de détection de la collision
    void warning();//Fonction pour faire apparaître une fenêtre de dialogue.
    void increaseTime();//Fonction d'augmentation du temps.
signals:
    void endGame();

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent * event);
    //Fonction de gestion d'interactions Souris
    void mousePressEvent(QMouseEvent *event);

    Dialog * dial_;

protected slots:
    void refresh();
    void gameOver();
    void gameRestart();

private:
    Car *maVoiture_ = nullptr;
    Ground *myGround_ = nullptr;
    OppCars *oppositeCar_ = nullptr;
    OppCarVector* oppositeCars_ = nullptr;

    float translationValue_ = 0.0f;

    QTimer* timer_ = nullptr;
    QString timeText_ = "00:00";
    int record_ = 0;

    bool pause_ = false;
    bool right_status_ = false;
    bool left_status_ = false;
    bool isnewgame_ = false;

};
