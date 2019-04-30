#ifndef PASS_BRANCH_CUTTER_H
#define PASS_BRANCH_CUTTER_H
#include "util/Magic.h"
#include <llvm/IR/Function.h>
#include <llvm/Pass.h>
#include <llvm/IR/IRBuilder.h>
#include <vector>
using namespace llvm;
using namespace std;
class BranchCutter : public FunctionPass {
private:
public:
    static char pid;
    BranchCutter() : FunctionPass(pid){};
    bool runOnFunction(Function &F) override;
    vector<BasicBlock *> getStoreBlocks(Function &F);
    void markStoreBlocks(vector<BasicBlock *> &storeBlocks);
    Instruction *findCallDfs(Function &F);
    void insertDump(Instruction *instruction);
};
char BranchCutter::pid = 0;
#endif