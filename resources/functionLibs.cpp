#include <iostream>
void demo() {
    std::cout << "function is called\n";
}
void loopInit() {
    static int count;
    count = 0;
}
void loopRun() {
    count++;
}
