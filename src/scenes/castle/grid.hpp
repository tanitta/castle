#pragma once
#ifdef Success
#undef Success
#endif
#include "Eigen/Core"
#include "cell.hpp"
#include "ofMain.h"
namespace alight {
	namespace scenes {
		namespace castle {
			class Grid {
				std::vector<std::vector<std::vector<alight::scenes::castle::Cell>>> cells_;
				public:
				Grid(const Eigen::Vector3i& size):
					cells_(size[0],std::vector<std::vector<alight::scenes::castle::Cell>>(size[1],std::vector<alight::scenes::castle::Cell>(size[2]))){
						// cells_(20,std::vector<std::vector<alight::scenes::castle::Cell>>(20,std::vector<alight::scenes::castle::Cell>(20))){
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

					alight::scenes::castle::Cell& cell(const int& x, const int& y, const int& z){
						return cell(Eigen::Vector3i(x ,y, z));
					}
					void update_boundary_condition(){
						// xz
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[2]; j++) {
								// cell(i, 0, j)[1] = -cell(i, 1, j)[4];
								// cell(i, size()[1]-1, j)[4] = -cell(i, size()[1]-2, j)[1];
							}
						}

						// xy
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								// cell(i, j, 0)[2] = -cell(i, j, 1)[5];
								// cell(i, j,size()[2]-1)[5] = -cell(i, j, size()[2]-2)[2];
							}
						}
					}

					void update_collision(){

					};
					void setup(){
						// cell(4,1,1).u_[0] = -10.0;
					};

					void update(){
						// cell(2,1,1).rho_ = 1000;
						// cell(4,1,1).adapt_force_to_f(Eigen::Vector3d(50,0,0));
						// cell(4,1,1).rho_ = 1.0;
						// int i = ofRandom(1,size()[0]-1);
						// int j = ofRandom(1,size()[1]-1);
						// int k = ofRandom(1,size()[2]-1);
						// 
						for (int i = 1; i < size()[0]-1; i++) {
							for (int j = 1; j < size()[1]-1; j++) {
								for (int k = 1; k < size()[2]-1; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.update_f();
								}
							}
						}
						for (int i = 1; i < size()[0]-1; i++) {
							for (int j = 1; j < size()[1]-1; j++) {
								for (int k = 1; k < size()[2]-1; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									// 近傍を取得
									for (int n = 1; n < 15; n++) {
										alight::scenes::castle::Cell& cell_near_ref =cell(Eigen::Vector3i(i,j,k) + cell_ref.c_[n].cast<int>());
										cell_near_ref.f_[n] = cell_ref.f_[n];
									}
								}
							}
						}
						for (int i = 1; i < size()[0]-1; i++) {
							for (int j = 1; j < size()[1]-1; j++) {
								for (int k = 1; k < size()[2]-1; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.update_streaming();
								}
							}
						}
						update_boundary_condition();
						std::cout<<cell(5,1,1).u_[0]<<std::endl;
					};
					void draw(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									ofPushMatrix();
									ofTranslate(i*50,j*50,k*50);
									cell(i,j,k).draw();
									ofPopMatrix();
								}
							}
						}
					};
					};
			} // namespace castle
		} // namespace scenes
	} // namespace alight
