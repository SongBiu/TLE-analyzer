#ifndef LOOP_FINDER_H
#define LOOP_FINDER_H
#include "util.h"
#include <cstring>
#include <llvm/IR/Function.h>
#include <llvm/Pass.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Support/raw_ostream.h>
using namespace llvm;
class LoopFinder : public FunctionPass {
  public:
    static char pid;
    LoopFinder() : FunctionPass(pid){};
    virtual void getAnalysisUsage(AnalysisUsage &AU) const override;
    bool runOnFunction(Function &F) override;

  private:
    void markLoopInFunction(Function &F, Loop *loop);

    void dumpBranchRuntime(vector<BasicBlock *> basicBlocks);
};
char LoopFinder::pid = 0;
#endif