#include <cstdio>
#include <iostream>

int cache[9];
char s[20];

int n, m;

void f(int k) {
	if (k == m) {
		printf("%s\n", s);
	} else {
		for(int i=1;i<=n;i++) {
			if (cache[i] == 0) {
				cache[i] = 1;
				s[2*k] = i+'0';		// 순서를 저장하는 대신, 아예 문자열을 만들어두면 더 빨라집니다 
				s[2*k+1] = ' ';
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
