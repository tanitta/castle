#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	
	keyboard.setup();
	
	network.start();
	
	specData = new float[BUFFER_SIZE];
	ofSoundStreamListDevices();
	ofSoundStreamSetup(0,2,this, 44100,BUFFER_SIZE, 4);
	
	sound.setup(this);
	sound.start();	
	
	ui.setup();
	
	cout<<sound.GetHanSoundData()<<"\n"; //ok
	sceneControl.SetHanDrawers(network.GetHanDrawer());
	sceneControl.SetHanSound(sound.GetHanSoundData());
	sceneControl.setup();
	// cout<<sound.GetHanSoundData()<<"\n"; //ok
}

//--------------------------------------------------------------
void testApp::update(){
	keyboard.update();
	sceneControl.SetSceneSelect(keyboard.GetSceneSelect());
	sceneControl.SetModeSelect(keyboard.GetModeSelect());
	sceneControl.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0);
	ofRect(0, 0, 1920, 1080);
	ofPopMatrix();
	
	ofSetHexColor(0x000000);
	// network.draw();
	
	sceneControl.draw();
	// // sceneControl.SetSceneMain();
	
	// // alight::Drawer *obj;
	// // obj = network.GetHanDrawer();
	
	// ofSetHexColor(0xFFFFFF);	
	// // string str;
	// // for (int i = 0; i < 4; i++)
	// // {
	// // 	str += "drawers[" + ofToString(i) + "]\n";
	// // 	str += "mouseX : " + ofToString(obj[i].mouseX) + "\n";
	// // 	str += "mouseY : " + ofToString(obj[i].mouseY) + "\n";
	// // 	str += "isDraw : " + ofToString(obj[i].isDraw) + "\n\n";
	// // }
	// // ofDrawBitmapString(str, 20, 256);
	int w = 2;
	int max = 256;//(int)(BUFFER_SIZE/2);
	for (int i = 1; i < max; i++){
		if(i%16 == 0){
			ofSetColor(60,220,255);
		}else{
			ofSetColor(255,255,255);
		};
		ofLine(400+(i*w),402,400+(i*w),400-sound.magnitude[i]*1.0f);
	}
	
	ofSetColor(255);
	ofLine(400+(1*w),400,400+(1*w),400+5);
	ofLine(400+(max*w),400,400+(max*w),400+5);
}

//--------------------------------------------------------------
void testApp::exit()
{
    sound.stop();
    
    ui.exit();
}

//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	ui.Event(e);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	ui.keyPressed(key);
	keyboard.SetKeyPressed(key);
  //   cout << "Scene:" << keyboard.GetSceneSelect()<<"\n";
  //   cout << "Mode:" << keyboard.GetModeSelect()<<"\n";
    
	 // cout << "P:" << key <<"\n";
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	keyboard.SetKeyReleased(key);
	//  cout << "R:" << key <<"\n";
	

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
void testApp::audioReceived(float * input, int bufferSize, int nChannels){ 
	mutex.lock();	
		sound.audioReceived(input, bufferSize, nChannels);
	mutex.unlock();
}