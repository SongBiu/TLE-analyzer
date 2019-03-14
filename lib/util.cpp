#include "util.h"
const string Util::functionLoopInit = "_Z8loopInitv";
const string Util::functionLoopRun = "_Z7loopRunv";
const string Util::functionLoopExit = "_Z8loopExitv";
const string Util::functionMain = "main";


void Util::initTarget() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();
}

