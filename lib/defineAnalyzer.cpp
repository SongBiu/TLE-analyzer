//
// Created by lisong on 2019-03-29.
//
// 获取define在loop外面的输入变量
#include "defineAnalyzer.h"

void DefineAnalyzer::getAnalysisUsage(AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<LoopInfoWrapperPass>();
}

bool DefineAnalyzer::runOnFunction(Function &F) {
    if (Util::functionMain != F.getName()) {
        return false;
    }
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (Loop *loop : loopInfo) {
        for (BasicBlock *basicBlock : loop->getBlocks()) {
            for (Instruction &instruction : basicBlock->getInstList()) {
                outs() << "Instruction: " << instruction.getOpcodeName() << ": "
                       << instruction << "\n";
                for (Use &use : instruction.operands()) {
                    if (((Instruction *) use.get())->getParent()) {
                        outs() << use.get() << ":"
                               << loop->contains((Instruction *) use.get()) << "\n";
                    }
                }
                outs() << "end Instruction\n\n";
            }
        }
    }
    return false;
}
