#pragma once

#include "ofMain.h"
#include "ofxVoiceSynthesizer.h"
#include "scene.h"
#include "series.h"
#include "character.h"
#include "thought.h"
#include "ofxOsc.h"
#include "ofxTwitter.h"

#define WATER       0
#define EARTH       1
#define AIR         2

#define TRIP_STATE_WAITING_FOR_VIEWER   0
#define TRIP_STATE_INTRODUCTION         1
#define TRIP_STATE_PLAYING              2
#define TRIP_STATE_OUTRO                3
#define TRIP_STATE_FLASH                4

#define PORT 9001

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
        void loadTweets();
		void gotMessage(ofMessage msg);		
        void nextSeriesBasedOnThoughts();
        void switchVoice();
        void startTrip();
        void introduction();
        void outro();
        string takePhoto();
        void flash();
        int randomUninterestingTopic(int interestedTopic);
        int randomThoughtIndex(int topic);
        int favoriteTopic();
    
        ofTrueTypeFont text;
        int tripState;
        float flashTime;
    
        //thought based architecture
        vector<Thought> thoughts[3];
        Series series;
        ofImage images[3][6];
        ofImage outroImage[3];
        ofSoundPlayer sounds[3];
        int brainWaveStrength[3];
        ofSoundPlayer introSound;
        ofImage heartImage;
        int heartbeatDirection;
        int selectedTopic;
        float heartbeatAlpha;
        float heartbeatTempo;
        float introSoundFadeOut;
        ofSoundPlayer outroSound;
        string viewerImage;
        string viewerName;
        string tweets[3][6];
    
    
    //true for all
        ofxVoiceSynthesizer synth;
        ofxOscReceiver receiver;
        ofxTwitter twitterClient;
        bool firstLine;
        bool lastLine;
        bool tookPhotoWithFlash;
        bool usingRandomValues;
    
    
    //webcam
    
    ofVideoGrabber 		camera;
    ofImage             viewer;
    
    //debugging features
    
    bool debug;

};

