#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int n, m;
int map[101][101];
int visited[101][101] = {0, };
int x_dir[] = {0, 1, 0, -1};
int y_dir[] = {-1, 0, 1, 0};
string tmp;

int dfa() {
    queue< pair< pair<int, int>, int> > q;
    q.push(make_pair(make_pair(1, 1), 1));
    visited[1][1] = true;

    while(!q.empty()) {
        pair< pair<int, int>, int> temp = q.front();
        q.pop();
        
        int y = temp.first.first;
        int x = temp.first.second;
        int num = temp.second;

        if (y == n && x == m) {
            return num;
        }

        for (int i = 0; i < 4; i++) {
            int yy = y + y_dir[i];
            int xx = x + x_dir[i];
            if (yy >= 1 && xx >= 1 && yy <= n && xx <= m) {
                if (map[yy][xx] && !visited[yy][xx]) {
                    visited[yy][xx] = true;
                    q.push(make_pair(make_pair(yy, xx), num + 1));
                }
            }
        }
    }

    return -1;
}
        


int main() {
    scanf("%d %d", &n, &m);
    getline(cin, tmp);
    for (int i = 0; i < n; i++) {
        getline(cin, tmp);
        for (int j = 0; j < m; j++) {
            map[i + 1][j + 1] = tmp[j] - '0';
        }
    }

    printf("%d", dfa());
    return 0;
}

