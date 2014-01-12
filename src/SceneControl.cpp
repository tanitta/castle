#include "SceneControl.h"
alight::SceneControl::SceneControl(){
	//add scene to scenes(array) here 
	scenes[0] = new alight::scenes::Pause(hanSound,hanDrawers);
	scenes[1] = new alight::scenes::Meteorites(hanSound,hanDrawers);
	
	// scenes[1] = new alight::scenes::Meteorites(hanSound,hanDrawers);
	//etc...
	
};
alight::SceneControl::~SceneControl(){};

void alight::SceneControl::setup(){};
void alight::SceneControl::update(){
	scenes[1]->update();
};

void alight::SceneControl::draw(){
	ofPushMatrix();
		ofTranslate(1920.0,0,0);
		scenes[1]->draw();
    ofPopMatrix();
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

void alight::SceneControl::SetHanSound(alight::Sound *han){
	hanSound = han;
};

void alight::SceneControl::SetHanDrawers(alight::Drawer *han){
	hanDrawers = han;
};
// void alight::SceneConrtol::SetHanNetwork(alight::Network han){
// 	hanNetwork = han;
// };