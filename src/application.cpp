#include "loopFinder.h"
#include "moduleManager.h"
#include "util.h"
using namespace llvm;
using namespace std;
int main() {
    Util::initTarget();
    string name = "../resources/test.ll";
    SMDiagnostic Err;
    LLVMContext context;
    string error;
    unique_ptr<Module> module(parseIRFile(name, Err, context));
    if (!module) {
        Err.print("main", errs());
    }
    Function *f = module->getFunction("main");
    EngineBuilder enginerBuilder(move(module));
    enginerBuilder.setErrorStr(&error);
    enginerBuilder.setEngineKind(EngineKind::JIT);
    auto executionEngine(enginerBuilder.create());
    if (!executionEngine) {
        outs() << error << "\n";
    }
    executionEngine->runFunctionAsMain(f, vector<string>(), NULL);
    return 0;
}