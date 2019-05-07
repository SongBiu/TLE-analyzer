// _Z3DFS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define N 100

//by Sinward Ye
//百练1724ROADS.c 

//adjacency list defination
typedef struct arc_{//defination of arc
	int d;//destination
	int t;//toll
	int l;//length
	struct arc_ *next;//pionter to next arc
}arc;
typedef struct node_{//defination of node
	arc *firstarc;//pionter to first arc
}node;



void DFS(int s,int k,int n,node nodes[N+1],char visited[N+1],int len,int *minlen){
	arc *p=NULL;
	if(k<0) return;
	if(s==n){
		if(len<*minlen) *minlen=len;
		return;
	}
	visited[s]=1;
	p=nodes[s].firstarc->next;
	while(p){
		if(!visited[p->d])
		 	DFS(p->d,k-p->t,n,nodes,visited,len+p->l,minlen);
		p=p->next;
	}
	visited[s]=0;
	return;
}

int main(){
	int i=0,j=0;
	node nodes[N+1];
	int n=0,k=0,r=0;
	int s=0,l=0,d=0,t=0;
	int minlen=INT_MAX;
	char visited[N+1];
	arc *p=NULL;
	scanf("%d %d %d",&k,&n,&r);
	for(i=1;i<=n;i++){
		nodes[i].firstarc=(arc*)malloc(sizeof(arc));
		nodes[i].firstarc->next=NULL;
	}
	for(i=1;i<=r;i++){
		scanf("%d %d %d %d",&s,&d,&l,&t);
		p=nodes[s].firstarc->next;
		nodes[s].firstarc->next=(arc*)malloc(sizeof(arc));
		nodes[s].firstarc->next->next=p;
		p=nodes[s].firstarc->next;
		p->d=d;
		p->l=l;
		p->t=t;
	}
	//DFS
	memset(visited,0,sizeof(visited));
	DFS(1,k,n,nodes,visited,0,&minlen);
	printf("%d\n",minlen);
	return 0;
}