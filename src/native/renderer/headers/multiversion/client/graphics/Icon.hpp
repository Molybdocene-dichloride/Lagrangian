#pragma once

#include <multiversion/client/graphics/Operable.hpp>

class TextureAtlas;
class Texture;

namespace lagrangian {
	namespace graphics {
		class Icon : public Operable {
			TextureAtlas* _vanilla;
			//std::__ndk1::vector<Magick::Image> ts;
			Icon() {}
			Icon(TextureAtlas* vanilla) : Icon() {
				_vanilla = vanilla;
			}

			/*void add(Magick::Image t) {
				ts.push_back(t);
			}*/
			/*void clear() {
				ts.clear();
			}*/

			void reload();

			void postInit() {
				//TextureAtlas* vanilla = new TextureAtlas();
				//_vanilla = vanilla;
				//Texture tx = new Texture();
				//_vanilla.push tx
			}
			void postInit(TextureAtlas* vanilla) {
				_vanilla = vanilla;


			}

			//Unsafe
			TextureAtlas* unsafeGet() {
				return _vanilla;
			}
		};
	}
}