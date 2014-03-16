#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	fingerMovie.loadMovie("movies/fingers.mov");
//	fingerMovie.play();
    //-- let's see the voices available in the system
    synthesizer.listVoices();
    synthesizer.initSynthesizer("Ralph");
//    synthesizer.
 //synth.setup("com.apple.speech.synthesis.voice.kyoko.premium");
    for (int i = 0; i < 3; i++) {
        Scene s;
        s.picture.loadImage(ofToString(i) + ".png");
        vector<Character> characters;
        for (int j = 0; j < 3; j++) {
            Character c;
            
            switch (j) {
                case 0:
                    c.name = "Alex";
                    break;
                case 1:
                    c.name = "Vicki";
                    break;
                case 2:
                    c.name = "Fred";
                    break;
                default:
                    break;
            }
            
            c.line = "This is " + c.name + " and I am talking in scene " + ofToString(i);
        }
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    fingerMovie.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetHexColor(0xFFFFFF);

    fingerMovie.draw(20,20);
    ofSetHexColor(0x000000);
    unsigned char * pixels = fingerMovie.getPixels();
    
    int nChannels = fingerMovie.getPixelsRef().getNumChannels();
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < 320; i+=8){
        for (int j = 4; j < 240; j+=8){
            unsigned char r = pixels[(j * 320 + i)*nChannels];
            float val = 1 - ((float)r / 255.0f);
            ofCircle(400 + i,20+j,10*val);
        }
    }


    ofSetHexColor(0x000000);
    if (synthesizer.speaking()) {
        ofDrawBitmapString("Ralph is speaking",20,320);
        
    }
    else {
        ofDrawBitmapString("Ralph is not speaking",20,320);
        
    }
    if(frameByframe) ofSetHexColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetHexColor(0x000000);

    ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);

    if(fingerMovie.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        float speed = (2 * pct - 1) * 5.0f;
        fingerMovie.setSpeed(speed);
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        fingerMovie.setPosition(pct);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if(!frameByframe){
        fingerMovie.setPaused(true);
	}
    synthesizer.speakPhrase("Hello, I am Ralph");

}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	if(!frameByframe){
        fingerMovie.setPaused(false);
	}
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
