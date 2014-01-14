#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{

	class Meteorites : public alight::scenes::BaseScene{
	public:
		Meteorites(alight::Sound *hanSound, alight::Drawer *hanDrawers);
		~Meteorites();
		
		virtual void setup();
		virtual void update();
		virtual void draw();
		

		
	private:
		alight::Sound* hanSound;
		alight::Drawer* hanDrawers;
	};
};
};