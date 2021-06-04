#include <QApplication>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));
    // Creation de l'application QT
    QApplication app(argc, argv);
	
	// Creation du widget opengl
    MyGLWidget * glWidget = new MyGLWidget;
    glWidget->setWindowTitle("CarGame");
    glWidget->show();
    app.connect(glWidget, SIGNAL(endGame()), &app, SLOT(quit()));

    // Execution de l'application QT
    return app.exec();
}
