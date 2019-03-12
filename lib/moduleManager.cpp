#include "moduleManager.h"
unique_ptr<Module> ModuleManager::getModule() {
    return move(module);
}

void ModuleManager::readModule(string name) {
    module = move(parseIRFile(name, Err, context));
    runLoopFinder();
}

void ModuleManager::runFunction(string functionName) {
    Function *function = module->getFunction(functionName);
    if (NULL == function) {
        outs() << "there is no " << functionName << " in module " << module->getName() << "\n";
    }
    executionEngine = Util::getExecuteEngine(move(module));
    executionEngine->runFunctionAsMain(function, Util::nullArgs(), NULL);
}

void ModuleManager::runLoopFinder() {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new LoopFinder());
    PM.run(*module);
}