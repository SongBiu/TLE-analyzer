#include "util.h"
const string Util::functionLoopInit = "_Z8loopInity";
const string Util::functionLoopRun = "_Z7loopRuny";
const string Util::functionLoopExit = "_Z8loopExity";
unique_ptr<ExecutionEngine> Util::getExecuteEngine(unique_ptr<Module> module) {
    string error;
    EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(EngineKind::JIT);
    unique_ptr<ExecutionEngine> ee(enginerBuilder.create());
    if (nullptr == ee) {
        outs() << error << "\n";
        return nullptr;
    }
    return ee;
}

void Util::initTarget() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();
}

void Util::linkFunctionLibs(string IRName) {
    outs() << "linking source file and libs file……\n";
    string command =
        "llvm-link " + IRName + " ../resources/functionLibs.ll -o " + IRName;
    system(command.c_str());
    outs() << "……linking is over\n\n";
}

vector<string> Util::nullArgs() { return vector<string>(); }

void Util::insertCallInBasicBlock(BasicBlock *basicBlock, Function *call,
                                  Loop **loopPtr) {
    Instruction *entryInstruction = &*basicBlock->getInstList().begin();
    vector<Value *> argContainer;
    IRBuilder<> builder(entryInstruction);
    // argContainer.push_back(builder.getInt64((uint64_t)*loopPtr));
    // ArrayRef<Value *> args(argContainer);
    // builder.CreateCall(call, args);
}