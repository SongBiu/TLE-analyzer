#include<iostream>
using namespace std;
int main()
{ int k;
cin >> k;
while (k != 0)
{ int m = 2, out = 0, cnt = 1, num = 1, total = 2 * k; //初始化
while (out < k) //出局人数少于坏小孩数
{ num = (num + m - 1) % total; //报数到m时小孩的编号
if (num == 0)
num = total; //模运算出现0，就是末尾；
if (num > k) //编号大于k是坏小孩
{ out++; total--; } //多一人出局，总人减1
else //落到好小孩，放弃
{ m++; //m++,再试
num = 1; out = 0; total = 2 * k; //变量回到初始值
}
}
cout << m << endl; //退出循环，说明m到达要求，输出
cin >> k; //读下一组数据
}
return 0;
}