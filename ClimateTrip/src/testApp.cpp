#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
    movieOver = false;
    begin = true;
    currentSceneIndex = 0;
    //-- let's see the voices available in the system
    vector<string> voices = ofxVoiceSynthesizer::getVoices();
    for(int i = 0; i < voices.size(); i++) {
        ofLogNotice() << voices[i];
    }

    for (int i = 0; i < 3; i++) {
        Scene s;
        ofImage img;
        img.loadImage(ofToString(i) + ".png");
        s.create(img, i);
        vector<Character> characters;
        for (int j = 0; j < 3; j++) {
            switch (j) {
                case 0:
                    s.newCharacter("Bruce", "This is Bruce and I am talking in scene " + ofToString(i));
                    break;
                case 1:
                    s.newCharacter("Albert", "This is Albert and I am talking in scene " + ofToString(i));
                    break;
                case 2:
                    s.newCharacter("Victoria", "This is Victoria and I am talking in scene " + ofToString(i));
                    break;
                default:
                    break;
            }
            
        }
        scenes.push_back(s);
        
    }

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("scene #" + ofToString(currentSceneIndex),20,20);
    if (!movieOver) {
        playScene();
        if (!synth.isSpeaking() && scenes[currentSceneIndex].getCharacterID() == 0 && !begin) {
            nextScene();
        }
        if (currentSceneIndex >= scenes.size()) {
            movieOver = true;
        }
    }
    
}

void testApp::nextScene() {
    currentSceneIndex++;
    scenes[currentSceneIndex].has_started = true;
    cout << "Advancing Scenes" << endl;
    
}
void testApp::playScene() {
    scenes[currentSceneIndex].display();
    if (scenes[currentSceneIndex].has_started) {
        cout << "Starting Scene " << ofToString(currentSceneIndex) << endl;
        synth.setup("com.apple.speech.synthesis.voice." + scenes[currentSceneIndex].getCharacterName());
        synth.speak(scenes[currentSceneIndex].getCharacterLine());
        scenes[currentSceneIndex].play();
    }
    else if (scenes[currentSceneIndex].playing) {
        //running scene
        if (!synth.isSpeaking()) {
            scenes[currentSceneIndex].nextCharacter();
            synth.setup("com.apple.speech.synthesis.voice." + scenes[currentSceneIndex].getCharacterName());
            synth.speak(scenes[currentSceneIndex].getCharacterLine());
            if (scenes[currentSceneIndex].is_over()) {
                cout << "Finished Scene " << currentSceneIndex << endl;
                scenes[currentSceneIndex].finish();
                
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    scenes[currentSceneIndex].start();
    begin = false;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
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
