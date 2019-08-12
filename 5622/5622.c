#include <stdio.h>

int main()
{
    char c[15] = {'\0',};
    int rec[15] = {0, };
    scanf("%s", c);
    int u = 0;
    int totalt = 0, time = 0;
    while(c[u] != '\0')
    {
        switch(c[u]){
                
                case 'A' : time = 3; break;
                case 'B' : time = 3; break;
                case 'C' : time = 3; break;
                case 'D' : time = 4; break;
                case 'E' : time = 4; break;
                case 'F' : time = 4; break;
                case 'G' : time = 5; break;
                case 'H' : time = 5; break;
                case 'I' : time = 5; break;
                case 'J' : time = 6; break;
                case 'K' : time = 6; break;
                case 'L' : time = 6; break;
                case 'M' : time = 7; break;
                case 'N' : time = 7; break;
                case 'O' : time = 7; break;
                case 'P' : time = 8; break;
                case 'Q' : time = 8; break;
                case 'R' : time = 8; break;
                case 'S' : time = 8; break;
                case 'T' : time = 9; break;
                case 'U' : time = 9; break;
                case 'V' : time = 9; break;
                case 'W' : time = 10; break;
                case 'X' : time = 10; break;
                case 'Y' : time = 10; break;
                case 'Z' : time = 10; break;
        }
        totalt += time;
        u++;
    }
    
    printf("%d\n", totalt);
}

