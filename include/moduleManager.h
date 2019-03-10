#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <string>
using namespace llvm;
using namespace std;
class ModuleManager {
private:
    LLVMContext context;
    SMDiagnostic Err;
public:
    unique_ptr<Module> readModule(string name);
};
#endif
