#include "ModuleAnalyzer.h"

unique_ptr<Module> &ModuleAnalyzer::getModule() { return module; }

Function *ModuleAnalyzer::getFunction(string name) { return module->getFunction(name); }

void ModuleAnalyzer::readModule(string name, string dirName, string libName) {
    if (!compileCxx2IR(dirName, name)) {
        outs() << "compile " << name << " error\n";
        return;
    }
    linkLib(name, libName);
    module = parseIRFile(name + ".ll", Err, context);
    if (!module) {
        Err.print("ModuleAnalyzer.h", errs());
    }
}

ExecutionEngine *ModuleAnalyzer::loadExecuteEngine() {
    EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(EngineKind::JIT);
    enginerBuilder.setOptLevel(CodeGenOpt::None);
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
    executionEngine->runFunctionAsMain(function, {}, 0);
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

void ModuleAnalyzer::runBranchCutter(string dfsFunction, string resultName) {
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new BranchCutter(dfsFunction, resultName));
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

bool ModuleAnalyzer::compileCxx2IR(string dirName, string name) {
    string cmd = "clang++ -S -emit-llvm " + dirName + "/" + name + ".cpp -o ./" + name + ".ll";
    return (0 == system(cmd.c_str()));
}

void ModuleAnalyzer::linkLib(string name, string libName) {
    compileCxx2IR("../resources", libName);
    string cmd = "llvm-link ./" + libName + ".ll ./" + name + ".ll -o " + name + ".ll";
    system(cmd.c_str());
}