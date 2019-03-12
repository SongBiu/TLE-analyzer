#include "loopFinder.h"
#include "moduleManager.h"
#include "util.h"
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "../resources/test.ll";
    Util::linkFunctionLibs(name);
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule(name);
    moduleManager->runFunction("main");
    return 0;
}