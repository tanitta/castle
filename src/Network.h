#pragma once

#include "ofMain.h"
#include "ofxUDPManager.h"
// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult

namespace alight{
	struct Drawer{
			int mouseX;
			int mouseY;
			int isDraw;
	};
	class Network : public ofThread{

	public:


    int count;  // threaded fucntions that share data need to use lock (mutex)
                // and unlock in order to write to that data
                // otherwise it's possible to get crashes.
                //
                // also no opengl specific stuff will work in a thread...
                // threads can't create textures, or draw stuff on the screen
                // since opengl is single thread safe

	//--------------------------
	Network();

	void start(){
        startThread(true, false);   // blocking, verbose
    }

    void stop(){
        stopThread();
    }

	//--------------------------
	void threadedFunction();

	//--------------------------
	
	alight::Drawer *GetHanDrawer();
	
	void draw();

	private:
		ofxUDPManager udpConnection;
		char udpMessage[10];
		
		
		Drawer drawers[5];
	};
}