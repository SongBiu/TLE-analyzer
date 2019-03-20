//
// Created by lisong on 2019-03-19.
//

#ifndef BLOCK_CONTAINER_H
#define BLOCK_CONTAINER_H

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <string>

using namespace llvm;
using namespace std;

class BlockContainer {
private:
    unique_ptr<Module> module;
public:
    BasicBlock *instertFunction(BasicBlock *from, BasicBlock *to, Function *function, string name = "jumper");
};

#endif //BLOCK_CONTAINER_H
