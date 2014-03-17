//
//  thought.h
//  ClimateTrip
//
//  Created by Clay Ewing on 3/17/14.
//
//

#ifndef __ClimateTrip__thought__
#define __ClimateTrip__thought__

#include "ofMain.h"

#define WATER       0
#define EARTH       1
#define AIR         2
#define EFFECT_MOVE 1
#define EFFECT_ZOOM 2

class Thought {
    
public:
    void create(ofImage img, ofSoundPlayer s, string l, int t, int iter);
    void gaugeInterest(float num);
    void move();
    void display();
    int topic;
    int iter;
    int effect;
    float scale;
    float moveX;
    float moveY;
    ofPoint position;
    ofImage image;
    ofSoundPlayer sound;
    string line;
    string name;
    float interest;
    bool finished;
};

#endif