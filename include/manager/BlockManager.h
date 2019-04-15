//
// Created by lisong on 2019-03-19.
//

#ifndef MANAGER_BLOCKMANAGER_H
#define MANAGER_BLOCKMANAGER_H

#include "Util.h"
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

using namespace llvm;
using namespace std;

class BlockManager {
private:
    void insertBlockAfterBlock(BasicBlock *from, BasicBlock *inserter);
public:
    void insertFunctionAfterBlock(BasicBlock *block, Function *function, ArrayRef<Value *> args, string name = "jumper");
};

#endif //BLOCK_MANAGER_H
