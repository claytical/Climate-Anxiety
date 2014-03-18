#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    cout << "WIDTH: " << ofGetWidth();
//    cout << "HEIGHT: " << ofGetHeight();
    text.loadFont("joystix.ttf", 32);
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
    //debugging
    vector<string> voices = ofxVoiceSynthesizer::getVoices();
    synth.setup("com.apple.speech.synthesis.voice.Vicki");
    usingRandomValues = true;
    introSound.loadSound("1.wav");
    outroSound.loadSound("2.wav");
    for(int i = 0; i < voices.size(); i++) {
        ofLogNotice() << voices[i];
    }
    
	receiver.setup(PORT);

}

void testApp::introduction() {
    synth.setVoice("com.apple.speech.synthesis.voice.Fred");
    synth.speak("Hello human, I am very happy to have you here! I want to introduce you to three of my friends, but before that I want you to take a deep breath.[[slnc 1000]] Relax! [[slnc 1000]] Listen to your heartbeat.");
    introSound.play();
    tripState = TRIP_STATE_INTRODUCTION;
}

void testApp::outro() {
    synth.setVoice("com.apple.speech.synthesis.voice.Fred");
    //TODO: Lookup Most Used Bucket
    synth.speak("Human, I am the Atmosphere. You seem to be concerned very much about my well being! I am very thankful for that![[slnc 500]] Can I get a hug?");
    outroSound.play();
    tripState = TRIP_STATE_OUTRO;
}
void testApp::startTrip() {
    brainWaveStrength[WATER] = 0;
    brainWaveStrength[AIR] = 0;
    brainWaveStrength[EARTH] = 0;
    firstLine = true;
    loadDialogue();
    series.reset();
    
    series.add(thoughts[WATER][0]);
    series.add(thoughts[AIR][0]);
    series.add(thoughts[EARTH][0]);
    thoughts[WATER].erase(thoughts[WATER].begin());
    thoughts[EARTH].erase(thoughts[EARTH].begin());
    thoughts[AIR].erase(thoughts[AIR].begin());
    tripState = TRIP_STATE_PLAYING;
}

