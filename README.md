# TLE-analyzer
It is a simple tools which can help students to find and solve tle error when they submit code to poj

# TODO

* 标志循环是第几次执行，给入口指令打桩
  * 难点：插入的代码需要通过llvm-link来和原始IR代码进行合并，但是记录代码执行的模块写到了程序代码里，由一个类进行管理。
* 输出if condition的属性，跳转到哪一个basicblock
* 插桩
