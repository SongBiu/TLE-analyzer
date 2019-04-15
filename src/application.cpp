#include "manager/ModuleManager.h"

using namespace llvm;
using namespace std;

int main() {
    ModuleManager *moduleManager = new ModuleManager();
    moduleManager->readModule("joseph");
    moduleManager->runDefineAnalyzer();
    moduleManager->dumpFunction();
    moduleManager->initTarget();
    moduleManager->runFunction();
    return 0;
}