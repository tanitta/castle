#pragma once
#include "../Sound.h"
#include "../Network.h"
namespace alight{
namespace scenes{
	class BaseScene{
	public:
		BaseScene(alight::Sound *hanSound, alight::Drawer *hanDrawers);
		~BaseScene();
	
		virtual void setup();
		virtual void update();
		virtual void draw();
		
	private:
		alight::Sound* hanSound;
		alight::Drawer* hanDrawers;
	};
};
};