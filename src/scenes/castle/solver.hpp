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
				Eigen::Vector3i field_size_;
				public:
					Solver(){field_size_<< 20, 20, 20;};
					virtual ~Solver(){};
					void set(alight::scenes::castle::Grid& grid_ref){
					};
					void update(){};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
