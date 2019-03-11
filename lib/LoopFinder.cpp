#include "loopFinder.h"
void LoopFinder::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}
bool LoopFinder::runOnFunction(Function &F) {
    if (F.getName() != "main") {
        return false;
    }
    Function *loopInit = F.getParent()->getFunction("_Z8loopInitv");
    Function *loopRun = F.getParent()->getFunction("_Z7loopRunv");
    Function *loopEnd = F.getParent()->getFunction("_Z7loopEndv");
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (LoopInfo::iterator loop = loopInfo.begin(); loop != loopInfo.end();
         loop++) {
        BasicBlock *preHeader = (*loop)->getLoopPreheader();
        BasicBlock *header = (*loop)->getHeader();
        BasicBlock *exitBB = (*loop)->getExitBlock();
        Util::insertCallInBasicBlock(preHeader, loopInit);
        Util::insertCallInBasicBlock(header, loopRun);
        Util::insertCallInBasicBlock(exitBB, loopEnd);
    }
    return true;
};
