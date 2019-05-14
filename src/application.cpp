#include "ModuleAnalyzer.h"
#include <chrono>
#include <iostream>
#include <thread>

void run(char *moduleDir, char *moduleName, char *functionName, char *result, char *input) {
    analyzer::ModuleAnalyzer *moduleAnalyzer = new analyzer::ModuleAnalyzer();
    moduleAnalyzer->readModule(moduleName, moduleDir, "dfsLib");
    moduleAnalyzer->runBranchCutter(functionName, result, input);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        llvm::outs() << "miss args\n";
        exit(1);
    }
    std::thread t(run, argv[1], argv[2], argv[3], argv[4], argv[5]);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "number is -1\n";
    exit(0);
    t.join();
    return 0;
}
