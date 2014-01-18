#include "Ribbons.h"
namespace alight{
namespace scenes{
	ColorBox::ColorBox(){
		size = 0;
		point = ofVec3f(0,0,0);
		rotate = ofVec3f(0,0,0);
		
		colorR = 255;
		colorG = 127;
		colorB = 127;
		
		isFill = true;
	};
	ColorBox::~ColorBox(){};
	
	void ColorBox::SetColor(int r, int g, int b){
		colorR = r;
		colorG = g;
		colorB = b;
	};
	
	void ColorBox::draw(){
		ofSetColor(colorR,colorG,colorB);
		ofPushMatrix();
			ofTranslate(point.x,point.y,point.z);
			if (isFill){
				ofFill();
				ofSphere(0,0,0,size*0.2);
			}else{	
				ofNoFill();
				ofSphere(0,0,0,size*0.2);
			}
			
		ofPopMatrix();
	};
	
	Ribbons::Ribbons(){};
	Ribbons::~Ribbons(){};
	void Ribbons::setup(){
		ofBackground(0);
		rotateAmount = 0;
		
		rotateStep = 0;
		
	   ofSetSphereResolution(12);

	};
	
	void Ribbons::update(){
		
		// ofVec3f mousePoint(x,y,0);
		double range = 1000;
		double rangeR = 7000;
		
		for (int i = 1; i < boxes.size(); ++i){
 				boxes[i-1] = boxes[i];
 		}
 		
		if(boxes.size()<200){
			alight::scenes::ColorBox obj;
 			boxes.push_back(obj);
 			boxes[boxes.size()-1].point.x = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 20;
 			boxes[boxes.size()-1].isFill = true;
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.1;
 		}else{
 			boxes[boxes.size()-1].point.x = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 0;
 			boxes[boxes.size()-1].isFill = true;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.1;
		}
		
		
		for (int i = 1; i < boxes.size(); ++i){
 				boxes[i-1] = boxes[i];
 		}
 		
		if(boxes.size()<200){
			alight::scenes::ColorBox obj;
 			boxes.push_back(obj);
 			boxes[boxes.size()-1].point.x = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 20;
 			boxes[boxes.size()-1].isFill = false;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.1;
 		}else{
 			boxes[boxes.size()-1].point.x = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 0;
 			boxes[boxes.size()-1].isFill = false;
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size*3;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size*3;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.3;
		}
		
		
		for (int i = 1; i < boxes.size(); ++i){
 				boxes[i-1] = boxes[i];
 		}
 		
		if(boxes.size()<200){
			alight::scenes::ColorBox obj;
 			boxes.push_back(obj);
 			boxes[boxes.size()-1].point.x = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 20;
 			boxes[boxes.size()-1].isFill = true;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.1;
 		}else{
 			boxes[boxes.size()-1].point.x = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 0;
 			boxes[boxes.size()-1].isFill = true;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size*10;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size*10;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size;
		}
		
		if(boxes.size()<200){
			alight::scenes::ColorBox obj;
 			boxes.push_back(obj);
 			boxes[boxes.size()-1].point.x = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 20;
 			boxes[boxes.size()-1].isFill = true;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size*0.1;
 		}else{
 			boxes[boxes.size()-1].point.x = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.y = 3.0*ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range);
 			boxes[boxes.size()-1].point.z = 0;
 			boxes[boxes.size()-1].isFill = true;	
 			boxes[boxes.size()-1].size = hanSound->mid[0]*hanSound->mid[0]*rangeR;
 			boxes[boxes.size()-1].colorR = boxes[boxes.size()-1].size*10;
			boxes[boxes.size()-1].colorG = boxes[boxes.size()-1].size*10;
			boxes[boxes.size()-1].colorB = boxes[boxes.size()-1].size;
		}
		
		
		if(points.size()<200){
 			points.push_back(ofVec3f(ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range),ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range),0));
 		}else{
 			for (int i = 1; i < points.size(); ++i)
 			{
 				points[i-1] = points[i];
 			}
 			points[points.size()-1] = ofVec3f(ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range),ofRandom(-hanSound->mid[0]*range,hanSound->mid[0]*range),0);
		}
		cout<<"pointSize:"<<points.size()<<"\n";
		
		ofVec3f sumOfAllPoints(0,0,0);
        for(unsigned int i = 0; i < points.size(); i++){
            points[i].z -= 16;
            boxes[i].point.z -= 16;
            sumOfAllPoints += points[i];
        }
        center = sumOfAllPoints / points.size();
        
        rotateStep = SetStepVal(rotateStep,mode*0.5,0.1);
        rotateAmount += rotateStep;
        // cout<<"rotateAmount:"<<rotateAmount<<"\n";
        ofVec3f furthestPoint;
        if (points.size() > 0) {
            furthestPoint = points[0];
        }
        else
        {
            furthestPoint = ofVec3f(0, 0, 20);
        }

        ofVec3f directionToFurthestPoint(0,40+rotateStep*100,100);
        ofVec3f directionToFurthestPointRotated = directionToFurthestPoint.rotated(rotateAmount, ofVec3f(0,0,1));
        // camera.setPosition(directionToFurthestPointRotated);
        
        camera.setPosition(directionToFurthestPointRotated);
        
        camera.lookAt(ofVec3f(0,0,-rotateStep*10));
	};
	
	void Ribbons::draw(){
		camera.begin();
		// ofDrawGrid(100);
		ofSetColor(255);
		//do the same thing from the first example...
	    ofMesh mesh;
		mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
		for(unsigned int i = 1; i < points.size(); i++){

			//find this point and the next point
			ofVec3f thisPoint = points[i-1];
			ofVec3f nextPoint = points[i];

			//get the direction from one to the next.
			//the ribbon should fan out from this direction
			ofVec3f direction = (nextPoint - thisPoint);

			//get the distance from one point to the next
			float distance = direction.length();

			//get the normalized direction. normalized vectors always have a length of one
			//and are really useful for representing directions as opposed to something with length
			ofVec3f unitDirection = direction.normalized();

			//find both directions to the left and to the right
			ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
			ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));

			//use the map function to determine the distance.
			//the longer the distance, the narrower the line.
			//this makes it look a bit like brush strokes
			float thickness = ofMap(distance, 0, 60, 20, 2, true)*hanSound->mid[0]*20.0;

			//calculate the points to the left and to the right
			//by extending the current point in the direction of left/right by the length
			ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
			ofVec3f rightPoint = thisPoint+toTheRight*thickness;

			//add these points to the triangle strip
			mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
			mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
		}

		for (int i = 0; i < boxes.size(); ++i){
 				boxes[i].draw();
 		}
 		
		ofSetColor(255,255,255);
		//end the shape
		mesh.draw();
		
		
		camera.end();
	};
	
	// void Ribbons::mouseMoved(int x, int y ){
	// 	ofVec3f mousePoint(x,y,0);
 	//  points.push_back(mousePoint);
	// };
};	
};