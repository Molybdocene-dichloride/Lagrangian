#include <cstddef>
#include <mod.h>
#include <symbol.h>
#include <hook.h>
#include <logger.h>
#include <nativejs.h>

#include <mcpe/BlockActor/BlockActor.hpp>

class RendererModule : public Module {
    public:
    RendererModule(const char* id): Module(id) {}; 
	virtual void initialize() {
        DLHandleManager::initializeHandle("libminecraftpe.so", "mcpe");
		
        stat(BlockActor, changed);
	}
};

MAIN {
	Module* rndr_module = new RendererModule("renderer");
}