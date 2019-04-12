#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

class Util {
public:
    static const int brOpCode = 2;
    static const int brTargetOpNum = 3;
    static const string functionLoopInit;
    static const string functionLoopRun;
    static const string functionLoopExit;
    static const string functionBranch;
    static const string functionMain;
};

#endif