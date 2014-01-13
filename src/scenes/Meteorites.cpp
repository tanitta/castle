#include "Meteorites.h"
namespace alight{
namespace scenes{
	int Meteorites::stars = 50;
	double Meteorites::disTime = 0.02;
	double Meteorites::grav = 30.0;
	double Meteorites::sizStar = 2000.0;
	double Meteorites::conC = 200.0;
	double Meteorites::conR = 0.1;
	double Meteorites::conBomb = 0.0;//128.0*2000.0;
	
	Meteorites::Meteorites(){
		star = new Star[stars];
		ofSeedRandom(); 
		for (int i = 0; i < stars; ++i)
		{
			star[i].Init(sizStar*ofRandom(1.0/sizStar, 1.0), ofRandom(0, 1024), ofRandom(0, 768));
			star[i].SetVelocity(ofRandom(-0.5, 0.5),ofRandom(-0.5, 0.5));
		}
	};
	Meteorites::~Meteorites(){};
	
	void Meteorites::setup(){
		cout<<"MT setup:"<<hanSound<<"\n";
	};	
	
	void Meteorites::update(){
		// cout << "Meteorites.updated!" <<"\n";
		double r,invr;
		for (int i = 0; i < stars; ++i)
		{
			star[i].SetForce(0.0,0.0);
			
			//
			for (int j = 0; j < stars; ++j)
			{
				if (i != j)		
				{
					r = pow(pow(star[i].posX-star[j].posX,2.0)+pow(star[i].posY-star[j].posY,2.0),0.5);
					invr = 1.0/pow(r,3.0);
					double fx = grav*star[i].mass*star[j].mass*invr*(star[i].posX-star[j].posX);
					double fy = grav*star[i].mass*star[j].mass*invr*(star[i].posY-star[j].posY);
					if (star[i].radius + star[j].radius < r){
						star[i].AddForce(-fx,-fy);
					}
					// }else{
					// 	star[i].AddForce(fx*conR,fy*conR);
					// 	star[i].AddForce(-(star[i].verX-star[j].verX)*conC, -(star[i].verY-star[j].verY)*conC);
					// }
					
					if (star[i].radius + star[j].radius > r*0.66 && star[j].bomb && star[i].GetForAbs()>32.0)
					{
						star[i].bomb = true;
					}
				}
			}
			
			if(star[i].GetForAbs() > conBomb){
				star[i].bomb = true;
			}
			
			if (star[i].bomb) star[i].counter += 1.0;
			
			if (star[i].counter > 5.0){
				star[i].AddForce(0.1*star[i].mass*star[i].GetForAbs()*ofRandom(-1.0,1.0), 0.1*star[i].mass*star[i].GetForAbs()*ofRandom(-1.0,1.0));
				star[i].counter = 0.0;
				star[i].bomb = false;
			};
		};
		
		// for (int i = 0; i < stars; ++i) star[i].update();
		
		for (int i = 0; i < stars; ++i){
			double resetX = star[i].verX;
			double resetY = star[i].verY;
			if(star[i].posX>1024.0){
				resetX = -abs(resetX)*0.6;
			}
			if(star[i].posX<0.0){
				resetX = abs(resetX)*0.6;
			}
			if(star[i].posY>768){
				resetY = -abs(resetY)*0.6;
			}
			if(star[i].posY<0.0){
				resetY = abs(resetY)*0.6;
			}
			
			star[i].SetVelocity(resetX, resetY);
		};
		star[0].SetPos(1024.0*0.5,768*0.5);
		star[0].SetMass(20000 + 100000*(abs(hanSound->mid[0])+abs(hanSound->mid[1])));
		for (int i = 1; i < stars; ++i) star[i].update();
		
	};	
	
	void Meteorites::draw(){
		ofSetColor(0);
		ofRect(0, 0, 1024, 768);
		
		ofSetColor(255);
		for (int i = 0; i < stars; ++i)
		{
			ofCircle(star[i].posX, star[i].posY, star[i].radius*0.5);
		}
		// cout<<hanSound<<"\n";
	};
	
//--------------------------------------------------------------
//Star
//--------------------------------------------------------------

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
	void Meteorites::Star::SetMass(double m){
		mass = m;
		invMass = 1.0/mass;
		radius = pow(mass*0.3183,0.5);
	};
	
	void Meteorites::Star::SetPos(double x, double y){
			posX = x;
			posY = y;
	};
	
	void Meteorites::Star::SetLock(bool b){
		isLock = b;
	};
	
	void Meteorites::Star::SetForce(double x, double y){
		forX = x;
		forY = y;
		forAbsX = abs(x);
		forAbsY = abs(y);	
	};
	
	void Meteorites::Star::SetVelocity(double x, double y){
		verX = x;
		verY = y;
	};
	
	double Meteorites::Star::GetForAbs(){
		return pow(pow(forAbsX,2.0)+pow(forAbsY,2.0),0.5)*0.1;
	}
	
	void Meteorites::Star::AddForce(double x, double y){
		forX += x;
		forY += y;
		forAbsX += abs(x);
		forAbsY += abs(y);
	};
	
	void Meteorites::Star::update(){
		accX = forX*invMass;
		accY = forY*invMass;
		verX += accX*disTime;
		verY += accY*disTime;
		posX += verX*disTime;
		posY += verY*disTime;	
	};
	
	void Meteorites::Star::draw(){};
	
};
};