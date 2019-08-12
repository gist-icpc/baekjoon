#include <cstdio>
#include <iostream>

long d[2001];
int dp[2001][2001];

int ask(int s, int e) {
	if(dp[s][e] > -1)
		return dp[s][e];
	
	if (d[s]!=d[e]) {
		//numbers don't match
		dp[s][e] = 0;
	} else if (e-s == 1) {
		//same numbers, next to each other
		dp[s][e] = 1;
	} else {
		//make further enquiry
		dp[s][e] = ask(s+1, e-1);
	}
	return dp[s][e];
}

int main () {
	int n, m, i,j, s,e;
	scanf("%d", &n);
	
	for(i=1;i<=n;i++) {
		scanf("%ld", &d[i]);
	}
	
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if (i==j) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = -1;
			}
		}
	}
	
	scanf("%d", &m);
	
	for(i=0;i<m;i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", ask(s,e));
	}
	
	return 0;
}
