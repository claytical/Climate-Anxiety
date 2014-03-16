//
//  scene.cpp
//  ClimateTrip2
//
//  Created by Clay Ewing on 3/16/14.
//
//

#include "scene.h"

void Scene::create(ofImage img, int tid) {
    topicID = tid;
    picture = img;
    has_started = false;
    finished = false;
    playing = false;
    currentCharacterIndex = 0;

}
void Scene::display() {
    picture.draw(0,0);
}

void Scene::start() {
//    currentCharacterIndex = 0;
    has_started = true;
}

void Scene::play() {
    has_started = false;
    playing = true;

}

void Scene::finish() {
   playing = false;
   finished = true;
   currentCharacterIndex = 0;

}

void Scene::nextCharacter() {
    currentCharacterIndex++;
}

void Scene::newCharacter(string name, string line) {
    Character c;
    c.interest = 0;
    c.name = name;
    c.line = line;
    characters.push_back(c);

}


int Scene::getCharacterID() {
    return currentCharacterIndex;
}

bool Scene::is_over() {
    if (currentCharacterIndex >= characters.size() - 1) {
        return true;
    }
    else {
        return false;
    }
}
string Scene::getCharacterLine() {
    return characters[currentCharacterIndex].line;
    
}

string Scene::getCharacterName() {
    return characters[currentCharacterIndex].name;
}