#include <FunctionAnalyzer.h>
bool FunctionAnalyzer::runOnFunction(Function &F) {
    LoopInfo* loopInfo = new LoopInfo();
    outs() << *loopInfo << "\n";
    for (LoopInfo::iterator loop = loopInfo->begin(); loop != loopInfo->end(); loop++) {
        outs() << *loop << "\n";
    }
    //     for (LoopInfo::iterator L = LI.begin(), e = LI.end(); L != e; ++L) {
    //         if (L->contains(&*b)) {
    //             break; // Skip those BB that belong to a loop.
    //         }
    //     }
    //     for (BasicBlock::iterator i = b->begin(), ie = b->end(); i != ie; i++) {
    //         if (isa<CallInst>(&(*i)) || isa<InvokeInst>(&(*i))) {
    //             errs() << "Call "
    //                    << cast<CallInst>(&(*i))->getCalledFunction()->getName()
    //                    << "\n";
    //         }
    //     }
    // }
    return false;
};