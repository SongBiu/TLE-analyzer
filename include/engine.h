#ifndef ENGINE_H
#define ENGINE_H
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/Module.h>
#include "loopFinder.h"
using namespace llvm;
using namespace std;
class Engine {
public:
    Engine() {
        PM.add(new LoopInfoWrapperPass());
        PM.add(new LoopFinder());
    }
    void run(unique_ptr<Module> module);
private:
    legacy::PassManager PM;
};
#endif