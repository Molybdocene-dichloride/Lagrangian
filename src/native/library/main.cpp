#include <string>
#include <stl/list>
#include <sstream>
#include <cmath>

#include <mod.h>
#include <symbol.h>
#include <hook.h>
#include <logger.h>
#include <nativejs.h>
#include "vtable.h"
#include <horizon/pool.h>
#include <innercore/global_context.h>
#include <innercore/block_registry.h>
#include <innercore/id_conversion_map.h>

#include <mcpe/common.hpp>
#include <mcpe/block/Block.hpp>
#include <mcpe/math/BlockPos.hpp>

#include <Localization.hpp>
#include <Flags.hpp>
#include <toString.hpp>

#include <LagrangianRegistries.hpp>

std::vector<long>::iterator it;

std::vector<long> blockids;
float sizeid = 0;
std::map<float, long> iblockids;

std::vector<long> blockdatas;
float sizedata = 0;
std::map<float, long> iblockdatas;

std::map<float, std::shared_ptr<Block>> blks;
std::map<float, std::shared_ptr<Block>>::iterator cur;

//JS_MODULE_VERSION(Stones, 1);
JS_MODULE_VERSION(LagrangianRegistries, 1);
JS_MODULE_VERSION(Flags, 1);
JS_MODULE_VERSION(LocalizationSystem, 1);

JS_MODULE_VERSION(Category, 1);
JS_MODULE_VERSION(CreativeTabs, 1);

/*JS_EXPORT(Stones, registerID, "V(II)", (JNIEnv* env, long id, long data) {
	Logger::debug("j", "wew");
	Logger::debug("j", patch::to_string<long>(id).c_str());
	Logger::debug("jf", patch::to_string<long>(data).c_str());
	
	blockids.push_back(id);
	blockdatas.push_back(data);
	Logger::debug("sj", patch::to_string<size_t>(blockids.size()).c_str());
	Logger::debug("fgj", patch::to_string<size_t>(blockdatas.size()).c_str());
	return 0;
});*/

JS_EXPORT(Flags, hasFlag, "I(LL)", (JNIEnv* env, long long value1, long long value2) {
	return NativeJS::wrapIntegerResult(hasFlag(value1, value2));
});

JS_EXPORT(Flags, createFlag, "I(L)", (JNIEnv* env, long long value1) {
	return NativeJS::wrapIntegerResult(createFlag(value1));
});
JS_EXPORT(Flags, recepiee, "I(L)", (JNIEnv* env, long long value1) {
	return NativeJS::wrapIntegerResult(recepiee(value1));
});
JS_EXPORT(Flags, pack2, "I(LL)", (JNIEnv* env, long long value1, long long value2) {
	return NativeJS::wrapIntegerResult(pack(2, value1, value2));
});
JS_EXPORT(Flags, pack3, "I(LLL)", (JNIEnv* env, long long value1, long long value2, long long value3) {
	return NativeJS::wrapIntegerResult(pack(3, value1, value2, value3));
});
JS_EXPORT(Flags, pack4, "I(LLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4) {
	return NativeJS::wrapIntegerResult(pack(4, value1, value2, value3, value4));
});
JS_EXPORT(Flags, pack5, "I(LLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5) {
	return NativeJS::wrapIntegerResult(pack(5, value1 , value2 , value3 , value4 , value5));
});
JS_EXPORT(Flags, pack6, "I(LLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6) {
	return NativeJS::wrapIntegerResult(pack(6, value1 , value2 , value3 , value4 , value5 , value6));
});
JS_EXPORT(Flags, pack7, "I(LLLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6, long long value7) {
	return NativeJS::wrapIntegerResult(pack(7, value1 , value2 , value3 , value4 , value5 , value6 , value7));
});
JS_EXPORT(Flags, pack8, "I(LLLLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6, long long value7, long long value8) {
	return NativeJS::wrapIntegerResult(pack(8, value1 , value2 , value3 , value4 , value5 , value6 , value7 , value8));
});
JS_EXPORT(Flags, pack9, "I(LLLLLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6, long long value7, long long value8, long long value9) {
	return NativeJS::wrapIntegerResult(pack(9, value1 , value2 , value3 , value4 , value5 , value6 , value7 , value8, value9));
});
JS_EXPORT(Flags, pack10, "I(LLLLLLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6, long long value7, long long value8, long long value9, long long value10) {
	return NativeJS::wrapIntegerResult(pack(10, value1 , value2 , value3 , value4 , value5 , value6 , value7 , value8, value9, value10));
});
JS_EXPORT(Flags, pack11, "I(LLLLLLLLLLL)", (JNIEnv* env, long long value1, long long value2, long long value3, long long value4, long long value5, long long value6, long long value7, long long value8, long long value9, long long value10, long long value11) {
	return NativeJS::wrapIntegerResult(pack(11, value1, value2, value3, value4, value5, value6 , value7 , value8, value9, value10, value11));
});

