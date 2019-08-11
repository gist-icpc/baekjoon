#include <cstdio>
#include <iostream>

int cache[9];

int n, m;

void f(int k) {
	if (k == m) {
		int order[9];
		for (int i=1;i<=n;i++) {
			order[cache[i]] = i;
		}
		for (int i=1;i<=m;i++) {
			printf("%d ", order[i]);
		}
		printf("\n");
		
	} else {
		for(int i=1;i<=n;i++) {
			if (cache[i] == 0) {
				cache[i] = k+1;
				f(k+1);
				cache[i] = 0;
			}
		}
	}
}

int main () {
	scanf("%d %d", &n, &m);
	
	for (int i=0;i<=n;i++) {
		cache[i] = 0;
	}
	f(0);
	
	return 0;
}
