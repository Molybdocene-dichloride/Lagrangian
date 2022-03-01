class TextureAtlas;
class Texture;
namespace lagrangian {
	namespace graphics {
		class AtlasTexture {
			TextureAtlas* _vanilla;
			//std::__ndk1::vector<Texture> ts;
			AtlasTexture() {

			}
			AtlasTexture(TextureAtlas* vanilla) {
				_vanilla = vanilla;
			}

			//void add(Texture t);
			//void remove(Texture t);

			void reload();
			void clear();
			//Unsafe
			TextureAtlas* unsafeGet() {
				return _vanilla;
			}

			void init(TextureAtlas* vanilla) {
				_vanilla = vanilla;
			}
		};
	}
}