namespace adapter {
	class Material {
		Material* nms_mat;
		
		Material(MaterialType);

		bool getBlocksMotion() const {
			return nms_mat->getBlocksMotion();
		};
		bool getBlocksPrecipitation() const {
			return nms_mat->getBlocksPrecipitation();
		}; //bool?!
		float getTranslucency() const {
			return nms_mat->getTranslucency();
		};

		bool isType(MaterialType type) const {
			return nms_mat->isType(type);
		};

		bool isSolidBlocking() const {
			return nms_mat->isSolidBlocking();
		};
		bool isFlammable() const {
			return nms_mat->isFlammable();
		};
		bool isNeverBuildable() const {
			return nms_mat->isNeverBuildable();
		};
		bool isAlwaysDestroyable() const {
			return nms_mat->isAlwaysDestroyable();
		};
		bool isReplaceable() const {
			return nms_mat->isReplaceable();
		};
		bool isLiquid() const {
			return nms_mat->isLiquid();
		};
		bool isSolid() const {
			return nms_mat->isSolid();	
		};
		bool isTopSolid(bool, bool) const {
			return nms_mat->isTopSolid();
		};
		bool isSuperHot() const {			
			return nms_mat->isSuperHot();
		};

		void setReplaceable() {
			nms_mat->setReplaceable();
		};
		void setFlammable() {
			nms_mat->setFlammable();
		};
		void setDestroyable(bool destroyable) {
			nms_mat->setAlwaysDestroyable();
		};
		void setBuildable(bool buildable) {
			nms_mat->setBuildable();			
		};
		void setBlockingMotion(bool motion) {
			nms_mat->isFlammable();
		};
		void setBlockingPrecipitation(bool precipation) {
			nms_mat->isFlammable();	
		};
		void setSolid(bool solid) {
			nms_mat->isFlammable();	
		};
		void setSuperHot() {
			nms_mat->isFlammable();	
		};

		void operator!=(Material const& mat) const {
			nms_mat != mat;
		};
		void operator==(Material const& mat) const {
			nms_mat == mat;
		};
	}
}
