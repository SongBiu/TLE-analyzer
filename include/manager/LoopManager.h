#ifndef MANAGER_LOOP_MANAGER_H
#define MANAGER_LOOP_MANAGER_H
#include "util/Magic.h"
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instruction.h>
#include <llvm/Support/raw_ostream.h>
#include <vector>

namespace analyzer {
class LoopManager {
private:
    llvm::Loop *loop;

public:
    void dumpLoop();
    void setLoop(llvm::Loop *loop);
    llvm::Instruction *getEntrySubLoop();
    llvm::Instruction *getFirstNoIOCall();
    llvm::Instruction *getLastLoad();
    llvm::Instruction *insertArgs(llvm::Instruction *instruction, llvm::Function *function,
                                  llvm::ArrayRef<llvm::Value *> args);
    llvm::Instruction *insertNoArgs(llvm::Instruction *instruction, llvm::Function *function);
    llvm::Instruction *dumpAndCompare(llvm::Instruction *Instruction, llvm::Function *dump, llvm::Function *compare);
    llvm::Instruction *getInsertPoint();
    std::vector<llvm::Instruction *> getLoadInstructions();
};
} // namespace analyzer

#endif