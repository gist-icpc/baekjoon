#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
	string def = "us";
	string conversion_tgts[] = { "a", "i", "y", "l", "n", "ne", "o", "r", "t", "u", "v", "w" };
	string conversion_rpcs[] = { "as", "ios", "ios", "les", "anes", "anes", "os", "res", "tas", "us", "ves", "was" };
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		string input;
		string result;
		cin >> input;
		bool converted = false;
		for (int j = 0; j < 12; j++)
		{
			int len = input.length() - conversion_tgts[j].length();
			if (!strcmp(input.c_str() + (len), conversion_tgts[j].c_str()))
			{
				result = input.substr(0, len) + conversion_rpcs[j];
				converted = true;
				break;
			}
		}
		if (!converted)
			result = input + def;
		cout << result << endl;
	}
	return 0;
}
