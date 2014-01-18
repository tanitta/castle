#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{
	class ColorBox{
	public:
		ColorBox();
		~ColorBox();
		ColorBox(const ColorBox& obj){};
		void SetColor(int r,int g, int b);
		void draw();
		
		int colorR;
		int colorG;
		int colorB;
		
		bool isFill;
		
		double size;
		
		ofVec3f point;
		ofVec3f rotate;
	};
	
	class Ribbons : public alight::scenes::BaseScene{
	public:
		Ribbons();
		~Ribbons();
		
		virtual void setup();
		virtual void update();
		virtual void draw();
		
		// void mouseMoved(int x, int y );
		
		//this holds all of our points
	    vector<ofVec3f> points;
	    //this keeps track of the center of all the points
	    ofVec3f center;
	    
		//our camera objects for looking at the scene from multiple perspectives
		ofCamera camera;
		float rotateAmount;
		
		double rotateStep;
		
	    vector<alight::scenes::ColorBox> boxes;
		
	};
};
};