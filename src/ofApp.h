#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

//#define _USE_LIVE_VIDEO //para usar v�deo em tempo real, remover o coment�rio

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
#ifdef _USE_LIVE_VIDEO
    ofVideoGrabber 		vidGrabber;
#else
		  ofVideoPlayer 		vidPlayer;
#endif
    
    ofxCvColorImage			colorImg;
    ofSoundPlayer plim;
    ofSoundPlayer plum;
    int camWidth;
    int camHeight;
    
    
    ofxCvContourFinder 	contourFinder;
    
    float sum;
};
