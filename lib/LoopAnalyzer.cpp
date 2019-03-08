#include "LoopAnalyzer.h"
void LoopAnalyzer::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
    AU.setPreservesCFG();
    AU.addRequired<LoopInfoWrapperPass>();
}
bool LoopAnalyzer::runOnFunction(Function &F) {
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (auto currentBB = loopInfo.begin(); currentBB != loopInfo.end(); currentBB++) {
        outs() << **currentBB << "\n";
    }
    for (auto currentBasicBlock = F.getBasicBlockList().begin();
         currentBasicBlock != F.getBasicBlockList().end();
         currentBasicBlock++) {
        for (auto currentInstruction = currentBasicBlock->getInstList().begin();
             currentInstruction != currentBasicBlock->getInstList().end();
             currentInstruction++) {
            if (!strcmp(currentInstruction->getOpcodeName(), "br")) {
                outs() << *currentInstruction << "\n";
            }
        }
    }
    return false;
};