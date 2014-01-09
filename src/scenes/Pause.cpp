#include "Pause.h"
namespace alight{
namespace scenes{
	Pause::Pause(alight::Sound *hanSound, alight::Drawer *hanDrawers){
		this->hanSound = hanSound;
		this->hanDrawers = hanDrawers;
	};
	Pause::~Pause(){};
	
	void Pause::setup(){
		
	};	
	
	void Pause::update(){
		// cout << "Pause.updated!" <<"\n";
	};	
	
	void Pause::draw(){
		// ofSetColor(0xffffff);
		ofRect(500, 500, 50, 50);
	};	
};
};