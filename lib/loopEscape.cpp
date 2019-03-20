//
// Created by lisong on 2019-03-18.
//
#include "loopEscape.h"

void LoopEscape::escapeLoop(Loop *loop) {
    BasicBlock *header = loop->getExitingBlock()->getPrevNode();
    BasicBlock *next = loop->getExitBlock()->getNextNode();
    BasicBlock *exit = loop->getExitBlock();
    Instruction *entryInstruction = header->getFirstNonPHI();
    IRBuilder<> builder(entryInstruction);
    Value *condition = builder.getTrue();
//    builder.CreateCondBr(condition, exit, next, entryInstruction);
    outs() << "condition is " << *condition << " true is " << exit << " and false is "
           << next << "\n";
}

