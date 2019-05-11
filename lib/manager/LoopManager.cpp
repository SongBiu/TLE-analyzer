#include "manager/LoopManager.h"
void LoopManager::dumpLoop() {
    for (llvm::BasicBlock *basicBlock : loop->getBlocksVector()) {
        llvm::outs() << *basicBlock << "\n";
    }
}

void LoopManager::setLoop(llvm::Loop *loop) { this->loop = loop; }

llvm::Instruction *LoopManager::getEntrySubLoop() {
    if (loop->getSubLoopsVector().empty()) {
        return NULL;
    }
    llvm::Loop *subLoop = *loop->getSubLoopsVector().begin();
    llvm::BasicBlock *entryBlock = *subLoop->getBlocksVector().begin();
    return entryBlock->getFirstNonPHI();
}

llvm::Instruction *LoopManager::getFirstNoIOCall() {
    for (llvm::BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (llvm::Instruction &instruction : *basiBlock) {
            if (instruction.getOpcode() == 55) {
                llvm::CallInst *callInstruction = llvm::dyn_cast<llvm::CallInst>(&instruction);
                if ("scanf" != callInstruction->getCalledFunction()->getName() &&
                    "printf" != callInstruction->getCalledFunction()->getName()) {
                    return &instruction;
                }
            }
        }
    }
    return NULL;
}

llvm::Instruction *LoopManager::getLastLoad() {
    llvm::Instruction *ret = NULL;
    for (llvm::BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (llvm::Instruction &instruction : *basiBlock) {
            if (Magic::loadOpCode == instruction.getOpcode()) {
                ret = &instruction;
            }
        }
    }
    return ret;
}

llvm::Instruction *LoopManager::insertArgs(llvm::Instruction *instruction, llvm::Function *function,
                                           llvm::ArrayRef<llvm::Value *> args) {
    if (!instruction) {
        return NULL;
    }
    llvm::IRBuilder<> builder(instruction);
    return builder.CreateCall(function, args);
}

llvm::Instruction *LoopManager::insertNoArgs(llvm::Instruction *instruction, llvm::Function *function) {
    if (!instruction) {
        return NULL;
    }
    llvm::IRBuilder<> builder(instruction);
    return builder.CreateCall(function, {});
}

llvm::Instruction *dumpAndCompare(llvm::Instruction *Instruction, llvm::Function *dump, llvm::Function *compare) {
    return NULL;
}

llvm::Instruction *LoopManager::getInsertPoint() {
    llvm::Instruction *firstNonIOCall = getFirstNoIOCall();
    llvm::Instruction *lastLoad = getLastLoad();
    llvm::Instruction *entrySubLoop = getEntrySubLoop();
    llvm::Instruction *insertPoint;
    if (entrySubLoop) {
        return std::min(entrySubLoop, std::min(lastLoad, firstNonIOCall));
    }
    return std::min(lastLoad, firstNonIOCall);
}

std::vector<llvm::Instruction *> LoopManager::getLoadInstructions() {
    std::vector<llvm::Instruction *> loadInstructions;
    std::vector<llvm::Instruction *> stopInstructions = {getEntrySubLoop(), getFirstNoIOCall()};
    for (llvm::BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (llvm::Instruction &instruction : *basiBlock) {
            if (Magic::loadOpCode != instruction.getOpcode()) {
                continue;
            }
            if (std::find(stopInstructions.begin(), stopInstructions.end(), &instruction) == stopInstructions.end()) {
                loadInstructions.push_back(&instruction);
            }
            if (&instruction == getLastLoad()) {
                return loadInstructions;
            }
        }
    }
    return loadInstructions;
}
