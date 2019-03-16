#include "loopFinder.h"

void LoopFinder::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}

bool LoopFinder::runOnFunction(Function &F) {
    if (F.getName() != Util::functionMain) {
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
    Function *loopInit = F.getParent()->getFunction(Util::functionLoopInit);
    BasicBlock *preHeader = loop->getLoopPreheader();
    insertCallInBasicBlock(preHeader, loopInit, loop);

    Function *loopRun = F.getParent()->getFunction(Util::functionLoopRun);
    BasicBlock *header = loop->getExitBlock()->getPrevNode();
    insertCallInBasicBlock(header, loopRun, loop);

    Function *loopExit = F.getParent()->getFunction(Util::functionLoopExit);
    BasicBlock *exitBB = loop->getExitBlock();
    insertCallInBasicBlock(exitBB, loopExit, loop);
}

void LoopFinder::dumpBranchRuntime(vector<BasicBlock *> basicBlocks) {
    for (BasicBlock *basicBlock : basicBlocks) {
        for (Instruction &instruction : *basicBlock) {
            if (instruction.getOpcode() == Util::brOpCode &&
                instruction.getNumOperands() == Util::brTargetOpNum) {
                // IRBuilder<> builder(&instruction);
                // vector<Value *> argContainer;
                // argContainer.push_back(instruction.getOperand(0));
                // ArrayRef<Value *> args(argContainer);
                // Function *f =
                // basicBlock->getParent()->getParent()->getFunction(
                // "_Z6branchb");
                // builder.CreateCall(f, args);
            }
        }
    }
}

void LoopFinder::insertCallInBasicBlock(BasicBlock *basicBlock, Function *call,
                                        Loop *loop) {
    Instruction *entryInstruction = &*basicBlock->getInstList().begin();
    IRBuilder<> builder(entryInstruction);
    Value *args[] = {builder.getInt64((uint64_t) loop)};
    try {
        builder.CreateCall(call, args);
    } catch (exception &e) {
        outs() << e.what() << "\n";
    }
}