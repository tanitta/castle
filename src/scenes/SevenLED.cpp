#include "SevenLED.h"
namespace alight{
namespace scenes{
	SevenLED::SevenLED(){};
	SevenLED::~SevenLED(){};
	
	void SevenLED::setup(){
		b = 20; 
		w = 40;
	};
	void SevenLED::update(){};
	void SevenLED::draw(){
		for (int i = 0; i < 10; ++i)
		{
			LEDs(100+i*120,200, GetBits(-1));
			cout<<GetBits(-1)<<"\n";
		}
	};
	
	string SevenLED::GetBits(int n){
		string s = "";
		switch(n){
			case -1:
				for (int i = 0; i < 7; ++i)
				{
					if((int)(ofRandom(0, 1)+0.5)==1){
						s += "1";
					}else{
						s += "0";
					}
				}
				
				cout<<s<<"\n";
				return s;
			case 0:
				return "1011111";
			case 1:
				return "0000011";
			case 2:
				return "1110110";
			case 3:
				return "1110011";
			case 4:
				return "0101011";
			case 5:
				return "1111001";
			case 6:
				return "1111101";
			case 7:
				return "1000011";
			case 8:
				return "1111111";
			case 9:
				return "1111011";
			case 10:
				return "1111011";
			case 11:
				return "1110000";
		}
	};
	string SevenLED::GetBits(string str){
		return "0000000";
	};
	
	void SevenLED::LEDs(int x, int y, string str){
		ofPushMatrix();
			ofTranslate(x,y,0);
			if (str.substr(0,1)=="1") LED(0,-100);//0
			if (str.substr(1,1)=="1") LED(0,0);//1
			if (str.substr(2,1)=="1") LED(0,100);//2
			
			ofPushMatrix();
				ofRotateZ(90);
				if (str.substr(3,1)=="1") LED(-50,50);//3
				if (str.substr(4,1)=="1") LED(50,50);//4
				if (str.substr(5,1)=="1") LED(-50,-50);//5
				if (str.substr(6,1)=="1") LED(50,-50);//6
			ofPopMatrix();
			
		ofPopMatrix();
	};
	
	void SevenLED::LED(int x, int y){
		ofPushMatrix();
			ofTranslate(x,y,0);
			ofSetColor(255);
			ofSetPolyMode(OF_POLY_WINDING_NONZERO);
			ofBeginShape();
				ofVertex(-w,0);
				ofVertex(-w+b/2,-b/2);
				ofVertex(w-b/2,-b/2);
				ofVertex(w,0);
				ofVertex(w-b/2,b/2);
				ofVertex(-w+b/2,b/2);
				ofVertex(-w,0);
				
			ofEndShape();
    	ofPopMatrix();
	};
}
}