#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <GL/glu.h>
#include <QTimer>

#include <DataTypes.h>

// Declarations des constantes
const unsigned int WIN = 900;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    record_=.5f;

    timer_ = new QTimer(this);
    timer_->setInterval(17);
    connect(timer_, SIGNAL(timeout()),this, SLOT(refresh()));
    timer_->start();

    keyboard_ = new Keyboard();
    // Reglage de la taille/position
    setMinimumSize(WIN, WIN);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    //QSound::play("://Music/ending_titles_tron.wav");
}

// Destructeur

MyGLWidget::~MyGLWidget(){
    clearGL();

    delete timer_;
    delete keyboard_;
}

void MyGLWidget::clearGL(){
    delete player_;
    delete oppCars_;
    delete ground_;
    delete speed_;
    delete sign_;
    delete plane_;
}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    speed_=new float(.5f);
    player_ = new Player();
    oppCars_=new OppCarVector(new OpposingCar(speed_));
    ground_ = new Ground(speed_);
    sign_ = new Sign(speed_);

    plane_ = new PlaneHolder(speed_);

    glClearColor(.3f,.7f,.9f,1.f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.,1.,2,2000.);
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.,width/(float)height,2,2000.);
    glViewport(0, 0, width, height);
}


// Fonction d'affichage
void MyGLWidget::lightGL()
{
    //GLfloat ambient_tab[]={.05f,.025f,.01f,1.f};
    //GLfloat light_tab[]={.5f,.5f,.5f,1.f};
    //glLightfv(GL_LIGHT0,GL_AMBIENT, light_tab);
    //glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.3f,.7f,.9f).get());
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,MaterialProperty(.8f,.05f,.02f,1.f).get());
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,MaterialProperty(.3f,.7f,.9f,1.f).get());
}

// Fonction d'affichage
//void MyGLWidget::paintGL(){};
/*
void MyGLWidget::paintGL()
{

    QPainter painter(this);
    painter.beginNativePainting();

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    //glOrtho(-5.f, 5.f, -5.f, 5.f, 2.f, 2000.f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //gluLookAt(0,3,4,
    gluLookAt(player_->getPosition().x()/4.f,3,4,
    //          0,1.,0,
              player_->getPosition().x()/3.f,1.,0,
              0,1,0);

    player_->draw();
    oppCars_->draw();
    sign_->draw();
    ground_->draw();

    painter.endNativePainting();

    //painter.setBrushOrigin(QPoint(0,0));
    painter.fillRect(0,0,width(),height(),QColor(0.,0.,0.,191));

}
*/

// fonction de rafraichissement
void MyGLWidget::refresh(){

    if (!(keyboard_->left_->status() && keyboard_->right_->status()))
    {
        if (keyboard_->left_->status()) player_->left();
        else {if (keyboard_->right_->status()) player_->right();}
    }

    unsigned int i;

    *speed_+=.05f * (float)oppCars_->clearOutOfBounds();

    BoxHitBox playerHitbox=player_->hitbox();
    for (i=0;i<oppCars_->cars_.size();i++)
    {
        if (playerHitbox.collision(oppCars_->cars_[i]->hitbox())) {
            clearGL();
            initializeGL();
            //close();
            return;
        }
    }

    if(*speed_>record_){record_=*speed_;}

    if(rand()/ (*speed_+.5f)/(float)RAND_MAX<.01f){oppCars_->cars_.push_back(new OpposingCar(speed_));}

    update();

}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            keyboard_->right_->press();
            break;
        case Qt::Key_Left:
            keyboard_->left_->press();
            break;
        case Qt::Key_P:
            if(timer_->isActive()){timer_->stop();}
            else {timer_->start();}
            break;
        case Qt::Key_R:
            clearGL();
            initializeGL();
            return;
            break;
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
}

void MyGLWidget::keyReleaseEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            keyboard_->right_->release();
            break;
        case Qt::Key_Left:
            keyboard_->left_->release();
            break;
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
}

void MyGLWidget::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.beginNativePainting();

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    //glOrtho(-5.f, 5.f, -5.f, 5.f, 2.f, 2000.f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //gluLookAt(0,3,4,
    gluLookAt(player_->getPosition().x()/4.f,3,4,
    //          0,1.,0,
              player_->getPosition().x()/3.f,1.,0,
              0,1,0);

    oppCars_->draw();
    sign_->draw();
    ground_->draw();

    plane_->draw();
    player_->draw();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    painter.endNativePainting();
    glDisable(GL_DEPTH_TEST);


    painter.setRenderHint(QPainter::Antialiasing);

    QRect hud=rect();
    hud.moveTop(3*hud.bottom()/4);

    painter.fillRect(hud,QColor(0,0,0,95));

    QFont font("times", width()/30);
    painter.setPen(Qt::white);
    painter.setFont(font);

    painter.drawText(width()/9,height()-height()/8, QString("Vitesse : ")+QString::number((int)(*speed_*120))+QString("kph"));
    painter.drawText(5*width()/9,height()-height()/8, QString("Record : ")+QString::number((int)(record_*120))+QString("kph"));
    painter.end();
};
