#include "videoprocessing.h"

using namespace cv;
using namespace std;
VideoProcessing::VideoProcessing(){}
VideoProcessing::VideoProcessing(int frameWidth, int frameHeight)
{


    cap_.open(0); // open the default camera
    cap_.set(CAP_PROP_FRAME_WIDTH,frameWidth);
    cap_.set(CAP_PROP_FRAME_HEIGHT,frameHeight);
    if(!cap_.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;

    }
    // tcheck if cascade classifier ok
    if( !fist_cascade_.load( "../StarterTD2/res/fist3.xml" ) )
    {
        std::cerr<<"Error loading haarcascade"<<std::endl;

    }

}
int VideoProcessing::process(){

    // Init output window
    namedWindow("WebCam",1);

    Mat frame,frame_gray;
    std::vector<Rect> fists;
    //std::vector<Rect> palms;
    // Get frame
    cap_ >> frame;
    // Mirror effect
    cv::flip(frame,frame,1);
    // Convert to gray
    cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
    // Equalize graylevels
    // equalizeHist( frame_gray, frame_gray );
    //-- Detect fists
    fist_cascade_.detectMultiScale( frame_gray, fists, 1.1, 4, 0, Size(60, 60) );
    if (fists.size()>0)
    {
        if(fists.size()==1){
            // Draw red rectangle
            rectangle(frame,fists[0],cv::Scalar(0,0,255),2);
             VideoProcessing::AnalyseRectangle(fists,true);
        }else{
        // Draw green rectangle
        for (int i=0;i<(int)fists.size();i++)
            rectangle(frame,fists[i],cv::Scalar(0,255,0),2);
             VideoProcessing::AnalyseRectangle(fists,false);
        }
    }else{

         VideoProcessing::AnalyseRectangle(fists,true);
    }

    // Display frame
    imshow("WebCam", frame);
    return direction_;

}

VideoProcessing::~VideoProcessing(){
    cap_.release();
}

void VideoProcessing::AnalyseRectangle(std::vector<cv::Rect> listRect,bool choix){
    direction_=25;
    VideoProcessing::findLeftRight(listRect);
    if(choix ==false){
    if(listRect.size()>1){ // deux mains ou plus

         if(listRect[index_rect_gauche_].y>listRect[index_rect_droit_].y && abs(listRect[index_rect_gauche_].y-listRect[index_rect_droit_].y)>20){
             direction_ =1; // on tourne à gauche


         }
         else if (listRect[index_rect_gauche_].y<listRect[index_rect_droit_].y && abs(listRect[index_rect_gauche_].y-listRect[index_rect_droit_].y)>20) {
             direction_=2; // on tourne à droite


         }
         else if (abs(listRect[index_rect_gauche_].x+listRect[index_rect_gauche_].height-listRect[index_rect_droit_].x)<20) {
             direction_=0;

         }
         else{
             direction_=3; // si une de ces condutions n'est pas satisfaite, fait rien du tout.
         }

        }
    }
    else{
        if(listRect.empty()){
        direction_=0;
        }
    }
}

void VideoProcessing::run(){

    while(true)
        VideoProcessing::process();

}
void VideoProcessing::findLeftRight(std::vector<cv::Rect> listRect){
    if(listRect.size()>1){ // deux mains ou plus

    int tab_tri[listRect.size()] ;

    for(int i=0;i<(int)listRect.size();i++){
        tab_tri[i]=listRect[i].width*listRect[i].height;
    }
     int largest = -1;
     int second_largest = -1;

     int index_of_largest = -1;
     int index_of_second_largest = -1;

     for (int j = 0; j < (int)listRect.size(); j++)  // find the largest
         {
             if (tab_tri[j] >= largest)
             {
                 largest = tab_tri[j];
                 index_of_largest = j;
             }
         }
     for (int k = 0; k < (int)listRect.size(); k++)  // find the second largest
         {
             if (k != index_of_largest) // skip over the largest one
             {
                 if (tab_tri[k] >= second_largest)
                 {
                     second_largest = tab_tri[k];
                     index_of_second_largest = k;
                 }
             }
         }
    // Rectangle gauche & droit
     if(listRect[index_of_largest].x>0&&listRect[index_of_second_largest].x>0){

     if(listRect[index_of_largest].x<listRect[index_of_second_largest].x){
         // donc le plus gros rectangle est à gauche
         index_rect_gauche_=index_of_largest;
         index_rect_droit_=index_of_second_largest;


     }
     else{
         index_rect_droit_=index_of_largest;
         index_rect_gauche_=index_of_second_largest;

     }
     }
    }
}
