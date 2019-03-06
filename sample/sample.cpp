#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Support/TargetSelect.h>

#include <iostream>

int main() {
    // Initialize global state
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    // Initialize local state
    llvm::LLVMContext context;

    // Create the module that will be compiled
    std::unique_ptr<llvm::Module> module(new llvm::Module("jit", context));

    // Create function type
    std::vector<llvm::Type*> arg_types;
    llvm::FunctionType* func_type = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), arg_types, false);

    // Create actual function
    llvm::Function* func = llvm::Function::Create(func_type, llvm::Function::LinkageTypes::ExternalLinkage, "anon", module.get());

    // Define function body
    llvm::IRBuilder<> builder(context);
    llvm::BasicBlock *block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);
    builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 42));

    // Verify function
    llvm::verifyFunction(*func);

    // Build the execution engine
    std::string error;
    llvm::EngineBuilder engine_builder(std::move(module));
    engine_builder.setErrorStr(&error);
    engine_builder.setEngineKind(llvm::EngineKind::JIT);
    std::unique_ptr<llvm::ExecutionEngine> engine(engine_builder.create());
    if (!engine) {
        std::cerr << error << std::endl;
        return 1;
    }

    // Get a pointer to the JITed function
    void* jit_ptr = engine->getPointerToFunction(func);
    auto function = (int32_t(*)())(jit_ptr);

    // Execute the JITed function
    std::cout << function() << std::endl;
    return 0;
}