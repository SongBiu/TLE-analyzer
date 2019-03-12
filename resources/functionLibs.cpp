#include <iostream>
int count;
void loopInit() {
    std::cout << "the loop init!\n";
    count = 0;
}
void loopRun() { count++; }
void loopEnd() { std::cout << "the loop run " << count << " times\n"; }
void branch(bool condition, int branchAlpha, int branchBeta) {
    std::cout << "condition is " << condition << " and branch alpha is "
              << branchAlpha << " , branch beta is " << branchBeta << std::endl;
}