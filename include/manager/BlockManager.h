//
// Created by lisong on 2019-03-19.
//

#ifndef MANAGER_BLOCK_MANAGER_H
#define MANAGER_BLOCK_MANAGER_H

#include "util/Magic.h"
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

class BlockManager {
private:
    void insertBlockAfterBlock(llvm::BasicBlock *from, llvm::BasicBlock *inserter);
public:
    void insertFunctionAfterBlock(llvm::BasicBlock *block, llvm::Function *function, llvm::ArrayRef<llvm::Value *> args, std::string name = "jumper");
};

#endif //BLOCK_MANAGER_H
