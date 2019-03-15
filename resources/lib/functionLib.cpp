#include <iostream>
const int maxSize = 0;

struct hashMap {
private:
    int *keys[maxSize];
    int values[maxSize];
    int size;
public:
    hashMap() {
        size = 0;
    }

    void insert(int *loopAddress) {
        keys[size] = loopAddress;
        values[size] = 0;
        size++;
    }

    int getIndex(int *loopAddress) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == loopAddress) {
                return i;
            }
        }
        return -1;
    }

    int getCount(int *loopAddress) {
        int index = getIndex(loopAddress);
        if (index == -1) {
            return -1;
        } else {
            return values[index];
        }
    }

    void addLoop(int *loopAddress) {
        int index = getIndex(loopAddress);
        if (index == -1) {
            return;
        } else {
            values[index]++;
        }
    }
};

hashMap loopCounter;

void loopInit(int *loopPointer) {
    loopCounter.insert(loopPointer);
}

void loopRun(int *loopPointer) {
    loopCounter.addLoop(loopPointer);
}

void loopExit(int *loopPointer) {
    std::cout << "loop run " << loopCounter.getCount(loopPointer) << "times\n";
}