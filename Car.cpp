#include "Car.h"

Car::Car() : Entity(){
    color_=new Color(1.f,1.f,1.f);
    vel_=new Velocity();
    rot_=new Rotation();

    wheelQuadric_=gluNewQuadric();
    gluQuadricDrawStyle(wheelQuadric_, GLU_FILL);
}

Car::Car(float colorR, float colorG, float colorB){
    color_= new Color(colorR,colorG,colorB);
    vel_= new Velocity();
    rot_= new Rotation();

    wheelQuadric_=gluNewQuadric();
    gluQuadricDrawStyle(wheelQuadric_, GLU_FILL);
}

Car::~Car(){
    gluDeleteQuadric(wheelQuadric_);
    delete rot_;
    delete color_;
    delete vel_;
}

void Car::drawCar(){

    glBegin(GL_QUADS);

//    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(color_->red()/4.,color_->green()/4.,color_->blue()/4.).get());
    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(color_->red()/4.+0.05,color_->green()/4.+0.05,color_->blue()/4.+0.05).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(color_->red()/2.5,color_->green()/2.5,color_->blue()/2.5).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(color_->red()/1.291,color_->green()/1.291,color_->blue()/1.291,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(76.8f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());

    glColor3f(color_->red(),color_->green(),color_->blue());

    // Front face
    glNormal3f(0.f,0.f,-1.f);
    glVertex3f(-0.5f,0.2f,-1.f);
    glVertex3f(-0.5f,.6f,-1.f);
    glVertex3f(0.5f,.6f,-1.f);
    glVertex3f(0.5f,0.2f,-1.f);

    // Top face
    glNormal3f(0.f,0.89f,-0.45f);
    glVertex3f(-0.5f,1.1f,0.5f);
    glVertex3f(0.5f,1.1f,0.5f);
    glVertex3f(0.5f,.85f,-.25f);
    glVertex3f(-0.5f,.85f,-.25f);

    glNormal3f(0.f,0.89f,-0.45f);
    glVertex3f(-0.5f,.85f,-0.25f);
    glVertex3f(0.5f,.85f,-0.25f);
    glVertex3f(0.5f,.6f,-1.f);
    glVertex3f(-0.5f,.6f,-1.f);

    // Right face
    glNormal3f(-1.f,0.f,0.f);
    glVertex3f(0.5f,1.1f,0.5f);
    glVertex3f(0.5f,0.2f,0.5f);
    glVertex3f(0.5f,0.2f,-.25f);
    glVertex3f(0.5f,.85f,-.25f);

    glNormal3f(-1.f,0.f,0.f);
    glVertex3f(0.5f,.85f,-.25f);
    glVertex3f(0.5f,0.2f,-.25f);
    glVertex3f(0.5f,0.2f,-1.f);
    glVertex3f(0.5f,.6f,-1.f);

    //glColor3f(color_->red()/2.,color_->green()/2.,color_->blue()/2.);

    // Back face
    glNormal3f(0.f,0.f,1.f);
    glVertex3f(-0.5f,0.2f,0.5f);
    glVertex3f(0.5f,0.2f,0.5f);
    glVertex3f(0.5f,1.1f,0.5f);
    glVertex3f(-0.5f,1.1f,0.5f);

    // Bottom face
    glNormal3f(0.f,-1.f,0.f);
    glVertex3f(-0.5f,0.2f,0.5f);
    glVertex3f(-0.5f,0.2f,-1.f);
    glVertex3f(0.5f,0.2f,-1.f);
    glVertex3f(0.5f,0.2f,0.5f);

    // Left face
    glNormal3f(1.f,0.f,0.f);
    glVertex3f(-0.5f,0.2f,0.5f);
    glVertex3f(-0.5f,1.1f,0.5f);
    glVertex3f(-0.5f,.85f,-.25f);
    glVertex3f(-0.5f,0.2f,-.25f);

    glNormal3f(1.f,0.f,0.f);
    glVertex3f(-0.5f,0.2f,-.25f);
    glVertex3f(-0.5f,.85f,-.25f);
    glVertex3f(-0.5f,.6f,-1.f);
    glVertex3f(-0.5f,0.2f,-1.f);

    glEnd();

    // Sphere
    /*
    glPushMatrix();

    glTranslatef(0.f,1.25f,0.5);
    gluSphere(wheelQuadric_,0.25,24,24);

    glPopMatrix();
    */

    // Phares

    glBegin(GL_QUADS);

    // Back
    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty().get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty().get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.9f,.9f,.9f).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(30.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(1.f,0.f,0.f).get());

    glNormal3f(0.f,0.f,1.f);

    glVertex3f(-0.45f,0.3f,0.55f);
    glVertex3f(-0.1f,0.3f,0.55f);
    glVertex3f(-0.1f,0.5f,0.55f);
    glVertex3f(-0.45f,0.6f,0.55f);

    glVertex3f(0.1f,0.3f,0.55f);
    glVertex3f(0.45f,0.3f,0.55f);
    glVertex3f(0.45f,0.6f,0.55f);
    glVertex3f(0.1f,0.5f,0.55f);

    // Front
    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty().get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty().get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.9f,.9f,.9f).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(30.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(.9f,.9f,.6f).get());

    glNormal3f(0.f,0.f,-1.f);

    glVertex3f(-0.45f,0.25f,-1.05f);
    glVertex3f(-0.45f,.55f,-1.05f);
    glVertex3f(-0.1f,.55f,-1.05f);
    glVertex3f(-0.1f,0.25f,-1.05f);

    glVertex3f(0.1f,0.25f,-1.05f);
    glVertex3f(0.1f,.55f,-1.05f);
    glVertex3f(0.45f,.55f,-1.05f);
    glVertex3f(0.45f,0.25f,-1.05f);

    glEnd();

    // Wheels

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(.02f,.02f,.02f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(.01f,.01f,.01f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.5f,.5f,.5f).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(10.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());

    //Front right wheel
    glPushMatrix();
    glTranslatef(.5f,.25f,-0.75);
    drawWheel();
    glPopMatrix();

    //Back right wheel
    glPushMatrix();
    glTranslatef(.5f,.25f,0.2);
    drawWheel();
    glPopMatrix();

    //Front left wheel
    glPushMatrix();
    glTranslatef(-0.75f,.25f,-0.75);
    drawWheel();
    glPopMatrix();

    //Back left wheel
    glPushMatrix();
    glTranslatef(-0.75f,.25f,0.2);
    drawWheel();
    glPopMatrix();

}

