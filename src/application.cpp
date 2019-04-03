#include "moduleManager.h"

using namespace llvm;
using namespace std;

int main() {
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule("joseph");
    moduleManager->runDefineAnalyzer();
//    moduleManager->dumpModule();
//    moduleManager->initTarget();
//    moduleManager->runFunction();
    return 0;
}