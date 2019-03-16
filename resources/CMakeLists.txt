ADD_CUSTOM_TARGET(test.ll ALL
        COMMAND clang++ -S -emit-llvm test.cpp -o test.ll)