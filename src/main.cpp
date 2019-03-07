#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Pass.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/Timer.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <memory>
#include <string>

using namespace llvm;
using namespace std;

unique_ptr<ExecutionEngine> getExecuteEngine(unique_ptr<Module> module) {
    string error;
    EngineBuilder engineBuilder(move(module));
    engineBuilder.setErrorStr(&error);
    engineBuilder.setEngineKind(EngineKind::JIT);
    unique_ptr<ExecutionEngine> ee(engineBuilder.create());
    if (!ee) {
        outs() << error << "\n";
        return nullptr;
    }
    return ee;
}

void insertFunctionToModule(Function* function, unique_ptr<Module> module) {
    function->removeFromParent();
    module->getFunctionList().push_front(function);
}

int main() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();
    string name = "../resources/test.ll";
    LLVMContext context;
    SMDiagnostic Err;
    unique_ptr<Module> test(parseIRFile(name, Err, context));
    unique_ptr<Module> functionLibs(parseIRFile("../resources/functionLibs.ll", Err, context));
    Function *mainF = test->getFunction("main");
    Function *demoF = functionLibs->getFunction("_Z4demov");
    insertFunctionToModule(demoF, move(test));
    Instruction* instruction = &*(mainF->getEntryBlock().getInstList().begin());
    IRBuilder<> builder(instruction);
    builder.CreateCall(demoF, None);
    outs() << *demoF << "\n";
    auto ee(getExecuteEngine(move(test)));
    ee->runFunctionAsMain(mainF, vector<string>(), NULL);
    return 0;
}