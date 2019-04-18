#include "ModuleAnalyzer.h"

using namespace llvm;
using namespace std;

int main() {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule("joseph");
    // moduleAnalyzer->dumpFunctionList();
    moduleAnalyzer->runDefineAnalyzer();
    moduleAnalyzer->dumpFunction();
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    moduleAnalyzer->dumpModule();
    return 0;
}
