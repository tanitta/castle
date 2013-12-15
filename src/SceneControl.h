#pragma once
#include "ofMain.h"
#include "Sound.h"
#include "Network.h"
#include "scenes/BaseScene.h"
namespace alight{
	class SceneControl{
	public:
		SceneControl();
		~SceneControl();
	
		void update();
		void setup();
		
		ofImage imageMain;
		ofImage imageSub;
		
		ofImage GetSceneMain();
		ofImage GetSceneSub();
		
		void ExchangeScene();
		
		alight::Sound* hanSound;
		void SetHanSound(alight::Sound *han);
		
		alight::Drawer* hanDrawers;
		void SetHanDrawers(alight::Drawer *han);
	private:
		alight::scenes::BaseScene* scenes[8];
	};
}