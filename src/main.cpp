// /*
// insert Function
// 找到for loop，记录开始地址（TODO）
// block if condition插入指令，记录condition的true/false，还有位置
// 示例程序跑一下
// */
#include "loopFinder.h"
#include "util.h"
#include "engine.h"
#include "moduleManager.h"
#include <vector>
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "../resources/test.ll";
    Util::linkFunctionLibs(name);
    ModuleManager* moduleManager = new ModuleManager();
    unique_ptr<Module> module(moduleManager->readModule(name));
    Engine* engine = new Engine();
    engine->run(move(module));
    unique_ptr<ExecutionEngine> executionEngine = Util::getExecuteEngine(move(module));
    executionEngine->runFunctionAsMain(module->getFunction("main"), vector<string>(), NULL);
    return 0;
}