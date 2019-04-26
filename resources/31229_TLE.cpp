#include<iostream>

using namespace std;

int k;
typedef class Node {
public:
    int data;
    Node *next;
};

class yusefu {
private:
    Node *head;
    Node *rear;
    int len;
public:
    yusefu(int n) {
        head = NULL;
        rear = NULL;
        len = n;
    }
    void create();
    void print();
    bool play(int m);
};

void yusefu::create() {
    Node *pre;
    for(int i = 1; i <= len; i ++ ) {
        Node *p = new Node();
        p->data = i;
        if(i == 1) {
            head = p;
            pre = head;
        }else {
           pre->next = p;
           pre = p;
        }
    }
    pre->next = head;
    rear = pre;
}
bool yusefu::play(int m) {
    int i = 1;
    Node *p = head;
    Node *pre = rear;

    while(len) {
        if(i < m) {
            pre = p;
            p = p->next;
            i ++;
        }else {
            if(len > k && p->data <= k) {
                return false;
            }
            i = 1;
            p = p->next;
            head = p;
            pre->next = head;
            len --;
        }
    }
    return true;
}
void yusefu::print() {
    int i = 0;
    Node * p = head;
    while(i < len) {
        cout << p->data << " ";
        p = p->next;
        i ++;
    }
    cout << endl;
}
int main() {
    while(cin >> k && k) {
            int i = 1;
            while(true) {
                if(i <= k) {
                    i ++;
                    continue;
                }
                yusefu yusefu(2*k);
                yusefu.create();
               // yusefu.print();
                if(yusefu.play(i)) {
                    cout << i << endl;
                    break;
                }
                i ++;
            }
    }
	return 0;
}
