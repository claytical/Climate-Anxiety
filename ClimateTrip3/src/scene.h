//
//  scene.h
//  ClimateTrip2
//
//  Created by Clay Ewing on 3/16/14.
//
//

#include "ofMain.h"
#include "character.h"

class Scene {
    
public:
    void display();
    int topicID;
    vector<Character> characters;
    ofImage picture;
    int currentCharacterIndex;
    bool finished;
    bool has_started;
    bool playing;
    void create(ofImage img, int tid);
    void start();
    void play();
    void finish();
    void nextCharacter();
    void newCharacter(string name, string line);
    bool is_over();
    string getCharacterLine();
    string getCharacterName();
    int getCharacterID();
};
