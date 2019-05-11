#include "ModuleAnalyzer.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace llvm;
using namespace std;

void run(char *moduleDir, char *moduleName, char *functionName, char *result) {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule(moduleName, moduleDir, "dfsLib");
    moduleAnalyzer->runBranchCutter(functionName, result);
    moduleAnalyzer->dumpFunction("main");
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    exit(0);
}

int main(int argc, char *argv []) {
    if (argc < 4) {
        outs() << "miss args\n";
        exit(1);
    }
    thread t(run, argv[1], argv[2], argv[3], argv[4]);
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "result is -1\n";
    exit(0);
    t.join();
    return 0;
}
