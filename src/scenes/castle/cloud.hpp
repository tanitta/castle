#pragma once
#include "pharticle/pharticle.hpp";
namespace alight {
	namespace scenes {
		namespace castle {
			class Cloud {
				public:
					pharticle::Particle particle_;
					Cloud():particle_(){};
					virtual ~Cloud(){};
			};
		} // namespace castle
	} // namespace scenes
} // namespace alight
