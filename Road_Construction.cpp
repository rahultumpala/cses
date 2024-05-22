/*
Simple Union Find implementation.
Union in O(N) where N = size of smaller tree
Find in O(1)
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> parent(n + 1, 0);
	map<int, int> tree;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		tree[i] = 1;
	}
	map<int, vector<int>> adj;

	int max_size = 0;

	int prev_parent = 0;
	auto _union = [&](auto && self, int p, int b) -> void {
		parent[b] = p;
		tree[p]++;
		max_size = max(max_size, tree[p]);
		for (int next : adj[b]) {
			if (parent[next] == prev_parent) {
				parent[next] = p;
				self(self, p, next);
			}
		}
	};

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (parent[a] != parent[b]) {
			if (tree[parent[a]] >= tree[parent[b]]) {
				prev_parent = parent[b];
				tree.erase(prev_parent);
				_union(_union, parent[a], prev_parent);
			} else {
				prev_parent = parent[a];
				tree.erase(prev_parent);
				_union(_union, parent[b], prev_parent);
			}
		}
		cout << tree.size() << " " << max_size << endl;
	}
	return 0;
}