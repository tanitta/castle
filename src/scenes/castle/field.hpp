#pragma once
#include "entity.hpp"
#include "ofxAssimpModelLoader.h"
namespace alight {
	namespace scenes {
		namespace castle {
			class Field : public alight::scenes::castle::Entity{
				ofxAssimpModelLoader model_;
				ofMesh mesh_;
				
				public:
				Field(){};
				
				virtual ~Field(){};
				
				void setup(){
					model_.loadModel("scenes/castle/field.obj");
					mesh_ = model_.getCurrentAnimatedMesh(0);
				};
				
				void draw(){
					
					ofPushMatrix();
					ofTranslate(70,40,0);
					ofScale(0.5,0.5,0.5);
					ofRotate(90,1,0,0);
							
					ofSetColor(ofColor::fromHsb(0,0,32));
					
					mesh_.drawFaces();
					ofSetColor(ofColor::fromHsb(0,0,16));
					mesh_.drawWireframe();
					for (auto&& vertex : mesh_.getVertices()) {
						ofDrawIcoSphere(vertex,1.0);
					}
					ofPopMatrix();
				
				}
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
