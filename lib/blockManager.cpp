//
// Created by lisong on 2019-03-19.
//
#include "blockManager.h"

void BlockManager::insertBlockAfterBlock(BasicBlock *from, BasicBlock *inserter) {
    Instruction *lastInstruction = &from->getInstList().back();
    if (Util::brOpCode == lastInstruction->getOpcode()) {
        if (3 == lastInstruction->getNumOperands()) {

        } else {
            lastInstruction->getOperand(0);

        }
    } else {
        IRBuilder<> builder(lastInstruction);
        builder.CreateBr(inserter);
        builder.SetInsertPoint(&inserter->getInstList().back());
        builder.CreateBr(from->getNextNode());
    }
}

void
BlockManager::insertFunctionAfterBlock(BasicBlock *block, Function *function, ArrayRef<Value *> args, string name) {

}
