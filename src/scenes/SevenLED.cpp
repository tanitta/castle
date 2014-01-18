#include "SevenLED.h"
namespace alight{
namespace scenes{
	SevenLED::SevenLED(){
		mode = 0;
	};
	SevenLED::~SevenLED(){};
	
	void SevenLED::setup(){
		b = 20; 
		w = 40;
	};
	void SevenLED::update(){};
	void SevenLED::draw(){
		ofSetColor(60,220,255);
		ofRect(0, 0, 1024, 768);
		int h = 120;
		// cout<<"LEDmode:"<<mode<<"\n";
		
		switch(mode){
			case 0:
				ofPushMatrix();
				ofTranslate(720,700,0);
					ofScale(0.2,0.2,1.0);
					// cout<<(int)abs(hanSound->mid[0]*10.0)<<"\n";		
					for (int i = 0; i < 10; ++i){
						LEDs(100+i*120,200, GetBits(-1));
					}

					
					// cout<<(int)abs(hanSound->mid[0]*80.0)<<"\n";	
				ofPopMatrix();
			break;
			
			case 1:
				ofPushMatrix();
					ofScale(1,1,1.0);
					LEDs(130,h, GetBits(2));
					LEDs(130*2,h, GetBits(0));
					LEDs(130*3,h, GetBits(1));
					LEDs(130*4,h, GetBits(4));
					LEDs(130*5,h, GetBits(-2));
					LEDs(130*6,h, GetBits(-2));
					
					LEDs(130*5,h+230, GetBits(-2));
					LEDs(130*6,h+230, GetBits(1));
					
					LEDs(130*5,h+230*2, GetBits(1));
					LEDs(130*6,h+230*2, GetBits(9));
				ofPopMatrix();
			break;
			
			case 2:
				ofPushMatrix();
					ofScale(1,1,1.0);
					LEDs(130,h, GetBits(-1));
					LEDs(130*2,h, GetBits(-1));
					LEDs(130*3,h, GetBits(-1));
					LEDs(130*4,h, GetBits(-1));
					LEDs(130*5,h, GetBits(-1));
					LEDs(130*6,h, GetBits(-1));
					
					LEDs(130*5,h+230, GetBits(-1));
					LEDs(130*6,h+230, GetBits(-1));
					
					LEDs(130*5,h+230*2, GetBits(-1));
					LEDs(130*6,h+230*2, GetBits(-1));
				ofPopMatrix();
			break;
			
			case 3:
				ofPushMatrix();
					ofScale(0.5,0.5,1.0);
					
					cout<<(int)abs(hanSound->mid[0]*10.0)<<"\n";		
					for (int i = 0; i < 15; ++i){
						for (int j = 0; j < 6; ++j){
							LEDs(100+i*130,200+j*230, GetBits(-1));
						}
					}
					// cout<<(int)abs(hanSound->mid[0]*80.0)<<"\n";	
				ofPopMatrix();
			break;
		};
		
		
	};
	
	string SevenLED::GetBits(int n){
		string s = "";
		switch(n){
			case -2:
				return "0000000";
			case -1:
				for (int i = 0; i < 7; ++i)
				{
					if((int)(ofRandom(0, 1)+0.5)==1){
						s += "1";
					}else{
						s += "0";
					}
				}
				
				// cout<<s<<"\n";
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
			if (str.substr(0,1)=="1"){
				ofSetColor(50,100,120);
				LED(0,-100);
			}else{
				ofSetColor(0,210,255);
				LED(0,-100);
			};//0
			
			if (str.substr(1,1)=="1"){
				ofSetColor(50,100,120);
				LED(0,0);
			}else{
				ofSetColor(0,210,255);
				LED(0,0);
			}//1
			
			if (str.substr(2,1)=="1"){
				ofSetColor(50,100,120);
				LED(0,100);
			}else{
				ofSetColor(0,210,255);
				LED(0,100);
			}//2
			
			ofPushMatrix();
				ofRotateZ(90);
				if (str.substr(3,1)=="1"){
					ofSetColor(50,100,120);
					LED(-50,50);
				}else{
					ofSetColor(0,210,255);
					LED(-50,50);
				}//3
				
				if (str.substr(4,1)=="1"){
					ofSetColor(50,100,120);
					LED(50,50);
				}else{
					ofSetColor(0,210,255);
					LED(50,50);
				}//4
				
				if (str.substr(5,1)=="1"){
					ofSetColor(50,100,120);
					LED(-50,-50);
				}else{
					ofSetColor(0,210,255);
					LED(-50,-50);
				}//5
				
				if (str.substr(6,1)=="1"){
					ofSetColor(50,100,120);
					LED(50,-50);
				}else{
					ofSetColor(0,210,255);
					LED(50,-50);
				}//6
			ofPopMatrix();
		ofPopMatrix();
	};
	
	void SevenLED::LED(int x, int y){
		ofPushMatrix();
			ofTranslate(x,y,0);
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