/*
1012:Joseph
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
The Joseph's problem is notoriously known. For those who are not familiar with the original problem: from among n people, numbered 1, 2, . . ., n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give us the message about the incident. For example when n = 6 and m = 5 then the people will be executed in the order 5, 4, 6, 2, 3 and 1 will be saved.

Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy. 

输入
The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
输出
The output file will consist of separate lines containing m corresponding to k in the input file.
样例输入
3
4
0
样例输出
5
30
*/
#include<iostream>
#include<memory.h>
using namespace std;
int main(){
	int k,m;
	bool guy[30];
	while(cin>>k){
		if(!k)
			return 0;
		if(k==1){
			cout<<'2'<<endl;
			continue;
		}
		for(m=k+1; ; m++){
			if(!(m%(k*2)))	continue;
			memset(guy,1,sizeof(guy));
			int t=0,d=0;	//t数数，d为死亡人数
			for(int i=1;d<k ;i++){
				if(i>k*2)	i=1;
				if(guy[i]){
					t++;
					if(t==m){
						if(i>k){
							guy[i]=false;
							d++;
							t=0;
						}
						else	break;
					}
				}
			}
			if(d==k){
				cout<<m<<endl;
				break;
			}
		}
	}
}