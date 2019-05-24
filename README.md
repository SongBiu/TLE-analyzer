# TLE-analyzer
It is a simple tools which can help students to find and solve tle error when they submit code to poj

# 依赖
* LLVM 7.0
* clang++/gcc（支持c++17)
* CMake
* make

#  环境

开发阶段主要是在MacOS Mojave 10.14.5上

如果在Linux和Windows上运行，可能需要更改CMakeLists.txt

将LLVM_HOME更改为LLVM的安装路径，并删去C_LIB及其相关的cmake命令。

# 使用
###  joseph问题

在主分支上执行

```bash
git checkout joseph
mkdir build
cd build
cmake ..
make
python3 ../scripts/test_joseph.py
```

### 深度优先搜索

需要的python库

```bash
numpy
sklearn
```

执行

```bash
git checkout dfs
mkdir build
cd build
cmake ..
make
python3 lab.py
python3 classify.py
```



