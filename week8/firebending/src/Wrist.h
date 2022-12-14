//
//  Wrist.h
//  firebending
//
//  Created by Thaís Xisto on 11/8/22.
//

#ifndef Wrist_h
#define Wrist_h

#include "ofMain.h"
#include "Particle.h"

class Wrist {
    public:
        
    void setup();
    void update(glm::vec3 detection, glm::vec3 neckDetection);
    void draw();
    
    float x;
    float y;
    float confidence;
    glm::vec3 detection;
    glm::vec3 neckDetection;
    ofPolyline path;
    std::vector<glm::vec2> velocities;
    std::vector<glm::vec2> accels;
    std::vector<Particle> particles;
    
    Wrist();
    
    private:
};

#endif /* Wrist_h */
