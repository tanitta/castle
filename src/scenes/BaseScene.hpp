#pragma once
#include "ofMain.h"
namespace alight{
namespace scenes{
	class BaseScene
	{
	public:
		BaseScene(){};
		~BaseScene(){};
		
		virtual void setup(){};
		virtual void update(){};
		virtual void draw(){};
	};
}
}