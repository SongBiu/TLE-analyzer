#include "ModuleAnalyzer.h"

unique_ptr<Module> &ModuleAnalyzer::getModule() { return module; }

Function *ModuleAnalyzer::getFunction(string name) { return module->getFunction(name); }

bool ModuleAnalyzer::readModule(string name) {
    if (!compileCxx2IR(name)) {
        outs() << "compile " << name << " error\n";
        return false;
    }
    linkLib(name);
    module = parseIRFile(name + ".ll", Err, context);
    if (!module) {
        Err.print("ModuleAnalyzer.h", errs());
    }
    return true;
}

ExecutionEngine *ModuleAnalyzer::loadExecuteEngine() {
    EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(EngineKind::JIT);
    ExecutionEngine *ee = enginerBuilder.create();
    if (!ee) {
        outs() << error << "\n";
    }
    return ee;
}

void ModuleAnalyzer::runFunction(string functionName) {
    Function *function = module->getFunction(functionName);
    ExecutionEngine *executionEngine = loadExecuteEngine();
    if (NULL == function) {
        outs() << "there is no " << functionName << " in module " << module->getName() << "\n";
    }
    executionEngine->runFunctionAsMain(function, {}, NULL);
}

void ModuleAnalyzer::runLoopFinder() {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new LoopFinder());
    PM.run(*module);
}

void ModuleAnalyzer::runDefineAnalyzer() {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new DefineAnalyzer());
    PM.run(*module);
}

void ModuleAnalyzer::dumpGlobalVariables() {
    for (GlobalVariable &globalVariable : module->getGlobalList()) {
        outs() << '(' << *globalVariable.getType() << ") " << globalVariable.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpModule() { outs() << *module << "\n"; }

void ModuleAnalyzer::dumpFunction(string functionName) {
    Function *function = module->getFunction(functionName);
    outs() << *function << "\n";
}

void ModuleAnalyzer::dumpFunctionList() {
    for (Function &function : module->getFunctionList()) {
        outs() << function.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpBasicBlocks(StringRef functionName) {
    for (BasicBlock &basicBlock : *module->getFunction(functionName)) {
        outs() << basicBlock << "\n";
    }
}

void ModuleAnalyzer::initTarget() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();
}

bool ModuleAnalyzer::compileCxx2IR(string name) {
    string cmd = "clang++ -std=c++17 -S -emit-llvm ../resources/" + name + ".cpp -o ./" + name + ".ll" +
                 ">/dev/null 2>&1";
    return (0 == system(cmd.c_str()));
}

void ModuleAnalyzer::linkLib(string name) {
    compileCxx2IR("functionLib");
    string cmd = "llvm-link ./functionLib.ll ./" + name + ".ll -o " + name + ".ll" + ">/dev/null 2>&1";
    system(cmd.c_str());
}