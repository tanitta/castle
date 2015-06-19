#pragma once
#ifdef Success
  #undef Success
#endif
#include "Eigen/Core"
#include "grid.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Solver {
				alight::scenes::castle::Grid* grid_ptr_;
				public:
					Solver(){};
					virtual ~Solver(){};
					void set(alight::scenes::castle::Grid& grid_ref){
						grid_ptr_ = &grid_ref;
					};
					void setup(){
						grid_ptr_->setup();
					}
					void update(){
						std::cout<<"--------------------------------"<<std::endl;
						grid_ptr_->update();
					};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
