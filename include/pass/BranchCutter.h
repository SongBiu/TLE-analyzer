#ifndef PASS_BRANCH_CUTTER_H
#define PASS_BRANCH_CUTTER_H
#include "util/Magic.h"
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Pass.h>
#include <string>
#include <vector>
namespace analyzer {
class BranchCutter : public llvm::FunctionPass {
private:
    std::string dfsFunction;
    std::string resultName;

public:
    static char pid;

    BranchCutter(std::string dfsFunction, std::string resultName)
        : FunctionPass(pid), dfsFunction(dfsFunction), resultName(resultName){};

    bool runOnFunction(llvm::Function &F) override;

    std::vector<llvm::BasicBlock *> getStoreBlocks(llvm::Function &F);

    void markStoreBlocks(std::vector<llvm::BasicBlock *> &storeBlocks);

    llvm::Instruction *findCallDfs(llvm::Function &F);

    void insertDump(llvm::Instruction *instruction);
};
char BranchCutter::pid = 0;
} // namespace analyzer

#endif