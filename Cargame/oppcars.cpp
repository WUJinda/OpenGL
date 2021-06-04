#include "oppcars.h"

OppCars::OppCars()
{
    quadrique_ = gluNewQuadric();

    posX_ = 12.0f * rand()/(float)RAND_MAX - 6.0f;
}

OppCars::~OppCars()
{
    gluDeleteQuadric(quadrique_);
}

void OppCars::updateZ()
{
    posZ_ += length_/40;
}

void OppCars::changeState(bool b)
{
    pause_ =  b;
}

float OppCars::getZ()
{
    return posZ_;
}
float OppCars::getX()
{
    return posX_;
}


void OppCars::Display()
{
    if (!pause_)
        updateZ();

    GLfloat oppcar_ambient[]   = {0.f, 0.f, 0.f, 1.0f};
    GLfloat oppcar_diffuse[]   = {0.f, 0.f, 0.f, 1.0f};
    GLfloat oppcar_specular[] = {0.f, 0.f, 0.f, 1.0f};
    GLfloat oppcar_emission[] = {0.6f, 0.f, 0.f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, oppcar_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, oppcar_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, oppcar_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, oppcar_emission);

    glBegin(GL_QUADS);

    glVertex3f(posX_ - 1, posY_ - 1, posZ_ - 1.5f);
    glVertex3f(posX_ + 1, posY_ - 1, posZ_ - 1.5f);
    glVertex3f(posX_ + 1, posY_ + 1, posZ_ - 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ - 1.5f);

    glVertex3f(posX_ - 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ + 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ + 1, posY_ + 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ + 1.5f);

    glVertex3f(posX_ - 1, posY_ - 1, posZ_ - 1.5f);
    glVertex3f(posX_ - 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ - 1.5f);

    glVertex3f(posX_ + 1, posY_ - 1, posZ_ - 1.5f);
    glVertex3f(posX_ + 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ + 1, posY_ + 1, posZ_ + 1.5f);
    glVertex3f(posX_ + 1, posY_ + 1, posZ_ - 1.5f);

    glVertex3f(posX_ + 1, posY_ - 1, posZ_ - 1.5f);
    glVertex3f(posX_ + 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ - 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ - 1, posZ_ - 1.5f);

    glVertex3f(posX_ + 1, posY_ + 1, posZ_ - 1.5f);
    glVertex3f(posX_ + 1, posY_ + 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ + 1.5f);
    glVertex3f(posX_ - 1, posY_ + 1, posZ_ - 1.5f);

    glEnd();

    GLfloat wheel_ambient[]   = {0.f, 0.f, 0.f, 1.0f};
    GLfloat wheel_diffuse[]   = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat wheel_specular[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat wheel_emission[] = {0.f, 0.f, 0.f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, wheel_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wheel_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wheel_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, wheel_emission);

    glPushMatrix();
    glTranslatef(posX_ - 1, posY_ - 1, posZ_ + 1.f);
    glRotatef(-90,0,1,0);
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posX_ - 1, posY_ - 1, posZ_ - 1.f);
    glRotatef(-90,0,1,0);
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posX_, posY_, posZ_);
    glTranslatef(1,-1,1);
    glRotatef(90,0,1,0);
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posX_, posY_, posZ_);
    glTranslatef(1,-1,-1);
    glRotatef(90,0,1,0);
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    glPopMatrix();
}


// CarVector

OppCarVector::OppCarVector() {
    cars_=std::vector<OppCars*>();
}

OppCarVector::OppCarVector(OppCars* car){
    cars_=std::vector<OppCars*>();
    cars_.push_back(car);
}

OppCarVector::~OppCarVector(){
    unsigned int n=cars_.size();
    for(unsigned int i=0;i<n;i++){
        delete cars_[i];
    }
}
void OppCarVector::changeState(bool b)
{
    unsigned int n=cars_.size();
    for(unsigned int i=0;i<n;i++){
        cars_[i]->changeState(b);
    }

}


void OppCarVector::moveOut(){
    int count=0;
    for (unsigned int i=0;i<cars_.size();i++)
    {
        if (cars_[i]->getZ()>48.5f){
            count+=1;
            erase(i);
        }
    }
    //return count;
};
void OppCarVector::Display(){
    unsigned int n=cars_.size();
    for(unsigned int i=0;i<n;i++){
        cars_[i]->Display();
    }
}
void OppCarVector::erase(unsigned int i){
    delete cars_[i];
    cars_.erase(cars_.begin()+i);
}
