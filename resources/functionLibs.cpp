#include <iostream>
#include <map>
std::map<uint64_t, int> loopCount;
void loopInit(uint64_t loopPtr) {
    std::cout << "the loop init!\n";
    std::cout << loopPtr << "\n";
    loopCount[loopPtr] = 0;
}
void loopRun(uint64_t loopPtr) { loopCount[loopPtr]++; }
void loopExit(uint64_t loopPtr) {
    std::cout << "the loop run " << loopCount[loopPtr] << " times\n";
}
void branch(bool condition) {
    std::cout << "condition is " << condition << std::endl;
}