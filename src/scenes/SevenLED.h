#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{
	class SevenLED : public alight::scenes::BaseScene{
	public:
		SevenLED();
		~SevenLED();
	
		virtual void setup();
		virtual void update();
		virtual void draw();
		
	private:
		int b;
		int w;
		void LED(int x, int y);
		void LEDs(int x, int y, string str);
		string GetBits(int n);
		string GetBits(string str);
	};
};
};