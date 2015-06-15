#pragma once
#ifdef Success
  #undef Success
#endif
#include "Eigen/Core"
#include "cell.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Grid {
				std::vector<std::vector<std::vector<alight::scenes::castle::Cell>>> cells_;
				public:
					Grid(const Eigen::Vector3i& size):cells_(size[0],std::vector<std::vector<Cell>>(size[1],std::vector<Cell>(size[2]))){
					};
					virtual ~Grid(){};
					
					int dimention()const{
						return 3;
					};
					
					Eigen::Vector3i size(){
						return Eigen::Vector3i(cells_.size(),cells_[0].size(),cells_[0][0].size());
					};
					
					alight::scenes::castle::Cell& cell(const Eigen::Vector3i& coordinate){
						return cells_[coordinate[0]][coordinate[1]][coordinate[2]];
					}
					
					void update(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.update();
								}
							}
						}
					};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
