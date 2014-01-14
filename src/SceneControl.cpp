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
	scenes[0]->update();
};

ofImage alight::SceneControl::GetSceneMain(){
	return imageMain;
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