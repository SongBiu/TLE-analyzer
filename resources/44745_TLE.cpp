#include <iostream>
using namespace std;

int main()
{
	int k, m, n;
	int Joseph[15] = { 0 };	//用来记录被杀死忍的下标，有题目可知最多14人
	while (cin >> k && k )
	{
		//if (k >= 14 || k <= 0)	//k不满足时跳过
		//{
		//	cout << k << endl;
		//	continue;
		//}

		n = 2 * k;	//总人数
		m = k;	//m是大于k的，m小于k第一次被杀死的就是好人
		Joseph[0] = 0;	//表示编号从0开始
		for (int i = 1; i <= k; i++)	//需要杀死k人，需要循环k次即可,遇到不满足的m时，i会被重置
		{
			//递推公式，每次枚举完毕将剩下的人按从0到n - i编号，只要好人没有杀掉，则前面k - 1个编号是不变的
			Joseph[i] = (Joseph[i - 1] + m - 1) % (n - i + 1);
			if (Joseph[i] < k)	//第k个人的编号为k - 1,所以这里是<而不是<=
			{
				i = 0;	//重置i，执行完本次循环i=1,
				m++;	//逐个寻找符合的m
			}
		}
		cout << m << endl;
	}
	return 0;
}