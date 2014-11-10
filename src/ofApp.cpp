#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    camWidth = ofGetWindowWidth();
    camHeight = ofGetWindowHeight();
    
    sum = 0;
    
#ifdef _USE_LIVE_VIDEO
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
#else
    vidPlayer.loadMovie("fingers.mov");
    vidPlayer.play();
#endif
    
    ofEnableAlphaBlending();
    
    plim.loadSound("sounds/synth.wav");
    plum.loadSound("sounds/Violet.mp3");
    plim.setVolume(0.75f);
    plum.setVolume(0.5f);
    //    plim.setMultiPlay(false);
    //    plum.setMultiPlay(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    
    bool bNewFrame = false;
    
#ifdef _USE_LIVE_VIDEO
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
#else
    vidPlayer.update();
    bNewFrame = vidPlayer.isFrameNew();
#endif
    
    if (bNewFrame){
        
#ifdef _USE_LIVE_VIDEO
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
#else
        colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
#endif
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
#ifdef _USE_LIVE_VIDEO
    vidGrabber.draw(0, 0, camWidth, camHeight);
    ofPixelsRef pixelsRef = vidGrabber.getPixelsRef();
    
#else
    
    vidPlayer.draw(0,0, camWidth, camHeight);
    ofPixelsRef pixelsRef = vidPlayer.getPixelsRef();
    
#endif
    
    ofSetHexColor(0xffffff);
    
    sum = 0;
    
    for (int i = 0; i < camWidth; i+= 7){
        for (int j = 0; j < camHeight; j+= 9){
            float lightness = pixelsRef.getColor(i,j).getLightness();
            sum += lightness;
            
        }
    }
    
    float average = sum / (camWidth * camHeight);
    
    ofLog(OF_LOG_NOTICE, ofToString(average));
    
    if(average < 1.8) {
        if (plim.getIsPlaying()) {
            plim.stop();
        } else if (plum.getIsPlaying()) {
            ofLog(OF_LOG_NOTICE, "plum a tocar");
        } else {
            plum.play();
            ofLog(OF_LOG_NOTICE, "chegou aqui!");
        }
    } else {
        if (plum.getIsPlaying()) {
            plum.stop();
        } else if (plim.getIsPlaying()) {
        } else {
            plim.play();
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}