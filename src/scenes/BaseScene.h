#pragma once
#include "../Sound.h"
#include "../Network.h"
namespace alight{
namespace scenes{
	class BaseScene{
	public:
		BaseScene();
		~BaseScene();
	
		virtual void setup();
		virtual void update();
		virtual void draw();
		
		void SetHanSound(alight::SoundData *han);
		void SetHanNetwork(alight::Drawer *han);
		
	protected:
		alight::SoundData* hanSound;
		alight::Drawer* hanDrawers;
		
	};
};
};