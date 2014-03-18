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
    usingRandomValues = false;
    introSound.loadSound("intro.wav");
    outroSound.loadSound("intro.wav");
    heartImage.loadImage("heart.png");
    outroImage[WATER].loadImage("ocean.jpg");
    outroImage[EARTH].loadImage("earth.jpg");
    outroImage[AIR].loadImage("air.jpg");
    string const CONSUMER_KEY = "tJuuYtvkX9D4yO4y3jtcg";
    string const CONSUMER_SECRET = "25qympGYaARpTyOVsTAUNtMkXwgjiAmvUelpgAOx8I";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);
    twitterClient.printDebugInfo();
    for(int i = 0; i < voices.size(); i++) {
        ofLogNotice() << voices[i];
    }
    
	receiver.setup(PORT);
    camera.setDeviceID(1);
	camera.setDesiredFrameRate(60);
	camera.initGrabber(320, 240);



}

void testApp::introduction() {
    introSoundFadeOut = 1;
    heartbeatDirection = 1;
    heartbeatAlpha = 10;
    heartbeatTempo = 2;
    synth.setVoice("com.apple.speech.synthesis.voice.Fred");
    synth.speak("[[slnc 5000]]Hello human,[[slnc 1000]] I am very happy to have you here![[slnc 5000]] I want to introduce you to three of my friends. [[slnc 2000]] But before that I want you to take a deep breath.[[slnc 1000]] Relax! [[slnc 2000]] Listen to your heartbeat.[[slnc 15000]].");
    introSound.play();
    tripState = TRIP_STATE_INTRODUCTION;
}

