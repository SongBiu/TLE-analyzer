#include<stdio.h>
#include<stdlib.h>

struct guy
{
	int a;
	int flag;
	struct guy *next;
};

typedef struct guy GUY;

int main()
{
	int m,k,i,j,x;
	GUY  *p1,*head,*p2,*p3;
	
	while(scanf("%d",&k)!=EOF)
	{
		p2=head=(GUY *)malloc(sizeof(GUY));
		p2->a=1;
		for(i=1;i<2*k;i++)
		{	
			p1=(GUY *)malloc(sizeof(GUY));
			p1->a=i+1;
			p2->next=p1;
			p2=p1;
		}
		p2->next=head;
		m=k+1;
		while(1)
		{
			p3=head;
			for(x=0;x<2*k;x++)
			{
				p3->flag=1;
				p3=p3->next;
			}
			p1=head;
			i=j=0;
			while(i<k)	
			{	
				if(p1->flag==1)
					j++;
				if(j==m)
				{
					p1->flag=0;
					j=0;
					i++;
				}
				p1=p1->next;
			}
			p3=head;
			for(i=0;i<k;i++)
			{
				if(p3->a>=1&&p3->a<=k&&p3->flag==1)
					p3=p3->next;
				else break;
			}
			if(i<k)
				m=m+1;
			else 
			{
				printf("%d\n",m);
				break;
			}
		}
	}
	free(head);
	return 0;
}