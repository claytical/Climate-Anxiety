//
//  series.h
//  ClimateTrip
//
//  Created by Clay Ewing on 3/17/14.
//
//

#include "thought.h"

class Series {
    
public:
    
    vector<Thought> thoughts;
    string defaultName;
    float interest;
    bool finished;
    bool started;
    bool playing;
    int currentThoughtIndex;
    string getCurrentThought();
    int getCurrentTopic();
    void add(Thought thought);
    void reset();
    void gaugeInterest(float num);
    void display();
    void play();
    bool nextThought();
    void newThought();

};
