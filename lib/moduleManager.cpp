#include "moduleManager.h"
unique_ptr<Module> ModuleManager::getModule() { return move(module); }
Function *ModuleManager::getFunction(string name) {
    return module->getFunction(name);
}
void ModuleManager::readModule(string name) {
    module = move(parseIRFile(name, Err, context));
    if (!module) {
        Err.print("moduleManager.h", errs());
    }
}

ExecutionEngine *ModuleManager::loadExecuteEngine() {
    EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(EngineKind::JIT);
    ExecutionEngine *ee = enginerBuilder.create();
    if (!ee) {
        outs() << error << "\n";
    }
    return ee;
}

void ModuleManager::runFunction(string functionName) {
    ExecutionEngine *executionEngine = loadExecuteEngine();
    Function *function = module->getFunction(functionName);
    if (NULL == function) {
        outs() << "there is no " << functionName << " in module "
               << module->getName() << "\n";
    }
    executionEngine->runFunctionAsMain(function, {}, NULL);
}

void ModuleManager::runLoopFinder() {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new LoopFinder());
    PM.run(*module);
}

void ModuleManager::dumpGlobalVariables() {
    for (GlobalVariable &globalVariable : module->getGlobalList()) {
        outs() << '(' << *globalVariable.getType() << ") "
               << globalVariable.getName() << "\n";
    }
}