#pragma once
#include "ofMain.h"
#include "solver.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Core {
				alight::scenes::castle::Solver solver_;
				alight::scenes::castle::Grid grid_;
				ofEasyCam camera_;
				public:
					Core():grid_(Eigen::Vector3i(10,3,3)){};
					virtual ~Core(){};
					void setup(){
						solver_.set(grid_);
					};
					void update(){
						solver_.update();
					};
					void draw(){
						camera_.begin();
							ofDrawGrid(100,100,100);
							grid_.draw();
						camera_.end();
					};
					
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
