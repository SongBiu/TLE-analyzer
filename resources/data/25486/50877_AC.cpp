// _Z3dfs min
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char visit;
	int length;
	int cost;
}data;
typedef struct node{
	data da;
	struct node * next;
}node;
typedef struct {
	node * r;
	int count;
}road;
node * insert(node * a,node *m)
{
	m->next=a;
	return m;
}
void dfs(road **a,data *visit,int begin,int end,int cost,int length,int *min,int k,int **save)
{
//	printf("%d %d\n",begin,end);
//	system("pause");

   if(cost>k)
   return ;
   if(length>*min)
   return;
	
	if(begin==end)
	{
		if(length<*min)
		*min=length;
		return ;
	}
	if(save[begin][cost]==0)
	save[begin][cost]=length;
	else
    {
    	if(save[begin][cost]<=length)
    	{
    		return ;
		}
		else
		{
			save[begin][cost]=length;
		}
	}
	visit[begin].visit=1;
	int i,j;

	for(i=1;i<=end;i++)
	{

	if(visit[i].visit==0&&a[begin][i].count!=0)
	{       
		node * swap=a[begin][i].r;
		visit[i].visit=1;
		for(j=0;j<a[begin][i].count;j++)
		{
			
			dfs(a,visit,i,end,cost+swap->da.cost,length+swap->da.length,min,k,save);
			 swap=swap->next;
		}
		visit[i].visit=0;
	}
    }
    
	visit[begin].visit=0;
	
	
}

int main()
{
	int k,n,r;
	scanf("%d %d %d",&k,&n,&r);
	data *visit=(data *)malloc(sizeof(data)*(n+1));
	road **a=(road **)malloc(sizeof(road *)*(n+1));
	int **save=(int **)malloc(sizeof(int *)*(n+1));
	
	int i,j,s,d,l,t;
	for(i=0;i<=n;i++)
    {
        a[i]=(road *)malloc(sizeof(road)*(n+1));
        save[i]=(int *)malloc(sizeof(int)*(k+1));
        for(j=0;j<=k;j++)
        save[i][j]=0;
    	for(j=0;j<=n;j++)
    	{
    		
    		a[i][j].r=NULL;
    		a[i][j].count=0;
    	}
    	visit[i].visit=0;
    	visit[i].cost=0;
    	visit[i].length=0;
    }
	
	for(i=0;i<r;i++)
	{
		scanf("%d %d %d %d",&s,&d,&l,&t);
		node * m=(node *)malloc(sizeof(node));
	  
		m->da.length=l;
		m->da.cost=t;
		m->next=NULL;
		a[s][d].r=insert(a[s][d].r,m);
		a[s][d].count++;
	}

	int min=99999;
	dfs(a,visit,1,n,0,0,&min,k,save);
	if(min!=99999)
	printf("%d",min);
	else
	printf("-1");
	
}