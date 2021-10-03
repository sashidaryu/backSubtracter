#include "ofApp.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/utility.hpp"
#include "ofxCv.h"
#include "ofxOpenCv.h"

void ofApp::setup(){
    grabber.setup(480, 640, OF_PIXELS_BGRA);
    ofSetFrameRate(10);
    capW = grabber.getWidth();
    capH = grabber.getHeight();
    bgfs = cv::createBackgroundSubtractorMOG2();
}

void ofApp::update() {
    grabber.update();
    frameImage.setFromPixels(grabber.getPixels().getData(), capW, capH);
    frame = ofxCv::toCv(frameImage);
    if(grabber.isFrameNew()){
        bgfs->apply(frame, mask, 0.1);
    }
    threshold(mask, mask, 100,255,cv::THRESH_BINARY );
    if (frame.size() == mask.size()){
        cv::cvtColor(mask, convetedMask, CV_GRAY2BGR);
        bitwise_and(convetedMask, frame, backSubtractedColorImage);
    }
}

void ofApp::draw() {
    ofxCv::drawMat(backSubtractedColorImage, 0, 0);
}
