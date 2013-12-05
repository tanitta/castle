#pragma once
#include "ofxUDPManager.h"
#include "ofMain.h"
namespace alight{
	class Network : public ofThread{
		public:
			int count;
			Network(){
				count = 0;
			};

			void start(){
	            startThread(true, false);   // blocking, verbose
	        }

	        void stop(){
	            stopThread();
	        }

			void threadedFunction(){
				while( isThreadRunning() != 0 ){
					if( lock() ){
						count++;
						if(count > 50000) count = 0;
						unlock();
						ofSleepMillis(1 * 1000);
					}
				}
			};
			void draw();
			
		private:
			ofxUDPManager udpConnection();
			// 
	};
}