#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <GL/glu.h>
#include <QPainter>
#include <QMessageBox>

// Declarations des constantes
const unsigned int WIN = 900;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    timer_ = new QTimer(this);
    timer_->setInterval(100);
    connect(timer_, SIGNAL(timeout()),this, SLOT(refresh()));
    timer_->start();

}
MyGLWidget::~MyGLWidget(){
    delete maVoiture_;
    delete myGround_;
    delete oppositeCar_;
    delete oppositeCars_;
    delete timer_;

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    //Init Voiture
    maVoiture_ = new Car();
    myGround_ = new Ground();
    oppositeCar_ = new OppCars();
    oppositeCars_ = new OppCarVector(oppositeCar_);


    //couleur 0du fond
    glClearColor(.5f,.7f,.8f,0.f);

    // Activer le mode profondeur
    glEnable(GL_DEPTH_TEST);


}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    //
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-5,5,-5,5,2,2000);
    gluPerspective(70,width/height,2,2000);

}

void MyGLWidget::refresh()
{

    if (!(right_status_ && left_status_))
    {
        if (left_status_) {
            if (translationValue_ > -7.0f)
                translationValue_ -= 0.5f;
        }
        else {
            if (right_status_) {
                if (translationValue_ < 7.0f)
                    translationValue_ += 0.5f;
            }
        }
    }
    if(!(maVoiture_->getOil() > 0)){
        warning();
    }
    detectCollision();
    oppositeCars_->moveOut();
    if(oppositeCars_->cars_.size() < 3 && oppositeCars_->cars_[0]->getZ() > -30 && !pause_){

        oppositeCar_ = new OppCars();
        oppositeCars_->cars_.push_back(oppositeCar_);

    }


    if(!pause_){
        increaseTime();
        record_ += 1;
        maVoiture_->consumeOil();
    }
    update();
}
void MyGLWidget::increaseTime(){
    int minutes = timeText_.split(":")[0].toInt();
    float seconds = timeText_.split(":")[1].toFloat();

    seconds+=0.1f;
    if(seconds>=60)
    {
        minutes++;
        seconds-=60;
    }
    timeText_ = QString("%1%2%3").arg(QString::number(minutes),tr(":"),QString::number(seconds));
}
void MyGLWidget::warning(){

    dial_ = new Dialog;
    dial_->setRandT(record_, timeText_);
    dial_->exec();

    if (dial_->getRestart()) gameRestart();
    if (dial_->getQuit()) gameOver();

}

void MyGLWidget::gameOver()
{
    emit endGame();

}

void MyGLWidget::gameRestart()
{
    myGround_->reinitial();
    maVoiture_->reinitial();
    timeText_ = QString("%1%2%3").arg(QString::number(0),tr(":"),QString::number(0));
    record_ = 0;
    translationValue_ = 0.0f;
    pause_ = false;
    right_status_ = false;
    left_status_ = false;
    addOil_ = false;
    oppositeCars_->cars_.clear();
}
void MyGLWidget::detectCollision(){

    unsigned int n=oppositeCars_->cars_.size();
    for(unsigned int i=0;i<n;i++){
        if (abs(oppositeCars_->cars_[i]->getX() - translationValue_) < 2.5
                && oppositeCars_->cars_[i]->getZ() > -1.5
                && oppositeCars_->cars_[i]->getZ() < 4.5)
        {
            warning();
            //QMessageBox::information(this,tr("GAME OVER"),tr("cnm"));
        }
    }
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{




    // Netoyer les buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // placer la camera
    gluLookAt(0,5,20,
              0,0,0,
              0,1,0);


    // luminance
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);

    GLfloat sun_light_position[] = {0.0f, 20.0f, 50.0f, 1.0f};
    GLfloat sun_light_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat sun_light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

    // Draw background
    glPushMatrix();
    glEnable(GL_LIGHTING);
    myGround_->Display();
    glPopMatrix();
    glDisable(GL_LIGHTING);


    // Draw cars
    glPushMatrix();
    glEnable(GL_LIGHTING);
    glTranslatef(0+translationValue_,0,0);
    maVoiture_->Display();
    glPopMatrix();

    glPushMatrix();

    oppositeCars_->Display();
    glPopMatrix();

    glDisable(GL_LIGHTING);

    glDisable(GL_DEPTH_TEST);
    QPainter painter(this);
    painter.beginNativePainting();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::white);
    painter.drawEllipse(QPointF(170.f,430.f), 40, 60);

    QRect hud=rect();
    hud.moveTop(4*hud.bottom()/5);

    painter.fillRect(hud,QColor(0,0,0,95));

    QFont font("times", width()/30);
    painter.setPen(Qt::red);
    painter.setFont(font);

    painter.drawText(width()/20,height()-height()/10, QString("Time[")+timeText_+QString(" s]"));
    painter.drawText(14*width()/20,height()-height()/10, QString("Record[ ")+QString::number((int)(record_))+QString(" ]"));
    painter.drawText(8*width()/20,height()-height()/10, QString("Oil [")+QString::number(maVoiture_->getOil())+QString("%o]"));
    painter.end();

    glEnable(GL_DEPTH_TEST);

}



// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
    {
        left_status_ = true;
        break;
    }

        case Qt::Key_Right:
    {
        right_status_ = true;
        break;
    }
    case Qt::Key_Space:
    {
//        if(timer_->isActive()){timer_->stop();}
//        else {timer_->start();}
        pause_ = !pause_;
        myGround_->changeState(pause_);
        oppositeCars_->changeState(pause_);

    }
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
    //update();
}
void MyGLWidget::keyReleaseEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
            right_status_ = false;
            break;
        case Qt::Key_Left:
            left_status_ = false;
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

void MyGLWidget::mousePressEvent(QMouseEvent * event)
{

    float x = event->x();
    float y = event->y();

    if (x > 150.f && x < 190.f && y > 400.f && y < 490.f){
        addOil_ = !addOil_;
        myGround_->addOil();
        maVoiture_->setOil(1000);
    }

    event->accept();
    update();
}

void MyGLWidget::updateMove(int move){
    switch (move) {
    // stop
    case 0:
        pause_ = true;
        myGround_->changeState(pause_);
        oppositeCars_->changeState(pause_);
        break;
    // move to left
    case 1:
        if (translationValue_ > -7.0f)
            translationValue_ -= 0.5f;
        break;
    // move to right
    case 2:
        if (translationValue_ < 7.0f)
            translationValue_ += 0.5f;
        break;
    case 3:
        pause_ = false;
        myGround_->changeState(pause_);
        oppositeCars_->changeState(pause_);
        break;
    default:
        return;
    }

}
