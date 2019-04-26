#include<stdio.h>

int n;

int main()
{
	int k;
	while(1)
	{
		scanf("%d",&k);
		if(k==0)
			break;
		int left=k;
		int s=0;
		n=2*k;
		int q=1;
		int cl=n;
		int xs=1,js=1;
		int m;
		int zh;
		int j;


		//好坏人标注完成//
		

		for(xs=0;;xs++)									//循环查找//
		{
			for(js=k+1;js<=2*k;js++)
			{
				int a[36]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1};
				left=k;
				n=2*k;

				for(j=k+1;j<16;j++)
					a[j]=-1;
				q=1;
				m=js+xs*cl;
				zh=0;
				while(left>0)
				{
					zh=(zh+m)%n;
					if(zh==0)
						zh=n;
					if(a[zh]==1)				//如果弄死好人，直接下一循环//
					{
						q=0;
						break;
					}

					left--;

					a[n]=0;


					zh--;
					n--;
				}


				if(q==0)
					continue;

				printf("%d\n",m);
				s=1;
				break;
			}
			if(s==1)
				break;
		}
	}
	return 1;
}