#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <string>
#include <vector>
#include <map>
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

    static vector<string> nullArgs();

    static void insertCallInBasicBlock(BasicBlock* basicBlock, Function* call);

};
#endif