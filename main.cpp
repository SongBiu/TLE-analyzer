//
// Created by lisong on 2019-03-05.
//

#include "util.h"
#include <iostream>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Pass.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/Timer.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <string>

using namespace llvm;
using namespace std;

typedef int (*fp)();

unique_ptr<ExecutionEngine> getExecuteEngine(unique_ptr<Module> module) {
  string error;
  EngineBuilder engineBuilder(move(module));
  engineBuilder.setErrorStr(&error);
  engineBuilder.setEngineKind(EngineKind::JIT);
  unique_ptr<ExecutionEngine> ee(engineBuilder.create());
  if (!ee) {
    outs() << error << "\n";
    return nullptr;
  }
  return ee;
}

int main() {
  InitializeNativeTarget();
  InitializeAllAsmParsers();
  InitializeAllAsmPrinters();
  string name = "../test.ll";
  LLVMContext context;
  SMDiagnostic Err;
  unique_ptr<Module> module(parseIRFile(name, Err, context));
  Function *mainF = module->getFunction("main");
  Function *demoF = module->getFunction("_Z4demov");


  Instruction *instruction = &*(mainF->getEntryBlock().getInstList().begin());
  IRBuilder<> builder(instruction);
  builder.CreateCall(demoF, None);
  outs() << *mainF << "\n";
  auto ee(getExecuteEngine(move(module)));
  ee->runFunctionAsMain(mainF, vector<string>(), NULL);
  return 0;
}