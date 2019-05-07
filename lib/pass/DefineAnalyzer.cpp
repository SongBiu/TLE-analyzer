//
// Created by lisong on 2019-03-29.
//
#include "pass/DefineAnalyzer.h"

void DefineAnalyzer::getAnalysisUsage(AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<LoopInfoWrapperPass>();
}

bool DefineAnalyzer::runOnFunction(Function &F) {
    if (Magic::functionMain != F.getName()) {
        return false;
    }
    LoopInfo &loopInfo = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
    LoopManager *loopManager = new LoopManager();
    for (Loop *loop : loopInfo) {
        loopManager->setLoop(loop);
        vector<Instruction *> loadInstructions = loopManager->getLoadInstructions();
        Instruction *insertPoint = loopManager->getInsertPoint();
        Function *initHash = F.getParent()->getFunction(Magic::initHash);
        Function *addHash = F.getParent()->getFunction(Magic::addHash);
        Function *dumpHash = F.getParent()->getFunction(Magic::dumpHash);
        Function *compareHash = F.getParent()->getFunction(Magic::compareHash);

        for (Instruction *instruction : loadInstructions) {
            loopManager->insertArgs(instruction->getNextNode(), addHash, {dyn_cast<Value>(instruction)});
        }

        loopManager->insertNoArgs(*loadInstructions.begin(), initHash);

        loopManager->insertNoArgs(insertPoint, dumpHash);
        loopManager->insertNoArgs(insertPoint, compareHash);
    }
    return true;
}
