#include "BaseScene.h"
namespace alight{
namespace scenes{
	BaseScene::BaseScene(){
		mode = 0;
	};
	BaseScene::~BaseScene(){};
	
	void BaseScene::setup(){
		
	};	
	
	void BaseScene::update(){
		
	};	
	
	void BaseScene::draw(){
		
	};	
	
	void BaseScene::SetHanSound(alight::SoundData *han){
		hanSound = han;
		cout<<"BS SetHanSound:"<<hanSound<<"\n";
		
	};
	void BaseScene::SetHanNetwork(alight::Drawer *han){
		hanDrawers = han;
	};
	
	void BaseScene::SetMode(int n){
		mode = n;
	}
	
	double BaseScene::SetStepVal(double a, double b, double d){
		double c;
		if(b-a>0){
			c = a+abs(d);
			if (b-c<0)
			{
				c = b;
			}
		}else if (b-a<0)
		{
			c = a-abs(d);
			if (b-c>0)
			{
				c = b;
			}
		}else{
			c = b;
		}
		
		return c;
	}
};
};