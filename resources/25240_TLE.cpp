#include"stdio.h"
void getnum(int a);
int Joseph(int length,int num);
int main()
{
	int a[50];
	int in,i=0;
	int j;
	do
	{
		scanf("%d",&in);
		if(in==0) 
			break;
		else 
			a[i++]=in;
		getnum(a[i-1]);
	}
	while(1);
	
	return 0;
}

void getnum(int k)
{
	int num=k+1;
	while(1)
	{
		if(Joseph(2*k,num)==1)break;
		else num++;
		if((num/k)%2==0) num+=k;
	}
	printf("%d\n",num);
}

int Joseph(int length,int num)
{
	int a[28]={0};
	int flag=0,i=0;
	int limit;
	limit=0;
	int stand;
	stand=num;
	while(1)
	{
		if(a[i]==0)
		{
			stand=num%(length-limit);
			if(stand==0) stand=length-limit; 
			flag++;
			if(stand==flag) 
			{
				a[i]=1;
				limit++;
				flag=0;
				if (i<length/2)
					if(limit>length/2)
						return 1;
					else
						return 0;
			}	
		}
		i++;
		if(i>=length) i=0;
	}
}
