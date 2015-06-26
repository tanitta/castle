#pragma once
#ifdef Success
#undef Success
#endif
#include "Eigen/Core"
#include "ofMain.h"
#include "cell_type.hpp";
namespace alight {
	namespace scenes {
		namespace castle {
			class Cell{
				//任意方向成分の局所平衡分布関数を求める
				double f_eq(const int& i){
					//速度ベクトルの2乗
					double u2 = u_.dot(u_);
					// double f_equa = weight_[i] * rho_ * (1 + 3 * c_[i].dot(u_) - 3.0/2.0 * u2 + 9.0/2.0 * c_[i].dot(u_)*c_[i].dot(u_));
					// return f_equa;
					return weight_[i] * rho_ * (1.0 + 3.0 * c_[i].dot(u_) - 3.0/2.0 * u2 + 9.0/2.0 * c_[i].dot(u_)*c_[i].dot(u_));
				};

				void update_collision(){
					//局所平衡分布関数を求める
					for (int i = 0; i < 15; i++) {
						f0_[i] = f_eq(i);
					}
				};
				
				CellType type_;
				int wall_way_;
				public:
				
				std::array<double,15> f_{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				std::array<double,15> f_tmp_{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				std::array<double,15> f0_{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				Eigen::Vector3d u_;

				double rho_;
				const double tau_;
				double vorticity_;
				const std::array<Eigen::Vector3d,15> c_{
					Eigen::Vector3d(0.0,0.0,0.0),
						Eigen::Vector3d(1.0,0.0,0.0),
						Eigen::Vector3d(0.0,1.0,0.0),
						Eigen::Vector3d(0,0,1),
						Eigen::Vector3d(-1,0,0),
						Eigen::Vector3d(0,-1,0),
						Eigen::Vector3d(0,0,-1),
						Eigen::Vector3d(1,1,1),//7
						Eigen::Vector3d(-1,1,1),
						Eigen::Vector3d(1,-1,1),
						Eigen::Vector3d(1,1,-1),
						Eigen::Vector3d(-1,-1,-1),//11
						Eigen::Vector3d(1,-1,-1),
						Eigen::Vector3d(-1,1,-1),
						Eigen::Vector3d(-1,-1,1),
				};
				const std::array<double,15> weight_{
					2.0/9.0,//0
						1.0/9.0,//1
						1.0/9.0,
						1.0/9.0,
						1.0/9.0,
						1.0/9.0,
						1.0/9.0,
						1.0/72.0,//7
						1.0/72.0,
						1.0/72.0,
						1.0/72.0,
						1.0/72.0,
						1.0/72.0,
						1.0/72.0,
						1.0/72.0,
				};

				Cell():
					vorticity_(0.0),
					type_(CellType::Fluid),
					wall_way_(1),
					rho_(1.0),
					tau_(0.8),
					u_(0,0,0)
				{
					std::cout<< "Cell initialized" << std::endl;
				};
				
				virtual ~Cell(){};
				
				//格子ボルツマン方程式を更新する
				void update_f(){
					update_collision();
					for (int i = 0; i < 15; i++) {
						f_[i] = f_[i] - (f_[i] - f0_[i])/tau_;
					}
				};

				//力をfに適応する
				void add_force_to_f(const Eigen::Vector3d& force){
					for (int i = 0; i < 15; i++) {
						f_[i] = f_[i]  + rho_* c_[i].dot(force)/6;
					}
				};
				void add_stream_to_f(const Eigen::Vector3d& speed, const double& gain){
					Eigen::Vector3d force = -(speed - u_);
					for (int i = 0; i < 15; i++) {
						f_[i] = f_[i]  + rho_* c_[i].dot(force)/6;
					}
				}

				//拡散?
				void update_diffuse(const int& i, const Cell& near_cell){
					int index_inv = get_way_index_reflected_point(i);
					f_[index_inv] = near_cell.f_tmp_[index_inv];
				};
				
				//流れの更新
				void update_streaming(){
					//密度の更新
					rho_ = std::accumulate(f_.begin(), f_.end(), 0.0);
					//流速の更新
					u_ << 0.0, 0.0, 0.0;
					for (int i = 0; i < 15; i++) {
						u_ += f_[i]*c_[i];
					}
					
					if(rho_ != 0.0){
						u_ = u_/rho_;
					}else{
						u_ << 0.0,0.0,0.0;
					}
				};
				
				void update_f_tmp(){
					f_tmp_ = f_;
				};

				void set_boudary_condition(const CellType& type, const int& wall_way){
					type_ = type;
					wall_way_ = wall_way;
				};
				
				void update_boundary_condition(){
					if(type_ == CellType::ZouHeBound){
						update_zou_he_boundary_condition();
					}else if(type_ == CellType::BounceBack){
						update_bounce_back_boundary_condition();
					};
				};
				
				int get_way_index_reflected_point(const int i)const{
					int index_inv = 0;
					index_inv = (i == 1?4:index_inv);
					index_inv = (i == 2?5:index_inv);
					index_inv = (i == 3?6:index_inv);
					index_inv = (i == 4?1:index_inv);
					index_inv = (i == 5?2:index_inv);
					index_inv = (i == 6?3:index_inv);
					index_inv = (i == 7?11:index_inv);
					index_inv = (i == 8?12:index_inv);
					index_inv = (i == 9?13:index_inv);
					index_inv = (i == 10?14:index_inv);
					index_inv = (i == 11?7:index_inv);
					index_inv = (i == 12?8:index_inv);
					index_inv = (i == 13?9:index_inv);
					index_inv = (i == 14?10:index_inv);
					return index_inv;
				}
				private:
				void update_bounce_back_boundary_condition(){
					std::vector<int> indexs = f_indexs_filted_by([=](int i){
							return c_[wall_way_].dot(c_[i]) < 0.0;}
							);
					
					for (int i = 0; i < indexs.size(); i++) {
						f_[indexs[i]] = f_[get_way_index_reflected_point(indexs[i])];
					}
					
				}
				
				void update_slip_boundary_condition(){
				}
				
				void update_zou_he_boundary_condition(){
					double u = c_[wall_way_].dot(u_);
					// double rho = 1.0/(1.0-u);
				};
				
				// std::vector<int> get_near_direction_f_index_on_c(const int& index){
				//	
				// };
				//
				std::vector<int> f_indexs_filted_by(std::function<bool(int)> condition){
					std::vector<int>v;
					for (int i = 0; i < 15; i++) {
						
						if(condition(i)){
							v.push_back(i);
						};
					}
					return v;
				}
					
				public:
				void draw(){
					double scale = 10;
					if(type_ == CellType::Fluid){;
						ofDrawIcoSphere(u_[0]*scale,u_[1]*scale,u_[2]*scale,0.1);
						// ofDrawLine(
						// 		u_[0]*scale,u_[1]*scale,u_[2]*scale,
						// 		u_[0]*scale*0.7,u_[1]*scale*0.7,u_[2]*scale*0.7);
						ofDrawLine(
								u_[0]*scale,u_[1]*scale,u_[2]*scale,
								0,0,0);
					}else{
						ofDrawIcoSphere(0,0,0,0.5);
					}
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
