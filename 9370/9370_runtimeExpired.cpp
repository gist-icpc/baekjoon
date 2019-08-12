#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

int distance[2001];
std::vector<std::pair<int, int>> edges[2001]; //(x, y) ... x: to, y: weight
const int INF = 100000000;
int previous[2001];
int target[100];
int n, m, t;
int s, g, h;
int x, y, w;

void shortest() {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({0, s});
	int curr;
	int cost;
	int nei;
	int wei;
	while(!pq.empty()) {
		cost = -pq.top().first;
		curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < edges[curr].size(); i++) {
			nei = edges[curr][i].first;
			wei = edges[curr][i].second;
			if (cost + wei < distance[nei]) {
				distance[nei] = cost + wei;
				previous[nei] = curr;
				pq.push({-distance[nei], nei});
			}
		}
	}
}

void check() {
	int curr;
	std::vector<int> out;
	for (int i = 0; i < t; i++) {
		curr = target[i];
		while (curr != s) {
			if (curr == g) {
				if (previous[curr] == h) {
					out.push_back(target[i]);
				}
				break;
			} else if (curr == h) {
				if (previous[curr] == g) {
					out.push_back(target[i]);
				}
				break;
			} else {
				curr = previous[curr];
			}
		}
	}
	std::sort(out.begin(), out.end());
	for(int i = 0; i < out.size(); i++) {
		std::cout << out[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int trie;
	std::cin >> trie;
	while (trie--) {
		trie--;
		std::cin>>n>>m>>t;
		std::cin>>s>>g>>h;
		for (x = 0; x <= n; x++) {
			distance[x] = INF;
			previous[x] = -1;
		}
		distance[s] = 0;
		for (int i = 0; i < m; i++) {
			std::cin>>x>>y>>w;
			edges[x].push_back({y, w});
			edges[y].push_back({x, w});
		}
		for (int i = 0; i < t; i++) {
			std::cin>>target[i];
		}
		
		shortest();
		check();
		
		for (x = 0; x <= n; x++) {
			edges[x].clear();
		}
	}
	return 0;
}
