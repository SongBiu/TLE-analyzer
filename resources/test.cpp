//
// Created by lisong on 2019-03-05.
//
#include <iostream>
int func(int x) {
    return x + 2;
}
void demo() {
    std::cout << "function is called\n";
}
int main() {
    int k = 50;
    for (int i = 0; i < 100; i++) {
        if (3 * i > k) {
            break;
        }
        k++;
    } 
    return 0;
}
