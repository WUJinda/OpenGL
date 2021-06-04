#include "Ground.h"
#include <QGLWidget>


Ground::Ground()
{
    textures_=new GLuint[4];
    glGenTextures(4, textures_);
    texture_road_ = QGLWidget::convertToGLFormat(QImage(":/road.jpg"));
    texture_grass_ = QGLWidget::convertToGLFormat(QImage(":/grass.jpg"));
    texture_sky_ = QGLWidget::convertToGLFormat(QImage(":/sky.jpg"));
    texture_fuel_ = QGLWidget::convertToGLFormat(QImage(":/fuel.jpg"));

    glBindTexture(GL_TEXTURE_2D, textures_[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,texture_road_.width(),texture_road_.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture_road_.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D, textures_[1]);
    glTexImage2D(GL_TEXTURE_2D,0,4,texture_grass_.width(),texture_grass_.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture_grass_.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D, textures_[2]);
    glTexImage2D(GL_TEXTURE_2D,0,4,texture_sky_.width(),texture_sky_.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture_sky_.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures_[3]);
    glTexImage2D(GL_TEXTURE_2D,0,4,texture_fuel_.width(),texture_fuel_.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texture_fuel_.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

Ground::~Ground()
{
    delete textures_;
    gluDeleteQuadric(quadrique_);
}

void Ground::resetPos()
{
    pos_ = 0.0f;
}

void Ground::move()
{
    pos_ += 0.1f;
    fuel_pos_ += 1.2f;
}

void Ground::changeState(bool pause)
{
    pause_ = pause;
}

void Ground::addOil()
{
    addOil_ = true;
}

void Ground::reinitial()
{
    fuel_pos_ = -198.5f;
    pos_ = 0.0f;
    pause_ = false;
    addOil_ = false;
}


void Ground::Display()
{

    if (!pause_)
        move();

    GLfloat ground_ambient[] = {0.75f, 0.75f, 0.75f, 1.0f};
    GLfloat ground_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    float ground_shininess = 76.8f;


    glMaterialfv(GL_FRONT, GL_AMBIENT, ground_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ground_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, ground_shininess);
    //road
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textures_[0]);

    glBegin(GL_QUADS);

    glColor3ub(40,40,40);
    glTexCoord2f(0.f,pos_); glVertex3f(-10,-1.25,50);
    glTexCoord2f(1.f,pos_); glVertex3f(10,-1.25,50);
    glTexCoord2f(1.f,20.f+pos_); glVertex3f(10,-1.25,-200);
    glTexCoord2f(0.f,20.f+pos_); glVertex3f(-10,-1.25,-200);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    //grass
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textures_[1]);

    glBegin(GL_QUADS);

    glColor3ub(0,100,0);
    glTexCoord2f(0,0); glVertex3f(-500,-2,50);
    glTexCoord2f(20,0); glVertex3f(500,-2,50);
    glTexCoord2f(20,6); glVertex3f(500,-2,-230);
    glTexCoord2f(0,6); glVertex3f(-500,-2,-230);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    //sky
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textures_[2]);

    glBegin(GL_QUADS);

    glColor3ub(120,180,200);
    glTexCoord2f(0,0); glVertex3f(-500,-1,-200);
    glTexCoord2f(5,0); glVertex3f(500,-1,-200);
    glTexCoord2f(5,1); glVertex3f(500,200,-200);
    glTexCoord2f(0,1); glVertex3f(-500,200,-200);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    //fuel
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textures_[3]);


    glColor3ub(230,0,0);
    glPushMatrix();
    glTranslatef(-9,-1.25,fuel_pos_);
    glRotatef(-90,1,0,0);
    quadrique_ = gluNewQuadric();
    gluQuadricTexture(quadrique_, GL_TRUE);
    gluQuadricDrawStyle(quadrique_,GLU_FILL);
    gluCylinder(quadrique_,.5,.5,2,12,1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glTranslatef(-9,.75,fuel_pos_);
    glRotatef(-90,1,0,0);

    GLfloat pile_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat pile_diffuse[] = {0.f, 0.f, 0.f, 1.0f};
    GLfloat pile_specular[] = {0.f, 0.f, 0.f, 1.0f};
    GLfloat pile_emission1[] = {0.0f, 1.0f, 0.0f, 1.0f};
    GLfloat pile_emission2[] = {1.0f, 0.0f, 0.0f, 1.0f};


    glMaterialfv(GL_FRONT, GL_AMBIENT, pile_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pile_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, pile_specular);
    if (!addOil_)
        glMaterialfv(GL_FRONT, GL_EMISSION, pile_emission1);
    else
        glMaterialfv(GL_FRONT, GL_EMISSION, pile_emission2);

    gluDisk(quadrique_,0,.5,12,1);

    if (pos_ > 0.99f)
        resetPos();
    if (fuel_pos_ > 8.0f)
        {
        fuel_pos_ = -198.5f;
        addOil_ = false;
        }
}
