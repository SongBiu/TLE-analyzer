#include "util/Magic.h"
namespace analyzer {
const std::string Magic::functionLoopInit = "_Z8loopInitPv";
const std::string Magic::functionLoopRun = "_Z7loopRunPv";
const std::string Magic::functionLoopExit = "_Z8loopExitPv";
const std::string Magic::functionBranch = "_Z6branchb";
const std::string Magic::functionMain = "main";
const std::string Magic::initHash = "_Z8initHashv";
const std::string Magic::addHash = "_Z7addhashi";
const std::string Magic::dumpHash = "_Z8dumpHashv";
const std::string Magic::compareHash = "_Z11compareHashv";
const std::string Magic::dfsCallInit = "_Z11dfsCallInitv";
const std::string Magic::dfsCallAdd = "_Z10dfsCallAddv";
const std::string Magic::dfsCallDump = "_Z11dfsCallDumpv";
const std::string Magic::storeInit = "_Z9storeInitv";
const std::string Magic::storeAdd = "_Z8storeAddv";
const std::string Magic::storeDump = "_Z9storeDumpv";
const std::string Magic::callBefore = "_Z10callBeforev";
const std::string Magic::callAfter = "_Z9callAfterv";
} // namespace analyzer
