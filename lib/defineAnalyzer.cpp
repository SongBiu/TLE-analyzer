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
                for (Use &use : instruction.operands()) {
                    if (((Instruction *)use.get())->getParent() &&
                        !loop->contains((Instruction *)use.get())) {
                        if (use.get()->getType()->getTypeID() == 7) {
                            continue;
                        }
                        outs() << "-------------------\n\n";
                        outs() << instruction.getOpcodeName() << "\n";
                        outs() << *use.get() << "\n";
                        outs() << *use.get()->getType() << "\n\n\n";
                        outs() << use.get()->getType()->getTypeID() << "\n";
                        IRBuilder<> builder((Instruction *)use.get());
                        Function *function =
                            F.getParent()->getFunction("Z4dumpi");
                        builder.CreateCall(function,
                                           ArrayRef<Value *>({use.get()}));
                    }
                }
            }
        }
    }
    return false;
}
