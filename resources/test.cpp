void func(int x) {
    while (true) {
        x++;
    }
}
int main() {
    int x = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 100; j++) {
            x++;
        }
    }
    for (int k = 0; k < 100; k++) {
        x--;
    }
    func(1);
    return 0;
}