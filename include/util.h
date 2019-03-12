#ifndef UTILS_H
#define UTILS_H
#include <cstdlib>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/TargetSelect.h>
#include <map>
#include <string>
#include <vector>
using namespace std;
using namespace llvm;
class Util {
  public:
    static const int brOpCode = 2;
    static const int brTargetOpNum = 3;
    static const string functionLoopInit;
    static const string functionLoopRun;
    static const string functionLoopExit;
    static const string functionBranch;
    static unique_ptr<ExecutionEngine>
    getExecuteEngine(unique_ptr<Module> module);

    static void initTarget();

    static void linkFunctionLibs(string IRName);

    static vector<string> nullArgs();

    static void insertCallInBasicBlock(BasicBlock *basicBlock, Function *call,
                                       Loop **loopPtr);
};
#endif