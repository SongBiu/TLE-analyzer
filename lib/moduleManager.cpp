#include "moduleManager.h"

unique_ptr<Module> &ModuleManager::getModule() { return module; }

Function *ModuleManager::getFunction(string name) {
    return module->getFunction(name);
}

void ModuleManager::readModule(string name) {
    if (!compileCxx2IR(name)) {
        outs() << "compile " << name << "error\n";
        return;
    }
//    linkLib(name);
    module = parseIRFile(name + ".ll", Err, context);
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
    Function *function = module->getFunction(functionName);
    ExecutionEngine *executionEngine = loadExecuteEngine();
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

void ModuleManager::runDefineAnalyzer() {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new DefineAnalyzer());
    PM.run(*module);
}

void ModuleManager::dumpGlobalVariables() {
    for (GlobalVariable &globalVariable : module->getGlobalList()) {
        outs() << '(' << *globalVariable.getType() << ") "
               << globalVariable.getName() << "\n";
    }
}

void ModuleManager::dumpModule() {
    outs() << *module << "\n";
}

void ModuleManager::dumpBasicBlocks(StringRef functionName) {
    for (BasicBlock &basicBlock: *module->getFunction(functionName)) {
        outs() << basicBlock << "\n";
    }
}

void ModuleManager::initTarget() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();
}

bool ModuleManager::compileCxx2IR(string name) {
    string cmd = "clang++ -S -emit-llvm ../resources/" + name + ".cpp -o ./" + name + ".ll";
    return (0 == system(cmd.c_str()));
}

void ModuleManager::linkLib(string name) {
    compileCxx2IR("lib/functionLib");
    string cmd = "llvm-link ./functionLib.ll ./" + name + ".ll -o " + name + ".ll";
    system(cmd.c_str());
}