void Car::drawWheel(){

    glPushMatrix();
    glRotatef(90,0,1,0);

    glColor3f(.5f,.5f,.5f);
    gluCylinder(wheelQuadric_,.25,.25,.25,12,1);

    glColor3f(.25f,.25f,.25f);
    gluDisk(wheelQuadric_,0.,.25,12,1);

    glColor3f(.5f,.5f,.5f);
    glTranslatef(0.f,0.f,0.25f);
    gluDisk(wheelQuadric_,0.,.25,12,1);

    glPopMatrix();
}

Position Car::getPosition()
{
    return(*pos_);
}

BoxHitBox Car::hitbox(){

    Position minPos=Position(pos_->x()-0.5f,pos_->y(),pos_->z()-1.f);
    Position maxPos=Position(pos_->x()+0.5f,1.1f+pos_->y(),pos_->z()+1.f);
    return(BoxHitBox(minPos, maxPos));
}

// Player

Player::Player() : Car()
{
    beaconTimer_=60;
}

Player::~Player()
{
}

void Player::updatePos(){
    if (pos_->x()+vel_->vX()<=3.5f && pos_->x()+vel_->vX()>=-3.5f){
        pos_->setX(pos_->x()+vel_->vX());
    }
}

void Player::left(){
    vel_->setVX((vel_->vX()-.1f)/2.f);
    rot_->setRotY((rot_->rotY()-10.f)/2.f+10.f);
}
void Player::right(){
    vel_->setVX((vel_->vX()+.1f)/2.f);
    rot_->setRotY((rot_->rotY()+10.f)/2.f-10.f);

}

