#include<iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int a_size, b_size;
	a_size = a.size();
	b_size = b.size();
	int *cmp = new int[b_size + 1];//用1到max
	for (int i = 0; i < b_size + 1; ++i)
	{
		cmp[i] = 0;
	}
	for (int i = 0; i < a_size; ++i)
	{
		int tmp = cmp[0];//代表的是左向上斜那个位置的值
		for (int j = 1; j < b_size+1; ++j)
		{
			int tmp2 = tmp;//左上角那一个
			tmp = cmp[j];
			if (a[i] == b[j-1])
			{
				cmp[j] = tmp2 + 1;
			}
			else 
			{
				if (cmp[j] > cmp[j - 1])
					cmp[j] = cmp[j];
				else cmp[j] = cmp[j - 1];
			}	
		}
	}
	cout << cmp[b_size];
	return 0; 
}

