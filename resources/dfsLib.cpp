#include <iostream>
int dfsCount = 0;
int storeCount = 0;

void dfsCallInit() {
    dfsCount = 0;
}

void dfsCallAdd() {
    dfsCount++;
}

void dfsCallDump() {
    std::cout << "call number is " << dfsCount << "\n";
}

void storeInit() {
    storeCount = 0;
}

void storeAdd() {
    storeCount++;
}

void storeDump() {
    std::cout << "store number is " << storeCount << "\n";
}