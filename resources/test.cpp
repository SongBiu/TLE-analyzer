#include <iostream>
int func(int x) {
    for (int i = 0; i < 10; i++) {
        x++;
    }
    return x;
};
int main() {
    // func(2);
    int x = 5;
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 233; k++) {
            x++;
        }
    }
    for (int j = 10; j < 100; j++) {
        x--;
    }
    std::cout << "main is called\n";
    return 0;
}