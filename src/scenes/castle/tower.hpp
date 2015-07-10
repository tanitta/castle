#pragma one
#include "pharticle/pharticle.hpp"
#include "ofxAssimpModelLoader.h"
#include "entity.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Tower : public alight::scenes::castle::Entity{
				ofxAssimpModelLoader model_;
				public:
				Tower(){};

				virtual ~Tower(){};
				
				void setup(){
					model_.loadModel("scenes/castle/Tower1.obj");
				};
				
				void draw(){
					ofPushMatrix();
					ofTranslate(0,0,-10);
					ofScale(0.25,0.25,0.25);
					ofSetColor(250,252,255,255);
					ofMesh mesh = model_.getCurrentAnimatedMesh(0);
					
					ofMesh mesh_face =  mesh;
					mesh_face.removeIndex(5);
					mesh_face.removeIndex(6);
					mesh_face.drawFaces();
					
					ofSetColor(ofColor::fromHsb(0,0,128));
					mesh.drawWireframe();
					for (auto&& vertex : mesh.getVertices()) {
						ofDrawIcoSphere(vertex,1.0);
					}
					ofPopMatrix();
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
