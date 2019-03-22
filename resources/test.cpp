// 区分for和别的的br，只输出if condition的变量是否发生变化，如果未变化则warning
// 拿一个oj的例子，从已经分类好的例子入手，从最简单的入手，尝试捕获问题
// 执行正确和错误代码，查看哪些地方行为有差别，查看错误代码的pattern
// for loop的output有差别
// 可以针对具体代码进行打桩，输出一些值，进行分析，来区分错误代码的pattern
// 分析for loop每次更新了哪些值


// 每次循环的时候，输出变量。当变量安全重复，说明计算冗余
// 在while loop里插入sout进行保存（手动），查看不同iter之间有没有值的重复
// 用一个简单的方式，找到问题的现象，如果能看到，再进行编码
int main() {
    int x = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            if (x > 20) {
//                break;
            }
        }
    }
    for (int k = 0; k < 100; k++) {
        x--;
    }
    return 0;
}