#include "pass/BranchCutter.h"
namespace analyzer {
bool BranchCutter::runOnFunction(llvm::Function &F) {
    std::string name = F.getName();
    if ("main" == name) {
        llvm::Instruction *instruction = findCallDfs(F);
        insertDump(instruction);
        return true;
    }
    if (!(strstr(name.c_str(), dfsFunction.c_str()))) {
        return false;
    }
    std::vector<llvm::BasicBlock *> storeBlocks = getStoreBlocks(F);
    markStoreBlocks(storeBlocks);
    return !storeBlocks.empty();
    // Instruction *firstInstruction = F.getBasicBlockList().begin()->getFirstNonPHI();
    // Function *function = F.getParent()->getFunction("_Z8countAddv");
    // IRBuilder<> builder(firstInstruction);
    // builder.CreateCall(function, {});
    // return true;
}

void stubDfsCall() {
    
}

std::vector<llvm::BasicBlock *> BranchCutter::getStoreBlocks(llvm::Function &F) {
    std::vector<llvm::BasicBlock *> storeBlocks;
    for (llvm::BasicBlock &basicBlock : F.getBasicBlockList()) {
        for (llvm::Instruction &instruction : basicBlock.getInstList()) {
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

void BranchCutter::markStoreBlocks(std::vector<llvm::BasicBlock *> &storeBlocks) {
    for (llvm::BasicBlock *basicBlock : storeBlocks) {
        llvm::Instruction *instruction = basicBlock->getFirstNonPHI();
        llvm::IRBuilder<> builder(instruction);
        llvm::Function *function = basicBlock->getModule()->getFunction("_Z8countAddv");
        builder.CreateCall(function, {});
    }
}

llvm::Instruction *BranchCutter::findCallDfs(llvm::Function &F) {
    for (llvm::BasicBlock &basicBlock : F.getBasicBlockList()) {
        for (llvm::Instruction &instruction : basicBlock.getInstList()) {
            if (!strcmp(instruction.getOpcodeName(), "call")) {
                for (int i = 0; i < instruction.getNumOperands(); i++) {
                    std::string name = instruction.getOperandUse(i).get()->getName();
                    if (name.length() == 0) {
                        continue;
                    }
                    if (strstr(name.c_str(), dfsFunction.c_str())) {
                        return &instruction;
                    }
                }
            }
        }
    }
    return NULL;
}

void BranchCutter::insertDump(llvm::Instruction *instruction) {
    if (!instruction) {
        llvm::outs() << "there is no call dfs\n";
        return;
    }
    llvm::Instruction *next = instruction->getNextNode();
    llvm::IRBuilder<> builder(instruction);
    llvm::Function *init = instruction->getModule()->getFunction("");
    builder.CreateCall(init, {});
    builder.SetInsertPoint(next);
    llvm::Function *dump = instruction->getModule()->getFunction("_Z9countDumpv");
    builder.CreateCall(dump, {});
}
} // namespace analyzer
