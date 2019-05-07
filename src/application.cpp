#include "ModuleAnalyzer.h"
#include <iostream>

using namespace llvm;
using namespace std;
int main() {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule("hello", "dfsLib");
    // moduleAnalyzer->dumpFunctionList();
    // moduleAnalyzer->runBranchCutter("dfs", "rt");
    // moduleAnalyzer->dumpModule();
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    return 0;
}
