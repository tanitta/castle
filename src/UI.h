#include "ofMain.h"

#include "ofxUI.h"

namespace alight{
	class UI{
	public:
		UI();
		~UI();
		
		void setup();
		void exit();
		void Event(ofxUIEventArgs &e);
		void keyPressed(int key);
		void keyReleased(int key);
		
		void set1();
		void set2();
		ofxUICanvas *gui1;

		
		
		ofxUIScrollableCanvas *gui2; 
		
		
		
	};
}