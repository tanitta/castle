#pragma once
#ifdef Success
  #undef Success
#endif
#include "Eigen/Core"
namespace alight {
	namespace scenes {
		namespace castle {
			class Cell{
				// std::vector<double> speed_;
				Eigen::Vector3d speed_;
				public:
					Cell(){};
					virtual ~Cell(){
						speed_ << 0,0,0;
					};
					double operator[](const int axis){
						return speed_[axis];
					};
					void update(){};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