JS_EXPORT_COMPLEX(LocalizationSystem, translate, "S(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return NativeJS::wrapStringResult(env, LocalizationSystem::translate(ca.get("lang").asString(), ca.get("key").asString()).c_str());
});
JS_EXPORT_COMPLEX(LocalizationSystem, translateToCurrent, "S(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return NativeJS::wrapStringResult(env, LocalizationSystem::translateToCurrent(ca.get("key").asString()).c_str());
});
JS_EXPORT_COMPLEX(LocalizationSystem, insert, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::insert(ca.get("lang").asString(), ca.get("key").asString(), ca.get("val").asString());
	return 0;
});
JS_EXPORT_COMPLEX(LocalizationSystem, insertToCurrent, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::insertToCurrent(ca.get("key").asString(), ca.get("val").asString());
	return 0;
});
JS_EXPORT_COMPLEX(LocalizationSystem, chooseLanguage, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::chooseLocalization(ca.get("lang").asString());
	return 0;
});
JS_EXPORT(LocalizationSystem, getCurrentLanguage, "S()", (JNIEnv* env) {
	return NativeJS::wrapStringResult(env, LocalizationSystem::getCurrentLanguage().c_str());
});
JS_EXPORT_COMPLEX(LocalizationSystem, loadTranslations, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::loadTranslations(ca.get("path").asString());
	return 0;
});
JS_EXPORT_COMPLEX(LocalizationSystem, loadTranslationDir, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::loadTranslationDir(ca.get("path").asString());
	return 0;
});
//technical for JS PrefixPostfixTranslator
JS_EXPORT_COMPLEX(LocalizationSystem, _createNativeTranslatorObj, "I(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	if(LocalizationSystem::trmap.find(std::__ndk1::pair<std::__ndk1::string, std::__ndk1::string>(ca.get("pre").asString(), ca.get("post").asString())) != LocalizationSystem::trmap.end()) {
		Logger::debug(/*hy=*/"89h", "ddd");
		return NativeJS::wrapIntegerResult(reinterpret_cast<uintptr_t>(LocalizationSystem::trmap[std::__ndk1::pair<std::__ndk1::string, std::__ndk1::string>(ca.get("pre").asString(), ca.get("post").asString())]));
	} else {
		Logger::debug("89fh", "{}");
		LocalizationSystem::PrefixPostfixTranslator* ppt = new LocalizationSystem::PrefixPostfixTranslator(ca.get("pre").asString(), ca.get("post").asString());
		Logger::debug("89fh", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(ppt)).c_str());
		return NativeJS::wrapIntegerResult(reinterpret_cast<uintptr_t>(ppt));
	}
});
JS_EXPORT_COMPLEX(LocalizationSystem, _deleteNativeTranslatorObj, "V(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	LocalizationSystem::PrefixPostfixTranslator* ppt = (LocalizationSystem::PrefixPostfixTranslator*)ca.get("_pointer").asPointer();
	delete ppt;
	return 0;
});

