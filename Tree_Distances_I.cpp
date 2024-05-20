/*
Find the diameter of the tree using dp.

When finding the diamter, make note of the leaf nodes
that form the ends of the diameter.

Travel from each end of the diameter and store the max distance upto each node in the tree.
*/
#include<bits/stdc++.h>
 
using namespace std;
 
int dist[200005];
map<int, vector<int>> adj;
int diameter = 0, n1 = 0, n2 = 0;
 
// return max depth leaf node
int calc_diameter(int cur, int p) {
	int dmax = 0;
	int max_d_leaf = cur;
 
	for (const int next : adj[cur]) {
		if (next == p || dist[next] > 0)
			continue;
 
		int leaf = calc_diameter(next, cur);
 
		int d = 1 + dist[next];
		if (d + dmax > diameter) {
			diameter = d + dmax;
			n1 = leaf;
			n2 = max_d_leaf;
		}
 
		if (d > dmax) {
			dmax = d;
			max_d_leaf = leaf;
		}
	}
 
	dist[cur] = dmax;
	return max_d_leaf;
}
 
void calc_max_dist(int cur, int p, int d) {
 
	if (dist[cur] <= d) dist[cur] = d;
 
	for (const int next : adj[cur]) {
		if (next == p) continue;
		calc_max_dist(next, cur, d + 1);
	}
}
 
signed main() {
	int n;
 
	cin >> n;
	int m = n - 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	memset(dist, 0, sizeof(dist));
 
	calc_diameter(1, -1);
 
	memset(dist, 0, sizeof(dist));
 
	calc_max_dist(n1, 0, 0);
	calc_max_dist(n2, 0, 0);
 
	// printf("start = %d, _end = %d\n", n1, n2);
 
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
 
	return 0;
}