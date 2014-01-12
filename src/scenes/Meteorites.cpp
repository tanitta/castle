#include "Meteorites.h"
namespace alight{
namespace scenes{
	int Meteorites::stars = 10;
	double Meteorites::disTime = 0.01;
	double Meteorites::grav = 15.0;
	double Meteorites::sizStar = 800.0;
	double Meteorites::conC = 200.0;
	double Meteorites::conR = 0.1;
	double Meteorites::conBomb = 128.0*2000.0;
	Meteorites::Meteorites(alight::Sound *hanSound, alight::Drawer *hanDrawers){
		this->hanSound = hanSound;
		this->hanDrawers = hanDrawers;
		
		star = new Star[stars];
		for (int i = 0; i < stars; ++i)
		{
			star[i].Init(1.0, 0.0, 0.0);
		}
	};
	Meteorites::~Meteorites(){};
	
	void Meteorites::setup(){
		
	};	
	
	void Meteorites::update(){
		// cout << "Meteorites.updated!" <<"\n";
	};	
	
	void Meteorites::draw(){
		// ofSetColor(0xffffff);
		ofRect(500, 500, 50, 50);
	};
	
	Meteorites::Star::Star(){
		
	};
	Meteorites::Star::~Star(){};
	
	void Meteorites::Star::Init(double m, double x, double y){
		mass = m;
		invMass = 1.0/mass;
		
		posX = x;
		posY = y;
		verX = stars;
		verY = 0;
		
		radius = pow(mass*0.3183,0.5);
		counter = 0;
		
		bomb = false;
		isLock = false;
	};
	
	
};
};