void Player::draw(){
    updatePos();

    glPushMatrix();

    glTranslatef(pos_->x(),pos_->y(),pos_->z());
    glRotatef(rot_->rotY(),0.f,1.f,0.f);
    vel_->setVX(3.f*vel_->vX()/4.f);
    rot_->setRotY(2.f*rot_->rotY()/3.f);

    // Phares
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,MaterialProperty(0.f,-0.1f,-1.f).get());
    glLightfv(GL_LIGHT1,GL_SPOT_CUTOFF,MaterialProperty(30.f).getFirst());
    glLightfv(GL_LIGHT1,GL_AMBIENT,MaterialProperty(.6f,.6f,.4f).get());
    glLightfv(GL_LIGHT1,GL_DIFFUSE,MaterialProperty(.6f,.6f,.4f).get());
    glLightfv(GL_LIGHT1,GL_SPECULAR,MaterialProperty(.6f,.6f,.4f).get());
    glLightfv(GL_LIGHT1,GL_POSITION,MaterialProperty(0.f,.3f,-1.f).get());

    drawCar();

    beacon();

    glPopMatrix();
}

void Player::beacon(){
    // Girophare

    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(0.05f,.05f,.05f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(0.05f,0.05f,0.05f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.5f,.5f,.5f,1.).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(30.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());

    glBegin(GL_QUADS);

    // Top
    glNormal3f(0.f,1.,0.f);
    glVertex3f(-0.2f,1.f,0.05f);
    glVertex3f(0.2f,1.f,0.05f);
    glVertex3f(0.2f,1.f,-0.05f);
    glVertex3f(-0.2f,1.f,-0.05f);

    // Back
    glNormal3f(0.f,0.,1.f);
    glVertex3f(-0.2f,0.6,0.05f);
    glVertex3f(0.2f,0.6f,0.05f);
    glVertex3f(0.2f,1.f,0.05f);
    glVertex3f(-0.2f,1.f,0.05f);

    // Face unnecessary

    glEnd();


    glMaterialfv(GL_FRONT,GL_AMBIENT,MaterialProperty(0.15f,.15f,.15f,.5f).get());
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MaterialProperty(0.05f,0.05f,0.05f,.5f).get());
    glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialProperty(.5f,.5f,.5f,1.f).get());
    glMaterialfv(GL_FRONT,GL_SHININESS,MaterialProperty(30.f).getFirst());
    glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty().get());
    glColor4f(0.15f,.15f,.15f,.5f);

    glDepthMask(GL_FALSE);
    glBegin(GL_QUADS);


    //Left red
    if(beaconTimer_>29){
        glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(1.f,0.f,0.f,0.f).get());
    }
    else{
        glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(0.f,0.f,0.f,0.f).get());
    }
    // Top
    glNormal3f(0.f,1.,0.f);
    glVertex3f(-0.35f,1.f,0.05f);
    glVertex3f(-0.2f,1.f,0.05f);
    glVertex3f(-0.2f,1.f,-0.05f);
    glVertex3f(-0.35f,1.f,-0.05f);

    // Back
    glNormal3f(0.f,0.,1.f);
    glVertex3f(-0.35f,0.6,0.05f);
    glVertex3f(-0.2f,0.6f,0.05f);
    glVertex3f(-0.2f,1.f,0.05f);
    glVertex3f(-0.35f,1.f,0.05f);

    // Left
    glNormal3f(1.f,0.f,0.f);
    glVertex3f(-0.35f,0.6f,0.05f);
    glVertex3f(-0.35f,1.f,0.05f);
    glVertex3f(-0.35f,1.f,-0.05f);
    glVertex3f(-0.35f,0.6f,-0.05f);

    //Right blue


    if(beaconTimer_<29){
        glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(0.f,0.f,1.f,0.f).get());
    }
    else{
        glMaterialfv(GL_FRONT,GL_EMISSION,MaterialProperty(0.f,0.f,0.f,0.f).get());
    }


    // Top
    glNormal3f(0.f,1.,0.f);
    glVertex3f(0.2f,1.f,0.05f);
    glVertex3f(0.35f,1.f,0.05f);
    glVertex3f(0.35f,1.f,-0.05f);
    glVertex3f(0.2f,1.f,-0.05f);

    // Back
    glNormal3f(0.f,0.,1.f);
    glVertex3f(.2f,0.6,0.05f);
    glVertex3f(.35f,0.6f,0.05f);
    glVertex3f(.35f,1.f,0.05f);
    glVertex3f(.2f,1.f,0.05f);

    // Right
    glNormal3f(-1.f,0.f,0.f);
    glVertex3f(0.35f,1.f,0.05f);
    glVertex3f(0.35f,0.6f,0.05f);
    glVertex3f(0.35f,0.6f,-0.05f);
    glVertex3f(0.35f,1.f,-0.05f);

    glEnd();
    glDepthMask(GL_TRUE);

    if(beaconTimer_>29){
        glLightfv(GL_LIGHT2,GL_AMBIENT,MaterialProperty(0.f,0.f,0.f).get());
        glLightfv(GL_LIGHT2,GL_DIFFUSE,MaterialProperty(1.f,0.f,0.f).get());
        glLightfv(GL_LIGHT2,GL_SPECULAR,MaterialProperty(1.f,0.f,0.).get());
        glLightfv(GL_LIGHT2,GL_POSITION,MaterialProperty(-0.3f,1.f,0.f).get());
    }
    else{
        glLightfv(GL_LIGHT2,GL_AMBIENT,MaterialProperty(.0f,.0f,0.f).get());
        glLightfv(GL_LIGHT2,GL_DIFFUSE,MaterialProperty(.0f,.0f,1.f).get());
        glLightfv(GL_LIGHT2,GL_SPECULAR,MaterialProperty(.0f,.0f,1.f).get());
        glLightfv(GL_LIGHT2,GL_POSITION,MaterialProperty(0.3f,1.f,0.f).get());

    }

    if(beaconTimer_<=0){
        beaconTimer_=60;
    }
    else {
        beaconTimer_=beaconTimer_-1;
    };
}

