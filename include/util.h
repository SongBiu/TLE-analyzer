#ifndef UTILS_H
#define UTILS_H
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/TargetSelect.h>
#include <string>
#include <cstdlib>
using namespace std;
using namespace llvm;
class Util {
  public:
    static unique_ptr<ExecutionEngine>
    getExecuteEngine(unique_ptr<Module> module);

    static void insertFunctionIntoModule(Function *function,
                                         unique_ptr<Module> module);

    static void initTarget();

    static void linkFunctionLibs(string IRName);
};
#endif