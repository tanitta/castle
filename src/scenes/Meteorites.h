#pragma once
#include "../Sound.h"
#include "../Network.h"
#include "BaseScene.h"
namespace alight{
namespace scenes{
	class Meteorites : public alight::scenes::BaseScene{
	public:
		Meteorites(alight::Sound *hanSound, alight::Drawer *hanDrawers);
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
		alight::Sound* hanSound;
		alight::Drawer* hanDrawers;
	};
};
};