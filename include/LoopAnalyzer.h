#ifndef LOOPANALYZER_H
#define LOOPANALYZER_H
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/PassAnalysisSupport.h>
#include <cstring>
#include "util.h"
using namespace llvm;
class LoopAnalyzer: public FunctionPass {
public:
    static char pid;
    LoopAnalyzer(): FunctionPass(pid) {};
    void getAnalysisUsage(AnalysisUsage &AU);
    bool runOnFunction(Function & F);
};
char LoopAnalyzer::pid = 0;
#endif