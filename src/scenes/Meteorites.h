#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{
	class Meteorites : public alight::scenes::BaseScene{
	public:
		Meteorites();
		~Meteorites();
	
		virtual void setup();
		virtual void update();
		virtual void draw();
	
		
		
	private:
		static int stars;
		static double disTime;
		static double grav;
		static double sizStar;
		static double conC;
		static double conR;
		static double conBomb;
		
		class Star
		{
			public:
				Star();
				~Star();
				
				void Init(double m, double x, double y);
				void SetMass(double m);
				void SetPos(double x, double y);
				void SetLock(bool b);
				void SetForce(double x, double y);
				void SetVelocity(double x, double y);
				double GetForAbs();
				void AddForce(double x, double y);
				void update();
				void draw();
				
				double mass,radius,invMass;
				double posX,posY;
				double verX,verY;
				double accX,accY;
				double forX,forY;
				double forAbsX,forAbsY;
				double counter;
				bool bomb;
				bool isLock;
				
				
		};
		
		Star* star;
		// alight::SoundData* hanSound;
		// alight::Drawer* hanDrawers;
	};
};
};