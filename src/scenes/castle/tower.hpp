#pragma one
// #include "ofx3DModelLoader.h"
#include "ofxAssimpModelLoader.h"<`0`>
namespace alight {
	namespace scenes {
		namespace castle {
			class Tower {
				ofxAssimpModelLoader model_;
				public:
					Tower(){};
					
					virtual ~Tower(){};
					void setup(){
						model_.loadModel("scenes/castle/Tower1.obj");
					};
					void draw(){
						model_.draw(OF_MESH_POINTS);
						
					};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
