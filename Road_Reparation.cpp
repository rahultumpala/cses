/*
The goal is to find a minmum total cost path that connects ALL the cities
aka. build the Minimum Spanning Tree and return its cost

Kruskal's Algorithm with Union Find.

sort(edges.begin(), edges.end()) gives Runtime error for the last test case. 
priority queue doesn't
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef tuple<int, int, long long> t3;
unordered_map<int, vector<int>> adj;

vector<int> parent;
vector<int> treesize;

int p_prev = -1;

void unite(int p, int b) {
	parent[b] = p;
	treesize[p]++;
	for (int next : adj[b]) {
		if (parent[next] == p_prev) {
			parent[next] = p;
			unite(p, next);
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	auto comp = [](t3 & a, t3 & b) {
		auto [a1, a2, a3] = a;
		auto [b1, b2, b3] = b;
		return a3 >= b3;
	};

	priority_queue<t3, vector<t3>, decltype(comp)> pq(comp);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({a, b, c});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	for (int i = 0; i <= n; i++){
		parent.push_back(i);
		treesize.push_back(1);
	}


	long long ans = 0;
	
	while(!pq.empty()){
		auto [a, b, cost] = pq.top();
		pq.pop();
		
		if (parent[a] == parent[b]) continue;

		ans += cost;
		if (treesize[parent[a]] > treesize[parent[b]]) {
			p_prev = parent[b];
			unite(parent[a], b);
		} else {
			p_prev = parent[a];
			unite(parent[b], a);
		}
	}

	if (treesize[parent[1]] != n)
		cout << "IMPOSSIBLE";
	else cout << ans;
}