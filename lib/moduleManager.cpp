#include "moduleManager.h"
unique_ptr<Module> ModuleManager::readModule(string name) {
    return move(parseIRFile(name, Err, context));
}