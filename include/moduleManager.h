#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <string>
#include "loopFinder.h"
#include "util.h"
using namespace llvm;
using namespace std;
class ModuleManager {
public:
    unique_ptr<Module> getModule();
    void readModule(string name);
    void runFunction(string functionName);
    void runLoopFinder();

private:
    LLVMContext context;
    SMDiagnostic Err;
    unique_ptr<Module> module;
    unique_ptr<ExecutionEngine> executionEngine;
};
#endif
