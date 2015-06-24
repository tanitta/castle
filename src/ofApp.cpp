#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	current_scene_id_ = 0;
	
	scene.setup();
	ofBackground(0);
	// ofSetFrameRate(1);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
	scene.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	scene.draw();
}

void ofApp::start_scene(const int scene_number){
	
}

void ofApp::stop_scene(const int scene_number){
	
}

void ofApp::start_current_scene(){
	start_scene(current_scene_id_);
};

void ofApp::stop_current_scene(){
	stop_scene(current_scene_id_);
};
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	scene.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
