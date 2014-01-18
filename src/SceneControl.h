#pragma once
#include "ofMain.h"
#include "Sound.h"
#include "Network.h"
#include "scenes/BaseScene.h"
#include "scenes/Pause.h"
#include "scenes/Meteorites.h"
#include "scenes/SevenLED.h"
#include "scenes/Ribbons.h"
#define DISP1_W
#define DISP1_H 
namespace alight{
	class SceneControl{
	public:
		SceneControl();
		~SceneControl();
	
		void update();
		void setup();
		void draw();
		
		ofRectangle viewport;
		
		//sceneの操作関係
		int sceneSelect;
		void SetSceneSelect(int i);
		int modeSelect;
		void SetModeSelect(int i);
			
		alight::SoundData* hanSound;
		void SetHanSound(alight::SoundData *han);
		
		alight::Drawer* hanDrawers;
		void SetHanDrawers(alight::Drawer *han);
	private:
		alight::scenes::BaseScene* scenes[10];
	};
}