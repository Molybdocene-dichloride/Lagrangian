#pragma once

#include <multiversion/client/graphics/Operable.hpp>

class TextureAtlas;
class Texture;

namespace lagrangian {
	namespace graphics {
		class Icon : public Operable {
			public:
			//Magick::Image image;
			Icon() {}
			//Icon() : Icon(Magick::Image) { image = image; }
			//Icon(TextureAtlas* vanilla) : Icon() {}
			//Icon(TextureAtlas* vanilla, int num) : Icon() {}

			/*void clear() {
				image.clear();
			}*/

			void reload();
		};
	}
}