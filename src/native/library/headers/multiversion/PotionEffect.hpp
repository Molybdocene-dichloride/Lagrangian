namespace adapter {
	class PotionEffect {
		private:
		MobEffect* instance;
		
		virtual ~MobEffect() {}
		virtual void applyEffects(Actor* entity, int level, int duration) const {
			return instance->applyEffects(entity, level, duration);
		}
		virtual void removeEffects(Actor* entity) {
			return instance->removeEffects(entity);
		}
		virtual void applyInstantaneousEffect(Actor* entity, Actor* entity1, Actor* entity2, int level, float i) const {
			return instance->applyInstantaneousEffect(entity, entity1, entity2, level, i);
		}
		virtual bool isInstantaneous() const { 
			return instance->isInstantaneous();
		}
		virtual void getAttributeModifierValue(int i, AttributeModifier const& modifier) const { 
			return instance->getAttributeModifierValue(i, modifier);
		}
		public:
		//Methods
		PotionEffect(int id, std::__ndk1::string const& name, std::__ndk1::string const&, bool, int level, int duration, std::__ndk1::string const&, bool) { 
			PotionEffect();
		}
		
		void shutdownEffects() { 
			instance->shutdownEffects();
		}
		void createTemporalBuff(AttributeBuff const& buff, int i0, int i1) const { 
			instance->createTemporalBuff(buff, i0, i1);
		}
		void clearAttributeBuffs() { 
			instance->clearAttributeBuffs();
		}
		void createAttributeModifer(AttributeModifier const& modifier, int i) const {
			instance->clearAttributeBuffs(modifier, i);
		}
		void addAttributeModifier(Attribute const&, std::__ndk1::shared_ptr<AttributeModifier>) {
			instance->addAttributeModifier();
		}
		void clearAttributeModifiers() { 
			instance->clearAttributeModifiers();
		}
		void setDurationAmplifier(std::__ndk1::shared_ptr<Amplifier>) {
			instance->setDurationAmplifier();
		}
		void addAttributeBuff(Attribute const&, std::__ndk1::shared_ptr<AttributeBuff>) { 
			instance->addAttributeBuff();
		}
		void formatDuration(MobEffectInstance const*) { 
			instance->formatDuration();
		}
		void createInstantBuff(AttributeBuff const&, int, float) const { 
			instance->createInstantBuff();
		}
		void setValueAmplifier(std::__ndk1::shared_ptr<Amplifier>) { 
			instance->setValueAmplifier();
		}
		
		std::_ndk1::string getComponentName() const { 
			return instance->getComponentName();
		}+
		void getColor() const { 
			return instance->getColor();
		}
		void getIcon() const { 
			return instance->getIcon();
		}
		bool isVisible() const { 
			return instance->isVisible();
		}
		void getDescriptionId() const { 
			return instance->getDescriptionId();
		}
		bool isDisabled() const { 
			return instance->isDisabled();
		}
		void viewAttributeModifiers() const { 
			return instance->viewAttributeModifiers();
		}
		void getId() const { 
			return instance->getId();
		}
		void getDurationModifier() const { 
			return instance->getDurationModifier();
		}
		std::_ndk1::string getIconName() const { 
			return instance->getIconName();
		}
		bool hasIcon() const { 
			return instance->hasIcon();
		}
		bool isHarmful() const { 
			return instance->isHarmful();
		}
		std::_ndk1::string getResourceName() const { 
			return instance->getResourceName();
		}
		MobEffect* nms() {
			return instance;
		}
	}
}
