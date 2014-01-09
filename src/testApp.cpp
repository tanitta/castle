#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// network.start();
	
	sound.setup(this);
	// sound.start();	
	
	ui.setup();
	
	sceneControl.setup();
	sceneControl.SetHanDrawers(network.GetHanDrawer());
	sceneControl.SetHanSound(&sound);
	
}

//--------------------------------------------------------------
void testApp::update(){
	// sound.update();
	sceneControl.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0x000000);
	// network.draw();
	
	sceneControl.draw();
	// sceneControl.SetSceneMain();
	
	// alight::Drawer *obj;
	// obj = network.GetHanDrawer();
	
	// ofSetHexColor(0xFFFFFF);	
	// string str;
	// for (int i = 0; i < 4; i++)
	// {
	// 	str += "drawers[" + ofToString(i) + "]\n";
	// 	str += "mouseX : " + ofToString(obj[i].mouseX) + "\n";
	// 	str += "mouseY : " + ofToString(obj[i].mouseY) + "\n";
	// 	str += "isDraw : " + ofToString(obj[i].isDraw) + "\n\n";
	// }
	// ofDrawBitmapString(str, 20, 256);
	// int w = 2;
	// int max = 256;//(int)(BUFFER_SIZE/2);
	// for (int i = 1; i < max; i++){
	// 	ofLine(400+(i*w),400,400+(i*w),400-sound.magnitude[i]*10.0f);
	// }
	// ofLine(400+(1*w),400,400+(1*w),400+5);
	// ofLine(400+(max*w),400,400+(max*w),400+5);
}

//--------------------------------------------------------------
void testApp::exit()
{
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

void testApp::audioReceived(float * input, int bufferSize, int nChannels){ 
	sound.audioReceived(input, bufferSize, nChannels);
}