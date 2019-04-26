#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node *PNode;
struct Node {
	int num;
	PNode link;
};
typedef struct Node *LinkList;

/*创建空链表*/
LinkList creatNullList_link(void) {
	LinkList list = (LinkList)malloc(sizeof(struct Node));
	if (list != NULL)
	{
		list->link = list;                                //将第一个结点的后继指针指向自己，形成循环链表
		list->num = 1;
	}
	else printf("Out of space!\n");                       //空间分配失败
	return list;
}

/*向链表中插入结点*/
int insert_link(LinkList list, int i, int x) {
	PNode p, q;
	p = list;
	int j = 0;
	while (p != NULL && j<i)                             //查找i的前驱
	{
		p = p->link; j++;
	}
	if (j != i)                                          //查找失败
	{
		printf("i=%d is not reasonable.\n", i); return 0;
	}
	q = (PNode)malloc(sizeof(struct Node));              //申请新节点
	if (q == NULL)                                       //申请失败
	{
		printf("Out of space!\n"); return 0;
	}
	else                                                 //插入链表中
	{
		q->num = x;
		q->link = p->link;
		p->link = q;
		return 1;
	}
}

/*删除链表中的结点*/
int delete_link(LinkList list, int x) {
	PNode p, q;
	p = list;
	while (p->link != NULL && p->link->num != x)//在list带头结点的链表中查找元素值为x的元素
		p = p->link;
	if (p->link == NULL)                        //没找到元素值为x的结点
	{
		printf("Not exist!\n"); return 0;
	}
	else                                        //删除该结点
	{
		q = p->link;
		p->link = q->link;
		free(q);
		return 1;
	}
}

int main() {
	int x = 0;
	for (;;) {
		int n, m, i, j, k, y, r = 0;
		scanf("%d", &n);
		int a[100][2];
		for (y = 0; y < x; y++) {
			if (n == a[y][0]) {
				printf("%d\n",a[y][1]);
				r = 1;
				break;
			}
		}
		if (r == 1) continue;
		if (n != 0) {
			for (m = n + 1;; m++) {
				LinkList Josepus, p;
				Josepus = creatNullList_link();      //创建循环链表Josepus
				for (i = 0; i < 2 * n - 1; i++) {
					insert_link(Josepus, i, i + 2);  //依次向Josepus中插入结点
				}
				p = Josepus;                         //p指向头指针Josepus
				k = 0;
				for (i = 0; i < 2 * n - 1; i++) {
					j = 1;
					while (j < m - 1) {	             //循环计数到需要删除结点的前一个结点
						p = p->link; j++;
					}
					if ((p->link->num)>n) {
						delete_link(p, p->link->num);//删除结点
						k++;
					}
					else break;
					p = p->link;                     //向后计一位，准备重新循环
				}
				if (k == n) {
					printf("%d\n", m);
					a[x][0] = n; a[x][1] = m;
					x++;
					break;
				}
				else {
					free(Josepus);
					continue;
				}
			}
		}
		else break;
	}
	return 0;
}