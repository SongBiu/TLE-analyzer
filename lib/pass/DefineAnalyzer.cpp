//
// Created by lisong on 2019-03-29.
//
// 获取define在loop外面的输入变量
#include "pass/DefineAnalyzer.h"

void DefineAnalyzer::getAnalysisUsage(AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<LoopInfoWrapperPass>();
}

bool DefineAnalyzer::runOnFunction(Function &F) {
    // outs() << F.getName() << "\n";
    // return false;
    if (Util::functionMain != F.getName()) {
        return false;
    }
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    for (Loop *loop : loopInfo) {
        for (BasicBlock *basicBlock : loop->getBlocks()) {
            for (Instruction &instruction : basicBlock->getInstList()) {
                if (!(instruction.getOpcode() == Util::loadOpCode || instruction.getOpcode() == Util::storeOpCode ||
                      instruction.isBinaryOp())) {
                    continue;
                }
                for (Use &use : instruction.operands()) {
                    Instruction *lastInstruction = dyn_cast<Instruction>(use.get());
                    if (lastInstruction && !loop->contains(lastInstruction)) {
                        if (!use.get()->getType()->isPointerTy()) {
                            continue;
                        }
                        IRBuilder<> builder(&instruction);
                        Function *function = F.getParent()->getFunction("_Z4dumpi");
                        vector<Value *> container = {
                            builder.CreatePtrToInt(use.get(), Type::getInt64Ty(F.getContext()))};
                        ArrayRef<Value *> args(container);
                        builder.CreateCall(function, args);
                    }
                }
            }
        }
    }
    return true;
}