JS_EXPORT_COMPLEX(LocalizationSystem, _translate, "S(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return NativeJS::wrapStringResult(env, ((LocalizationSystem::PrefixPostfixTranslator*)ca.get("_pointer").asPointer())->translate(ca.get("lang").asString(), ca.get("key").asString()).c_str());
});
JS_EXPORT_COMPLEX(LocalizationSystem, _translateToCurrent, "S(SS)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	Logger::debug("89fh", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(ca.get("_pointer").asPointer())).c_str());
	return NativeJS::wrapStringResult(env, ((LocalizationSystem::PrefixPostfixTranslator*)ca.get("_pointer").asPointer())->translateToCurrent(ca.get("key").asString()).c_str());
});

//JS_EXPORT_COMPLEX(LagrangianRegistries, registerCategory, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	//Logger::debug("u89fh", ca.get("id").asString());

	//ItemCategory* cc = new ItemCategory(ca);

	//LagrangianRegistries::registerCategory(cc);

	//return NativeJS::wrapIntegerResult(reinterpret_cast<uintptr_t>(cc));
//});

JS_EXPORT_COMPLEX(Category, addItems, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	
	ItemCategory* cat = reinterpret_cast<ItemCategory*>(ca.get("_pointer").asPointer());
	
	cat->addItem(ca);

	return 0;
});

JS_EXPORT_COMPLEX(CreativeTabs, getCategoryCount, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return CreativeTabs::cat_count;
});
JS_EXPORT_COMPLEX(CreativeTabs, getPageCount, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return CreativeTabs::page_count;
});
JS_EXPORT_COMPLEX(CreativeTabs, getCurrentPage, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	return CreativeTabs::current_page;
});

JS_EXPORT_COMPLEX(CreativeTabs, setPage, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	CreativeTabs::setPage(ca.get("page").asInt());
});

JS_EXPORT_COMPLEX(CreativeTabs, prevPage, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	CreativeTabs::prevPage();
});

JS_EXPORT_COMPLEX(CreativeTabs, nextPage, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	CreativeTabs::nextPage();
});
bool is = true;
JS_EXPORT(CreativeTabs, invalidate, "I()", (JNIEnv* env) {
	is = true;
});

class CategoryModule : public Module { //
    public:
    CategoryModule(const char* id): Module(id) {}; 
	virtual void initialize() {	
        // any HookManager::addCallback calls must be in initialize method of a module
            // any other initialization also highly recommended to happen here
        DLHandleManager::initializeHandle("libminecraftpe.so", "mcpe");
		HookManager::addCallback(SYMBOL("mcpe", "_ZN12ItemRegistry23initCreativeItemsServerEP17ActorInfoRegistryP20BlockDefinitionGroupbRK15BaseGameVersionRK11ExperimentsNSt6__ndk18functionIFvS1_S3_P20CreativeItemRegistrybS6_S9_EEE"), LAMBDA((HookManager::CallbackController* controller), {	
			LagrangianRegistries::postInit();
	
			return 0;
		}, ), HookManager::RETURN | HookManager::LISTENER | HookManager::CONTROLLER);
		
		HookManager::addCallback(SYMBOL("mcpe", "_ZN29CraftingContainerManagerModel19_populateContainersERj"), LAMBDA((HookManager::CallbackController* controller), {
			//controller->prevent();
		}, ), HookManager::CALL | HookManager::LISTENER | HookManager::CONTROLLER);
		
		HookManager::addCallback(SYMBOL("mcpe", "_ZN29CraftingContainerManagerModel4tickEv"), LAMBDA((HookManager::CallbackController* controller, CraftingContainerManagerModel* ths), {
			Logger::debug("derr", "ddytty");
			if(is) {
				CreativeTabs::invalidateModels(ths);
				is = false;
			}
			Logger::debug("derr", "ddytty");
			CreativeTabs::populateItems(ths);

			return 0;
		}, ), HookManager::RETURN | HookManager::LISTENER | HookManager::CONTROLLER);
		
	}
};

MAIN {
	Module* localization_module = new LocalizationSystem::CustomLocalizationLoadingModule("lagrangiankernel.localizations_module");
	Module* cat_module = new CategoryModule("lagrangiankernel.categories");
}