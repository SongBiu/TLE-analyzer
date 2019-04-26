# include <iostream>
# include <list>

using namespace std;
int data[13] ={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
class Node
{
public:
	bool is_good;
};

void joseph(int k)
{
	for(int min_id =1; ;min_id++)
	{
		list<Node> node_list;
		for(int i=0; i<k; i++)
		{
			Node node;
			node.is_good = true;
			node_list.push_back(node);
		}
		for(int i=0; i<k; i++)
		{
			Node node;
			node.is_good = false;
			node_list.push_back(node);
		}

		list<Node>::iterator iter = node_list.begin();
		int i=0;
		for(; i<k; i++)
		{
			for(int j=0; j<(min_id-1)%node_list.size(); j++)
			{
				iter++;
				if(iter == node_list.end())
					iter = node_list.begin();
			}
			if(iter->is_good == true)
				break;
			else
			{
				list<Node> ::iterator temp_iter = iter;
				iter++;
				if(iter == node_list.end())
					iter = node_list.begin();			
				node_list.erase(temp_iter);
			}
		}

		if(i == k)
		{
			cout<<min_id<<endl;
			return ;
		}
		else
		{
			continue;
		}
	}
}

void joseph2(int k)
{
	int min_id =1;
	int ans[15];
	ans[0] = 0;
	for(int i=1; i<=k; i++)
	{
		ans[i] =(ans[i-1]+min_id-1)%(2*k-i+1);
		if(ans[i]<k)
		{
			i = 0;
			min_id ++;
		}
	}

	cout<<min_id<<endl;
}

int main()
{
	//freopen("e:/test.txt","r",stdin);
	int k;
	while(cin>>k && k!=0)
	{
		joseph2(k);
	}
	return 0;
}