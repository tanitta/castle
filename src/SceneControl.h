#pragma once
#include "ofMain.h"
#include "Sound.h"
#include "Network.h"
#include "scenes/BaseScene.h"
#include "scenes/Pause.h"
#include "scenes/Meteorites.h"
#include "scenes/SevenLED.h"
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
		
		ofImage imageMain;
		ofImage imageSub;
		
		ofImage GetSceneMain();
		ofImage GetSceneSub();
		
		void SetSceneMain();
		
		void ExchangeScene();
		
		alight::SoundData* hanSound;
		void SetHanSound(alight::SoundData *han);
		
		alight::Drawer* hanDrawers;
		void SetHanDrawers(alight::Drawer *han);
	private:
		alight::scenes::BaseScene* scenes[8];
	};
}