#pragma once
#include "entity.hpp"
#include "cloud.hpp"

namespace alight {
	namespace scenes {
		namespace castle {
			class EntityRenderer {
				std::vector<std::shared_ptr<Entity>> entity_sptrs_;
				std::vector<std::shared_ptr<Entity>> semi_transparent_entity_sptrs_;
				std::vector<std::shared_ptr<Entity>> opacity_entity_sptrs_;


				void sort(const ofCamera& camera){
					ofVec3f camera_position = camera.getPosition();
					std::sort(semi_transparent_entity_sptrs_.begin(),semi_transparent_entity_sptrs_.end(),[=](std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b)->bool{
							ofVec3f entity_position_a(a->particle_.position_[0],a->particle_.position_[1],a->particle_.position_[2]);
							ofVec3f entity_position_b(b->particle_.position_[0],b->particle_.position_[1],b->particle_.position_[2]);
							float distance_a = camera_position.distance(entity_position_a);
							float distance_b = camera_position.distance(entity_position_b);
							return distance_a>distance_b;
							});
				};

				void distribute_entity(){
					for (auto&& entity_sptr : entity_sptrs_) {
						if(typeid(*entity_sptr) == typeid(Cloud)){
							semi_transparent_entity_sptrs_.push_back(entity_sptr);
						}else{
							opacity_entity_sptrs_.push_back(entity_sptr);
						}
					}
				};
				
				public:
				EntityRenderer(){};

				virtual ~EntityRenderer(){};

				void add_entity(std::shared_ptr<Entity> entity_sptr){
					entity_sptrs_.push_back(entity_sptr);
				};

				void setup(){
					distribute_entity();
				};

				void draw(const ofCamera& camera){
					// opacity_entity
					for (auto&& entity_sptr : opacity_entity_sptrs_) {
						double x = entity_sptr->particle_.position_[0];
						double y = entity_sptr->particle_.position_[1];
						double z = entity_sptr->particle_.position_[2];
						ofPushMatrix();
						ofTranslate(x,y,z);
						entity_sptr->draw();
						ofPopMatrix();
					}

					//semi_transparent_entity
					sort(camera);
					glDepthMask(GL_FALSE);
					for (auto&& entity_sptr : semi_transparent_entity_sptrs_) {
						double x = entity_sptr->particle_.position_[0];
						double y = entity_sptr->particle_.position_[1];
						double z = entity_sptr->particle_.position_[2];
						ofPushMatrix();
						ofTranslate(x,y,z);
						entity_sptr->draw();
						ofPopMatrix();
					}
					glDepthMask(GL_TRUE);
					// entity_sptrs_.clear();
				};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
