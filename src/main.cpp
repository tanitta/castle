#include "ofMain.h"
#include "testApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){ 
	ofAppGLFWWindow win;
	//win.setNumSamples(8);
	win.setMultiDisplayFullscreen(true); //this makes the fullscreen window span across all your monitors
	ofSetupOpenGL(&win, 1920+1024,1080+768, OF_FULLSCREEN);
	
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
