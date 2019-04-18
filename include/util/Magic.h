#ifndef UTIL_MAGIC_H
#define UTIL_MAGIC_H

#include <string>

using namespace std;

class Magic {
public:
    static const int brOpCode = 2;
    static const int brTargetOpNum = 3;
    static const int loadOpCode = 31;
    static const int storeOpCode = 32;
    static const int pointerTypeId = 15;
    static const string functionLoopInit;
    static const string functionLoopRun;
    static const string functionLoopExit;
    static const string functionBranch;
    static const string functionMain;
    static const string initHash;
    static const string addHash;
    static const string dumpHash;
    static const string compareHash;
};

#endif