#include "pass/BranchCutter.h"
bool BranchCutter::runOnFunction(Function &F) {
    string name = F.getName();
    if ("main" == name) {
        Instruction *instruction = findCallDfs(F)->getNextNode();
        insertDump(instruction);
        return true;
    }
    if (!(strstr(name.c_str(), dfsFunction.c_str()))) {
        return false;
    }
    vector<BasicBlock *> storeBlocks = getStoreBlocks(F);
    markStoreBlocks(storeBlocks);
    return !storeBlocks.empty();
}

vector<BasicBlock *> BranchCutter::getStoreBlocks(Function &F) {
    vector<BasicBlock *> storeBlocks;
    for (BasicBlock &basicBlock : F.getBasicBlockList()) {
        for (Instruction &instruction : basicBlock.getInstList()) {
            if (Magic::storeOpCode == instruction.getOpcode()) {
                if (instruction.getNumOperands() < 2 || resultName != instruction.getOperandUse(1)->getName()) {
                    continue;
                }
                storeBlocks.push_back(&basicBlock);
                break;
            }
        }
    }
    return storeBlocks;
}

void BranchCutter::markStoreBlocks(vector<BasicBlock *> &storeBlocks) {
    for (BasicBlock *basicBlock : storeBlocks) {
        Instruction *instruction = basicBlock->getFirstNonPHI();
        IRBuilder<> builder(instruction);
        Function *function = basicBlock->getModule()->getFunction("_Z8countAddv");
        builder.CreateCall(function, {});
    }
}

Instruction *BranchCutter::findCallDfs(Function &F) {
    for (BasicBlock &basicBlock : F.getBasicBlockList()) {
        for (Instruction &instruction : basicBlock.getInstList()) {
            if (!strcmp(instruction.getOpcodeName(), "call")) {
                for (int i = 0; i < instruction.getNumOperands(); i++) {
                    string name = instruction.getOperandUse(i).get()->getName();
                    if (name.length() == 0) {
                        continue;
                    }
                    if (strstr(name.c_str(), "dfs") || strstr(name.c_str(), "Dfs") || strstr(name.c_str(), "DFS")) {
                        return &instruction;
                    }
                }
            }
        }
    }
    return NULL;
}

void BranchCutter::insertDump(Instruction *instruction) {
    if (!instruction) {
        outs() << "there is no call dfs\n";
        return;
    }
    IRBuilder<> builder(instruction);
    Function *function = instruction->getModule()->getFunction("_Z9countDumpv");
    builder.CreateCall(function, {});
}