#include "plane.h"

Plane::Plane(float* speed):Entity()
{
    //direction_=-1;
    direction_=(2*rand()/(RAND_MAX+1))*2-1;
    speed_=speed;
    //pos_=new Position(5.,3.,-10.f);
    vel_=new Velocity();
    vel_->setVZ(rand()/(float)RAND_MAX+1.5f);
    pos_->setPosition(100.f*rand()/(float)RAND_MAX-50.f,20.f*rand()/(float)RAND_MAX+4.f,-710.f);
    if(direction_<0)(pos_->setZ(10.f));

    standAlone_=true;
    planeQuadric_=gluNewQuadric();
    gluQuadricDrawStyle(planeQuadric_, GLU_FILL);
}

Plane::Plane(float* speed, GLUquadric* planeQuadric)
{
    //direction_=-1;
    direction_=(2*rand()/(RAND_MAX+1))*2-1;
    speed_=speed;
    //pos_=new Position(5.,3.,-10.f);
    vel_=new Velocity();
    vel_->setVZ(rand()/(float)RAND_MAX+1.5f);
    pos_=new Position(100.f*rand()/(float)RAND_MAX-50.f,20.f*rand()/(float)RAND_MAX+4.f,-710.f);
    if(direction_<0)(pos_->setZ(10.f));

    standAlone_=false;
    planeQuadric_=planeQuadric;
}

Plane::~Plane()
{
    delete vel_;
    if(standAlone_) gluDeleteQuadric(planeQuadric_);
}

void Plane::draw()
{
    glPushMatrix();
    glTranslatef(pos_->x(),pos_->y(),pos_->z());
    if(direction_>0){glRotatef(180,0.f,1.f,0.f);}
    glRotatef(10.f,1.f,0.f,0.f);
    pos_->setZ(pos_->z()+*speed_+vel_->vZ()*(float)direction_);
    //if (pos_->z()>10.f) pos_->setZ(-350.f);
    //if (pos_->z()<-350.f) pos_->setZ(10.f);

    //glPushMatrix();
    //glTranslatef(0.f,1.75f,0.f);

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(0.5f+0.05f,0.05f+0.05f,0.05f+0.05f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.8f,.4f,.4f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(0.774597f,0.774597f,0.774597f,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(76.8f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());
    glColor3f(0.f,0.f,1.f);

    gluCylinder(planeQuadric_,1.f,.6f,5.f,12,8);

    glPushMatrix();
    glTranslatef(0.f,0.f,5.f);
    gluCylinder(planeQuadric_,.6f,0.f,1.5f,12,2);

    glBegin(GL_QUADS);
    glNormal3f(1.f,0.f,0.f);
    glVertex3f(0.f,1.f,0.f);
    glVertex3f(0.f,1.f,1.5f);
    glVertex3f(0.f,0.f,1.f);
    glVertex3f(0.f,0.f,-.5f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f,0.f,-.3f);
    gluCylinder(planeQuadric_,.7f,1.f,.5f,12,4);
    glRotatef(180,0.f,1.f,0.f);
    gluDisk(planeQuadric_,0.,.7,12,4);
    glPopMatrix();

    // Upper wing

    glPushMatrix();
    glTranslatef(0.f,.55f,2.f);
    glRotatef(5.,1.f,0.f,0.f);
    glBegin(GL_QUADS);

    glNormal3f(0.f,-1.f,0.f);
    glVertex3f(-4.5f,0.f,-1.f);
    glVertex3f(-4.5f,0.f,1.f);
    glVertex3f(4.5f,0.f,1.f);
    glVertex3f(4.5f,0.f,-1.f);

    glEnd();
    glPopMatrix();

    // Lower wing

    glPushMatrix();
    glTranslatef(0.f,-.2f,2.f);
    glRotatef(5.,1.f,0.f,0.f);
    glBegin(GL_QUADS);

    glNormal3f(0.f,-1.f,0.f);
    glVertex3f(-4.f,0.f,-1.f);
    glVertex3f(-4.f,0.f,1.f);
    glVertex3f(4.f,0.f,1.f);
    glVertex3f(4.f,0.f,-1.f);

    glEnd();
    glPopMatrix();

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.05f,.05f,.05f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.05f,.05f,.05f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(0.774597f,0.774597f,0.774597f,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(76.8f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());

    gluSphere(planeQuadric_,.5,12,12);

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.05f,.05f,.05f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.05f,.05f,.05f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(0.774597f,0.774597f,0.774597f,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(76.8f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());

    glPushMatrix();
    glTranslatef(0.f,.7f,1.5f);
    glRotatef(5.,1.f,0.f,0.f);
    glScalef(1.f,.7f,1.4f);

    gluSphere(planeQuadric_,.7,12,12);
    glPopMatrix();


    // Cockpit


    //glPopMatrix();

    /*
    glRotatef(90,-1.f,0.f,0.f);


    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.7f,.7f,.7f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.7f,.7f,.7f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.8,.8,.8,1.).get());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());
    glColor3f(.7f,.7f,.7f);
    gluCylinder(planeQuadric_,.1,.1,1.25,3,1);
    */
    glPopMatrix();
}

float Plane::posZ(){
    return(pos_->z());
}

// PlaneHolder

PlaneHolder::PlaneHolder(float* speed){
    speed_=speed;

    planeQuadric_=gluNewQuadric();
    gluQuadricDrawStyle(planeQuadric_, GLU_FILL);

    delete plane_;
}

PlaneHolder::~PlaneHolder(){
    gluDeleteQuadric(planeQuadric_);
    delete plane_;
}

void PlaneHolder::draw(){
    if (plane_==nullptr){
        if(rand()/(float)RAND_MAX<.002f){
            plane_=new Plane(speed_,planeQuadric_);
        }
    }
    else{
        if(plane_->posZ()>10 || plane_->posZ()<-710){
            delete plane_;
            plane_=nullptr;
        }
        else{
            plane_->draw();
        }
    }
}
