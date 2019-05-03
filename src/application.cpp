#include "ModuleAnalyzer.h"
#include <chrono>
#include <thread>

using namespace llvm;
using namespace std;

void run(char *name) {
    ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    moduleAnalyzer->readModule(name);
    moduleAnalyzer->runDefineAnalyzer();
    moduleAnalyzer->initTarget();
    moduleAnalyzer->runFunction();
    exit(0);
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        outs() << "miss args\n";
        exit(1);
    }
    thread t(run, argv[1]);
    this_thread::sleep_for(chrono::milliseconds(2000));
    exit(0);
    t.join();
    return 0;
}
