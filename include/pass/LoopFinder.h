#ifndef PASS_LOOP_FINDER_H
#define PASS_LOOP_FINDER_H

#include "util/Magic.h"
#include <cstring>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Pass.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Support/raw_ostream.h>

namespace analyzer {
class LoopFinder : public llvm::FunctionPass {
public:
    static char pid;

    LoopFinder() : FunctionPass(pid){};

    virtual void getAnalysisUsage(llvm::AnalysisUsage &usage) const override;

    bool runOnFunction(llvm::Function &F) override;

private:
    void markLoopInFunction(llvm::Function &F, llvm::Loop *loop);

    void dumpBranchRuntime(std::vector<llvm::BasicBlock *> basicBlocks);

    void insertCallInBasicBlock(llvm::BasicBlock *basicBlock, llvm::Function *call, llvm::Loop *loop);
};
char LoopFinder::pid = 0;
} // namespace analyzer

#endif