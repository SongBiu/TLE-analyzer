#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
struct f{
	int y;
	struct f *next;
};
int hanshu(int m,int a){
	int n,j,b,c=0,t;	
	    t=a;
	a*=2;
		int i,k=0;
		struct f *p,*head,*p1;
		head=(struct f *)malloc(sizeof(struct f));
		head->y=1;
		p1=head;
		p=p1;
		for(i=2;i<=a;i++){
		p1=(struct f *)malloc(sizeof(struct f));
		p->next=p1;
		p1->y=i;
		p=p1;
		}
		p->next=head;
		while(k<t){
		for(i=1;i<m;i++){
			p=p->next;}
		if(p->next->y<=t)break;
		p1=p->next->next;
		p->next=p1;
		k++;
		}
		if(k==t)return 1;
		else return 0;
	}
int main(){
	int a,b;
	while(scanf("%d",&a),a!=0){
	for(b=a;;b++)if(hanshu(b,a)==1)break;
	printf("%d",b);
	}
}
