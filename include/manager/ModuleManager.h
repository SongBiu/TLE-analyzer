#include "util/Magic.h"
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <vector>

namespace analyzer {
class ModuleManager {
private:
    std::unique_ptr<llvm::Module> &module;
    std::string dfsFunction;
    std::string result;
    void stubDfsCall();
    void stubStore();
    std::vector<llvm::BasicBlock *> getStoreBlocks(llvm::Function *function);
    void markStoreBlock(std::vector<llvm::BasicBlock *> &storeBlocks);
    llvm::Instruction *findCallDfs(llvm::Function *F);
    void insertAroundCallDfs(llvm::Instruction *instruction, std::string task);
    llvm::Function *findDfsFunction();

public:
    ModuleManager(std::unique_ptr<llvm::Module> &module) : module(module) {}

    void stub(std::string dfsFunction, std::string result);

    void timeCounterDfs(std::string dfsFunction);
};
} // namespace analyzer