all:
	@echo compile cpp to ir
	@clang++ -S -emit-llvm *.cpp
	@clang++ -S -emit-llvm lib/functionLibs.cpp -o lib/functionLibs.ll
	@echo linking ir
	@llvm-link *.ll lib/functionLibs.ll -o *.ll
clean:
	@rm *.ll
	@rm lib/*.ll