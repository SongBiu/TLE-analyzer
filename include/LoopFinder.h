#ifndef LOOP_FINDER_H
#define LOOP_FINDER_H
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/PassAnalysisSupport.h>
#include <cstring>
#include "util.h"
using namespace llvm;
class LoopFinder: public FunctionPass {
public:
    static char pid;
    LoopFinder(): FunctionPass(pid) {};
    virtual void getAnalysisUsage(AnalysisUsage &AU) const override;
    bool runOnFunction(Function & F) override;

private:
};
char LoopFinder::pid = 0;
#endif