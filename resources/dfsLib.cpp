#include <ctime>
#include <iostream>
std::clock_t startTime;
std::clock_t endTime;
int dfsCount = 0;
int storeCount = 0;

void dfsCallInit() { dfsCount = 0; }

void dfsCallAdd() { dfsCount++; }

void dfsCallDump() { std::cout << "call number is " << dfsCount << "\n"; }

void storeInit() { storeCount = 0; }

void storeAdd() { storeCount++; }

void storeDump() { std::cout << "store number is " << storeCount << "\n"; }

void callBefore() { startTime = std::clock(); }

void callAfter() {
    endTime = std::clock();
    std::cout << "time number is " << (double)(endTime - startTime) * 1000 / CLOCKS_PER_SEC << std::endl;
}