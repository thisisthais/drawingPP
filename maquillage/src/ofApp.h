#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h"
#include "ofxKinect.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void drawPointCloud();

    ofxFaceTracker2 faceTracker;
    ofxKinect kinect;
    ofMesh pointCloud;
    bool b_drawPointCloud;
    ofEasyCam cam;

    ofxCv::ContourFinder contourFinder;
    ofxPanel gui;
    ofxFloatSlider thresh;
    ofxFloatSlider minRadius;
    ofxFloatSlider maxRadius;
    
    ofImage background;
    ofImage diff;
    ofImage thresholdImage;
    ofPolyline myLine;
    ofPixels depthPixels;
    
    vector<ofImage> stamps;
    
};
