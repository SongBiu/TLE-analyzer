#include "ModuleAnalyzer.h"
#include <boost/filesystem.hpp>
#include <iostream>

using namespace llvm;
using namespace std;
using namespace boost;

vector<filesystem::path> getSource(filesystem::path directoryPath) {
    vector<filesystem::path> sources;
    if (filesystem::exists(directoryPath)) {
        filesystem::directory_iterator begin(directoryPath);
        filesystem::directory_iterator end;
        for (; begin != end; begin++) {
            sources.push_back(begin->path());
        }
    }
    return sources;
}

int main() {
    // ModuleAnalyzer *moduleAnalyzer = new ModuleAnalyzer();
    // moduleAnalyzer->readModule("joseph");
    // moduleAnalyzer->dumpFunctionList();
    // moduleAnalyzer->runDefineAnalyzer();
    // moduleAnalyzer->dumpFunction();
    // moduleAnalyzer->initTarget();
    // moduleAnalyzer->runFunction();
    // moduleAnalyzer->dumpModule();
    auto sources = getSource("../resources");
    for (auto source : sources) {
        cout << source << "\n";
    }
    return 0;
}