void testApp::outro() {
    synth.setVoice("com.apple.speech.synthesis.voice.Fred");
    //TODO: Lookup Most Used Bucket
    int randomTweet = int(ofRandom(0,6));
    string filename = takePhoto();

    twitterClient.postStatus(tweets[favoriteTopic()][randomTweet], filename);
    switch (favoriteTopic()) {
        case WATER:
            synth.speak("Human, I am the ocean. You seem to be concerned very much about my well being! I am very thankful for that![[slnc 500]] Can I get a hug? [[slnc 10000]].");
            
            break;
        case AIR:

            synth.speak("Human, I am the atmosphere. You seem to be concerned very much about my well being! I am very thankful for that![[slnc 500]] Can I get a hug? [[slnc 10000]].");

            break;
        case EARTH:
            synth.speak("Human, I am the earth. You seem to be concerned very much about my well being! I am very thankful for that![[slnc 500]] Can I get a hug? [[slnc 10000]]");
            
            
            break;
        default:
            break;
    }
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
void testApp::loadTweets() {
    
    tweets[WATER][0] = "this human loves the ocean #StoryMatter";
    tweets[EARTH][0] = "this human can't get enough of earth #StoryMatter";
    tweets[AIR][0] = "this human loves the atmosphere #StoryMatter";

    tweets[WATER][1] = "this human enjoys the ocean #StoryMatter";
    tweets[EARTH][1] = "an earth loving human #StoryMatter";
    tweets[AIR][1] = "this human can't get enough of the atmosphere #StoryMatter";
    
    tweets[WATER][2] = "who loves the ocean? this human. #StoryMatter";
    tweets[EARTH][2] = "i hear this human hearts earth #StoryMatter";
    tweets[AIR][2] = "so much love for the atmosphere #StoryMatter";
    
    tweets[WATER][3] = "ocean loving human example #" + ofToString(int(ofRandom(99999))) + " #StoryMatter";
    tweets[EARTH][3] = "the earth loves this human #StoryMatter";
    tweets[AIR][3] = "this love is out of the atmosphere #StoryMatter";
    
    tweets[WATER][4] = "the ocean is feeling good #StoryMatter";
    tweets[EARTH][4] = "this earth can contain all of your love #StoryMatter";
    tweets[AIR][4] = "no need to fear, this human is all about the atmosphere #StoryMatter";
    
    tweets[WATER][5] = "oceans, lakes, rivers, creeks, this human loves them all #StoryMatter";
    tweets[EARTH][5] = "gaia love! #StoryMatter";
    tweets[AIR][5] = "pure air! pure love! #StoryMatter";

}
void testApp::loadDialogue() {
    Thought thought;
    //WATER SOUND
    sounds[WATER].loadSound("water_001.wav");
    //WATER IMAGES
    images[WATER][0].loadImage("ocean0.jpg");
    images[WATER][1].loadImage("ocean1.jpg");
    images[WATER][2].loadImage("ocean2.jpg");
    images[WATER][3].loadImage("ocean3.jpg");
    images[WATER][4].loadImage("ocean4.jpg");
    images[WATER][5].loadImage("ocean5.jpg");
    
    //WATER THOUGHTS
    thought.create(images[WATER][0], sounds[WATER],  "I am holding so much heat beneath my vast surface, [[slnc 500]] you can barely see it, but I can really feel it. [[slnc 1000]] I am the ocean. [[slnc 3000]].", WATER, 1);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][1], sounds[WATER],  " I am unleashing my heated frustration  [[slnc 400]] as tumultuous surf and currents. [[slnc 500]] I am torrid. [[slnc 1000]] I am the ocean. [[slnc 3000]].", WATER, 2);
    thoughts[WATER].push_back(thought);
    thought.create(images[WATER][2], sounds[WATER],  "Carbon dioxide is forced into me. [[slnc 500]] I'm acidified, and the life within me is dying. [[slnc 1000]] I am the ocean. [[slnc 3000]].", WATER, 3);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][3], sounds[WATER],  "My honor is upheld by valiant sheets of ice, [[slnc 500]] yet they are slipping away and melting into me. [[slnc 500]] I am swelling, [[slnc 1000]] I am the ocean. [[slnc 3000]].", WATER, 4);
    
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][4], sounds[WATER],  "I have greenhouse gases trapped within my ice, and the melting releases my gaseous enemy. [[slnc 1000]] I am the ice, [[slnc 350]] I am the ocean. [[slnc 3000]].", WATER, 5);
    thoughts[WATER].push_back(thought);
    
    thought.create(images[WATER][5], sounds[WATER],  "I have have changed size before, [[slnc 500]] but never this extreme. [[slnc 400] I am scared [[slnc 1000]] I am the ocean. [[slnc 3000]]", WATER, 6);
    thoughts[WATER].push_back(thought);
    
    
    //AIR SOUND
    sounds[AIR].loadSound("atmosphere_001.mp3");

    //AIR IMAGES
    images[AIR][0].loadImage("air0.jpg");
    images[AIR][1].loadImage("air1.jpg");
    images[AIR][2].loadImage("air2.jpg");
    images[AIR][3].loadImage("air3.jpg");
    images[AIR][4].loadImage("air4.jpg");
    images[AIR][5].loadImage("air5.jpg");
    
    //AIR THOUGHTS
    
    thought.create(images[AIR][0],  sounds[AIR], "It is hard to breathe. [[slnc 700]] There are more greenhouse gases than I have ever experienced before, it is suffocating. [[slnc 1000]] I am the atmosphere. [[slnc 3000]]", AIR, 1);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][1], sounds[AIR], "My environment has always been in flux [[slnc 500]] and my rhythm for 650,000 years was great. [[slnc 1000]] since 1950 I have not been able to adjust [[slnc 500]] I don't know what is going to happen. I am the atmosphere.", AIR, 2);
    thoughts[AIR].push_back(thought);
    
    thought.create(images[AIR][2], sounds[AIR], "The burning of fossil fuels changes my identity [[slnc 500]] and traps heat within my sphere. [[slnc 500]]I don't recognize myself. [[slnc 1000]] I am the atmosphere. [[slnc 3000]].", AIR, 3);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][3], sounds[AIR], "Even if you stop burning fuel now and reduce greenhouse gas emissions to zero I will still heat up the earth more than ever before.[[slnc 500]] I donÕt know what will happen. [[slnc 1000]] I am the Atmosphere. [[slnc 3000]].", AIR, 4);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][4], sounds[AIR], "I will continue to make hot days hotter and cold days colder, [[slnc 500]] I will throw more storms at you and with more intensity than before. [[slnc 1000]] I am the Atmosphere. [[slnc 3000]].", AIR, 5);
    thoughts[AIR].push_back(thought);
    
    
    thought.create(images[AIR][5], sounds[AIR], "If we stay on the path weÕre on, I will continue to heat up faster. [[slnc 1000]] I have become your experiment, [[slnc 500]] yet I shelter your only home. I am [[slnc 500]] nervous. I am the atmosphere. [[slnc 3000]].", AIR, 6);
    thoughts[AIR].push_back(thought);
   
    //EARTH SOUND
    sounds[EARTH].loadSound("earth_001.mp3");


    //EARTH IMAGES - not in directory yet
    images[EARTH][0].loadImage("earth0.jpg");
    images[EARTH][1].loadImage("earth1.jpg");
    images[EARTH][2].loadImage("earth2.jpg");
    images[EARTH][3].loadImage("earth3.jpg");
    images[EARTH][4].loadImage("earth4.jpg");
    images[EARTH][5].loadImage("earth5.jpg");
    
    
    //EARTH THOUGHTS
    
    thought.create(images[EARTH][0], sounds[EARTH],"I have seen the greatest temperature increase, [[slnc 500]]I am unable to let all the heat out. [[slnc 500]] It is uncomfortable. [[slnc 1000]]I am the Earth. [[slnc 3000]].", EARTH, 1);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][1], sounds[EARTH], "My altered climate spreads tropical diseases such as malaria to more regions. [[slnc 1000]] I am the Earth. [[slnc 3000]].", EARTH, 2);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][2], sounds[EARTH], "The extreme weather is changing my soil so unpredictably that agriculture will lose productivity. [[slnc 1000]] I am confused. I am the Earth. [[slnc 3000]]", EARTH, 3);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][3], sounds[EARTH], "My temperatures started to rise along with the industrial revolution. [[slnc 500]] Since the 1960Õs my temperature has risen faster. [[slnc 500]] I am not chill.  [[slnc 1000]] I am the Earth. [[slnc 3000]].", EARTH, 4);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][4], sounds[EARTH], "The ice is melting, leaving more of my minerals accessible. [[slnc 500]] People are digging into me to get them  [[slnc 500]] exposing me. [[slnc 1000]] I am the Earth. [[slnc 3000]].", EARTH, 5);
    thoughts[EARTH].push_back(thought);
    thought.create(images[EARTH][5], sounds[EARTH], "I may lose more than 15 to 37% of all my plant and animal species, [[slnc 1000]] they will never be able to return. [[slnc 500]] I am living too. [[slnc 500]] I am the Earth. [[slnc 3000]]", EARTH, 6);
    thoughts[EARTH].push_back(thought);
  
    
}
//--------------------------------------------------------------
void testApp::update(){
    int brainWave = 0;
    bool pulse = false;
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        cout << "got message" << endl;
        
        if (m.getAddress() == "/attention") {
            brainWave = m.getArgAsInt32(0);

            cout << "got attention " << brainWave << endl;
        }
        if (m.getAddress() == "/pulse") {
            //got pulse, let's go!
            pulse = true;
            
        }
        
        
    }

    switch (tripState) {
        case TRIP_STATE_WAITING_FOR_VIEWER:
            if (pulse) {
                introduction();
            }
            
            camera.update();
            
            if (camera.isFrameNew()){
            }

            break;
        case TRIP_STATE_INTRODUCTION:
            if (!synth.isSpeaking()) {
                startTrip();
            }
            break;
        case TRIP_STATE_PLAYING:

            introSoundFadeOut *= .99;
            introSound.setVolume(introSoundFadeOut);
            if (introSoundFadeOut <= .01) {
                introSound.stop();
            }
            if (synth.isSpeaking()) {
                if (usingRandomValues) {
                    series.gaugeInterest(ofRandom(2));
                }
                else {
                    series.gaugeInterest(brainWave);

                }
            }
            break;
        case TRIP_STATE_OUTRO:
            while(receiver.hasWaitingMessages()){
                // get the next message, clear the queue
                ofxOscMessage m;
                receiver.getNextMessage(&m);
            }

            if (!synth.isSpeaking()) {
                tripState = TRIP_STATE_WAITING_FOR_VIEWER;
                outroSound.stop();
            }
            break;
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    switch (tripState) {
        case TRIP_STATE_WAITING_FOR_VIEWER:
            ofSetColor(255, 255, 255);
            camera.draw(ofGetWidth()/2 - 160,20);

            text.drawString("please put your", ofGetWidth()/2 - (text.stringWidth("please put your")/2), ofGetHeight()/2);
            text.drawString("hands on the globes", ofGetWidth()/2 - (text.stringWidth("hands on the globes")/2), ofGetHeight()/2 + 40);


            break;
        case TRIP_STATE_INTRODUCTION:
            heartbeatAlpha = heartbeatAlpha + (heartbeatTempo * heartbeatDirection);
            cout << "Heartbeat Alpha: " << heartbeatAlpha << endl;
            if (heartbeatAlpha > 100) {
                heartbeatDirection = -1;
            }
            if(heartbeatAlpha < 10) {
                heartbeatDirection = 1;
                heartbeatTempo *= .95;
            }
            
            ofSetColor(255, 255, 255, heartbeatAlpha);
            heartImage.draw(ofGetWidth()/2 - heartImage.width/2, ofGetHeight()/2 - heartImage.height/2);
            break;
        case TRIP_STATE_PLAYING:
            ofSetColor(255, 255, 255);
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
            outroImage[selectedTopic].draw(0,0);
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
    selectedTopic = highestInterestTopic;
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

string testApp::takePhoto() {
    string tmpName = "viewer" + ofToString(int(ofRandom(99999999))) + ".png";
    ofSaveImage(camera.getPixelsRef(), tmpName);
    return tmpName;
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
    takePhoto();
    
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
