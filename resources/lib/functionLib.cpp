#include <iostream>

const int MAXSIZE = 10000;

class hashMap {
private:
    void *keys[MAXSIZE];
    int values[MAXSIZE];
    int size;
public:
    hashMap() {
        size = 0;
    }

    void insert(void *loopAddress) {
        keys[size] = loopAddress;
        values[size] = 0;
        size++;
    }

    int getIndex(void *loopAddress) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == loopAddress) {
                return i;
            }
        }
        return -1;
    }

    int getCount(void *loopAddress) {
        int index = getIndex(loopAddress);
        if (index == -1) {
            return -1;
        } else {
            return values[index];
        }
    }

    void addLoop(void *loopAddress) {
        int index = getIndex(loopAddress);
        if (index == -1) {
            return;
        } else {
            values[index]++;
        }
    }
};

hashMap loopCounter;

void loopInit(void *loopPointer) {
    loopCounter.insert(loopPointer);
}

void loopRun(void *loopPointer) {
    loopCounter.addLoop(loopPointer);
}

void loopExit(void *loopPointer) {
    std::cout << "loop(" << loopPointer << ") run " << loopCounter.getCount(loopPointer) << " times\n";
}

void branch(bool condition) {
    std::cout << "branch's condition is " << condition << std::endl;
}