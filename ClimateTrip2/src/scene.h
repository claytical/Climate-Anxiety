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
    int topicID;
    vector<Character> characters;
    ofImage picture;
};
