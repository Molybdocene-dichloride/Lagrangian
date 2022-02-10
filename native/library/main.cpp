#include <string>
#include <sstream>
#include <cmath>

#include <mod.h>
#include <symbol.h>
#include <hook.h>
#include <logger.h>
#include <nativejs.h>

#include <mcpe/common.hpp>
//#include <mcpe\VanillaBlocks.h>
//#include <mcpe/ChunkSource.hpp>
//#include <mcpe/IBlockWorldGenAPI.hpp>
//#include <mcpe/RenderParams.hpp>
//#include <mcpe/NativeBlockSource.hpp>
#include <mcpe/block/Block.hpp>

#include <horizon/pool.h>
#include <innercore/block_registry.h>
#include <innercore/id_conversion_map.h>

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



/*namespace Stones {
	void ends() {
		//FurnaceSystem::addFurnaceRecipes

		Logger::debug("b", "gotoir");
		Logger::debug("v", patch::to_string<size_t>(blockids.size()).c_str());
		sizeid = 1.0f / blockids.size();
		sizedata = 1.0f / blockdatas.size();
		Logger::debug("jsd", patch::to_string<long>(blockids[7]).c_str());
		for(it = blockids.begin(); it != blockids.end(); ++it) {
			iblockids.insert(std::pair<float, long>(sizeid * (it - blockids.begin()), *it));
			iblockdatas.insert(std::pair<float, long>(sizedata * (it - blockids.begin()), blockdatas[it - blockids.begin()]));
			Logger::debug("nukew", patch::to_string<float>(sizeid * (it - blockids.begin())).c_str());

			Block* b = BlockRegistry::getBlockStateForIdData(*it, blockdatas[it - blockids.begin()]);
			std::shared_ptr<Block> bsh(b);
			Logger::debug("Ys", patch::to_string<long>(*it).c_str());
			Logger::debug("Es", patch::to_string<long>(blockdatas[it - blockids.begin()]).c_str());
			Logger::debug("s", patch::to_string<bool>(b == nullptr).c_str());
			blks.insert(std::pair<float, std::shared_ptr<Block>>(sizeid * (it - blockids.begin()), bsh));
			Logger::debug("zoolium", patch::to_string<void const*>((void const*) b).c_str());
		}
		Logger::debug("grt", patch::to_string<size_t>(blks.size()).c_str());
		Logger::debug("grt", patch::to_string<size_t>(iblockids.size()).c_str());
		Logger::debug("grt", patch::to_string<size_t>(iblockdatas.size()).c_str());
	}
}
long getNearest(long pos, short mode) {
	switch(mode) {
		case 0:
		return floor(pos / sizeid) * sizeid;
		case 1:
		return floor(pos / sizedata) * sizedata;
	}
	return 0;
}
bool ifLoaded = false;
void generate(long x, long z) {
	if(!ifLoaded) {
		Stones::ends();
		ifLoaded = true;
	}
	//BlockLegacy* stone = BlockRegistry::getBlockById(8);
	//Logger::debug("BGTY", patch::to_string<int>((int) stone->id).c_str());

	//BlockPos xc((float)x * 16 + 4, (float)43, (float)z * 16 + 4);
	//Block* b = BlockSourceProvider::getBlockSource().getBlock(xc);
	//Logger::debug("pexes", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(b)).c_str());
	//Logger::debug("jjsw", patch::to_string<int>((int)b->getVariant()).c_str());

	//BlockLegacy* bli = b->getBlockLegacy();
	//Logger::debug("vczx", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(bli)).c_str());
	//Logger::debug("bll", bli->id);
	/*for(int x = 0; x < 16; x++) {
		for(int y = 0; y < 170; y++) {
			for(int z = 0; z < 16; z++) {
				int xx = x * 16 + x;
				int zz = z * 16 + z;

				BlockPos xc((float) xx, (float) y, (float) zz);
				Block* b = BlockSourceProvider::getBlockSource().getBlock(xc);
				Logger::debug("pexes", patch::to_string<bool>(b != nullptr).c_str());
				Logger::debug("jjsw", patch::to_string<int>((int)b->getVariant()).c_str());

				BlockLegacy* bli = b->getBlockLegacy();
				//Logger::debug("vczx", patch::to_string<bool>(bli != nullptr).c_str());
				//Logger::debug("vaasdd", patch::to_string<short>(bli->id).c_str());
				//Logger::debug("bll", patch::to_string<short>(bl->getBlockItemId()).c_str());
				IdConversion::dynamicToStatic(bli->id, IdConversion::Scope::BLOCK);
				//delete xc;
				/*if(chunk.getBlock(*cbp).getRuntimeId() != VanillaBlocks::mStone->getRuntimeId()) continue;
				PerlinSimplexNoise* psn = new PerlinSimplexNoise(chunkSource.getLevel().getSeed(), 2);
				if(iblockids[getNearest(psn->getValue(*new Vec3(*new BlockPos(cp, *cbp, 256))), 0)] != 0 && iblockdatas[getNearest(psn->getValue(*new Vec3(*new BlockPos(cp, *cbp, 256))), 1)] != 0) BlockSourceProvider::getBlockSource().setBlock(*new BlockPos(chunk.getPosition().x + x, chunk.getPosition().y + y, chunk.getPosition().z + z), *blks[iblockids[getNearest(psn->getValue(*new Vec3(*new BlockPos(*cp, *cbp, 256))), 0)]], iblockdatas[getNearest(psn->getValue(*new Vec3(*new BlockPos(*cp, *cbp, 256))), 1)], nullptr);
			}
		}
	}
}*/

