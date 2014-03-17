//
//  thought.cpp
//  ClimateTrip
//
//  Created by Clay Ewing on 3/17/14.
//
//

#include "thought.h"
void Thought::create(ofImage img, ofSoundPlayer s, string l, int t, int it) {
    image = img;
    sound = s;
    s.setLoop(true);
    line = l;
    topic = t;
    iter = it;
    name = "Alex";
    interest = 0;
    finished = false;
    effect = ofRandom(1,2);
    switch (effect) {
        case EFFECT_MOVE:
            moveX = ofRandom(-.2, .2);
            moveY = ofRandom(-.2, .2);
            position.x += (moveX * 20);
            position.y += (moveY * 20);
            scale = 1;
            break;
        case EFFECT_ZOOM:
            moveX = 0;
            moveY = 0;
            scale = .8;
            break;
    }
}

void Thought::display() {
    image.draw(position, image.width * scale, image.height * scale);
}
void Thought::gaugeInterest(float num) {
    interest += num;
}

void Thought::move() {
    switch (effect) {
        case EFFECT_MOVE:
            position.x += moveX;
            position.y += moveY;
            break;
        case EFFECT_ZOOM:
            scale += .0005;

            break;
    }

}
