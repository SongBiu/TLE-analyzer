#ifndef UTIL_MAGIC_H
#define UTIL_MAGIC_H

#include <string>

namespace analyzer {
class Magic {
public:
    static const int brOpCode = 2;
    static const int brTargetOpNum = 3;
    static const int loadOpCode = 31;
    static const int storeOpCode = 32;
    static const int pointerTypeId = 15;
    static const std::string functionLoopInit;
    static const std::string functionLoopRun;
    static const std::string functionLoopExit;
    static const std::string functionBranch;
    static const std::string functionMain;
    static const std::string initHash;
    static const std::string addHash;
    static const std::string dumpHash;
    static const std::string compareHash;
    static const std::string dfsCallInit;
    static const std::string dfsCallAdd;
    static const std::string dfsCallDump;
    static const std::string storeInit;
    static const std::string storeAdd;
    static const std::string storeDump;
};
} // namespace analyzer

#endif