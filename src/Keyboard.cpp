#include "Keyboard.h"
namespace alight{
	Keyboard::Keyboard(){

	};
	Keyboard::~Keyboard(){
		
	};
	
	void Keyboard::setup(){
		sceneSelect = 0;
		modeSelect = 0;
		for (int i = 0; i < 26; ++i){
			isKeyPressed[i] = false;
		}
		isSpacePressed = false;
		
		for (int i = 0; i < 8; ++i){
			sceneVol[i] = 0.0;
		}
		
		for (int i = 0; i < 8; ++i){
			effectVol[i] = 0.0;
		}
		dScene = 0.1;
		dEffect = 0.1;
	};
	
	double Keyboard::GetSceneVol(int i){
		if (0<=i&&i<=7){
			return sceneVol[i];
		}
	};
	double Keyboard::GetEffectVol(int i){
		if (0<=i&&i<=7){
			return effectVol[i];
		}	
	};
	

	double Keyboard::SetMinmax(double val, double min, double max, double d){
			double v = val + d;
			if(v<min){
				return min;
			}else{
				if(max<v){
					return max;
				}else{
					return v;
				}
			}			
	};
	void Keyboard::update(){
		// cout<<sceneVol[0]<<"\n";
		if (!isSpacePressed){
		//sceneVol
			if(isKeyPressed[1])sceneVol[0]=SetMinmax(sceneVol[0],0,127,dScene);
			if(isKeyPressed[26])sceneVol[0]=SetMinmax(sceneVol[0],0,127,-dScene);

			if(isKeyPressed[19])sceneVol[1]=SetMinmax(sceneVol[1],0,127,dScene);
			if(isKeyPressed[24])sceneVol[1]=SetMinmax(sceneVol[1],0,127,-dScene);
			
			if(isKeyPressed[4])sceneVol[2]=SetMinmax(sceneVol[2],0,127,dScene);
			if(isKeyPressed[3])sceneVol[2]=SetMinmax(sceneVol[2],0,127,-dScene);
			
			if(isKeyPressed[6])sceneVol[3]=SetMinmax(sceneVol[3],0,127,dScene);
			if(isKeyPressed[22])sceneVol[3]=SetMinmax(sceneVol[3],0,127,-dScene);						
			
			if(isKeyPressed[7])sceneVol[4]=SetMinmax(sceneVol[4],0,127,dScene);
			if(isKeyPressed[2])sceneVol[4]=SetMinmax(sceneVol[4],0,127,-dScene);
			
			if(isKeyPressed[8])sceneVol[5]=SetMinmax(sceneVol[5],0,127,dScene);
			if(isKeyPressed[14])sceneVol[5]=SetMinmax(sceneVol[5],0,127,-dScene);
			
			if(isKeyPressed[10])sceneVol[6]=SetMinmax(sceneVol[6],0,127,dScene);
			if(isKeyPressed[13])sceneVol[6]=SetMinmax(sceneVol[6],0,127,-dScene);

		}else{
		//effectvol
			if(isKeyPressed[1])effectVol[0]=SetMinmax(effectVol[0],0,127,dEffect);
			if(isKeyPressed[26])effectVol[0]=SetMinmax(effectVol[0],0,127,-dEffect);

			if(isKeyPressed[19])effectVol[1]=SetMinmax(effectVol[1],0,127,dEffect);
			if(isKeyPressed[24])effectVol[1]=SetMinmax(effectVol[1],0,127,-dEffect);
			
			if(isKeyPressed[4])effectVol[2]=SetMinmax(effectVol[2],0,127,dEffect);
			if(isKeyPressed[3])effectVol[2]=SetMinmax(effectVol[2],0,127,-dEffect);
			
			if(isKeyPressed[6])effectVol[3]=SetMinmax(effectVol[3],0,127,dEffect);
			if(isKeyPressed[22])effectVol[3]=SetMinmax(effectVol[3],0,127,-dEffect);						
			
			if(isKeyPressed[7])effectVol[4]=SetMinmax(effectVol[4],0,127,dEffect);
			if(isKeyPressed[2])effectVol[4]=SetMinmax(effectVol[4],0,127,-dEffect);
			
			if(isKeyPressed[8])effectVol[5]=SetMinmax(effectVol[5],0,127,dEffect);
			if(isKeyPressed[14])effectVol[5]=SetMinmax(effectVol[5],0,127,-dEffect);
			
			if(isKeyPressed[10])effectVol[6]=SetMinmax(effectVol[6],0,127,dEffect);
			if(isKeyPressed[13])effectVol[6]=SetMinmax(effectVol[6],0,127,-dEffect);
		}
	};

	int Keyboard::GetSceneSelect(){
		return sceneSelect;
	};

	int Keyboard::GetModeSelect(){
		return modeSelect;
	};

	void Keyboard::SetKeyPressed(int key){
		//SceneSelect
		if(48<=key && key<=57) sceneSelect = key-48;
		
		//ModeSelect
		switch(key){
			case 113: modeSelect = 0; break;
			case 119: modeSelect = 1; break;
			case 101: modeSelect = 2; break;
			case 114: modeSelect = 3; break;
			case 116: modeSelect = 4; break;
			case 121: modeSelect = 5; break;
			case 117: modeSelect = 6; break;
			case 105: modeSelect = 7; break;
		}
		
		//a - z 
		if (97<=key && key<=122) isKeyPressed[key-96] = true;
		
		//Space
		if (key == 32) isSpacePressed = true;
		
		
	};
	void Keyboard::SetKeyReleased(int key){
		//a - z 
		if (97<=key && key<=122) isKeyPressed[key-96] = false;
		
		//Space
		if (key == 32) isSpacePressed = false;
	};
};