// OpposingCar

OpposingCar::OpposingCar(float* speed) : Car(rand()/(float)RAND_MAX,rand()/(float)RAND_MAX,rand()/(float)RAND_MAX)
{
    speed_=speed;

    pos_->setPosition(7.f*rand()/(float)RAND_MAX-3.5f,0.f,-250.f);
    rot_->setRotY(180.f);
    //
    vel_->setVZ(.5f*rand()/(float)RAND_MAX+.5f);
}

OpposingCar::~OpposingCar()
{

}

void OpposingCar::updatePos(){
    pos_->setZ(pos_->z()+vel_->vZ()+*speed_);
}

void OpposingCar::draw(){
    updatePos();

    glPushMatrix();

    glTranslatef(pos_->x(),pos_->y(),*speed_+pos_->z());
    glRotatef(rot_->rotY(),0.f,1.f,0.f);

    drawCar();

    glPopMatrix();

}

// CarVector

OppCarVector::OppCarVector() {
    cars_=std::vector<OpposingCar*>();
}

OppCarVector::OppCarVector(OpposingCar* car){
    cars_=std::vector<OpposingCar*>();
    cars_.push_back(car);
}

OppCarVector::~OppCarVector(){
    unsigned int n=cars_.size();
    for(unsigned int i=0;i<n;i++){
        delete cars_[i];
    }
}

int OppCarVector::clearOutOfBounds(){
    int acc=0;
    for (unsigned int i=0;i<cars_.size();i++)
    {
        if (cars_[i]->getPosition().z()>5){
            acc+=1;
            erase(i);
        }
    }
    return(acc);
};
void OppCarVector::draw(){
    unsigned int n=cars_.size();
    for(unsigned int i=0;i<n;i++){
        cars_[i]->draw();
    }
}
void OppCarVector::erase(unsigned int i){
    delete cars_[i];
    cars_.erase(cars_.begin()+i);
}
