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
    unique_ptr<Module> &getModule();
    Function *getFunction(string name);
    void readModule(string name);
    ExecutionEngine *loadExecuteEngine();
    void runFunction(string functionName = "main");
    void runLoopFinder();
    void dumpGlobalVariables();

private:
    LLVMContext context;
    SMDiagnostic Err;
    string error;
    unique_ptr<Module> module;
    bool compileCxx2IR(string name);
    void linkLib(string name);
};
#endif
