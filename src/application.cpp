#include "ModuleAnalyzer.h"
#include <iostream>

using namespace llvm;
using namespace std;

int main() {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule("dfs");
    moduleAnalyzer->runBranchCutter();
    return 0;
}
