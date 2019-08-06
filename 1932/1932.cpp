#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int num;
	int i, j, k;
	
	cin>>num;
	
	int array[num][num];
	int ans_array[num][num];
	
	for(i = 1; i <= num; i++)
	{
		for(j = 0; j < num; j++)
		{
			for(k = 0; k < i; k++)
			{
				cin>>array[j][k];
			}
			i++;
		}
	}
	
	for(i = 1; i <= num; i++)
	{
		for(j = 0; j < num; j++)
		{
			for(k = 0; k < i; k++)
			{
				ans_array[j][k] = 0;
			}
			i++;
		}
	}
	
	ans_array[0][0] = array[0][0];
	
	ans_array[1][0] = array[0][0] + array[1][0];
	ans_array[1][1] = array[0][0] + array[1][1];
	
	for(i = 1; i <= num; i++)
	{
		for(j = 1; j < num; j++)
		{
			for(k = 0; k < i + 1; k++)
			{
				if(k == 0)
					ans_array[j][k] = array[j][k] + ans_array[j - 1][k];
				else if(k == j){
					ans_array[j][k] = array[j][k] + ans_array[j - 1][j - 1];
				}
				else if(k > 0 && k < j)
					ans_array[j][k] = array[j][k] + max(ans_array[j - 1][k], ans_array[j - 1][k - 1]);
			}
			i++;
		}
	}

	int max;
	
	max = ans_array[num - 1][0];
	
	for(j = 1; j < num; j++)
	{
		if(max < ans_array[num - 1][j])
			max = ans_array[num - 1][j];
		else
			continue;
	}
	
	cout<<max;
	
	return 0;
}
