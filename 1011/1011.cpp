#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int bgn, ed, ret = 0;
        scanf("%d %d", &bgn, &ed);

        int fil = ed - bgn;

        for (int i = 46340; i > 0; i--) {
            if (fil >= i * i) {
                ret = 2 * i - 1;
                fil -= i * i;
                while (i > 0 && fil > 0) {
                    ret += fil / i;
                    fil %= i;
                    i--;
                }
                break;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}

