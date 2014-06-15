#include "../scenes/BaseScene.hpp"
#include "../scenes/VoidScene.hpp"
namespace alight{
namespace frame{
	class SceneContainer
	{
	public:
		int trackNumberA;
		int trackNumberB;
		alight::scenes::BaseScene* scenes[12];

		SceneContainer():trackNumberA(0),trackNumberB(0){
			for (int i = 0; i < 12; ++i){
				scenes[i] = new alight::scenes::VoidScene();
			}
		};
		~SceneContainer(){};
	
		void setup(){
			for (int i = 0; i < 12; ++i){
				scenes[i]->setup();
			}
		};
		void update(){
			scenes[trackNumberA]->update();
			scenes[trackNumberB]->update();
		};
		void draw(){
			scenes[trackNumberA]->draw();
			scenes[trackNumberB]->draw();
		};
	};
}
}