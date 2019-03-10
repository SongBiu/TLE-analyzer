int func(int x) {
    for (int i = 0; i < 10; i++) {
        x++;
    }
    return x;
};
int main() {
    func(2);
    return 0;
}