#pragma once

#include "ofMain.h"
#include "opencv2/opencv.hpp"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();

        float capW;
        float capH;
        bool bLearnBakground;
    
        ofVideoGrabber grabber;
        ofxCvColorImage frameImage;

        cv::Mat frame;
        cv::Mat mask;
        cv::Mat convetedMask;
        cv::Mat backSubtractedColorImage;
        cv::Ptr<cv::BackgroundSubtractor> bgfs;
};

