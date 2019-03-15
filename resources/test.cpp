#include <iostream>
#include <string>

using namespace std;

int main() {
    string line = "demo";
    int x = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            x++;
        }
    }
    for (int k = 0; k < 100; k++) {
        x--;
    }
    cout << "main is called\n" << line << "\n";
    return 0;
}