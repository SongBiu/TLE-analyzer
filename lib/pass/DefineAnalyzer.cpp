//
// Created by lisong on 2019-03-29.
//
#include "pass/DefineAnalyzer.h"
namespace analyzer {
void DefineAnalyzer::getAnalysisUsage(llvm::AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<llvm::LoopInfoWrapperPass>();
}

bool DefineAnalyzer::runOnFunction(llvm::Function &F) {
    return false;
    if (Magic::functionMain != F.getName()) {
        return false;
    }
    llvm::LoopInfo &loopInfo = getAnalysis<llvm::LoopInfoWrapperPass>().getLoopInfo();
    LoopManager *loopManager = new LoopManager();
    for (llvm::Loop *loop : loopInfo) {
        loopManager->setLoop(loop);
        std::vector<llvm::Instruction *> loadInstructions = loopManager->getLoadInstructions();
        llvm::Instruction *insertPoint = loopManager->getInsertPoint();

        llvm::Function *initHash = F.getParent()->getFunction(Magic::initHash);
        llvm::Function *addHash = F.getParent()->getFunction(Magic::addHash);
        llvm::Function *dumpHash = F.getParent()->getFunction(Magic::dumpHash);
        llvm::Function *compareHash = F.getParent()->getFunction(Magic::compareHash);

        for (llvm::Instruction *instruction : loadInstructions) {
            loopManager->insertArgs(instruction->getNextNode(), addHash, {llvm::dyn_cast<llvm::Value>(instruction)});
        }

        loopManager->insertNoArgs(*loadInstructions.begin(), initHash);

        loopManager->insertNoArgs(insertPoint, dumpHash);
        loopManager->insertNoArgs(insertPoint, compareHash);
    }
    return true;
}
} // namespace analyzer
