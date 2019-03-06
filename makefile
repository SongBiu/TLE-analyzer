test.ll: test.cpp
	clang++ -S -emit-llvm -I${MACOS_SDK}/include test.cpp
clean:
	rm test.ll
