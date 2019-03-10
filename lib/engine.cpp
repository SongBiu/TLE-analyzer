#include "engine.h"
void Engine::run(unique_ptr<Module> module) {
    PM.run(*module);
}