#include "ModuleAnalyzer.h"
#include <iostream>

using namespace llvm;
using namespace std;
int main() {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule("dfs", "dfsLib");
    // moduleAnalyzer->dumpFunctionList();
    moduleAnalyzer->runBranchCutter("DFS", "MinLen");
    // moduleAnalyzer->dumpModule();
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    return 0;
}
