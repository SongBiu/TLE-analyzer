#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 100
#define M 100000000
int number[N];
int Input()
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", number + i);
		if (number[i] == 0) break;
	}
	return i;
}
struct Node 
{
	int value;
	struct Node* link;
};
typedef struct Node* PNode;
bool Joseph(int k, int m)
{
	int n = 2 * k;
	PNode p = (PNode)malloc(sizeof(struct Node));
	p->value = 1;
	p->link = p;
	PNode* head = (PNode*)malloc(sizeof(PNode));
	*head = p;
	for (int i = 2; i <= n; i++)
	{
		PNode q = (PNode)malloc(sizeof(struct Node));
		q->value = i;
		q->link = p->link;
		p->link = q;
		p = q;
	}
	p = *head;
	int dead = 0;
	while (dead < k)
	{
		for (int count = 1; count < m - 1; p = p->link, count++);
		PNode q = p->link;
		if (q->value <= k) return false;
		else
		{
			p->link = q->link;
			dead++;
			free(q);
			p = p->link;
		}
	}
	return true;
}
int main()
{
	int count = Input();
	int i, m;
	for (i = 0; i < count; i++)
	{
		for (m = number[i] + 1; m <= M; m++)
		{
			if (Joseph(number[i], m) == true)
				break;
		}
		printf("%d",m);
		if (i != count - 1) printf("\n");
	}
	return 0;
}
