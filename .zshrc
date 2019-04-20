alias gamp='git add . && git commit -m "sync" && git push'
alias build='rm -rf build && mkdir build && cd build && cmake ..'
alias count='cloc --exclude-dir="build",".vscode" .'