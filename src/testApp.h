#pragma once

#include "ofMain.h"
#include "Network.h"
#include "Sound.h"
#include "SceneControl.h"
#include "ofxUI.h"
#include "ui/UI.h"
class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		alight::ui::UI ui;
	    void exit(); 
    	void guiEvent(ofxUIEventArgs &e);
		
		// alight::Network network;
		alight::Network network;
		alight::Sound sound;
		
		alight::SceneControl sceneControl;
		
};
