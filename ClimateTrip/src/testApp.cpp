#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cout << "WIDTH: " << ofGetWidth();
    cout << "HEIGHT: " << ofGetHeight();
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
    movieOver = false;
    begin = false;
    firstLine = true;
    currentSceneIndex = 0;
    //-- let's see the voices available in the system
    vector<string> voices = ofxVoiceSynthesizer::getVoices();
    for(int i = 0; i < voices.size(); i++) {
        ofLogNotice() << voices[i];
    }
    loadDialogue();
    series.reset();
    synth.setup("com.apple.speech.synthesis.voice.Vicki");
   // synth[WATER].setup("com.apple.speech.synthesis.voice.Bubbles");
   // synth[EARTH].setup("com.apple.speech.synthesis.voice.Vicki");
   // synth[AIR].setup("com.apple.speech.synthesis.voice.Ralph");

    series.add(thoughts[WATER][0]);
    series.add(thoughts[AIR][0]);
    series.add(thoughts[EARTH][0]);
    thoughts[WATER].erase(thoughts[WATER].begin());
    thoughts[EARTH].erase(thoughts[EARTH].begin());
    thoughts[AIR].erase(thoughts[AIR].begin());

}
void testApp::loadDialogue() {
    Thought thought;
    
    //WATER IMAGES
    images[WATER][0].loadImage("water0.jpg");
    images[WATER][1].loadImage("water1.jpg");
    images[WATER][2].loadImage("water2.jpg");
    images[WATER][3].loadImage("water3.jpg");
    images[WATER][4].loadImage("water4.jpg");
    images[WATER][5].loadImage("water5.jpg");
    
    //WATER THOUGHTS
    thought.create(images[WATER][0],  "I am holding so much heat beneath my vast surface, you can barely see it. I am the ocean.", WATER, 1);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][1],  "I am unleashing my heated frustration as tumultuous surf and currents. I am the ocean.", WATER, 2);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][2],  "Carbon dioxide is forced into me, I'm acidified, the life within me is dying. I am the ocean.", WATER, 3);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][3],  "My integrity is upheld by valiant sheets of ice, yet they are slipping away, crashing down and melting into me. I am swelling, I am the ocean.", WATER, 4);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][4],  "I have trapped polluting gases within my ice, yet the melting releases more my gaseous enemy uncontrollably. I am the ice, I am the ocean.", WATER, 5);
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][5],  "I have gone through changes like this before, but never this extreme. I am scared. I am the ocean.", WATER, 6);
    thoughts[WATER].push_back(thought);
    
    
    
    //AIR IMAGES
    images[AIR][0].loadImage("air0.jpg");
    images[AIR][1].loadImage("air1.jpg");
    images[AIR][2].loadImage("air2.jpg");
    images[AIR][3].loadImage("air3.jpg");
    images[AIR][4].loadImage("air4.jpg");
    images[AIR][5].loadImage("air5.jpg");
    
    //AIR THOUGHTS
    
    thought.create(images[AIR][0],  "There is unequivocal evidence that shows atmospheric concentration of greenhouse gasses has increased over the past few centuries.", AIR, 1);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][1],  "For the past 650,000 years the atmospheric carbon dioxide levels have stayed below a specific threshold, which was crossed in 1950. It continues to increase at faster rates. This brings us into uncharted territory.", AIR, 2);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][2],  "World leaders have agreed to limit the warming to 2 degrees Celsius. To even have a chance to achieve we have to cut down our dependence on fossil fuels. We are limited to 1000 billion tonne of carbon , but have already released 560 billions tonnes. With increasing economic productivity it is unlikely that we will be able to stay under this limit.", AIR, 3);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][3],  "Even if we reduce atmospheric greenhouse gasses to zero today temperature is expected to by 2 degree Celsius and bring us into uncharted territory.", AIR, 4);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][4],  "Weather is expected to become more extreme, with hot days becoming hotter and cold days becoming colder. Storms will hit more frequently and with more intensity. Deserts will experience longer and more devastating dry spells.", AIR, 5);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][5],  "Only radical emission cuts would prevent us from exceeding our limit by 2050. We are on the path to exceed this limit just before then.  We are experimenting with the only home we have.  By not acting sooner we have selected the wait and see approach, and each day we fail to act the more extreme this experiment become.", AIR, 6);
    thoughts[AIR].push_back(thought);
    
    //EARTH IMAGES - not in directory yet
    images[EARTH][0].loadImage("earth0.jpg");
    images[EARTH][1].loadImage("earth1.jpg");
    images[EARTH][2].loadImage("earth2.jpg");
    images[EARTH][3].loadImage("earth3.jpg");
    images[EARTH][4].loadImage("earth4.jpg");
    images[EARTH][5].loadImage("earth5.jpg");
    
    
    //EARTH THOUGHTS
    
    thought.create(images[EARTH][0], "As we decrease our usage of oil and fossil fuels international politics will be disturbed and potential friction and animosity will occur.", EARTH, 1);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][1], "Diseases such as malaria are spreading due to the increasing tropical climate. Increased air pollutants correlates with increased respiratory diseases.", EARTH, 2);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][2], "Agriculture may not be able to keep up with the climate change and extreme weather patterns, decreasing productivity", EARTH, 3);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][3], "Within several decades of CO2 emissions, about a third to half of an initial pulse of anthropogenic CO2 goes into the land and ocean, while the rest stays in the atmosphere", EARTH, 4);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][4], "Land and surface air temperature has increased since the industrial revolution in 19th century, and sharply increased since 1961.", EARTH, 5);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][5], "Climate change threatens 20-30% of plant and animal species with extinction. Climate change has been estimated to be a major driver of biodiversity loss in cool conifer forests, savannas, mediterranean-climate systems, tropical forests, in the Arctic tundra, and in coral reefs. 20 to 30% of plant and animal species are at increased risk of extinction as the global temperature warms beyond 2 degrees celsuis.", EARTH, 6);
    thoughts[EARTH].push_back(thought);

    //AUTOMATIC
    /*
     for (int i = 0; i < 4; i++) {
     images[WATER][i].loadImage("water" + ofToString(i) + ".jpg");
     images[EARTH][i].loadImage("earth" + ofToString(i) + ".jpg");
     images[AIR][i].loadImage("air" + ofToString(i) + ".jpg");
     }
     for (int i = 0; i < 4; i++) {
     Thought tmpThought;
     tmpThought.create(images[WATER][i],  "Line " + ofToString(i) + " of water", WATER, 1);
     thoughts[WATER].push_back(tmpThought);
     tmpThought.create(images[EARTH][i],  "Line " + ofToString(i) + " of earth", EARTH, 1);
     thoughts[EARTH].push_back(tmpThought);
     tmpThought.create(images[AIR][i],  "Line " + ofToString(i) + " of air", AIR, 1);
     thoughts[AIR].push_back(tmpThought);
     
     }
     */

    
    
    
}
//--------------------------------------------------------------
void testApp::update(){
    if (!movieOver) {
        if (synth.isSpeaking()) {
            //add to aggregate interest level
            series.gaugeInterest(ofRandom(2));
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
//    ofDrawBitmapString("scene #" + ofToString(currentSceneIndex),20,20);
    if (!movieOver) {
        series.display();
        currentSynthIndex = series.getCurrentTopic();
        if (firstLine) {
            if (!synth.isSpeaking()) {
                switchVoice();
                synth.speak(series.getCurrentThought());
            }
            firstLine = false;
        }
        else {
            if (!synth.isSpeaking()) {
                if (series.nextThought()) {
                    switchVoice();
                    synth.speak(series.getCurrentThought());
                }
                else {
                    //generate new series
                    if (lastLine) {
                        movieOver = true;
                    }
                    else {
                        nextSeriesBasedOnThoughts();
                        firstLine = true;
                    }
                }
            }
        
        }
        
    }
   
}

int testApp::randomThoughtIndex(int type) {
    int selectedIndex;
    selectedIndex = ofRandom(thoughts[type].size());
    return selectedIndex;
}

int testApp::randomUninterestingTopic(int interestedTopic) {
    int selectedTopic;
    //CONSTANT 3 right now is WATER, EARTH, AIR
    selectedTopic = ofRandom(3);
    if (selectedTopic == interestedTopic) {
        return randomUninterestingTopic(interestedTopic);
    }
    else {
        return selectedTopic;
    }
}



void testApp::nextSeriesBasedOnThoughts() {
    float highestInterestLevel = -999999;
    int highestInterestTopic = -1;
    int highestInterestIndex = -1;
    for (int i = 0; i < series.thoughts.size(); i++) {
        if (series.thoughts[i].interest > highestInterestLevel) {
            highestInterestTopic = series.thoughts[i].topic;
            highestInterestIndex = i;
        }
    }
        series.reset();
    cout << "Adding two of topic " << highestInterestTopic << endl;
    cout << "That topic has " << thoughts[highestInterestTopic].size() << " thoughts left" << endl;
    if (thoughts[highestInterestTopic].size() <= 0) {
        lastLine = true;
        cout << "This is the last line of the experience, exact count" << endl;
        movieOver = true;
        return;
    }
    //add two of the selected topic
    Thought thoughtCopy;
    int index = randomThoughtIndex(highestInterestTopic);
    //add thought to series
    thoughtCopy =thoughts[highestInterestTopic][index];
    series.add(thoughtCopy);

    //delete thought from bucket
    thoughts[highestInterestTopic].erase(thoughts[highestInterestTopic].begin() + index);
    if (thoughts[highestInterestTopic].size() > 1) {
        //second thought
        index = randomThoughtIndex(highestInterestTopic);
        thoughtCopy = thoughts[highestInterestTopic][index];
        series.add(thoughtCopy);
        thoughts[highestInterestTopic].erase(thoughts[highestInterestTopic].begin() + index);
        cout << "Deleted two for that interesting topic, now it has " << thoughts[highestInterestTopic].size() << " thoughts left" << endl;
    }
    
    if (thoughts[highestInterestTopic].size() <= 0) {
        lastLine = true;
        cout << "This is the last line of the experience" << endl;
    }
    
    //choose the second or a random?
    
    int randomTopic = randomUninterestingTopic(highestInterestTopic);
    index = randomThoughtIndex(randomTopic);
    thoughtCopy =thoughts[randomTopic][index];
    series.add(thoughts[randomTopic][index]);
    cout << "Picking Random Topic " << randomTopic << endl;
    //erase that one as well
    thoughts[randomTopic].erase(thoughts[randomTopic].begin() + index);
    cout << "And I delete it, now that topic has " << thoughts[randomTopic].size() << endl;
 }

void testApp::switchVoice() {
    switch(series.getCurrentTopic()) {
        case WATER:
            synth.setVoice("com.apple.speech.synthesis.voice.Vicki");
            break;
        case EARTH:
            synth.setVoice("com.apple.speech.synthesis.voice.Ralph");
            break;
        case AIR:
            synth.setVoice("com.apple.speech.synthesis.voice.Alex");
            break;
    }

}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){
//    scenes[currentSceneIndex].start();
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
