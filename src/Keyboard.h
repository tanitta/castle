#pragma once
#include "ofMain.h"
namespace alight{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();
	
		void setup();
		void update();
	
		int GetSceneSelect();
		int GetModeSelect();
		
		void SetKeyPressed(int key);
		void SetKeyReleased(int key);
		
		//あとEffectとか
		double GetSceneVol(int i);
		double GetEffectVol(int i);
		
		//option
		// void SetDScene(double d);
		// void SetDMode(double d);
	private:
		double SetMinmax(double val, double min, double max,double d);
		
		int sceneSelect;
		int modeSelect;
		
		
		
		//a-z 
		bool isKeyPressed[27];
		bool isSpacePressed;
		
		double sceneVol[8];
		double effectVol[8];
		
		double dScene;
		double dEffect;
	};
}