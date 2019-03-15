#include "loopFinder.h"
#include "moduleManager.h"
#include "util.h"
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "test";
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule(name);
    moduleManager->runLoopFinder();
    moduleManager->runFunction();
    return 0;
}