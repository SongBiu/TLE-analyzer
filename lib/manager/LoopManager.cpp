#include "manager/LoopManager.h"
void LoopManager::dumpLoop() {
    for (BasicBlock *basicBlock : loop->getBlocksVector()) {
        outs() << *basicBlock << "\n";
    }
}

void LoopManager::setLoop(Loop *loop) { this->loop = loop; }

Instruction *LoopManager::getEntrySubLoop() {
    if (loop->getSubLoopsVector().empty()) {
        return NULL;
    }
    Loop *subLoop = *loop->getSubLoopsVector().begin();
    BasicBlock *entryBlock = *subLoop->getBlocksVector().begin();
    return entryBlock->getFirstNonPHI();
}

Instruction *LoopManager::getFirstNoIOCall() {
    for (BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (Instruction &instruction : *basiBlock) {
            if (instruction.getOpcode() == 55) {
                CallInst *callInstruction = dyn_cast<CallInst>(&instruction);
                if ("scanf" != callInstruction->getCalledFunction()->getName() &&
                    "printf" != callInstruction->getCalledFunction()->getName()) {
                    return &instruction;
                }
            }
        }
    }
    return NULL;
}

Instruction *LoopManager::getLastLoad() {
    Instruction *ret = NULL;
    for (BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (Instruction &instruction : *basiBlock) {
            if (Magic::loadOpCode == instruction.getOpcode()) {
                ret = &instruction;
            }
        }
    }
    return ret;
}

Instruction *LoopManager::insertArgs(Instruction *instruction, Function *function, ArrayRef<Value *> args) {
    if (!instruction) {
        return NULL;
    }
    IRBuilder<> builder(instruction);
    return builder.CreateCall(function, args);
}

Instruction *LoopManager::insertNoArgs(Instruction *instruction, Function *function) {
    if (!instruction) {
        return NULL;
    }
    IRBuilder<> builder(instruction);
    return builder.CreateCall(function, {});
}

Instruction *dumpAndCompare(Instruction *Instruction, Function *dump, Function *compare) { return NULL; }

Instruction *LoopManager::getInsertPoint() {
    Instruction *firstNonIOCall = getFirstNoIOCall();
    Instruction *lastLoad = getLastLoad();
    Instruction *entrySubLoop = getEntrySubLoop();
    Instruction *insertPoint;
    if (entrySubLoop) {
        return min(entrySubLoop, min(lastLoad, firstNonIOCall));
    }
    return min(lastLoad, firstNonIOCall);
}

vector<Instruction *> LoopManager::getLoadInstructions() {
    vector<Instruction *> loadInstructions;
    vector<Instruction *> stopInstructions = {getEntrySubLoop(), getFirstNoIOCall()};
    for (BasicBlock *basiBlock : loop->getBlocksVector()) {
        for (Instruction &instruction : *basiBlock) {
            if (Magic::loadOpCode != instruction.getOpcode()) {
                continue;
            }
            if (find(stopInstructions.begin(), stopInstructions.end(), &instruction) == stopInstructions.end()) {
                loadInstructions.push_back(&instruction);
            }
            if (&instruction == getLastLoad()) {
                return loadInstructions;
            }
        }
    }
    return loadInstructions;
}
