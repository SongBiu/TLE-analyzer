//
// Created by lisong on 2019-03-29.
//

#include "defineAnalyzer.h"


DefineAnalyzer::DefineAnalyzer() : FunctionPass(pid) {}

void DefineAnalyzer::getAnalysisUsage(AnalysisUsage &usage) const {
    usage.setPreservesCFG();
    usage.addRequired<LoopInfoWrapperPass>();
}

bool DefineAnalyzer::runOnFunction(Function &F) {
    return false;
}
