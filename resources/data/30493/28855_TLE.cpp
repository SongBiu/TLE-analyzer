/*
POJ1724 
N cities named with numbers 1 ... N are connected with one-way roads. 
Each road has two parameters associated with it : 
the road length and the toll that needs to be paid for the road (expressed in the number of coins). 
Bob and Alice used to live in the city 1. 
After noticing that Alice was cheating in the card game they liked to play, 
Bob broke up with her and decided to move away - to the city N. 
He wants to get there as quickly as possible, but he is short on cash. 

We want to help Bob to find the shortest path from the city 1 to the city N that he can afford 
with the amount of money he has. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Road
{
	int sou;
  	int des;
  	int len;
  	int toll;
  	int next;
  	bool enable;
}road[11000];

int M,N,R;
int Min=1e6;
int Head[10010];
void DFS(int city,int curlen,int leftm)
{
	if(Min<curlen)
		return;
	if(city==N && leftm>=0 && curlen<Min)
	{
		Min=curlen;
		return;
	}	
	for(int i=Head[city];i!=-1;i=road[i].next)
	{
		if(road[i].enable=true && leftm>=road[i].toll)
		{
			int d=road[i].des;
			int l=road[i].len;
			int t=road[i].toll;
			road[i].enable=false;
			DFS(d,curlen+l,leftm-t);
			road[i].enable=true;
		}
	}
}
int main()
{
	cin>>M>>N>>R;
	int pr=0;
	int s,d,l,t;
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<=R;i++)
	{
		cin>>s>>d>>l>>t;
		road[pr].sou=s;
		road[pr].des=d;
		road[pr].len=l;
		road[pr].toll=t;
		road[pr].enable=true;
		road[pr].next=Head[s];
		Head[s]=pr++;
	}
	DFS(1,0,M);
	if(Min==1e6)
		cout<<"-1\n";
	else
		cout<<Min<<endl;
	return 0;
	
}
