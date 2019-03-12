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
    for (Loop *loop: loopInfo) {
        markLoopInFunction(F, loop);
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
