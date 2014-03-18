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
//    sound = s;
//    sound.setLoop(true);
//    sound.setVolume(1);
    line = l;
    topic = t;
    iter = it;
    name = "Alex";
    interest = 0;
    alpha = 0;
    alphaDirection = 1;
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
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255, 255, 255, alpha);
    image.draw(position.x - image.width/2, position.y - image.height/2, image.width * scale, image.height * scale);
    ofPopMatrix();
}
void Thought::gaugeInterest(float num) {
    interest += num;
}

void Thought::move() {
    if (alphaDirection == 1) {
        alpha+= alphaDirection;
    }
    else {
        alpha *= .999;
        
    }

    if (alpha >= 255) {
        alphaDirection = -1;
    }
    
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
