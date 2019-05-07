#include <iostream>
using namespace std;
int assCount = 0;

void countAdd() {
    assCount++;
}

void countDump() {
    cout << "count over! result is " << assCount << "\n";
}