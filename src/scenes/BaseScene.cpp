#include "BaseScene.h"
namespace alight{
namespace scenes{
	BaseScene::BaseScene(alight::Sound *hanSound, alight::Drawer *hanDrawers){
		this->hanSound = hanSound;
		this->hanDrawers = hanDrawers;
	};
	BaseScene::~BaseScene(){};
	
	void BaseScene::setup(){
		
	};	
	
	void BaseScene::update(){
		
	};	
	
	void BaseScene::draw(){
		
	};	
};
};