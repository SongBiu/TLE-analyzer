#ifndef FUNCTIONANALYZER_CPP
#define FUNCTIONANALYZER_CPP
#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/PassAnalysisSupport.h>
#include "util.h"
using namespace llvm;
class FunctionAnalyzer: public FunctionPass {
public:
    static char pid;
    FunctionAnalyzer(): FunctionPass(pid) {};
    bool runOnFunction(Function & F);
};
#endif