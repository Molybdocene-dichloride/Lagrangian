#pragma once

#include <multiversion/client/graphics/Icon.hpp>

namespace lagrangian {
	namespace graphics {
		class Icon : public Operable {
			public:
			//Magick::Image image;

			Icon() {}
			//Icon(Magick::Image image) { image = image; }
			//Icon(TextureAtlas* vanilla) : Icon() {}
			//Icon(TextureAtlas* vanilla, int num) : Icon() {}

			void clear() {
				//image.clear();
			}
		};
	}
}