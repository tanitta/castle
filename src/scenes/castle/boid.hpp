#pragma once
#include "Eigen/Core"
#include "entity.hpp"

namespace alight {
	namespace scenes {
		namespace castle {
			class Boid : public alight::scenes::castle::Entity{
				Eigen::Vector3d direction_;
				
				ofxAssimpModelLoader model_;
				
				public:
				Boid():direction_(0,0,0){};
				
				virtual ~Boid(){};

				void setup(){
					model_.loadModel("scenes/castle/2x2x2cube.obj");
				};
				
				void draw(){
					ofSetColor(128,32,0,255);
					ofMesh mesh = model_.getCurrentAnimatedMesh(0);
					mesh.drawWireframe();
					for (auto&& vertex : mesh.getVertices()) {
						ofDrawIcoSphere(vertex,1.0);
					}
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace aligh
