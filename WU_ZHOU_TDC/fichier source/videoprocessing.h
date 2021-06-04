#ifndef VIDEOPROCESSING_H
#define VIDEOPROCESSING_H

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/objdetect.hpp>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <QDebug>

using namespace cv;
using namespace std;
/*
 * Ce class est destiné au traitement des flux vidéo,
 * à l'analyse des images et à l'identification des poings.
*/
class VideoProcessing // auteurs : WU & ZHOU
{
public:
    VideoProcessing();// Constructeur
    VideoProcessing(int frameWidth, int frameHeight);// Constructeur avec parametres
    ~VideoProcessing();// Destructeur
    int process();//La méthode de traitement du flux vidéo.
    void AnalyseRectangle(std::vector<cv::Rect> listRect,bool choix);//La méthode d'analyse des gestes.
    void findLeftRight(std::vector<cv::Rect> listRect);//La méthode de détermination la main droite et de la main gauche.

protected:
       void run();

private:
    int frameWidth_=640;
    int frameHeight_=480;
    int direction_=0 ; // 0 : arrêt, 1: gauche, 2: droite

    VideoCapture cap_;
    CascadeClassifier fist_cascade_;
    int index_rect_gauche_,index_rect_droit_;
};

#endif // VIDEOPROCESSING_H
