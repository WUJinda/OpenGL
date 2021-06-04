#include <QApplication>
#include "myglwidget.h"
#include "videoprocessing.h"

int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));
    int frameWidth=640;
    int frameHeight=480;
    // Creation de l'application QT
    QApplication app(argc, argv);
	
	// Creation du widget opengl
    MyGLWidget * glWidget = new MyGLWidget;
    VideoProcessing* videoProc = new VideoProcessing(frameWidth, frameHeight);
    glWidget->setWindowTitle("CarGame");
    glWidget->show();


    while(cv::waitKey(5) != 27)
    {
        if(cv::waitKey(5) == 27){

            app.quit();
            //glWidget->destroyed();
            break;
        }
        int m=videoProc->process();
        glWidget->updateMove(m);
        //app.connect(glWidget, SIGNAL(endGame()), &app, SLOT(quit()));

    }
    app.connect(glWidget, SIGNAL(endGame()), &app, SLOT(quit()));

    // Execution de l'application QT
    return app.exec();
}
