#include <iostream>

const int MAXSIZE = 10000;

template <class K, class V>
class HashMap {
private:
    K keys[MAXSIZE];
    V values[MAXSIZE];
    int size;
public:
    HashMap() {
        size = 0;
    }

    void insert(K key, V value) {
        keys[size] = key;
        values[size] = value;
        size++;
    }

    V& get(K key) {
        for (int i = 0; i < ; ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        throw "key not exists!";
    }

    V& operator [] (K key) {
        return get(key);
    }
};

template <class T
class VariableTable

HashMap *loopCounter = new HashMap();
HashMap<void*, char*> *inVariable = new HashMap();

void insertVariable(void *var, ) {
    inVariable->get()
}
