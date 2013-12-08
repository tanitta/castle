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
						int id = (int)udpMessage[0];
						drawers[id].mouseX = (int)udpMessage[1] + 128*(int)udpMessage[3];
						drawers[id].mouseY = (int)udpMessage[2] + 128*(int)udpMessage[4];
							drawers[id].isDraw = (int)udpMessage[5];
						// if(count > 50000) count = 0;	/* code */
						
						unlock();
						ofSleepMillis(1);
					}
				}
			}

			//--------------------------
			void draw(){

				string str = "I am a slowly increasing thread. \nmy current count is: ";

				if( lock() ){
					str += ofToString(count) + "\n";
					for (int i = 0; i < 4; i++)
					{
						str += "drawers[" + ofToString(i) + "]\n";
						str += "mouseX : " + ofToString(drawers[i].mouseX) + "\n";
						str += "mouseY : " + ofToString(drawers[i].mouseY) + "\n";
						str += "isDraw : " + ofToString(drawers[i].isDraw) + "\n\n";
					}
					unlock();
				}else{
					str = "can't lock!\neither an error\nor the thread has stopped";
				}
				ofDrawBitmapString(str, 50, 56);
			}

			private:
				ofxUDPManager udpConnection;
				char udpMessage[10];
				
				struct Drawer
				{
						int mouseX;
						int mouseY;
						int isDraw;
				};
				Drawer drawers[5];
	};
}