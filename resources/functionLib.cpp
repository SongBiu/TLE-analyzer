#include <iostream>
#include <string>

const int HMAX = 100000;
int h;
int history[HMAX];
int size = 0;

void initHash() { h = 0; }

void addhash(int var) {
    h = h * 31 + var;
}

void dumpHash() {
    history[size] = h;
    size++;
}

void compareHash() {
    for (int i = 0; i < size - 1; i++) {
        if (history[i] == history[size - 1]) {
            std::cout << "重复计算\n";
            break;
        }
    }
}