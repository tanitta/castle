#pragma once
#ifdef Success
#undef Success
#endif
#include "Eigen/Core"
#include "cell.hpp"
#include "ofMain.h"
#include "cell_type.hpp";
namespace alight {
	namespace scenes {
		namespace castle {
			class Grid {
				std::vector<std::vector<std::vector<alight::scenes::castle::Cell>>> cells_;
				public:
				double max_vorticity_;
				double stream_speed_;
				Grid(const Eigen::Vector3i& size):
					max_vorticity_(0.0),
					stream_speed_(0.3),
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
						Eigen::Vector3i point;
						Eigen::Vector3i tmp;
						for (int i = 0; i < 3; i++) {
							if(coordinate[i]<0){
								tmp[i] = (coordinate[i]+1)%(size()[i]);
								point[i] = size()[i]+(tmp[i])-1;
							}else if(size()[i]-1 < coordinate[i]){
								tmp[i] = coordinate[i]%(size()[i]);
								point[i] = tmp[i];
							}else{
								point[i] = coordinate[i];
							};
						}
						return cells_[point[0]][point[1]][point[2]];
					}

					alight::scenes::castle::Cell& cell(const int& x, const int& y, const int& z){
						return cell(Eigen::Vector3i(x ,y, z));
					}
					void set_box_boudary_condition(const Eigen::Vector3i& p1, const Eigen::Vector3i& p2){
						set_box_boudary_condition(p1[0],p1[1],p1[2],p2[0],p2[1],p2[2]);
					}
					
					void set_box_boudary_condition(const int& x1,const int& y1,const int& z1,const int& x2,const int& y2,const int& z2){
						// cell(x1, -2, -2).set_boudary_condition(CellType::BounceBack,4);
						// //yz
						for (int j = y1+1; j < y2; j++) {
							for (int k = z1+1; k < z2; k++) {
								cell(x1, j, k).set_boudary_condition(CellType::BounceBack,1);
								cell(x2, j, k).set_boudary_condition(CellType::BounceBack,4);
							}
						}
						//zx
						for (int k = z1+1; k < z2; k++) {
							for (int i = x1+1; i < x2; i++) {
								cell(i, y1, k).set_boudary_condition(CellType::BounceBack,2);
								cell(i, y2, k).set_boudary_condition(CellType::BounceBack,5);
							}
						}
						//xy
						for (int i = x1+1; i < x2; i++) {
							for (int j = y1+1; j < y2; j++) {
								cell(i, j, z1).set_boudary_condition(CellType::BounceBack,3);
								cell(i, j, z2).set_boudary_condition(CellType::BounceBack,6);
							}
						}
						
						// cell(x2, y2, z2).set_boudary_condition(CellType::BounceBack,11);
						// cell(x1, y2, z2).set_boudary_condition(CellType::BounceBack,12);
						// cell(x2, y1, z2).set_boudary_condition(CellType::BounceBack,13);
						// cell(x2, y2, z1).set_boudary_condition(CellType::BounceBack,14);
						//
						// cell(x1, y1, z1).set_boudary_condition(CellType::BounceBack,7);
						// cell(x2, y1, z1).set_boudary_condition(CellType::BounceBack,8);
						// cell(x1, y2, z1).set_boudary_condition(CellType::BounceBack,8);
						// cell(x1, y1, z2).set_boudary_condition(CellType::BounceBack,8);
					};
					
					void update_boundary_condition(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									cell(i, j, k).update_boundary_condition();
								}
							}
						}
					}
					void update_collision(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.update_f();
								}
							}
						}

					};

					void update_streaming(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									cell(i,j,k).update_f_tmp();
								}
							}
						}
						max_vorticity_ = 0.0;
						for (int i = 0; i < size()[0]-0; i++) {
							for (int j = 0; j < size()[1]-0; j++) {
								for (int k = 0; k < size()[2]-0; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.vorticity_ = 0.0;
									for (int n = 1; n < 15; n++) {
										Eigen::Vector3i near_cell_pos = Eigen::Vector3i(i,j,k) + cell_ref.c_[n].cast<int>();
											alight::scenes::castle::Cell& cell_near_ref = cell(near_cell_pos);
											cell_ref.update_diffuse(n,cell_near_ref);
									};
									cell_ref.vorticity_ += cell(i-1,j,k).u_[1];
									cell_ref.vorticity_ -= cell(i+1,j,k).u_[1];
									cell_ref.vorticity_ -= cell(i,j-1,k).u_[0];
									cell_ref.vorticity_ += cell(i,j+1,k).u_[0];
									if(cell_ref.vorticity_<0)cell_ref.vorticity_=-cell_ref.vorticity_;
									if(cell_ref.vorticity_ > max_vorticity_)max_vorticity_ = cell_ref.vorticity_;
								}
							}
						}

						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									alight::scenes::castle::Cell& cell_ref = cell(Eigen::Vector3i(i,j,k));
									cell_ref.update_streaming();
								}
							}
						}
					};

					void setup(){
						set_box_boudary_condition(Eigen::Vector3i(7,size()[1]/2-5,size()[2]/2-6),Eigen::Vector3i(8,size()[1]/2+5,size()[2]/2+6));
						// set_box_boudary_condition(Eigen::Vector3i(2,2,-7),Eigen::Vector3i(6,6,6));
					};

					void update(){
						// for (int i = 0; i < size()[0]; i++) {
						// 	for (int j = 0; j < size()[1]; j++) {
						// 		for (int k = 0; k < size()[2]; k++) {
						// 			cell(i,j,k).add_force_to_f(Eigen::Vector3d(0.00001,0.0,0.0));
						// 		}
						// 	}
						// }
						
						for (int j = 0; j < size()[1]; j++) {
							for (int k = 0; k < size()[2]; k++) {
								cell(1,j,k).add_stream_to_f(Eigen::Vector3d(stream_speed_,0.0,0.0),1);
							}
						}
								cell(2,20,size()[2]/2).add_stream_to_f(Eigen::Vector3d(0.0,0.10,0.0),1);

						update_collision();
						update_boundary_condition();
						update_streaming();
					};
					void draw(){
						for (int i = 0; i < size()[0]; i++) {
							for (int j = 0; j < size()[1]; j++) {
								for (int k = 0; k < size()[2]; k++) {
									// ofSetColor((float)k/(float)size()[2]*255.0*2);
									if(max_vorticity_!=0.0){
										float g = cell(i,j,k).vorticity_/max_vorticity_*255*4;
										if(g>255)g=255;
										ofSetColor(g);
									}else{
										ofSetColor(0);
									};
									ofPushMatrix();
									ofTranslate(i,j,k);
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
