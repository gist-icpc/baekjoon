#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int n, ret = 0;
    scanf("%d", &n);

    for (int i = 5; i <= n; i += 5) {
        int tmp = i;
        while (tmp % 5 == 0) {
            tmp /= 5;
            ret++;
        }

    }
    printf("%d", ret);
    return 0;
}

