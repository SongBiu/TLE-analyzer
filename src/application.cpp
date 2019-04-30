#include "ModuleAnalyzer.h"
#include <iostream>

using namespace llvm;
using namespace std;
int main() {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule("hello", "dfsLib");
    // moduleAnalyzer->dumpFunctionList();
    // moduleAnalyzer->runBranchCutter();
    // moduleAnalyzer->dumpModule();
    // moduleAnalyzer->dumpFunction("_Z3Dfsiii");
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    return 0;
}
