// /*
// insert Function
// 找到for loop，记录开始地址（TODO）
// block if condition插入指令，记录condition的true/false，还有位置
// 示例程序跑一下
// */
#include "LoopFinder.h"
#include "util.h"
#include <string>
#include <vector>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/LegacyPassManager.h>
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "../resources/test.ll";
    LLVMContext context;
    SMDiagnostic Err;
    Util::linkFunctionLibs(name);
    unique_ptr<Module> module(parseIRFile(name, Err, context));
    Function *main = module->getFunction("_Z4demov");
    
    // legacy::PassManager PM;
    // PM.add(new LoopInfoWrapperPass());
    // PM.add(new LoopFinder());
    // PM.run(*module);
    unique_ptr<ExecutionEngine> ee = Util::getExecuteEngine(move(module));
    ee->runFunctionAsMain(main, vector<string>(), NULL);
    return 0;
}