#include "manager/ModuleManager.h"
namespace analyzer {
void ModuleManager::stub(std::string dfsFunction, std::string result) {
    this->dfsFunction = dfsFunction;
    this->result = result;
    stubDfsCall();
    stubStore();
}
void ModuleManager::stubDfsCall() {
    auto dfs = findDfsFunction();
    auto firstInstruction = dfs->getBasicBlockList().begin()->getFirstNonPHI();
    auto add = module->getFunction(Magic::dfsCallAdd);
    llvm::IRBuilder<> builder(firstInstruction);
    builder.CreateCall(add, {});
    auto main = module->getFunction(Magic::functionMain);
    auto callInstruction = findCallDfs(main);
    insertAroundCallDfs(callInstruction, "dfsCall");
}
void ModuleManager::stubStore() {
    auto dfs = findDfsFunction();
    auto storeBlocks = getStoreBlocks(dfs);
    markStoreBlock(storeBlocks);
    auto main = module->getFunction(Magic::functionMain);
    auto callInstruction = findCallDfs(main);
    insertAroundCallDfs(callInstruction, "store");
}

std::vector<llvm::BasicBlock *> ModuleManager::getStoreBlocks(llvm::Function *F) {
    std::vector<llvm::BasicBlock *> storeBlocks;
    for (auto &basicBlock : F->getBasicBlockList()) {
        for (auto &instruction : basicBlock.getInstList()) {
            if (Magic::storeOpCode == instruction.getOpcode()) {
                if (instruction.getNumOperands() < 2 || result != instruction.getOperandUse(1)->getName()) {
                    continue;
                }
                storeBlocks.push_back(&basicBlock);
                break;
            }
        }
    }
    return storeBlocks;
}

void ModuleManager::markStoreBlock(std::vector<llvm::BasicBlock *> &storeBlocks) {
    for (auto *basicBlock : storeBlocks) {
        auto instruction = basicBlock->getFirstNonPHI();
        llvm::IRBuilder<> builder(instruction);
        auto function = basicBlock->getModule()->getFunction(Magic::storeAdd);
        builder.CreateCall(function, {});
    }
}
llvm::Instruction *ModuleManager::findCallDfs(llvm::Function *F) {
    for (auto &basicBlock : F->getBasicBlockList()) {
        for (auto &instruction : basicBlock.getInstList()) {
            if (!strcmp(instruction.getOpcodeName(), "call")) {
                for (int i = 0; i < instruction.getNumOperands(); i++) {
                    std::string name = instruction.getOperandUse(i).get()->getName();
                    if (name.length() == 0) {
                        continue;
                    }
                    if (strstr(name.c_str(), dfsFunction.c_str())) {
                        return &instruction;
                    }
                }
            }
        }
    }
    return NULL;
}

void ModuleManager::insertAroundCallDfs(llvm::Instruction *instruction, std::string task) {
    llvm::Function *init = NULL, *dump = NULL;
    if (task == "store") {
        init = module->getFunction(Magic::storeInit);
        dump = module->getFunction(Magic::storeDump);
    } else {
        init = module->getFunction(Magic::dfsCallInit);
        dump = module->getFunction(Magic::dfsCallDump);
    }
    llvm::IRBuilder<> builder(instruction);
    builder.CreateCall(init, {});
    builder.SetInsertPoint(instruction->getNextNode());
    builder.CreateCall(dump, {});
}

llvm::Function *ModuleManager::findDfsFunction() {
    for (auto &function : module->getFunctionList()) {
        std::string functionName = function.getName();
        if (strstr(functionName.c_str(), dfsFunction.c_str())) {
            return &function;
        }
    }
    return NULL;
}

void ModuleManager::timeCounterDfs(std::string dfsFunction) {
    this->dfsFunction = dfsFunction;
    auto main = module->getFunction(Magic::functionMain);
    auto dfsCallDfs = findCallDfs(main);
    auto callBefore = module->getFunction(Magic::callBefore);
    auto callAfter = module->getFunction(Magic::callAfter);
    llvm::IRBuilder<> builder(dfsCallDfs);
    builder.CreateCall(callBefore, {});
    builder.SetInsertPoint(dfsCallDfs->getNextNode());
    builder.CreateCall(callAfter, {});
}

} // namespace analyzer