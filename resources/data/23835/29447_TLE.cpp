// _Z7findwayiii shortestlength
/*
 * roads.cpp
 *
 *  Created on: 2013-6-9
 *      Author: Gaular
 */
#include<iostream>
using namespace std;
class Roads{
public:
	int destination[101];
	int length[101];
	int toll[101];
	bool used[101];
	int desnumber;
	Roads(){
		for(int i=0;i<101;i++){
			destination[i]=0;
			length[i]=0;
			toll[i]=0;
			used[i]=false;
		}
		desnumber=0;
	}
};
Roads roads[101];//脚标为起点城市
int totalmoney=0;
int totalcity=0;
int totalroads=0;
int shortestlength=10000000;
void findway(int departure,int havecost,int nowlength){
	if(departure==totalcity&&havecost<=totalmoney&&nowlength<shortestlength){
		shortestlength=nowlength;
		return;
	}
	if(nowlength>shortestlength)
		return;
	for(int i=1;i<=roads[departure].desnumber;i++){
		if(roads[departure].used[i]==true)
			continue;
		if((havecost+roads[departure].toll[i])>totalmoney)
			continue;
		roads[departure].used[i]=true;
		findway(roads[departure].destination[i],havecost+roads[departure].toll[i],nowlength+roads[departure].length[i]);
		roads[departure].used[i]=false;
}
}
int main (){
	cin>>totalmoney>>totalcity>>totalroads;
	for(int i=0;i<totalroads;i++){
		int temp=0;
		cin>>temp;
		roads[temp].desnumber++;
		cin>>roads[temp].destination[roads[temp].desnumber];
		cin>>roads[temp].length[roads[temp].desnumber];
		cin>>roads[temp].toll[roads[temp].desnumber];
	}
	findway(1,0,0);
	if(shortestlength==10000000)
		cout<<-1<<endl;
	else
		cout<<shortestlength<<endl;

	return 0;
}
