#include <cstdio>
#include <iostream>

const unsigned long INF = 1UL << 31;

int d[501];
long dp [500][500];


int main () {
	int n;
	scanf("%d", &n);

	for (int i=0;i<n;i++) {
		scanf("%d %d", &d[i], &d[i+1]);
		
		for (int j=i;j<n;j++) {
			dp[i][j] = i==j? 0 : INF;
		}
	}
	
	//recursive func: 168ms vs iterative: 48ms. this one is better
	for (int i=0;i<n-1;i++) {
		dp[i][i+1] = d[i]*d[i+1]*d[i+2];
	}
	
	for (int k=2;k<=n-1;k++) {
		for (int s=0;s+k<n;s++) {
			int e = s+k;
			for(int m=s;m<e;m++) {
				dp[s][e] = std::min((unsigned long)dp[s][e], (unsigned long)dp[s][m] + dp[m+1][e] + d[s]*d[m+1]*d[e+1]);
			}
		}
	}
	
	printf("%lu", dp[0][n-1]);
}
