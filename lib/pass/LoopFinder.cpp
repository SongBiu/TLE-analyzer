#include "pass/LoopFinder.h"

void LoopFinder::getAnalysisUsage(AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<LoopInfoWrapperPass>();
}

bool LoopFinder::runOnFunction(Function &F) {
    if (F.getName() != Magic::functionMain) {
        return false;
    }
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (Loop *loop : loopInfo) {
        markLoopInFunction(F, loop);
        //        dumpBranchRuntime(loop->getBlocksVector());
        for (Loop *subLoop : loop->getSubLoops()) {
            markLoopInFunction(F, subLoop);
            //            dumpBranchRuntime(subLoop->getBlocksVector());
        }
    }
    return true;
};

void LoopFinder::markLoopInFunction(Function &F, Loop *loop) {
    Function *loopInit = F.getParent()->getFunction(Magic::functionLoopInit);
    BasicBlock *preHeader = loop->getLoopPreheader();
    insertCallInBasicBlock(preHeader, loopInit, loop);

    Function *loopRun = F.getParent()->getFunction(Magic::functionLoopRun);
    BasicBlock *header = loop->getExitBlock()->getPrevNode();
    insertCallInBasicBlock(header, loopRun, loop);

    Function *loopExit = F.getParent()->getFunction(Magic::functionLoopExit);
    BasicBlock *exitBB = loop->getExitBlock();
    insertCallInBasicBlock(exitBB, loopExit, loop);
}

void LoopFinder::dumpBranchRuntime(vector<BasicBlock *> basicBlocks) {
    for (BasicBlock *basicBlock : basicBlocks) {
        for (Instruction &instruction : *basicBlock) {
            if (instruction.getOpcode() == Magic::brOpCode && instruction.getNumOperands() == Magic::brTargetOpNum) {
                IRBuilder<> builder(&instruction);
                vector<Value *> argContainer;
                argContainer.push_back(instruction.getOperand(0));
                ArrayRef<Value *> args(argContainer);
                Function *f = basicBlock->getParent()->getParent()->getFunction(Magic::functionBranch);
                builder.CreateCall(f, args);
            }
        }
    }
}

void LoopFinder::insertCallInBasicBlock(BasicBlock *basicBlock, Function *call, Loop *loop) {
    Instruction *entryInstruction = basicBlock->getFirstNonPHI();
    IRBuilder<> builder(entryInstruction);
    Value *args[] = {builder.getInt64((uint64_t)loop)};
    try {
        builder.CreateCall(call, args);
    } catch (exception &e) {
        outs() << e.what() << "\n";
    }
}