//JS_MODULE_VERSION(Stones, 1);
JS_MODULE_VERSION(LagrangianRegistries, 1);
JS_MODULE_VERSION(Flags, 1);
JS_MODULE_VERSION(LocalizationSystem, 1);

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

JS_EXPORT(Scientific, NO, "F()", (JNIEnv* env) {
	return NativeJS::wrapDoubleResult(-1);
});
JS_EXPORT(Flags, hasFlag, "I(LL)", (JNIEnv* env, long long value1, long long value2) {
	return NativeJS::wrapIntegerResult(hasFlag(value1, value2));
});
/*JS_EXPORT(Stones, generate, "V(II)", (JNIEnv* env, long x, long z) {
	generate(x, z);
	return 0;
});*/
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
		Logger::debug("89h", "ddd");
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



JS_EXPORT_COMPLEX(LagrangianRegistries, registerCategory, "I(SI)", (JNIEnv* env, NativeJS::ComplexArgs ca) {
	Logger::debug("u89fh", ca.get("id").asString());
    Logger::debug("u89fh", patch::to_string<long>(ca.get("index").asInt()).c_str());
        
	Logger::debug("u81", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(CreativeItemRegistry::current())).c_str());

	ItemCategory cc = ItemCategory(ca.get("index").asInt(), ca.get("id").asString());
	ItemCategory& ic = cc;

	LagrangianRegistries::registerCategory(ic);
        /*std::__ndk1::string str = std::__ndk1::string(ca.get("id").asString());
        std::__ndk1::string& stri = str;
        CreativeItemCategory ci = CreativeItemCategory(ca.get("index").asInt());
        CreativeItemCategory& cic = ci;
        CreativeItemGroupCategory* cat = LagrangianRegistries::registerCategory(stri, cic);*/

	return /*NativeJS::wrapIntegerResult(reinterpret_cast<uintptr_t>(cat))*/ 12;
});


void deo() {
	std::__ndk1::unordered_map<ContainerEnumName, std::__ndk1::string,ContainerEnumNameHasher>::iterator at;
	for(at = ContainerCollectionNameMap.begin(); at != ContainerCollectionNameMap.end(); ++at) {
		Logger::debug("Lg0", patch::to_string<ContainerEnumName>(at->first).c_str());
		Logger::debug("Lg1", at->second.c_str());
	}
}
class CategoryModule : public Module { //destroy vanilla ore generation
    public:
    CategoryModule(const char* id): Module(id) {}; 
	virtual void initialize() {	
        // any HookManager::addCallback calls must be in initialize method of a module
            // any other initialization also highly recommended to happen here
        DLHandleManager::initializeHandle("libminecraftpe.so", "mcpe");
		HookManager::addCallback(SYMBOL("mcpe", "_ZN12ItemRegistry23initCreativeItemsServerEP17ActorInfoRegistryP20BlockDefinitionGroupbRK15BaseGameVersionRK11ExperimentsNSt6__ndk18functionIFvS1_S3_P20CreativeItemRegistrybS6_S9_EEE"), LAMBDA((HookManager::CallbackController* controller), {
			Logger::debug("u81", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(CreativeItemRegistry::current())).c_str());
			
			LagrangianRegistries::registerAll();

			return 0;
		}, ), HookManager::RETURN | HookManager::LISTENER | HookManager::CONTROLLER | HookManager::RESULT);
		HookManager::addCallback(SYMBOL("mcpe", "_ZN29CraftingContainerManagerModel9_postInitEv"), LAMBDA((HookManager::CallbackController* controller), {
			Logger::debug("u81", patch::to_string<uintptr_t>(reinterpret_cast<uintptr_t>(CreativeItemRegistry::current())).c_str());
			
			//int o = *((int*)0);
			deo();
			
			return 0;
		}, ), HookManager::RETURN | HookManager::LISTENER | HookManager::CONTROLLER | HookManager::RESULT);
		
	}
};

MAIN {
	Module* localization_module = new LocalizationSystem::CustomLocalizationLoadingModule("gregtech.loading_localizations_module");
	Module* cat_module = new CategoryModule("gregtech.loading");
}
// native js signature rules:
/* signature represents parameters and return type, RETURN_TYPE(PARAMETERS...) example: S(OI)
	return types:
		V - void      - return 0
		I - long int  - wrapIntegerResult
		F - double    - wrapDoubleResult
		S - string    - wrapStringResult
		O - object    - wrapObjectResult
	parameter types:
		I - int (4 bits) 
		L - long (8 bits)
		F - float (4 bits)
		D - double (8 bits)
		B - boolean (1 bit)
		C - char (1 bit)
	as seen, basic call functions cannot receive string and objects for sake of performance, so complex functions come in place
	in case of complex functions parameters are ignored
	JNIEnv* is always passed as first parameter
*/


