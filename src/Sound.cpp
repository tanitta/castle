#include "Sound.h"
namespace alight{
	Sound::Sound(){};
	Sound::~Sound(){};
	void Sound::setup(ofSimpleApp* p){
		ofSoundStreamSetup(0,2,p, 44100,BUFFER_SIZE, 4);
		// ofSoundStreamEnumerateDevices();
		this->left = new float[BUFFER_SIZE];
		this->right = new float[BUFFER_SIZE];
		this->mid = new float[BUFFER_SIZE];
		
		
		for (int i = 0; i < NUM_WINDOWS; i++){
			for (int j = 0; j < BUFFER_SIZE/2; j++){
				freq[i][j] = 0;	
			};
		};
	};
	void Sound::update(){
		while( isThreadRunning() != 0 ){
			// cout << (this->left[0]+this->right[0])*0.5 <<"\n";
			static int index=0;
			float avg_power = 0.0f;	
			if(index < NUM_WINDOWS)
				index += 1;
			else
				index = 0;
			
			myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, mid,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
			for(int j=1; j < BUFFER_SIZE/2; j++) {
				freq[index][j] = magnitude[j];		
			};
		};
	};
	void Sound::threadedFunction(){
		update();
		ofSleepMillis(10);
	}
	
	void Sound::audioReceived(float * input, int bufferSize, int nChannels){ 
	for (int i = 0; i < bufferSize; i++){
		this->left[i] = input[i*2];
		this->right[i] = input[i*2+1];
		this->mid[i] = (this->left[i]+this->right[i])*0.5;
		
	}
	bufferCounter++;
}
}

