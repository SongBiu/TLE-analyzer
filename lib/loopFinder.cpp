#include "loopFinder.h"
void LoopFinder::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}
bool LoopFinder::runOnFunction(Function &F) {
    if (F.getName() != "main") {
        return false;
    }
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (Loop *loop : loopInfo) {
        markLoopInFunction(F, loop);
        dumpBranchRuntime(loop->getBlocksVector());
    }
    return true;
};

void LoopFinder::markLoopInFunction(Function &F, Loop *loop) {
    Function *loopInit = F.getParent()->getFunction("_Z8loopInitv");
    BasicBlock *preHeader = loop->getLoopPreheader();
    Util::insertCallInBasicBlock(preHeader, loopInit);

    Function *loopRun = F.getParent()->getFunction("_Z7loopRunv");
    BasicBlock *header = loop->getHeader();
    Util::insertCallInBasicBlock(header, loopRun);

    Function *loopEnd = F.getParent()->getFunction("_Z7loopEndv");
    BasicBlock *exitBB = loop->getExitBlock();
    Util::insertCallInBasicBlock(exitBB, loopEnd);
}

void LoopFinder::dumpBranchRuntime(vector<BasicBlock *> basicBlocks) {
    for (BasicBlock *basicBlock : basicBlocks) {
        for (Instruction &instruction : *basicBlock) {
            if (instruction.getOpcode() == Util::brOpCode &&
                instruction.getNumOperands() == Util::brTargetOpNum) {
                outs() << "--------info-------------\n";
                outs() << instruction << ": " << instruction.getOpcode()
                       << "\n";
                outs() << "--------args-------------\n";
                for (int i = 0; i < instruction.getNumOperands(); i++) {
                    outs() << instruction.getOperand(i) << ": "
                           << *instruction.getOperand(i) << "\n";
                }
                outs() << "--------over-------------\n";
            }
        }
    }
}