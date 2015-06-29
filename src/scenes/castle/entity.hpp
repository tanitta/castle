#pragma once
#include "ofMain.h"
#include "pharticle/particle.hpp"

namespace alight {
	namespace scenes {
		namespace castle {
			class Entity {
				public:
					pharticle::Particle particle_;
					Entity():particle_(){};
					
					virtual ~Entity(){};
					
					virtual void draw(){};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
