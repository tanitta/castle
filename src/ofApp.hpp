#pragma once

#include "ofMain.h"
#include "frame/SceneContainer.hpp"
#include "interface/GUI.hpp"

class ofApp : public ofBaseApp{

	public:
		alight::frame::SceneContainer sceneContainer;
		alight::interface::GUI gui;
		void setup(){
			gui.setup();
			
		};
		void update(){};
		void draw(){};

		void keyPressed(int key){
			gui.keyPressed(key);
		};
		void keyReleased(int key){};
		void mouseMoved(int x, int y ){};
		void mouseDragged(int x, int y, int button){};
		void mousePressed(int x, int y, int button){};
		void mouseReleased(int x, int y, int button){};
		void windowResized(int w, int h){};
		void dragEvent(ofDragInfo dragInfo){};
		void gotMessage(ofMessage msg){};
		void exit(){
			gui.exit();
		}; 
		void guiEvent(ofxUIEventArgs &e){
			gui.guiEvent(e);
		};
};
