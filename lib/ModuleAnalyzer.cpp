#include "ModuleAnalyzer.h"

namespace analyzer {
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
    auto ee = enginerBuilder.create();
    if (!ee) {
        llvm::outs() << error << "\n";
    }
    return ee;
}

void ModuleAnalyzer::runFunction(std::string functionName) {
    auto function = module->getFunction(functionName);
    auto executionEngine = loadExecuteEngine();
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

void ModuleAnalyzer::runBranchCutter(std::string dfsFunction, std::string resultName, std::string input) {
    auto moduleManager = new ModuleManager(module);
    moduleManager->stub(dfsFunction, resultName);
    std::error_code EC;
    llvm::raw_fd_ostream file("target.ll", EC, llvm::sys::fs::F_None);
    llvm::WriteBitcodeToFile(*module, file);
    file.flush();
    std::system("clang++ target.ll -o target");
    std::system(("./target < " + input).c_str());
}

void ModuleAnalyzer::dumpGlobalVariables() {
    for (llvm::GlobalVariable &globalVariable : module->getGlobalList()) {
        llvm::outs() << '(' << *globalVariable.getType() << ") " << globalVariable.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpModule() { llvm::outs() << *module << "\n"; }

void ModuleAnalyzer::dumpFunction(std::string functionName) {
    auto function = module->getFunction(functionName);
    llvm::outs() << *function << "\n";
}

void ModuleAnalyzer::dumpFunctionList() {
    for (auto &function : module->getFunctionList()) {
        llvm::outs() << function.getName() << "\n";
    }
}

void ModuleAnalyzer::dumpBasicBlocks(llvm::StringRef functionName) {
    for (auto &basicBlock : *module->getFunction(functionName)) {
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
} // namespace analyzer
