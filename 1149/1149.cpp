#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int num, i, j;
	cin>>num;
	
	int array[num][3];
	int ans_array[num][3];
	vector<int> temp;
	
	int min_value;
	
	
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < 3; j++)
		{
			cin>>array[i][j];
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		ans_array[0][0] = array[0][0];
		ans_array[0][1] = array[0][1];
		ans_array[0][2] = array[0][2];
		if(i == 0)
			ans_array[0][1] = ans_array[0][2] = 10000;
		if(i == 1)
			ans_array[0][0] = ans_array[0][2] = 10000;
		if(i == 2)
			ans_array[0][1] = ans_array[0][0] = 10000;
		
		for(int row = 1; row < num; row++)
		{
			for(int col = 0; col < 3; col++)
			{
				if(col == 0)
					ans_array[row][col] = array[row][col] + min(ans_array[row - 1][1], ans_array[row - 1][2]);
				else if(col == 1)
					ans_array[row][col] = array[row][col] + min(ans_array[row - 1][0], ans_array[row - 1][2]);
				else if(col == 2)
					ans_array[row][col] = array[row][col] + min(ans_array[row - 1][1], ans_array[row - 1][0]);
			}
		}
		
		min_value = min(ans_array[num - 1][0], ans_array[num - 1][1]);
		min_value = min(ans_array[num - 1][2], min_value);
		temp.push_back(min_value);
	}
	
	min_value = min(temp[0], temp[1]);
	min_value = min(temp[2], min_value);
	
	cout<<min_value;
	
	return 0;
}
