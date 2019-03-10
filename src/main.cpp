// /*
// insert Function
// 找到for loop，记录开始地址（TODO）
// block if condition插入指令，记录condition的true/false，还有位置
// 示例程序跑一下
// */
#include "loopFinder.h"
#include "moduleManager.h"
#include "util.h"
#include <llvm/Analysis/LoopAccessAnalysis.h>
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "../resources/test.ll";
    Util::linkFunctionLibs(name);
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule(name);
    moduleManager->runLoopFinder();
    // moduleManager->runFunction("main");
    return 0;
}