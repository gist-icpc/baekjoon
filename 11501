#include <cstdio>

int price[1000005];

int main(){
	int T;
	scanf("%d", &T);
	for(int testcase = 0; testcase < T; testcase++){
		int day, count = 0, buy = 0, sell = 0;
		long long int answer = 0;
		
		scanf("%d", &day);
		
		for(int i = 0; i < day; i++)
			scanf("%d", &price[i]);
		
		for(int i = day-1; i >= 0; i--){
			if(sell > price[i]){
				count++;
				buy += price[i];
			}
			
			else{
				answer += count * sell - buy;
				sell = price[i];
				count = 0;
				buy = 0;
			}
		}
		answer += count * sell - buy;
		
		printf("%lld\n", answer);
	}
}
