#include <iostream>
using namespace std;

int main(void) {
	
	int num, snum;
	int i;
	int j;
	int a[50];
	int b[300];
	cin>>num;
	
	a[0] = 0;
	a[1] = 1;
	
	for(j = 2; j < 45; j++)
	{
		a[j] = a[j - 1] + a[j - 2];
	}
	
	for(i = 0; i < num; i++)
	{
		cin>>snum;
		b[i] = snum;
	}
	
	
	for(i = 0; i < num; i++)
	{
		if(b[i] == 0)
		{
			cout<<1<<' '<<0<<endl;
		}
		else
			cout<<a[b[i] - 1]<<' '<<a[b[i]]<<endl;
	}
	
	return 0;
}
