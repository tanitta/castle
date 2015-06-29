#pragma one
#include "pharticle/pharticle.hpp";
#include "ofxAssimpModelLoader.h"
#include "entity.hpp"<`0`>
namespace alight {
	namespace scenes {
		namespace castle {
			class Tower : public Entity{
				ofxAssimpModelLoader model_;
				public:
				Tower(){};

				virtual ~Tower(){};
				
				void setup(){
					model_.loadModel("scenes/castle/Tower1.obj");
				};
				
				void draw(){
					ofPushMatrix();
					ofTranslate(0,0,-20);
					ofScale(0.25,0.25,0.25);
					ofSetColor(0,0,0,255);
					model_.draw(OF_MESH_POINTS);
					ofPopMatrix();


				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
