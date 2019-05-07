#ifndef MODULE_ANALYZER_H
#define MODULE_ANALYZER_H

#include "pass/BranchCutter.h"
#include "pass/DefineAnalyzer.h"
#include "pass/LoopFinder.h"
#include <cstdlib>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>

using namespace llvm;
using namespace std;

class ModuleAnalyzer {
public:
    unique_ptr<Module> &getModule();

    Function *getFunction(string name);

    void readModule(string name, string dirName = "resources", string libName = "functionLib");

    ExecutionEngine *loadExecuteEngine();

    void runFunction(string functionName = "main");

    void runLoopFinder();

    void runDefineAnalyzer();

    void runBranchCutter(string dfsFunction, string resultName);

    void dumpGlobalVariables();

    void dumpModule();

    void dumpFunction(string functionName = "main");

    void dumpFunctionList();

    void dumpBasicBlocks(StringRef functionName = "main");

    void initTarget();

private:
    LLVMContext context;
    SMDiagnostic Err;
    string error;
    unique_ptr<Module> module;

    bool compileCxx2IR(string dirName, string name);

    void linkLib(string name, string libName);
};

#endif
