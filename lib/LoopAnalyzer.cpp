#include "LoopAnalyzer.h"
void LoopAnalyzer::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}
bool LoopAnalyzer::runOnFunction(Function &F) {
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (LoopInfo::iterator currentLoop = loopInfo.begin();
         currentLoop != loopInfo.end(); currentLoop++) {
             outs() << *getHeaderOfLoop(*currentLoop) << "\n";
    }
    // for (auto currentBasicBlock = F.getBasicBlockList().begin();
    //      currentBasicBlock != F.getBasicBlockList().end();
    //      currentBasicBlock++) {
    //     for (auto currentInstruction =
    //     currentBasicBlock->getInstList().begin();
    //          currentInstruction != currentBasicBlock->getInstList().end();
    //          currentInstruction++) {
    //         if (!strcmp(currentInstruction->getOpcodeName(), "br")) {
    //             outs() << *currentInstruction << "\n";
    //         }
    //     }
    // }
    return false;
};

BasicBlock* LoopAnalyzer::getHeaderOfLoop(Loop* loop) const {
    return loop->getHeader();
}