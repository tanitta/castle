#pragma once

#include "ofMain.h"
#include "scenes/castle/core.hpp"
class ofApp : public ofBaseApp{
	
	int current_scene_id_;
	alight::scenes::castle::Core scene;
	public:
		void setup();
		void update();
		void draw();
		
		void start_scene(const int scene_number);
		void stop_scene(const int scene_number);
		void start_current_scene();
		void stop_current_scene();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
