#pragma once

#include "ofMain.h"
#include "ofxUDPManager.h"
// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult


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
		Network(){
			count = 0;
			udpConnection.Create();
			udpConnection.BindMcast("224.0.0.0",6000);
			udpConnection.SetNonBlocking(true);
			// udpConnection.Bind(6000);
		}

		void start(){
            startThread(true, false);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }

		//--------------------------
		void threadedFunction(){

			while( isThreadRunning() != 0 ){
				if( lock() ){
					count++;
					udpConnection.Receive(udpMessage,10);
					// if(count > 50000) count = 0;
					unlock();
					ofSleepMillis(1 * 10);
				}
			}
		}

		//--------------------------
		void draw(){

			string str = "I am a slowly increasing thread. \nmy current count is: ";

			if( lock() ){
				str += ofToString(count) + "\n";
				str += "data[0] : " + ofToString((int)udpMessage[1]);
				unlock();
			}else{
				str = "can't lock!\neither an error\nor the thread has stopped";
			}
			ofDrawBitmapString(str, 50, 56);
		}

		private:
			ofxUDPManager udpConnection;
			char udpMessage[10];
};
