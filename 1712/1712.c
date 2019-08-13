#include <stdio.h>

void prob5622();
void prob1712();

int main()
{
    prob1712();
}

void prob1712()
{
    int a = 0, b = 0, c = 0;
    int k;
    scanf("%d %d %d", &a, &b, &c);
    if(b>=c) printf("-1\n");
    else { k = a/(c-b) + 1; printf("%d\n", k);}
}
