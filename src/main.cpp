// /*
// insert Function
// 找到for loop，记录开始地址（TODO）
// block if condition插入指令，记录condition的true/false，还有位置
// 示例程序跑一下
// */
#include "LoopAnalyzer.h"
#include <string>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/LegacyPassManager.h>
using namespace llvm;
using namespace std;
int main() {
    string name = "../resources/test.ll";
    LLVMContext context;
    SMDiagnostic Err;
    unique_ptr<Module> module(parseIRFile(name, Err, context));
    legacy::PassManager PM;
    PM.add(new LoopInfoWrapperPass());
    PM.add(new LoopAnalyzer());
    PM.run(*module);
    return 0;
}