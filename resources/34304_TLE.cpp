
#include<stdio.h>
#include<stdlib.h>
struct llistnode
{
	int ele;
	llistnode * p;
};
int main()
{
	int n,m,k,s;
	int i,j=0;
	llistnode *p1,*p2,*h;
	
	printf("please enter the total number of these people,k\n");
	scanf("%d",&k);
	while(k!=0)
	{
	int tag=0;
	m=k-1;
	while(tag==0)
	{
		j=0;
		p1=(llistnode *)malloc(sizeof(llistnode));
		h=p1;
		s=1;
		n=2*k;
		
		m++;
		//printf("m=%d\n",m);
	for(i=0;i<n;i++)
	{
		p1->ele=i+1;
		p2=p1;
		p1=(llistnode*)malloc(sizeof(llistnode));
		p2->p=p1;
	}
	p2->p=h;
	p1=h;
	p2=h;
	while(p1->ele!=s)
	{
		p2=p1;
		p1=p1->p;
	}
	//printf("%d\n",p1->p->p->ele);
	
//	printf("the out sequence is:\n");
	i=2*k;
	while(i>k&&p1->p!=p1)
	{
		j++;
		//printf("%d\n",p1->ele);
		//printf("j=%d,m=%d\n",j,m);
		if(j%m==0)
		{
			
			//printf("in if%d\n",p1->ele);
			if(p1->ele<=n/2)
			{
				//printf("break\n");
				break;
			}
			i--;
			p2->p=p1->p;
			free(p1);
			p1=p2->p;
			//printf("in the if\n");
			//printf("the seq is: ");
			continue;
		}
		//printf("aaa\n");
		p2=p1;
		p1=p1->p;
		//printf("after %d",p1->ele);
	}
	if(i==k)
	{
		//printf("tag=1");
		tag=1;
	}

	//printf("%d\n",p1->ele);
	/*while(h!=NULL)
	{
		printf("%d ",h->ele);
		h=h->p;
	}*/
	//printf("%d",p1->ele);
	}
	printf("%d\n",m);
	scanf("%d",&k);
	}
	scanf("%d",&j);
	return 0;
}