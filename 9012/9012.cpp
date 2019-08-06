#include <iostream>
#include <stack>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	char input[51];
	int T;
	bool fin = false;
	
	std::cin>>T;
	
	for(int i = 0; i < T; i++)
	{
		std::cin>>input;
		std::stack<int> checker;
		fin = false;
		for(int j = 0; input[j] != '\0'; j++)
		{
			switch(input[j])
			{
				case '(' : 
					checker.push(1);
					break;
				case ')' :
					if(checker.empty())
					{
						fin = true;
					}
					else checker.pop();
					break;
			}
			if(fin) break;
		}
		if(!fin && checker.empty()) std::cout<<"YES\n";
		else std::cout<<"NO\n";
	}
	
	return 0;
}
