#include "moduleManager.h"

using namespace llvm;
using namespace std;

int main() {
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule("test");
    moduleManager->runLoopFinder();
//    moduleManager->dumpModule();
//    moduleManager->initTarget();
//    moduleManager->runFunction();
    return 0;
}