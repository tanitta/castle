#pragma once
#include "ofMain.h"
#include "pharticle/pharticle.hpp";

#include "value_box.hpp"
#include "network_gate.hpp"

#include "solver.hpp"
#include "entity.hpp"
#include "entity_renderer.hpp"

#include "cloud.hpp"
#include <thread>
#include "tower.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Core {
				const Eigen::Vector3i mesh_size_;
				const Eigen::Vector3i world_size_;
				
				alight::scenes::castle::Grid grid_;
				alight::scenes::castle::Solver flow_solver_;
				
				std::vector<std::shared_ptr<Entity>> entity_ptrs_;
				EntityRenderer entity_renderer_;
				
				pharticle::Engine particle_solver_;
				std::vector<std::shared_ptr<alight::scenes::castle::Cloud>> cloud_sptrs_;
				std::vector<std::vector<std::vector<double>>> cloud_density_grid_;;
				
				ofEasyCam camera_;
				std::thread thread_;
				int thread_counter_;
				
				std::shared_ptr<Tower> tower_sptr;
				
				variable_controller::ValueBox vb_;
				variable_controller::NetworkGate network_gate_;
				
				public:
				Core():
					network_gate_(vb_),
					mesh_size_(Eigen::Vector3i(120,80,2)),
					world_size_(mesh_size_[0],mesh_size_[1],mesh_size_[2]*10),
					grid_(mesh_size_),
					thread_counter_(0),
					tower_sptr(new Tower),
					cloud_density_grid_(world_size_[0],std::vector<std::vector<double>>(world_size_[1],std::vector<double>(world_size_[2]))){};

				virtual ~Core(){};

				void setup(){
					network_gate_.connect(8090,8080);
					network_gate_.receive();
					
					tower_sptr->setup();
					tower_sptr->particle_.position_<<11.0, 40.0, 0.0;
					entity_renderer_.add_entity(tower_sptr);
					
					Cloud load_image_cloud;
					load_image_cloud.load_images();
					for (int i = 0; i < 1000; i++) {
						std::shared_ptr<Cloud> cloud_sptr(new Cloud);
						
						cloud_sptr->particle_.position_<<ofRandom(0,world_size_[0]-1), ofRandom(0,world_size_[1]-1), ofRandom(0,ofRandom(0,world_size_[2]-1));
						cloud_sptr->image_size_ = ofRandom(1,10);
						cloud_sptr->image_angle_= ofRandom(0,360);
						cloud_sptr->set_camera_ptr(&camera_);
						cloud_sptrs_.push_back(cloud_sptr);
						entity_renderer_.add_entity(cloud_sptr);
					}
					grid_.setup();
					flow_solver_.set(grid_);
					// thread_ = std::thread([=]{this->update_flow();});
				};
				
				void update_flow(){
					while(true){
						flow_solver_.update();
					}
				};
				
				void update(){
					network_gate_.receive();
						flow_solver_.update();
					for (auto&& cloud_sptr : cloud_sptrs_) {
						cloud_sptr->particle_.velocity_ = grid_.cell(cloud_sptr->position_in_mesh()[0],cloud_sptr->position_in_mesh()[1],0).u_*0.5;
						cloud_sptr->particle_.velocity_[1] *= (double)cloud_sptr->position_in_mesh()[2]/(double)world_size_[2]*0.05+0.95;
						cloud_sptr->particle_.velocity_[0] *= (double)cloud_sptr->position_in_mesh()[2]/(double)world_size_[2]*0.05+0.95;
						cloud_sptr->particle_.integrate();
						
						if(cloud_sptr->position_in_mesh()[0]>=world_size_[0]){
							cloud_sptr->particle_.position_[0] = 0.0;
						};
						
						if(cloud_sptr->position_in_mesh()[1]<0||world_size_[1]<=cloud_sptr->position_in_mesh()[1]){
							cloud_sptr->particle_.position_[0] = 0.0;
							cloud_sptr->particle_.position_[1] = ofRandom(0,world_size_[1]-1);
						};
						if(cloud_sptr->position_in_mesh()[2]<0||world_size_[2]<=cloud_sptr->position_in_mesh()[2]){
							cloud_sptr->particle_.position_[0] = 0.0;
							cloud_sptr->particle_.position_[2] =ofRandom(0,ofRandom(0,world_size_[2]-1));
						};
						double z = cloud_sptr->particle_.position_[2];
						cloud_sptr->brightness_ = (float)z/(float)world_size_[2]*90.0 +(256.0-90.0);
					}
					for (auto&& i : cloud_density_grid_) {
						for (auto&& j : i) {
							for (auto&& cloud_density : j) {
								cloud_density = 0.0;
							}
						}
					}
					
					for (auto&& cloud_sptr : cloud_sptrs_) {
						cloud_density_grid_[cloud_sptr->position_in_mesh()[0]][cloud_sptr->position_in_mesh()[1]][cloud_sptr->position_in_mesh()[2]] += cloud_sptr->image_size_;
					}
					tower_sptr->particle_.position_[0] = (float)world_size_[0]*vb_.get_float_ref("midi_control_20");
					tower_sptr->particle_.position_[2] = (float)world_size_[2]*vb_.get_float_ref("midi_control_21");
				};
				
				void draw(){
					camera_.begin();
					ofDrawGrid(10,10,10);
					ofDisableDepthTest();
					entity_renderer_.draw(camera_);
					ofEnableDepthTest();
					
					// grid_.draw();
					camera_.end();
				};
				void keyPressed(int key){
					if(key == 107){
						//++
						grid_.stream_speed_ += 0.01;
					};
					if(key == 106){
						grid_.stream_speed_ -= 0.01;
					};
					std::cout<<"stream_speed"<<grid_.stream_speed_<<std::endl;
				}
				
				void exit(){
					// thread_.join();
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
