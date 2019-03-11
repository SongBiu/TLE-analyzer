#include <iostream>
int count;
void loopInit() {
    std::cout << "the loop init!\n";
    count = 0;
}
void loopRun() {
    count++;
}
void loopEnd() {
    std::cout << "the loop run " << count << " times\n";
}
