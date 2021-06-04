#include "Car.h"


Car::Car()
{
    oil_ = 1000;
}

Car::~Car()
{
}

void Car::reinitial()
{
    oil_ = 1000;
}

void Car::consumeOil()
{
    oil_ -= 5;
}

void Car::Display()
{
    // Dessiner le voiture
    glBegin(GL_QUADS);

    GLfloat car_ambient[]  = {0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat car_diffuse[]  = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat car_specular[] = {0.774597f, 0.774597f, 0.774597f, 1.0f};
    GLfloat car_emission[] = {0.f, 0.f, 0.f, 1.0f};
    float car_shininess = 76.8f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, car_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, car_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, car_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, car_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, car_shininess);

    glColor3ub(100,0,0);
    glVertex3f(-1,-1,0);
    glVertex3f(1,-1,0);
    glVertex3f(1,1,0);
    glVertex3f(-1,1,0);

    glVertex3f(-1,-1,3);
    glVertex3f(1,-1,3);
    glVertex3f(1,1,3);
    glVertex3f(-1,1,3);

    glVertex3f(-1,-1,0);
    glVertex3f(-1,-1,3);
    glVertex3f(-1,1,3);
    glVertex3f(-1,1,0);

    glVertex3f(1,-1,0);
    glVertex3f(1,-1,3);
    glVertex3f(1,1,3);
    glVertex3f(1,1,0);

    glVertex3f(1,-1,0);
    glVertex3f(1,-1,3);
    glVertex3f(-1,-1,3);
    glVertex3f(-1,-1,0);

    glVertex3f(1,1,0);
    glVertex3f(1,1,3);
    glVertex3f(-1,1,3);
    glVertex3f(-1,1,0);

    glEnd();   

    // Dessiner les cylindres
    GLfloat wheel_ambient[]   = {0.f, 0.f, 0.f, 1.0f};
    GLfloat wheel_diffuse[]   = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat wheel_specular[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat wheel_emission[] = {0.f, 0.f, 0.f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, wheel_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wheel_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wheel_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, wheel_emission);

    glColor3ub(0,0,0);
    glPushMatrix();
    glTranslatef(-1,-1,2.5);
    glRotatef(-90,0,1,0);
    quadrique_ = gluNewQuadric();
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-1,0.5);
    glRotatef(-90,0,1,0);
    quadrique_ = gluNewQuadric();
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,-1,2.5);
    glRotatef(90,0,1,0);
    quadrique_ = gluNewQuadric();
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,-1,0.5);
    glRotatef(90,0,1,0);
    quadrique_ = gluNewQuadric();
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.25,.25,.25,12,1);
    gluDisk(quadrique_,0,.25,12,1);
    glTranslatef(0,0,0.25);
    gluDisk(quadrique_,0,.25,12,1);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();

    //Beacon
    beaconTimer_ = QTime::currentTime();
    int now = beaconTimer_.second();
    if (now%2 == 0){
        GLfloat beacon_ambient[]   = {0.f, 0.f, 0.f, 1.0f};
        GLfloat beacon_diffuse[]   = {0.f, 0.f, 0.f, 1.0f};
        GLfloat beacon_specular[] = {0.f, 0.f, 0.f, 1.0f};
        GLfloat beacon_emission[] = {1.f, 0.f, 1.f, 1.0f};

        glMaterialfv(GL_FRONT, GL_AMBIENT, beacon_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, beacon_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, beacon_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, beacon_emission);

        GLfloat beacon_light_position[] = {0.0f, 1.2f, 1.5f, 1.0f};
        GLfloat beacon_light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat beacon_light_diffuse[] = {1.0f, 0.0f, 1.0f, 1.0f};
        GLfloat beacon_light_specular[] = {1.0f, 0.0f, 1.0f, 1.0f};
        GLfloat beacon_light_direction[] = {0,-1,0};

        glLightfv(GL_LIGHT1, GL_POSITION, beacon_light_position);
        glLightfv(GL_LIGHT1, GL_AMBIENT, beacon_light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, beacon_light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, beacon_light_specular);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, beacon_light_direction);
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,60);

    } else {
        GLfloat beacon_ambient[]   = {1.f, 1.f, 1.f, 1.0f};
        GLfloat beacon_diffuse[]   = {0.f, 0.f, 0.f, 1.0f};
        GLfloat beacon_specular[] = {0.f, 0.f, 0.f, 1.0f};
        GLfloat beacon_emission[] = {0.f, 0.f, 0.f, 1.0f};

        glMaterialfv(GL_FRONT, GL_AMBIENT, beacon_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, beacon_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, beacon_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, beacon_emission);

        GLfloat beacon_light_position[] = {0.0f, 1.2f, 1.5f, 1.0f};
        GLfloat beacon_light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat beacon_light_diffuse[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat beacon_light_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};

        glLightfv(GL_LIGHT1, GL_POSITION, beacon_light_position);
        glLightfv(GL_LIGHT1, GL_AMBIENT, beacon_light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, beacon_light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, beacon_light_specular);
    }


    glPushMatrix();
    glTranslatef(0,1,1.5);
    glRotatef(-90,1,0,0);
    quadrique_ = gluNewQuadric();
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.2,.2,.2,12,1);
    glTranslatef(0,0,0.2);
    gluDisk(quadrique_,0,.2,12,1);
    gluDeleteQuadric(quadrique_);
    glPopMatrix();

}
