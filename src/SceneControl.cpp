#include "SceneControl.h"
alight::SceneControl::SceneControl(){
	//add scene to scenes(array) here 
	// cout<<"SC int:"<<hanSound<<"\n";
	scenes[0] = new alight::scenes::Pause();
	scenes[1] = new alight::scenes::Meteorites();
	
	// scenes[1] = new alight::scenes::Meteorites(hanSound,hanDrawers);
	//etc...
	
	
};
alight::SceneControl::~SceneControl(){};

void alight::SceneControl::setup(){
	scenes[0]->SetHanSound(hanSound);
	scenes[0]->SetHanNetwork(hanDrawers);
	
	scenes[1]->SetHanSound(hanSound);
	scenes[1]->SetHanNetwork(hanDrawers);
	
	scenes[0]->setup();
	scenes[1]->setup();

	cout<<"SC setup:"<<hanSound<<"\n";//ok
	
};
void alight::SceneControl::update(){
	scenes[1]->update();
};

void alight::SceneControl::draw(){
	ofPushMatrix();
		ofTranslate(1920.0,0,0);
		scenes[1]->draw();
    ofPopMatrix();
    
	ofSetColor(255);
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(fpsStr, 100,100);
};

ofImage alight::SceneControl::GetSceneMain(){
	return imageMain;
};

void alight::SceneControl::SetSceneMain(){
	// imageMain.grabScreen(0, 0, 1024, 768);
};

ofImage alight::SceneControl::GetSceneSub(){
	return imageSub;
};

void alight::SceneControl::ExchangeScene(){
};

void alight::SceneControl::SetHanSound(alight::SoundData *han){
	hanSound = han;
	cout<<"SC sethandound:"<<hanSound<<"\n";//ok
	
};

void alight::SceneControl::SetHanDrawers(alight::Drawer *han){
	hanDrawers = han;
};
// void alight::SceneConrtol::SetHanNetwork(alight::Network han){
// 	hanNetwork = han;
// };