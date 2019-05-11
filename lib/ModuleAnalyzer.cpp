#include "ModuleAnalyzer.h"

std::unique_ptr<llvm::Module> &ModuleAnalyzer::getModule() { return module; }

llvm::Function *ModuleAnalyzer::getFunction(std::string name) { return module->getFunction(name); }

void ModuleAnalyzer::readModule(std::string name, std::string dirName, std::string libName) {
    if (!compileCxx2IR(dirName, name)) {
        llvm::outs() << "compile " << name << " error\n";
        return;
    }
    linkLib(name, libName);
    module = parseIRFile(name + ".ll", Err, context);
    if (!module) {
        Err.print("ModuleAnalyzer.h", llvm::errs());
    }
}

llvm::ExecutionEngine *ModuleAnalyzer::loadExecuteEngine() {
    llvm::EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(llvm::EngineKind::JIT);
    enginerBuilder.setOptLevel(llvm::CodeGenOpt::None);
    llvm::ExecutionEngine *ee = enginerBuilder.create();
    if (!ee) {
        llvm::outs() << error << "\n";
    }
    return ee;
}

void ModuleAnalyzer::runFunction(std::string functionName) {
    llvm::Function *function = module->getFunction(functionName);
    llvm::ExecutionEngine *executionEngine = loadExecuteEngine();
    if (NULL == function) {
        llvm::outs() << "there is no " << functionName << " in module " << module->getName() << "\n";
    }
    executionEngine->runFunctionAsMain(function, {}, 0);
}

void ModuleAnalyzer::runLoopFinder() {
    llvm::legacy::PassManager PM;
    PM.add(new llvm::LoopInfoWrapperPass());
    PM.add(new LoopFinder());
    PM.run(*module);
}

void ModuleAnalyzer::runDefineAnalyzer() {
    llvm::legacy::PassManager PM;
    PM.add(new llvm::LoopInfoWrapperPass());
    PM.add(new DefineAnalyzer());
    PM.run(*module);
}

void ModuleAnalyzer::runBranchCutter(std::string dfsFunction, std::string resultName) {
    llvm::legacy::PassManager PM;
    PM.add(new llvm::LoopInfoWrapperPass());
    PM.add(new BranchCutter(dfsFunction, resultName));
    PM.run(*module);
}

void ModuleAnalyzer::dumpGlobalVariables() {
    for (llvm::GlobalVariable &globalVariable : module->getGlobalList()) {
        llvm::outs() << '(' << *globalVariable.getType() << ") " << globalVariable.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpModule() { llvm::outs() << *module << "\n"; }

void ModuleAnalyzer::dumpFunction(std::string functionName) {
    llvm::Function *function = module->getFunction(functionName);
    llvm::outs() << *function << "\n";
}

void ModuleAnalyzer::dumpFunctionList() {
    for (llvm::Function &function : module->getFunctionList()) {
        llvm::outs() << function.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpBasicBlocks(llvm::StringRef functionName) {
    for (llvm::BasicBlock &basicBlock : *module->getFunction(functionName)) {
        llvm::outs() << basicBlock << "\n";
    }
}

void ModuleAnalyzer::initTarget() {
    llvm::InitializeNativeTarget();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();
}

bool ModuleAnalyzer::compileCxx2IR(std::string dirName, std::string name) {
    std::string cmd = "clang++ -S -emit-llvm " + dirName + "/" + name + ".cpp -o ./" + name + ".ll";
    return (0 == system(cmd.c_str()));
}

void ModuleAnalyzer::linkLib(std::string name, std::string libName) {
    compileCxx2IR("../resources", libName);
    std::string cmd = "llvm-link ./" + libName + ".ll ./" + name + ".ll -o " + name + ".ll";
    system(cmd.c_str());
}