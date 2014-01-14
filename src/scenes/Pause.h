#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{
	class Pause : public alight::scenes::BaseScene{
	public:
		Pause();
		~Pause();
	
		virtual void setup();
		virtual void update();
		virtual void draw();
	
	};
};
};