#ifndef PASS_BRANCH_CUTTER_H
#define PASS_BRANCH_CUTTER_H
#include <llvm/Pass.h>
using namespace llvm;
using namespace std;
class BranchCutter : public FunctionPass {
private:
public:
    static char pid;
    BranchCutter() : FunctionPass(pid){};
    bool runOnFunction(Function &F) override;
};
char BranchCutter::pid = 0;
#endif