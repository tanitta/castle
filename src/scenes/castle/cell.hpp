#pragma once
#ifdef Success
#undef Success
#endif
#include "Eigen/Core"
#include "ofMain.h"
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
					return weight_[i] * rho_ * (1 + 3 * c_[i].dot(u_) - 3.0/2.0 * u2 + 9.0/2.0 * c_[i].dot(u_)*c_[i].dot(u_));
				};

				void update_collision(){
					//局所平衡分布関数を求める
					for (int i = 0; i < 15; i++) {
						f0_[i] = f_eq(i);
					}
				};
				
				public:
				
				std::array<double,15> f_{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				std::array<double,15> f0_{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				Eigen::Vector3d u_;

				double rho_;
				const double tau_;
				const std::array<Eigen::Vector3d,15> c_{
					Eigen::Vector3d(0,0,0),
						Eigen::Vector3d(1,0,0),
						Eigen::Vector3d(0,1,0),
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

				Cell():rho_(10.0),tau_(1.0),u_(50,0,0){
					// u_ << 0,0,0;
					std::cout<< "Cell initialized" << std::endl;
				};
				virtual ~Cell(){
				};
				double operator[](const int& num){
					return f_[num];
				};

				//格子ボルツマン方程式を更新する
				void update_f(){
					update_collision();
					for (int i = 0; i < 15; i++) {
						f_[i] = f_[i] - (f_[i] - f0_[i])/tau_;
					}
				};

				//力をfに適応する
				void adapt_force_to_f(const Eigen::Vector3d& force){
					for (int i = 0; i < 15; i++) {
						f_[i] = f_[i]  + rho_* c_[i].dot(force);
					}
				};

				//拡散?
				void update_diffuse(const int& i, const Cell& near_cell){
					f_[i] = near_cell.f_[i];
				};
				
				//流れの更新
				void update_streaming(){
					//密度の更新
					rho_ = std::accumulate(f_.begin(), f_.end(), 0);
					
					//流速の更新
					for (int i = 0; i < 15; i++) {
						u_ += f_[i]*c_[i];
					}
					
					if(rho_ != 0.0){
						u_ = u_/rho_;
					}else{
						u_ << 0.0,0.0,0.0;
					}
				};

				void draw(){
					ofSetColor(0);
					ofDrawIcoSphere(0,0,0,1);

					ofSetColor(255);
					ofDrawLine(0,0,0,u_[0],u_[1],u_[2]);
					ofDrawIcoSphere(u_[0],u_[1],u_[2],0.5);
					// ofDrawLine(0,0,0,speed_[0],speed_[1],speed_[2]);
					// ofDrawLine(0,0,0,speed_[3],speed_[4],speed_[5]);


				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
