#include <cstdio>
#include <iostream>
#define INF 16000001

int n;

int w[16][16];
int dp[16][(long)1<<17];

int f(int cur, long bit, int cities) {
	
	if (cities == 0)
		return w[n-1][cur];
	
	if (dp[cur][bit] != -1)
		return dp[cur][bit];
		
	int x = INF;
	for (int i=0;i<n-1;i++) {
		if(bit & ((long)1<<i)) {
			x = std::min(x, f(i, bit ^ ((long)1<<i), cities-1) + w[i][cur]); 
		}
	}
	
	return dp[cur][bit] = x;
}

int main() {
	scanf("%d", &n);
	
	for (long i=0;i<16*((long)1<<17);i++) {
		dp[i%16][i/16] = -1;
	}
	
	
	for (int i=0;i<n*n;i++) {
		int* p = &w[i/n][i%n];
		scanf("%d", p);
		if (!*p)
			*p = INF;
	}
	
	printf("%d", f(n-1,  ((long) 1<<n)-1, n-1));
}
