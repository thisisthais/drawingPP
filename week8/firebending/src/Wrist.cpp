//
//  Wrist.cpp
//  firebending
//
//  Created by Thaís Xisto on 11/8/22.
//

#include <stdio.h>
#include "Wrist.h"
Wrist::Wrist() {
    
}

void Wrist::setup() {

}

void Wrist::update(glm::vec3 _detection, glm::vec3 _neckDetection) {
    if (ofGetElapsedTimef() <= 0.5) { // first time changing detection
        detection = _detection;
        neckDetection = _neckDetection;
    } else {
        detection = detection * 0.7 + _detection*0.3;
        neckDetection = neckDetection * 0.7 + _neckDetection*0.3;
    }
    x = detection.x;
    y = detection.y;
    confidence = detection.z;
    
    if (confidence > 0.5) {
        path.addVertex(x, y);
        
        if (path.size() > 1) {
            ofPoint prev = path[path.size() - 1];
            ofPoint curr = path[path.size()];
            
            float vel = (curr - prev).length();
            if (vel > 0 && vel < 10000) {
                velocities.push_back(vel);
            }
        }
        
        if (velocities.size() > 1) {
            float prev = velocities.at(velocities.size() - 2);
            float curr = velocities.back();
            
            float acc = curr - prev;
            accels.push_back(acc);
        }
    }
    
    if (path.size() > 100) {
        path.getVertices().erase(path.begin());
    }
    
    if (velocities.size() > 1000) {
        velocities.erase(velocities.begin());
    }
    
    if (neckDetection.z > 0.4) {
        ofPoint diff = ofPoint(x, y) - ofPoint(neckDetection.x, neckDetection.y);
        float angle = atan2f(diff.x, diff.y) * RAD_TO_DEG;
        ofLog() << angle;
    }
    
//    for (int i = 0; i < path.size(); i++) {
//        int i_minus_1 = i - 1;
//        int i_plus_1 = i + 1;
//        if (i_minus_1 < 0) {
//            i_minus_1 = 0;
//        }
//        if (i_plus_1 == path.size()) {
//            i_plus_1 = path.size()-1;
//        }
//
//        ofPoint prev = path[i_minus_1];
//        ofPoint curr = path[i];
//        ofPoint next = path[i_plus_1];
//
//        float vel = (next - prev).length();
//        ofLog() << vel;
//    }
}

void Wrist::draw() {
    if (confidence > 0.5) {
        ofPushStyle();
        
        float acc;
        if (accels.size() > 0) {
            acc = accels.back();
        } else {
            acc = -1;
        }
        
        float whole;
        modf(acc, &whole);
        
        if (whole == 0) {
            ofSetColor(ofColor::red);
        } else {
            ofSetColor(ofColor::blue);
        }
        ofDrawCircle(x, y, 20);
        ofPopStyle();
    }
}
