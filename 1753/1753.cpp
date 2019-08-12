#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Vertex {
	private:
		int item;
		int dist;
	public:
		Vertex(int v, int d) : item(v), dist(d) {}
		int getItem() { return item; }
		int getDist() { return dist; }
		void setDist(int dist) { this -> dist = dist; }
};

class Edge {
	private:
		int from;
		int to;
		int weight;
	public:
		Edge() {}
		Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
		int getFrom() { return from; }
		int getTo() { return to; }
		int getWeight() { return weight; }
};

class Comparator {
	public:
		bool operator() (Vertex i, Vertex j) {
			return (i.getDist()) > (j.getDist());
		}
};

class Fringe {
	private:
		int size;
		std::unordered_set<int> visited;
		std::vector<Vertex> vertice;
		std::priority_queue<Vertex, std::vector<Vertex>, Comparator> pq;
	public:
		Fringe() {}
		Fringe(int start, int s) : size(s) {
			vertice.push_back(Vertex(-1, -1));
			for (int i = 1; i <= size; i++) {
				if (i == start) {
					vertice.emplace_back(Vertex(i, 0));
				} else {
					vertice.emplace_back(Vertex(i, 1000000000));
				}
				pq.emplace(vertice.at(i));
			}
		}
		
		int pop() {
			Vertex temp = pq.top();
			pq.pop();
			while (visited.find(temp.getItem()) != visited.end()) {
				temp = pq.top();
				pq.pop();
			}
			visited.insert(temp.getItem());
			return temp.getItem();
		}
		
		void update(int i, int dist) {
			vertice.erase(vertice.begin() + i);
			vertice.insert(vertice.begin() + i, Vertex(i, dist));
			pq.push(Vertex(i, dist));
		}
		
		int getDist(int i) {
			return vertice.at(i).getDist();
		}
		
		bool isVisited(int i) {
			return (visited.find(i) != visited.end());
		}
		
		bool isEmpty() {
			if (pq.empty()) {
				return true;
			} else {
				/*
				Vertex temp = pq.top();
				pq.pop();
				while (visited.find(temp.getItem()) != visited.end() && !pq.empty()) {
					temp = pq.top();
					pq.pop();
				}
				*/
				return visited.size() == size;
			}
		}
};

class Shortest {
	private:
		Fringe fringe;
		int v, e, k;
		std::vector<Edge>* edges;
		std::vector<Edge>::iterator* iter;
		int* previous;
	public:
		Shortest() {
			std::cin>>v>>e>>k;
			fringe = Fringe(k, v);
			edges = new std::vector<Edge>[v + 1];
			//iter = new std::vector<Edge>::iterator[v + 1];
			previous = new int[v + 1];
			for (int i = 1; i <= v; i++) {
				//iter[i] = edges[i].begin();
				previous[i] = -1;
			}
			
			int f, t, w;
			for (int i = 0; i < e; i++) {
				std::cin>>f>>t>>w;
				edges[f].emplace_back(Edge(f, t, w));
			}
		
			/*
			for (int i = 1; i <= v; i++) {
				std::cout<<i<<"th edges\n";
				std::cout<<"# = "<<edges[i].size()<<'\n';
				for (int j = 0; j < edges[i].size(); j++) {
					std::cout<<edges[i].at(j).getFrom()<<' '<<edges[i].at(j).getTo()<<' '<<edges[i].at(j).getWeight()<<'\n';
				}
			}
			*/
		}
		
		void distanceInit() {
			int curr, nei, wei;
			while (!fringe.isEmpty()) {
				curr = fringe.pop();
				//std::cout<<"Now processing: "<<curr<<'\n';
				for (int i = 0; i < edges[curr].size(); i++) {
					nei = edges[curr].at(i).getTo();
					wei = edges[curr].at(i).getWeight();
					//std::cout<<i + 1<<"th edge: "<<'('<<curr<<", "<<nei<<", "<<wei<<")\n";
					//std::cout<<"  New distance: "<<fringe.getDist(curr) + wei<<'\n';
					//std::cout<<"  Best distance: "<<fringe.getDist(nei)<<'\n';
					if (fringe.getDist(curr) + wei < fringe.getDist(nei)) {
						fringe.update(nei, fringe.getDist(curr) + wei);
						previous[nei] = curr;
					}
				}
			}
		}
		
		void pathCount() {
			int temp;
			int count;
			for (int i = 1; i <= v; i++) {
				//std::cout<<"Current Vertex: "<<i<<'\n';
				//std::cout<<"Previous Vertex: "<<previous[i]<<'\n';
				if (!fringe.isVisited(i) || fringe.getDist(i) == 1000000000) {
					std::cout<<"INF\n";
				} else if (i == k) {
					std::cout<<"0\n";
				} else {
					std::cout<<fringe.getDist(i)<<'\n';
				}
			}
		}
};

int main() {
	Shortest run = Shortest();
	run.distanceInit();
	run.pathCount();
	return 0;
}
