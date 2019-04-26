#include "pass/BranchCutter.h"
bool BranchCutter::runOnFunction(Function &F) {
    string name = F.getName();
    if (!(strstr(name.c_str(), "dfs") || strstr(name.c_str(), "Dfs") || strstr(name.c_str(), "DFS"))) {
        return false;
    }
    auto storeBlocks = getStoreBlocks(F);
    outs() << storeBlocks.size() << "\n";
    return false;
}

vector<BasicBlock *> BranchCutter::getStoreBlocks(Function &F) {
    vector<BasicBlock*> storeBlocks;
    for (BasicBlock &basicBlock : F.getBasicBlockList()) {
        for (Instruction &instruction : basicBlock.getInstList()) {
            if (Magic::storeOpCode == instruction.getOpcode()) {
                if (instruction.getNumOperands() < 2 || "answer" != instruction.getOperandUse(1)->getName()) {
                    continue;
                }
                storeBlocks.push_back(&basicBlock);
                break;
            }
        }
    }
    return storeBlocks;
}