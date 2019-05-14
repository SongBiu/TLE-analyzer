//
// Created by lisong on 2019-03-29.
//

#ifndef PASS_DEFINE_ANALYZER_H
#define PASS_DEFINE_ANALYZER_H

#include "manager/LoopManager.h"
#include "util/Magic.h"
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/Pass.h>
#include <llvm/PassAnalysisSupport.h>
#include <llvm/Support/Casting.h>
#include <llvm/Support/raw_ostream.h>
namespace analyzer {
class DefineAnalyzer : public llvm::FunctionPass {
public:
    static char pid;

    DefineAnalyzer() : FunctionPass(pid){};

    virtual void getAnalysisUsage(llvm::AnalysisUsage &usage) const override;

    bool runOnFunction(llvm::Function &F) override;

private:
};

char DefineAnalyzer::pid = 1;
} // namespace analyzer

#endif // DEFINE_ANALYZER_H
