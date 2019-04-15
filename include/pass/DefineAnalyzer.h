//
// Created by lisong on 2019-03-29.
//

#ifndef PASS_DEFINEANALYZER_H
#define PASS_DEFINEANALYZER_H

#include <llvm/Pass.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/Casting.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include "Util.h"

using namespace llvm;

class DefineAnalyzer : public FunctionPass {
public:
    static char pid;

    DefineAnalyzer() : FunctionPass(pid) {};

    virtual void getAnalysisUsage(AnalysisUsage &usage) const override;

    bool runOnFunction(Function &F) override;

private:
};

char DefineAnalyzer::pid = 1;
#endif //DEFINE_ANALYZER_H
