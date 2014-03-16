#include "testApp.h"

static string voices[24] = {"Agnes", "Albert", "Alex", "Bad News", "Bahh", "Bells", "Boing", "Bruce", "Bubbles", "Cellos", "Deranged", "Fred", "Good News", "Hysterical", "Junior", "Kathy", "Pipe Organ", "Princess", "Ralph", "Trinoids", "Vicki", "Victoria", "Whisper", "Zarvox"};

//--------------------------------------------------------------
void testApp::setup() {

    font.loadFont("verdana.ttf", 34);
    voice = "Agnes";
    bRandomVoice = false;

    // load the lyrics from a text file and split them
    // up in to a vector of strings
    string lyrics = ofBufferFromFile("lyrics.txt").getText();
    step = 0;
    words = ofSplitString(lyrics, " ");

    actorIndex = 0;
    wordQueueIndex = 0;
    
    actors.push_back("Agnes");
    actors.push_back("Albert");
    actors.push_back("Alex");
    actors.push_back("Bad News");
    actors.push_back("Bahh");
    actors.push_back("Bells");
    actors.push_back("Boing");
    actors.push_back("Bruce");
    actors.push_back("Bubbles");
    actors.push_back("Cellos");
    actors.push_back("Deranged");
    actors.push_back("Fred");
    actors.push_back("Good News");
    actors.push_back("Hysterical");
    actors.push_back("Junior");
    actors.push_back("Kathy");
    actors.push_back("Pipe Organ");
    actors.push_back("Princess");
    actors.push_back("Ralph");
    actors.push_back("Trinoids");
    actors.push_back("Vicki");
    actors.push_back("Victoria");
    actors.push_back("Whisper");
    actors.push_back("Zarvox");
    for (int i = 0; i < actors.size(); i++) {
        wordQueue.push_back("hello");
        wordQueue.push_back("my");
        wordQueue.push_back("name");
        wordQueue.push_back("is");
        wordQueue.push_back(actors[i]);
    }
    
    // we are running the systems commands
    // in a sperate thread so that it does
    // not block the drawing
    startThread();
}

//--------------------------------------------------------------
void testApp::threadedFunction() {

    while (isThreadRunning()) {


        // call the system command say

        #ifdef TARGET_OSX
            string cmd = "say -v "+actors[actorIndex]+" "+wordQueue[wordQueueIndex]+" ";   // create the command
            system(cmd.c_str());
        #endif
        #ifdef TARGET_WIN32
            string cmd = "data\\SayStatic.exe "+wordQueue[wordQueueIndex];   // create the command
            cout << cmd << endl;
            system(cmd.c_str());
        #endif


        //step to the next word
        if (wordQueueIndex%5 == 4) {
            actorIndex++;
        }
        if (wordQueueIndex == wordQueue.size()) {
            wordQueueIndex = 0;
        }
        else {
            wordQueueIndex++;
        }
        
        
        // step to the next word
        step ++;
        step %= words.size();

        // slowdown boy
        ofSleepMillis(1);
    }
}

//--------------------------------------------------------------
void testApp::update() {
    // get a random voice
    if(bRandomVoice) {
        voice = voices[(int)ofRandom(24)];
    }
}


//--------------------------------------------------------------
void testApp::draw() {
    // center the word on the screen
    float x = (ofGetWidth() - font.stringWidth(words[step])) / 2;
    float y = ofGetHeight() / 2;

    // draw the word
    ofSetColor(0);
    font.drawString(words[step], x, y);
}

//--------------------------------------------------------------
void testApp::exit() {
    // stop the thread on exit
    waitForThread(true);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    if(key == 'r') {
        bRandomVoice = !bRandomVoice;
    }

    if(key == ' ') {
        voice = voices[(int)ofRandom(24)];
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
