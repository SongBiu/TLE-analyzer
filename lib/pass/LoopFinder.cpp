#include "pass/LoopFinder.h"
namespace analyzer {
void LoopFinder::getAnalysisUsage(llvm::AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<llvm::LoopInfoWrapperPass>();
}

bool LoopFinder::runOnFunction(llvm::Function &F) {
    if (F.getName() != Magic::functionMain) {
        return false;
    }
    llvm::LoopInfo &loopInfo = getAnalysis<llvm::LoopInfoWrapperPass>().getLoopInfo();
    for (llvm::Loop *loop : loopInfo) {
        markLoopInFunction(F, loop);
        //        dumpBranchRuntime(loop->getBlocksVector());
        for (llvm::Loop *subLoop : loop->getSubLoops()) {
            markLoopInFunction(F, subLoop);
            //            dumpBranchRuntime(subLoop->getBlocksVector());
        }
    }
    return true;
};

void LoopFinder::markLoopInFunction(llvm::Function &F, llvm::Loop *loop) {
    llvm::Function *loopInit = F.getParent()->getFunction(Magic::functionLoopInit);
    llvm::BasicBlock *preHeader = loop->getLoopPreheader();
    insertCallInBasicBlock(preHeader, loopInit, loop);

    llvm::Function *loopRun = F.getParent()->getFunction(Magic::functionLoopRun);
    llvm::BasicBlock *header = loop->getExitBlock()->getPrevNode();
    insertCallInBasicBlock(header, loopRun, loop);

    llvm::Function *loopExit = F.getParent()->getFunction(Magic::functionLoopExit);
    llvm::BasicBlock *exitBB = loop->getExitBlock();
    insertCallInBasicBlock(exitBB, loopExit, loop);
}

void LoopFinder::dumpBranchRuntime(std::vector<llvm::BasicBlock *> basicBlocks) {
    for (llvm::BasicBlock *basicBlock : basicBlocks) {
        for (llvm::Instruction &instruction : *basicBlock) {
            if (instruction.getOpcode() == Magic::brOpCode && instruction.getNumOperands() == Magic::brTargetOpNum) {
                llvm::IRBuilder<> builder(&instruction);
                std::vector<llvm::Value *> argContainer;
                argContainer.push_back(instruction.getOperand(0));
                llvm::ArrayRef<llvm::Value *> args(argContainer);
                llvm::Function *f = basicBlock->getParent()->getParent()->getFunction(Magic::functionBranch);
                builder.CreateCall(f, args);
            }
        }
    }
}

void LoopFinder::insertCallInBasicBlock(llvm::BasicBlock *basicBlock, llvm::Function *call, llvm::Loop *loop) {
    llvm::Instruction *entryInstruction = basicBlock->getFirstNonPHI();
    llvm::IRBuilder<> builder(entryInstruction);
    llvm::Value *args[] = {builder.getInt64((uint64_t)loop)};
    try {
        builder.CreateCall(call, args);
    } catch (std::exception &e) {
        llvm::outs() << e.what() << "\n";
    }
}

} // namespace analyzer
