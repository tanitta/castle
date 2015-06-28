#pragma once
#include "ofMain.h"

#include "value_box.hpp"
#include "network_gate.hpp"

#include "solver.hpp"
#include "pharticle/pharticle.hpp";
#include "cloud.hpp"
#include "thread"
#include "tower.hpp"
namespace alight {
	namespace scenes {
		namespace castle {
			class Core {
				const Eigen::Vector3i mesh_size_;
				const Eigen::Vector3i world_size_;
				
				alight::scenes::castle::Grid grid_;
				alight::scenes::castle::Solver flow_solver_;
				
				pharticle::Engine particle_solver_;
				std::vector<alight::scenes::castle::Cloud> clouds_;
				std::vector<std::vector<std::vector<double>>> cloud_density_grid_;;
				
				ofEasyCam camera_;
				std::thread thread_;
				int thread_counter_;
				
				Tower tower_;
				
				variable_controller::ValueBox vb_;
				variable_controller::NetworkGate network_gate_;
				
				public:
				Core():
					network_gate_(vb_),
					mesh_size_(Eigen::Vector3i(120,80,2)),
					world_size_(mesh_size_[0],mesh_size_[1],mesh_size_[2]*10),
					grid_(mesh_size_),
					thread_counter_(0),
					cloud_density_grid_(world_size_[0],std::vector<std::vector<double>>(world_size_[1],std::vector<double>(world_size_[2]))){};

				virtual ~Core(){};

				void setup(){
					network_gate_.connect(8090,8080);
					
					tower_.setup();
					
					Cloud load_image_cloud;
					load_image_cloud.load_images();
					for (int i = 0; i < 6000; i++) {
						Cloud cloud;
						// cloud.setup();
						cloud.particle_.position_<<ofRandom(0,world_size_[0]-1), ofRandom(0,world_size_[1]-1), ofRandom(0,ofRandom(0,world_size_[2]-1));
						cloud.image_size_ = ofRandom(0.5,8);
						cloud.image_angle_= ofRandom(0,360);
						clouds_.push_back(cloud);
					}
					grid_.setup();
					flow_solver_.set(grid_);
					thread_ = std::thread([=]{this->update_flow();});
				};
				void update_flow(){
					while(true){
						flow_solver_.update();
					}
				};
				
				void update(){
					network_gate_.receive();
					
					for (auto&& cloud : clouds_) {
						cloud.particle_.velocity_ = grid_.cell(cloud.position_in_mesh()[0],cloud.position_in_mesh()[1],0).u_*0.5;
						cloud.particle_.velocity_[1] *= (double)cloud.position_in_mesh()[2]/(double)world_size_[2]*0.05+0.95;
						cloud.particle_.velocity_[0] *= (double)cloud.position_in_mesh()[2]/(double)world_size_[2]*0.05+0.95;
						cloud.particle_.integrate();
						
						if(cloud.position_in_mesh()[0]>=world_size_[0]){
							cloud.particle_.position_[0] = 0.0;
						};
						
						if(cloud.position_in_mesh()[1]<0||world_size_[1]<=cloud.position_in_mesh()[1]){
							cloud.particle_.position_[0] = 0.0;
							cloud.particle_.position_[1] = ofRandom(0,world_size_[1]-1);
						};
						if(cloud.position_in_mesh()[2]<0||world_size_[2]<=cloud.position_in_mesh()[2]){
							cloud.particle_.position_[0] = 0.0;
							cloud.particle_.position_[2] =ofRandom(0,ofRandom(0,world_size_[2]-1));
						};
					}
					for (auto&& i : cloud_density_grid_) {
						for (auto&& j : i) {
							for (auto&& cloud_density : j) {
								cloud_density = 0.0;
							}
						}
					}
					
					for (auto&& cloud : clouds_) {
						cloud_density_grid_[cloud.position_in_mesh()[0]][cloud.position_in_mesh()[1]][cloud.position_in_mesh()[2]] += cloud.image_size_;
					}
					// if(thread_counter_ == 0){
					// 	thread_counter_ = 0;
					// 	thread_.join();
					// 	thread_ = std::thread(update_flow);
					// };
					// thread_counter_++;
				};
				
				void sort_clouds(){
					ofVec3f camera_position = camera_.getPosition();
					std::sort(clouds_.begin(),clouds_.end(),[=](Cloud& a, Cloud& b)->bool{
							ofVec3f cloud_position_a(a.particle_.position_[0],a.particle_.position_[1],a.particle_.position_[2]);
							ofVec3f cloud_position_b(b.particle_.position_[0],b.particle_.position_[1],b.particle_.position_[2]);
							float distance_a = camera_position.distance(cloud_position_a);
							float distance_b = camera_position.distance(cloud_position_b);
							return distance_a>distance_b;
							});
				}
				
				void draw(){
					camera_.begin();
					ofDisableDepthTest();
					sort_clouds();
					for (auto&& cloud : clouds_) {
						int x_i = cloud.position_in_mesh()[0];
						int y_i = cloud.position_in_mesh()[1];
						int z_i = cloud.position_in_mesh()[2];
						
						double shading_rate = 0.0;//cloud_density_grid_[x_i][y_i][z_i];
						for (int h = z_i+1; h < world_size_[2]; h++) {
							shading_rate += cloud_density_grid_[x_i][y_i][h]*(1.0-(double)(h-z_i-1)/(double)(world_size_[2]-1-z_i-1));
						}
						shading_rate = shading_rate/10;
						double x = cloud.particle_.position_[0];
						double y = cloud.particle_.position_[1];
						double z = cloud.particle_.position_[2];
						ofSetColor(ofColor::fromHsb(0,0,(float)z/(float)world_size_[2]*60 +(256.0-90.0),90));
						// ofSetColor(ofColor::fromHsb(0,0,255.0 - shading_rate*255.0));
						double brightness = 255.0 - shading_rate*255.0;
						cloud.close_brightness_to(brightness,1);
						ofPushMatrix();
						ofTranslate(x*0.5,y*0.5,z*0.5);
						cloud.draw(camera_);
						ofPopMatrix();
					}
					ofEnableDepthTest();
					
					ofPushMatrix();
					ofTranslate(11,40,-40);
					ofScale(0.25,0.25,0.25);
					ofSetColor(0,0,0,255);
					tower_.draw();
					ofPopMatrix();
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
					thread_.join();
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
