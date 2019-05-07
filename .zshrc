alias gamp='git add . && git commit -m "sync" && git push'
alias build='rm -rf build && mkdir build && cd build && cmake ..'
alias count='cloc --exclude-dir="build",".vscode" .'
export LLVM_HOME=/usr/local/opt/llvm
export C_LIB=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
export CC=$LLVM_HOME/bin/clang
export CXX=$LLVM_HOME/bin/clang++