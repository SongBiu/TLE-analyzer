#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
#include "loopFinder.h"
#include "util.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <string>
using namespace llvm;
using namespace std;
class ModuleManager {
  public:
    unique_ptr<Module> getModule();
    void readModule(string name);
    void runFunction(string functionName);

  private:
    LLVMContext context;
    SMDiagnostic Err;
    unique_ptr<Module> module;
    unique_ptr<ExecutionEngine> executionEngine;

    void runLoopFinder();
};
#endif
