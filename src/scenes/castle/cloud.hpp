#pragma once
#include "ofMain.h"
#include "pharticle/pharticle.hpp"
#include "Eigen/Core"
#include "entity.hpp"

namespace alight {
	namespace scenes {
		namespace castle {
			class Cloud : public Entity{
					ofCamera* camera_ptr_;
				public:
					static ofImage image_2_;
					static ofImage image_3_;
					static ofImage image_4_;
					int image_index_;
					double image_angle_;
					double image_size_;
					double brightness_;
					
					Cloud():image_size_(1),image_angle_(0),brightness_(0){};
					
					virtual ~Cloud(){};
					
					Eigen::Vector3i position_in_mesh(){
						Eigen::Vector3i p;
						for (int i = 0; i < 3; i++) {
							p[i] = std::round(particle_.position_[i]);
						}
						return p;
					};
					
					void load_images(){
						image_2_.loadImage("scenes/castle/cloud2.png");
						// image_2_.loadImage("scenes/castle/cloud2.png");
						// image_2_.loadImage("scenes/castle/cloud2.png");
					};
					
					// void close_brightness_to(double target_brightness, double rate){
					// 	if(brightness_-rate<target_brightness && brightness_-target_brightness>-rate){
					// 		brightness_ = target_brightness;
					// 	}else if(brightness_<target_brightness){
					// 		brightness_+=rate;
					// 	}else if(brightness_>target_brightness){
					// 		brightness_-=rate;
					// 	};
					// }
					
					void set_camera_ptr(ofEasyCam* camera_ptr){
						camera_ptr_ = camera_ptr;
					};
					
						
					void draw(){
						ofVec3f camera_position = camera_ptr_->getPosition();
						ofVec3f camera_direction_from_particle = camera_position - ofVec3f(particle_.position_[0],particle_.position_[1],particle_.position_[2]);
						double theta_z = std::atan2(camera_direction_from_particle[0],camera_direction_from_particle[1]);
						double distance_of_camera_and_particle_in_xy_plane = std::sqrt(
								std::pow( camera_direction_from_particle[0],2 )+
								std::pow( camera_direction_from_particle[1],2 )
								);
						double theta_x = std::atan2(camera_direction_from_particle[2],distance_of_camera_and_particle_in_xy_plane);
						
						ofSetColor(ofColor::fromHsb(0,0,brightness_,90));
						std::cout<<brightness_<<std::endl;
						// ofSetColor(ofColor::fromHsb(0,0,255,90));
						// ofDrawIcoSphere(0,0,0,1);
						ofVec3f position(particle_.position_[0],particle_.position_[1],particle_.position_[2]);
						ofPushMatrix();
							ofRotate(ofRadToDeg(-theta_z),0,0,1);
							ofRotate(ofRadToDeg(theta_x),1,0,0);
							ofScale(0.004*image_size_,0.004*image_size_,0.004*image_size_);
							ofRotate(90,1,0,0);
							ofRotate(image_angle_,0,0,1);
							ofTranslate(-256,-256,0);
							image_2_.draw(0,0);
						ofPopMatrix();
					};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
