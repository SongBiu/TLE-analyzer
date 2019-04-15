#ifndef PASS_LOOPFINDER_H
#define PASS_LOOPFINDER_H

#include "Util.h"
#include <cstring>
#include <llvm/IR/Function.h>
#include <llvm/Pass.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

class LoopFinder : public FunctionPass {
public:
    static char pid;

    LoopFinder() : FunctionPass(pid) {};

    virtual void getAnalysisUsage(AnalysisUsage &usage) const override;

    bool runOnFunction(Function &F) override;


private:
    void markLoopInFunction(Function &F, Loop *loop);

    void dumpBranchRuntime(vector<BasicBlock *> basicBlocks);

    void insertCallInBasicBlock(BasicBlock *basicBlock, Function *call,
                                Loop *loop);
};

char LoopFinder::pid = 0;
#endif