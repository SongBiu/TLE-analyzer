#include <iostream>
#include <fstream>

const int HMAX = 100000;
int h;
int history[HMAX];
int size = 0;

void dump(int v) {
    std::cout << v << std::endl;
}

void hInit() {
    h = 0;
}

void hAdd(int var) {
    h = h * 31 + var;
}

void hDump() {
    history[size] = h;
    size++;
}

void hCompare() {
    for (int i = 0; i < size - 1; i++) {
        if (history[i] == history[size - 1]) {
            std::cout << "重复计算\n";
            exit(0);
        }
    }
}