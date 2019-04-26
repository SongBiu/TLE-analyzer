#ifndef PASS_BRANCH_CUTTER_H
#define PASS_BRANCH_CUTTER_H
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include "util/Magic.h"
#include <vector>
using namespace llvm;
using namespace std;
class BranchCutter : public FunctionPass {
private:
public:
    static char pid;
    BranchCutter() : FunctionPass(pid){};
    bool runOnFunction(Function &F) override;
    vector<BasicBlock*> getStoreBlocks(Function &F);
};
char BranchCutter::pid = 0;
#endif