#pragma once

#include "ofMain.h"
#include "ofxVoiceSynthesizer.h"
#include "scene.h"
#include "series.h"
#include "character.h"
#include "thought.h"
#define WATER       0
#define EARTH       1
#define AIR         2


class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void loadDialogue();
		void gotMessage(ofMessage msg);		
        void nextSeriesBasedOnThoughts();
        void switchVoice();
        void startTrip();
        void introduction();
        void outro();
        int randomUninterestingTopic(int interestedTopic);
        int randomThoughtIndex(int topic);
    
        ofTrueTypeFont text;
    
    //thought based architecture
    vector<Thought> thoughts[3];
    Series series;
    ofImage images[3][6];
    
    
    
    //true for all
        ofxVoiceSynthesizer synth;
       // ofxVoiceSynthesizer synths[3];
        bool movieOver;
        bool outroducingTrip;
        bool introducingTrip;
        bool begin;
        bool firstLine;
        bool lastLine;
        int currentSceneIndex;
        int currentSynthIndex;
};

