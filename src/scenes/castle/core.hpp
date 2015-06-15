#pragma once
#include "solver.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Core {
				alight::scenes::castle::Solver solver_;
				public:
					Core(){};
					virtual ~Core(){};
					void setup(){};
					void update(){
						solver_.update();
					};
					void draw(){};
					
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
