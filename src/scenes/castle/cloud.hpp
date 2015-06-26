#pragma once
#include "ofMain.h";
#include "pharticle/pharticle.hpp";
#include "Eigen/Core";
#include <ofxBillboard.h>
namespace alight {
	namespace scenes {
		namespace castle {
			class Cloud {
				public:
					static ofImage image_2_;
					static ofImage image_3_;
					static ofImage image_4_;
					int image_index_;
					double image_angle_;
					double image_size_;
					double brightness_;
					pharticle::Particle particle_;
					
					Cloud():particle_(),image_size_(1),image_angle_(0),brightness_(0){};
					
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
					
					void close_brightness_to(double target_brightness, double rate){
						if(brightness_-rate<target_brightness && brightness_-target_brightness>-rate){
							brightness_ = target_brightness;
						}else if(brightness_<target_brightness){
							brightness_+=rate;
						}else if(brightness_>target_brightness){
							brightness_-=rate;
						};
					}
						
					void draw(ofEasyCam& camera){
						// ofSetColor(ofColor::fromHsb(0,0,brightness_,90));
						// ofDrawIcoSphere(0,0,0,0.3);
						ofVec3f position(particle_.position_[0],particle_.position_[1],particle_.position_[2]);
						ofxBillboardBeginSpherical(camera.getPosition(),position);
						ofPushMatrix();
						ofScale(0.01*image_size_,0.01*image_size_,0.01*image_size_);
						ofRotate(image_angle_,0,0,1);
						ofTranslate(-256,-256,0);
						image_2_.draw(0,0);
						ofPopMatrix();
						ofxBillboardEnd();
					};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