void testApp::loadDialogue() {
    Thought thought;
    //WATER SOUND
    sounds[WATER].loadSound("1.wav");
    //WATER IMAGES
    images[WATER][0].loadImage("water0.jpg");
    images[WATER][1].loadImage("water1.jpg");
    images[WATER][2].loadImage("water2.jpg");
    images[WATER][3].loadImage("water3.jpg");
    images[WATER][4].loadImage("water4.jpg");
    images[WATER][5].loadImage("water5.jpg");
    
    //WATER THOUGHTS
    thought.create(images[WATER][0], sounds[WATER],  "I am holding so much heat beneath my vast surface, you can barely see it. [[slnc 400]] I am the ocean.", WATER, 1);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][1], sounds[WATER],  "I am unleashing my heated frustration as tumultuous surf and currents. [[slnc 400]] I am the ocean.", WATER, 2);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][2], sounds[WATER],  "Carbon dioxide is forced into me, I'm acidified, the life within me is dying. [[slnc 400]] I am the ocean.", WATER, 3);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][3], sounds[WATER],  "My integrity is upheld by valiant sheets of ice, yet they are slipping away, crashing down and melting into me. I am swelling, [[slnc 400]] I am the ocean.", WATER, 4);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][4], sounds[WATER],  "I have trapped polluting gases within my ice, yet the melting releases more my gaseous enemy uncontrollably. I am the ice, [[slnc 400]] I am the ocean.", WATER, 5);
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][5], sounds[WATER],  "I have gone through changes like this before, but never this extreme. I am scared, [[slnc 400]] I am the ocean.", WATER, 6);
    thoughts[WATER].push_back(thought);
    
    
    //AIR SOUND
    sounds[AIR].loadSound("2.wav");

    //AIR IMAGES
    images[AIR][0].loadImage("air0.jpg");
    images[AIR][1].loadImage("air1.jpg");
    images[AIR][2].loadImage("air2.jpg");
    images[AIR][3].loadImage("air3.jpg");
    images[AIR][4].loadImage("air4.jpg");
    images[AIR][5].loadImage("air5.jpg");
    
    //AIR THOUGHTS
    
    thought.create(images[AIR][0],  sounds[AIR], "I am trying to breathe, but my airways feel obstructed, there is more greenhouse gases than I have ever experienced before. It is suffocating, [[slnc 400]] I am the atmosphere.", AIR, 1);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][1], sounds[AIR], "My environment has always been constantly changing, and I was in rhythm with it for the past 650,000 years, but since 1950 things I have not been able to adjust. I donÕt know what is going to happen, this is new for me, [[slnc 400]] I am the atmosphere.", AIR, 2);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][2], sounds[AIR], "The burning of fossil fuels changes my identity and heat gets trapped beneath my surface. You have already burned half of all fossil fuels available to you. If you burn the rest you will put more than 1000 tonnes of carbon into me. [[slnc 400]] I am the atmosphere.", AIR, 3);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][3], sounds[AIR], "Even if you stop burning fuel now and reduce greenhouse gas emissions to zero I will still heat up the earth and take us into uncharted territory. Nobody, including me, knows what will happen then. [[slnc 400]]I am the Atmosphere!", AIR, 4);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][4], sounds[AIR], "I will continue to make hot days hotter and cold days colder, I will throw more storms at you and with more intensity than before. Yet the desert will not see these storms and it will become thirsty. [[slnc 400]]I am the Atmosphere!", AIR, 5);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][5], sounds[AIR], "If we stay on the path weÕre on, I will continue to heat up. I have become an experiment, I hold your only home. I am nervous.[[slnc 400]] I am the atmosphere. ", AIR, 6);
    thoughts[AIR].push_back(thought);
   
    //EARTH SOUND
    sounds[EARTH].loadSound("3.wav");


    //EARTH IMAGES - not in directory yet
    images[EARTH][0].loadImage("earth0.jpg");
    images[EARTH][1].loadImage("earth1.jpg");
    images[EARTH][2].loadImage("earth2.jpg");
    images[EARTH][3].loadImage("earth3.jpg");
    images[EARTH][4].loadImage("earth4.jpg");
    images[EARTH][5].loadImage("earth5.jpg");
    
    
    //EARTH THOUGHTS
    
    thought.create(images[EARTH][0], sounds[EARTH],"I have seen the greatest temperature increase, I try to reflect radiative heat but something is not letting it out and I am soaking more in than I can handle. I am uncomfortable. [[slnc 400]] I am the Earth.", EARTH, 1);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][1], sounds[EARTH], "My altered climate spreads tropical regions along with  diseases such as malaria. The changes also spike pollution episodes and increase the number of airborne particulates to worsen respiratory diseases.[[slnc 400]] I am the Earth.", EARTH, 2);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][2], sounds[EARTH], "The extreme weather is changing my soil. It is will become more difficult to keep up with my changing weather and agriculture not be as productive. I am confused. [[slnc 400]]I am the Earth.", EARTH, 3);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][3], sounds[EARTH], "I started heating up at the onset of the industrial revolution and increased burning of coal. During the 1960Õs my temperature rose faster and is continuing to rise, I donÕt think this was from the increased burning of marijuana. I am not chill. [[slnc 400]]I am the Earth.", EARTH, 4);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][4], sounds[EARTH], "My altered climate spreads tropical regions along with  diseases such as malaria. The changes also spike pollution episodes and increase the number of airborne particulates to worsen respiratory diseases. [[slnc 400]]I am the Earth.", EARTH, 5);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][5], sounds[EARTH], "Through climate change I had to let go of more than 20% of animal species, which will never be able to return. I am living. [[slnc 400]] I am the Earth!", EARTH, 6);
    thoughts[EARTH].push_back(thought);
  
    
}
//--------------------------------------------------------------
void testApp::update(){
    
    
    switch (tripState) {
        case TRIP_STATE_WAITING_FOR_VIEWER:
            break;
        case TRIP_STATE_INTRODUCTION:
            if (!synth.isSpeaking()) {
                startTrip();
            }
            break;
        case TRIP_STATE_PLAYING:
            if (synth.isSpeaking()) {
                if (usingRandomValues) {
                    series.gaugeInterest(ofRandom(2));
                }
                else {
                    while(receiver.hasWaitingMessages()){
                        // get the next message
                        ofxOscMessage m;
                        receiver.getNextMessage(&m);
                        if (m.getAddress() == "/eeg") {
                            int brainWave = m.getArgAsInt32(0);
                            series.gaugeInterest(brainWave);
                        }
                    }
                }
                    //add to aggregate interest level
            }
            break;
        case TRIP_STATE_OUTRO:
            if (!synth.isSpeaking()) {
                tripState = TRIP_STATE_WAITING_FOR_VIEWER;
            }
            break;
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    
    switch (tripState) {
        case TRIP_STATE_WAITING_FOR_VIEWER:
            ofSetColor(255, 255, 255);
            text.drawString("PLEASE PUT YOUR HANDS ON THE GLOBES", 20, ofGetHeight()/2);

            break;
        case TRIP_STATE_INTRODUCTION:
            ofSetColor(255, 255, 255);
            text.drawString("introduction...", 20, ofGetHeight()/2);
            break;
        case TRIP_STATE_PLAYING:
            series.display();
           // currentSynthIndex = series.getCurrentTopic();
            if (firstLine) {
                if (!synth.isSpeaking()) {
                    switchVoice();
                    synth.speak(series.getCurrentThought());
                    series.play();
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
                            outro();
                        }
                        else {
                            nextSeriesBasedOnThoughts();
                            firstLine = true;
                        }
                    }
                }
                
            }

            
            
            break;
        case TRIP_STATE_OUTRO:
            ofSetColor(255, 255, 255);
            text.drawString("You Favored ...", 20, ofGetHeight()/2);

            break;
    }

    
}


int testApp::favoriteTopic() {
    float highestInterestLevel = -999999;
    int highestInterestTopic = -1;
    for (int i = 0; i < 3; i++) {
        if (brainWaveStrength[i] > highestInterestLevel) {
            highestInterestTopic = i;
            highestInterestLevel = brainWaveStrength[i];
        }
    }
    return highestInterestTopic;

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
            highestInterestLevel = series.thoughts[i].interest;
            highestInterestIndex = i;
        }
    }
    series.reset();
    cout << "Adding two of topic " << highestInterestTopic << endl;
    brainWaveStrength[highestInterestTopic]++;
    cout << "That topic has " << thoughts[highestInterestTopic].size() << " thoughts left" << endl;
    if (thoughts[highestInterestTopic].size() <= 0) {
        lastLine = true;
        cout << "This is the last line of the experience, exact count" << endl;
       // movieOver = true;
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
            synth.setVoice("com.apple.speech.synthesis.voice.Victoria");
            break;
        case AIR:
            synth.setVoice("com.apple.speech.synthesis.voice.Alex");
            break;
    }

}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch (tripState) {
        case TRIP_STATE_WAITING_FOR_VIEWER:
            if (key == ' ') {
                introduction();
            }
            break;
        case TRIP_STATE_INTRODUCTION:
            break;
        case TRIP_STATE_PLAYING:
            break;
        case TRIP_STATE_OUTRO:
            break;
    }
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
