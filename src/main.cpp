#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <highgui.h>
#include <stdlib.h>

using namespace std;


void *  showCamera(void *)
{

    CvCapture * pCapture;// = cvCreateCameraCapture(0);
    IplImage * pFrame;

    //printf("thread created!\n");
    
    pCapture = cvCreateCameraCapture(-1);
    //printf("OK!!!!\n");

    cvSetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_WIDTH,640);
    cvSetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_HEIGHT,480);
    
    pFrame = cvQueryFrame(pCapture);
    
    //printf("Camera Created!\n"); 
    while(1)
    {
        pFrame = cvQueryFrame(pCapture);   
        //printf("width:%d height:%d \n",pFrame->width,pFrame->height);
        //if(!pFrame) continue;
        cvShowImage("Sender",pFrame);
        char c = cvWaitKey(30);
        if(c==27) break;
    }
    //printf("OpenCV run Successful!\n");
    
    return NULL;
}


int main()
{
    showCamera(NULL);
    pthread_t id;
    pthread_create(&id,NULL,&showCamera,NULL);
   // pthread_join(id,NULL);
    return 0;
}


