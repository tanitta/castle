#pragma once
#include "ofMain.h"
#include "solver.hpp"
#include "pharticle/pharticle.hpp";
#include <cloud.hpp>
namespace alight {
	namespace scenes {
		namespace castle {
			class Core {
				const Eigen::Vector3i mesh_size_;
				
				alight::scenes::castle::Grid grid_;
				alight::scenes::castle::Solver flow_solver_;
				
				pharticle::Engine particle_solver_;
				std::vector<alight::scenes::castle::Cloud> clouds_;
				
				ofEasyCam camera_;

				public:
				Core():
					mesh_size_(Eigen::Vector3i(120,80,2)),
					grid_(Eigen::Vector3i(120,80,2)){};

				virtual ~Core(){};

				void setup(){
					for (int i = 0; i < 10; i++) {
						// Cloud cloud;
						// cloud.particle_.position_<<0.0, ofRandom(0,mesh_size_[1]-1), ofRandom(0,mesh_size_[2]-1);
						// clouds_.push_back(Cloud());
					}
					grid_.setup();
					flow_solver_.set(grid_);
				};
				void update(){
					flow_solver_.update();
				};
				void draw(){
					camera_.begin();
					// ofDrawGrid(100,100,100);
					grid_.draw();
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
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
