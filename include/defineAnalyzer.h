//
// Created by lisong on 2019-03-29.
//

#ifndef DEFINE_ANALYZER_H
#define DEFINE_ANALYZER_H

#include <llvm/Pass.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Analysis/LoopInfo.h>

using namespace llvm;

class DefineAnalyzer : public FunctionPass {
public:
    static char pid;

    DefineAnalyzer();

    virtual void getAnalysisUsage(AnalysisUsage &usage) const override;

    bool runOnFunction(Function &F) override;

private:
};

char DefineAnalyzer::pid = 0;
#endif //DEFINE_ANALYZER_H
