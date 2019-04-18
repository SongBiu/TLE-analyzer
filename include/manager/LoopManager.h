#ifndef MANAGER_LOOP_MANAGER_H
#define MANAGER_LOOP_MANAGER_H
#include "util/Magic.h"
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instruction.h>
#include <llvm/Support/raw_ostream.h>
#include <vector>
using namespace llvm;
using namespace std;
class LoopManager {
private:
    Loop *loop;

public:
    void dumpLoop();
    void setLoop(Loop *loop);
    Instruction *getEntrySubLoop();
    Instruction *getFirstNoIOCall();
    Instruction *getLastLoad();
    Instruction *insertArgs(Instruction *instruction, Function *function, ArrayRef<Value *> args);
    Instruction *insertNoArgs(Instruction *instruction, Function *function);
    Instruction *dumpAndCompare(Instruction *Instruction, Function *dump, Function *compare);
    Instruction *getInsertPoint();
    vector<Instruction *> getLoadInstructions();
};
#endif