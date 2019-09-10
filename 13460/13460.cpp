#include<iostream>
#include<stdio.h>
#include<utility>

using namespace std;

int ret = -1;
int n, m;
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
char map[10][10];
pair<int, int> red, blue, hole;

void solve(int num, int yred, int xred, int yblue, int xblue) {
    if (num == 10) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int yred_tmp = yred;
        int xred_tmp = xred;
        int yblue_tmp = yblue;
        int xblue_tmp = xblue;

        if (xdir[i] * xred + ydir[i] * yred > xdir[i] * xblue + ydir[i] * yblue) {

            while (map[yred_tmp + ydir[i]][xred_tmp + xdir[i]] == '.') {
                map[yred_tmp][xred_tmp] = '.';
                yred_tmp += ydir[i];
                xred_tmp += xdir[i];
                map[yred_tmp][xred_tmp] = '#';
            }

            if (map[yred_tmp + ydir[i]][xred_tmp + xdir[i]] == 'O') {
                map[yred_tmp][xred_tmp] = '.';
            }

            while (map[yblue_tmp + ydir[i]][xblue_tmp + xdir[i]] == '.') {
                map[yblue_tmp][xblue_tmp] = '.';
                yblue_tmp += ydir[i];
                xblue_tmp += xdir[i];
                map[yblue_tmp][xblue_tmp] = '#';
            }

            if (map[yblue_tmp + ydir[i]][xblue_tmp + xdir[i]] == 'O') {
                map[yblue_tmp][xblue_tmp] = '.';
                map[yred_tmp][xred_tmp] = '.';
                map[yred][xred] = '#';
                map[yblue][xblue] = '#';
                continue;
            }

            if (map[yred_tmp + ydir[i]][xred_tmp + xdir[i]] == 'O') {

                map[yblue_tmp][xblue_tmp] = '.';
                map[yred_tmp][xred_tmp] = '.';
                map[yred][xred] = '#';
                map[yblue][xblue] = '#';

                if (ret == -1) {
                    ret = num + 1;
                } else {
                    ret = min(ret, num + 1);
                }
                return;
            } else {
                solve(num + 1, yred_tmp, xred_tmp, yblue_tmp, xblue_tmp);
            }

            map[yblue_tmp][xblue_tmp] = '.';
            map[yred_tmp][xred_tmp] = '.';
            map[yred][xred] = '#';
            map[yblue][xblue] = '#';

        } else {

            while (map[yblue_tmp + ydir[i]][xblue_tmp + xdir[i]] == '.') {
                map[yblue_tmp][xblue_tmp] = '.';
                yblue_tmp += ydir[i];
                xblue_tmp += xdir[i];
                map[yblue_tmp][xblue_tmp] = '#';
            }

            if (map[yblue_tmp + ydir[i]][xblue_tmp + xdir[i]] == 'O') {
                map[yblue_tmp][xblue_tmp] = '.';
                map[yred_tmp][xred_tmp] = '.';
                map[yred][xred] = '#';
                map[yblue][xblue] = '#';
                continue;
            }

            while (map[yred_tmp + ydir[i]][xred_tmp + xdir[i]] == '.') {
                map[yred_tmp][xred_tmp] = '.';
                yred_tmp += ydir[i];
                xred_tmp += xdir[i];
                map[yred_tmp][xred_tmp] = '#';
            }

            if (map[yred_tmp + ydir[i]][xred_tmp + xdir[i]] == 'O') {

                map[yblue_tmp][xblue_tmp] = '.';
                map[yred_tmp][xred_tmp] = '.';
                map[yred][xred] = '#';
                map[yblue][xblue] = '#';

                if (ret == -1) {
                    ret = num + 1;
                } else {
                    ret = min(ret, num + 1);
                }
                return;
            } else {
                solve(num + 1, yred_tmp, xred_tmp, yblue_tmp, xblue_tmp);
            }

            map[yblue_tmp][xblue_tmp] = '.';
            map[yred_tmp][xred_tmp] = '.';
            map[yred][xred] = '#';
            map[yblue][xblue] = '#';
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    string tmp;
    getline(cin, tmp);

    for (int y = 0; y < n; y++) {
        getline(cin, tmp);
        for (int x = 0; x < m; x++) {
            if (tmp[x] == '#' || tmp[x] == '.' || tmp[x] == 'O') {
                map[y][x] = tmp[x];
            } else if (tmp[x] == 'R') {
                red.first = y;
                red.second = x;
                map[y][x] = '#';
            } else {
                blue.first = y;
                blue.second = x;
                map[y][x] = '#';
            }
        }
    }

    solve(0, red.first, red.second, blue.first, blue.second);

    printf("%d", ret);

    return 0;

}

