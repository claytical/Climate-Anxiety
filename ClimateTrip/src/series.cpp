//
//  series.cpp
//  ClimateTrip
//
//  Created by Clay Ewing on 3/17/14.
//
//

#include "series.h"

void Series::add(Thought thought) {

    thoughts.push_back(thought);
}
void Series::gaugeInterest(float num) {
    //series interest
    interest += num;
    //current thought interest
    thoughts[currentThoughtIndex].gaugeInterest(num);
}

void Series::display() {
    thoughts[currentThoughtIndex].image.draw(0, 0);
}
void Series::reset() {
    thoughts.clear();
    currentThoughtIndex = 0;
    started = false;
    finished = false;
    playing = false;
}
int Series::getCurrentTopic() {
    return thoughts[currentThoughtIndex].topic;
}
bool Series::nextThought() {
    if (currentThoughtIndex < thoughts.size() - 1) {
        currentThoughtIndex++;
        return true;
    }
    else {
        
        return false;
    }
}

string Series::getCurrentThought() {
    return thoughts[currentThoughtIndex].line;
}