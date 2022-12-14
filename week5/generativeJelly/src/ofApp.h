#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFatLine.h"

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
    
    // My Functions
        void makeHead();
        void makeBody();
        ofPoint makeHeadVertex(float angle);
        ofPoint makeBodyVertex(float angle);
        void headSegmentsChanged(int & numSegments);
        void headAChanged(float & num);
        void headBChanged(float & num);
        void headCChanged(int & num);
        void bodyAChanged(float & num);
        void bodyBChanged(float & num);
        void rotateBody();
        void manyHeads();
        void makeMesh();
        void makeFatLines();
        void reset();
    
        ofxPanel gui;
        ofEasyCam cam;
    
        float width;
        float height;
        float radius;
    
    // Head related
        ofPolyline head;
        vector<ofPolyline> heads;
        vector<ofPoint> tentaclePlacements;
        ofParameter<int> headSegments;
        ofParameter<float> headA;
        ofParameter<float> headB;
        ofParameter<int> headC;
    
    // Body related
        ofPolyline body;
        vector<ofPolyline> bodies;
        ofParameter<float> bodyA;
        ofParameter<float> bodyB;
    
        ofMesh mesh;
        vector<ofxFatLine> fatlines;
		
};
