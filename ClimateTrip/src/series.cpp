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
    thoughts[currentThoughtIndex].display();
    thoughts[currentThoughtIndex].move();
}
void Series::reset() {
    thoughts.clear();
    currentThoughtIndex = 0;
    started = false;
    finished = false;
    playing = false;
}

void Series::play() {
    thoughts[currentThoughtIndex].sound.play();
}
int Series::getCurrentTopic() {
    return thoughts[currentThoughtIndex].topic;
}
bool Series::nextThought() {
    thoughts[currentThoughtIndex].sound.stop();
    if (currentThoughtIndex < thoughts.size() - 1) {
        currentThoughtIndex++;
        thoughts[currentThoughtIndex].sound.play();
        return true;
    }
    else {
        
        return false;
    }
}

string Series::getCurrentThought() {
    return thoughts[currentThoughtIndex].line;
}