#include "BaseScene.h"
namespace alight{
namespace scenes{
	BaseScene::BaseScene(){};
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
};
};