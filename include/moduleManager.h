#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "loopFinder.h"
#include "defineAnalyzer.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <cstdlib>


using namespace llvm;
using namespace std;

class ModuleManager {
public:
    unique_ptr<Module> &getModule();

    Function *getFunction(string name);

    void readModule(string name);

    ExecutionEngine *loadExecuteEngine();

    void runFunction(string functionName = "main");

    void runLoopFinder();

    void runDefineAnalyzer();

    void dumpGlobalVariables();

    void dumpModule();

    void dumpBasicBlocks(StringRef functionName = "main");

    void initTarget();

private:
    LLVMContext context;
    SMDiagnostic Err;
    string error;
    unique_ptr<Module> module;

    bool compileCxx2IR(string name);

    void linkLib(string name);
};

#endif
