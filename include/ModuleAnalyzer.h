#ifndef MODULE_ANALYZER_H
#define MODULE_ANALYZER_H

#include "pass/BranchCutter.h"
#include "pass/DefineAnalyzer.h"
#include "pass/LoopFinder.h"
#include <cstdlib>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>

class ModuleAnalyzer {
public:
    std::unique_ptr<llvm::Module> &getModule();

    llvm::Function *getFunction(std::string name);

    void readModule(std::string name, std::string dirName = "resources", std::string libName = "functionLib");

    llvm::ExecutionEngine *loadExecuteEngine();

    void runFunction(std::string functionName = "main");

    void runLoopFinder();

    void runDefineAnalyzer();

    void runBranchCutter(std::string dfsFunction, std::string resultName);

    void dumpGlobalVariables();

    void dumpModule();

    void dumpFunction(std::string functionName = "main");

    void dumpFunctionList();

    void dumpBasicBlocks(llvm::StringRef functionName = "main");

    void initTarget();

private:
    llvm::LLVMContext context;
    llvm::SMDiagnostic Err;
    std::string error;
    std::unique_ptr<llvm::Module> module;

    bool compileCxx2IR(std::string dirName, std::string name);

    void linkLib(std::string name, std::string libName);
};

#endif
