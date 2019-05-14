//
// Created by lisong on 2019-03-19.
//
#include "manager/BlockManager.h"

namespace analyzer {
void BlockManager::insertBlockAfterBlock(llvm::BasicBlock *from, llvm::BasicBlock *inserter) {
    llvm::Instruction *lastInstruction = &from->getInstList().back();
    if (Magic::brOpCode == lastInstruction->getOpcode()) {
        if (3 == lastInstruction->getNumOperands()) {

        } else {
            lastInstruction->getOperand(0);
        }
    } else {
        llvm::IRBuilder<> builder(lastInstruction);
        builder.CreateBr(inserter);
        builder.SetInsertPoint(&inserter->getInstList().back());
        builder.CreateBr(from->getNextNode());
    }
}

void BlockManager::insertFunctionAfterBlock(llvm::BasicBlock *block, llvm::Function *function,
                                            llvm::ArrayRef<llvm::Value *> args, std::string name) {}
} // namespace analyzer
