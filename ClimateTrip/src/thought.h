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

class Thought {
    
public:
    void create(ofImage img, string l, int t, int iter);
    void gaugeInterest(float num);
    int topic;
    int iter;
    ofImage image;
    string line;
    string name;
    float interest;
    bool finished;
};

#endif