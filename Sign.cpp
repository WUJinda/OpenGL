#include "Sign.h"

Sign::Sign(float* speed):Entity()
{
    speed_=speed;
    pos_->setPosition(5.5f,0.f,-360.f);

    signQuadric_=gluNewQuadric();
    gluQuadricDrawStyle(signQuadric_, GLU_FILL);
}

Sign::~Sign()
{
    gluDeleteQuadric(signQuadric_);
}

void Sign::draw()
{
    glPushMatrix();
    glTranslatef(pos_->x(),pos_->y(),pos_->z());
    pos_->setZ(pos_->z()+*speed_);
    if (pos_->z()>10.f) pos_->setZ(-350.f);

    glPushMatrix();
    glTranslatef(0.f,1.75f,0.f);

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(0.f,0.f,.3f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(0.f,0.f,.5f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.8,.8,.8,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(30.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());
    glColor3f(0.f,0.f,1.f);
    gluDisk(signQuadric_,0.,.5,12,4);
    glPopMatrix();

    glRotatef(90,-1.f,0.f,0.f);


    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.7f,.7f,.7f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.7f,.7f,.7f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.8,.8,.8,1.).get());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());
    glColor3f(.7f,.7f,.7f);
    gluCylinder(signQuadric_,.1,.1,1.25,6,4);

    glPopMatrix();
}
