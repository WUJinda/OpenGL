#include <qopengl.h>
#include <GL/glu.h>

#include <QImage>

// Classe dediee pour la gestion du sol
class Ground
{
public:
    Ground(float* speed);
    ~Ground();
    void draw();

private:
    void light();
    GLUquadric* sunQuadric_;
    float* speed_=nullptr;
    QImage qim_TextureGrass_;
    QImage qim_TextureRoad_;
    QImage qim_TextureSky_;
    GLuint* m_TextureID_=nullptr;
    float shift_=0;
};
