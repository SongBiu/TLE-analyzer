#include <iostream>

struct Node {
	int num;
	bool alive = 1;
	Node *ahead;
	Node *next;
};

Node* Create(int N) {
	int n = 1;
	Node *head, *tail;
	head = new Node;
	head->num = n;
	tail = head;
	while (n++ < 2 * N) {
		Node *tmp = new Node;
		tmp->num = n;
		tail->next = tmp;
		tmp->ahead = tail;
		tail = tmp;
	}
	tail->next = head;
	head->ahead = tail;
	/*Node *p = head;
	int tmp_n = 0;
	while (tmp_n++ < 4*N) {
		std::cout << p->num << " " << p->alive << std::endl;
		p = p->next;
	}*/
	return head;
}

bool Guess(Node *head, int N, int M) {
	int cnt = 1, kill = 0;
	Node *tmp = head;
	int tmp_n = 0;
	while (tmp_n++ < 2*N) {
		tmp->alive = 1;
		tmp = tmp->next;
	}
	tmp = head;
	//std::cout << "the oup is " << M << " and num is " << tmp->num << std::endl;
	while (kill < N) { //当杀掉的人没有达到N时，继续循环
		while (cnt < M) { //找到当前要杀的那个人
			tmp = tmp->next;
			while (!tmp->alive) {
				tmp = tmp->next;
			}
			cnt++;
		}
		if (tmp->num >= 1 && tmp->num <= N) {//如果这个人的代号在1-N之间，也就是好人，则猜测失败;
			return false;
		}
		tmp->alive = 0;
		while (!tmp->alive)
			tmp = tmp->next;
		kill++;
		cnt = 1;
	}
	return true;
}

int main() {
	int Joseph[14] = { 0 };
	int inp, oup;
	Node *head;
	while ((std::cin >> inp) && (inp != 0)) {
		if (Joseph[inp] != 0) {
			std::cout << Joseph[inp] << std::endl;
			continue;
		}
		head = Create(inp);
		oup = 1;
		while (!Guess(head, inp, oup)) {
			oup++;
		}
		Joseph[inp] = oup;
		std::cout << oup << std::endl;
	}
	return 0;
}