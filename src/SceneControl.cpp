#include "SceneControl.h"
alight::SceneControl::SceneControl(){
	//add scene to scenes(array) here 
	// cout<<"SC int:"<<hanSound<<"\n";
	scenes[0] = new alight::scenes::Pause();
	scenes[1] = new alight::scenes::Meteorites();
	scenes[2] = new alight::scenes::SevenLED();
	
	scenes[3] = new alight::scenes::Ribbons();
	scenes[4] = new alight::scenes::Pause();
	scenes[5] = new alight::scenes::Pause();
	scenes[6] = new alight::scenes::Pause();
	scenes[7] = new alight::scenes::Pause();
	scenes[8] = new alight::scenes::Pause();
	scenes[9] = new alight::scenes::Pause();
	
	
	// scenes[1] = new alight::scenes::Meteorites(hanSound,hanDrawers);
	//etc...
	
	sceneSelect = 0;
	modeSelect = 0;
};
alight::SceneControl::~SceneControl(){};

void alight::SceneControl::setup(){
	viewport.x = 1920;
	viewport.y = 0;
	viewport.width = 1024;
	viewport.height = 768;
	
	for (int i = 0; i < 10; ++i)
	{
		scenes[i]->SetHanSound(hanSound);
		scenes[i]->SetHanNetwork(hanDrawers);	/* code */
		scenes[i]->setup();
		
	}
    
	cout<<"SC setup:"<<hanSound<<"\n";//ok
};
void alight::SceneControl::update(){
	scenes[sceneSelect]->SetMode(modeSelect);
	// cout<<"SceneControl"<<modeSelect<<"\n";
	scenes[sceneSelect]->update();
};

void alight::SceneControl::draw(){
	// ofPushMatrix();
	// 	ofTranslate(1920.0,0,0);
	// 	scenes[sceneSelect]->draw();
	// ofPopMatrix();
    
	
	
	
	// keep a copy of your viewport and transform matrices for later
	ofPushView();
		// tell OpenGL to change your viewport. note that your transform matrices will now need setting up
		ofViewport(viewport);

		// setup transform matrices for normal oF-style usage, i.e.
		//  0,0=left,top
		//  ofGetViewportWidth(),ofGetViewportHeight()=right,bottom
		ofSetupScreen();

		scenes[sceneSelect]->draw();
		
	// restore the old viewport (now full view and oF coords)
	ofPopView();
	
	
	
	ofSetColor(255);
	string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(fpsStr, 100,100);
};

void alight::SceneControl::SetSceneSelect(int i){
	sceneSelect = i;
}

void alight::SceneControl::SetModeSelect(int i){
	modeSelect = i;
}

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