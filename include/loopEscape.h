//
// Created by lisong on 2019-03-18.
//

#ifndef LOOP_ESCAPE_H
#define LOOP_ESCAPE_H

#include <llvm/Analysis/LoopInfo.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;

class LoopEscape {
private:
public:
    void escapeLoop(Loop *loop);
};

#endif //LOOP_ESCAPE_H
