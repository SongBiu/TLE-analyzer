#include "loopFinder.h"
void LoopFinder::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}
bool LoopFinder::runOnFunction(Function &F) {
    if (F.getName() == "_Z4demov") {
        return false;
    }
    Function *demo = F.getParent()->getFunction("_Z4demov");
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (LoopInfo::iterator loop = loopInfo.begin(); loop != loopInfo.end();
         loop++) {
        BasicBlock *basicBlock = getHeaderOfLoop(*loop);
        Instruction *instruction = &*(basicBlock->getInstList().begin());
        IRBuilder<> builder(instruction);
        builder.CreateCall(demo, None);
    }
    // outs() << F.getName() << "\n";
    return false;
};

BasicBlock *LoopFinder::getHeaderOfLoop(Loop *loop) const {
    return loop->getHeader();
}