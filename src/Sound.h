#pragma once
#include "ofMain.h"
#include "fft.h"

#define BUFFER_SIZE 2048
#define NUM_WINDOWS 80

namespace alight{
	struct SoundData
	{
		float *mid;
		float magnitude[BUFFER_SIZE];
		int a;
	};
	class Sound : public ofThread{
		public:
			Sound();
			~Sound();
			void start(){
			    startThread(true, false);   // blocking, verbose
			}

			void stop(){
			    stopThread();
			}

			//--------------------------
			void threadedFunction();

			void setup(ofSimpleApp* p);
			void update();
			
			void audioReceived(float * input, int bufferSize, int nChannels); 
	  		float *left;
	  		float *right;
	  		float *mid;
	  		
		  	int 	bufferCounter;
			fft		myfft;
			
			float magnitude[BUFFER_SIZE];
			float phase[BUFFER_SIZE];
			float power[BUFFER_SIZE];
			
			float freq[NUM_WINDOWS][BUFFER_SIZE/2];
			float freq_phase[NUM_WINDOWS][BUFFER_SIZE/2];
			
			SoundData soundData;
			SoundData *GetHanSoundData();
	};
}