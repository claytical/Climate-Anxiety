//
//  thought.cpp
//  ClimateTrip
//
//  Created by Clay Ewing on 3/17/14.
//
//

#include "thought.h"
void Thought::create(ofImage img, string l, int t, int it) {
    image = img;
    line = l;
    topic = t;
    iter = it;
    name = "Alex";
    interest = 0;
    finished = false;
}

void Thought::gaugeInterest(float num) {
    interest += num;
}
