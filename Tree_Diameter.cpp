#include <bits/stdc++.h>

using namespace std;

#define forn(i,k,e) for(int i = k; i < e; i++)
/*
Find max depth from each child of current node
add top 2 max depths + 1 = to get the longest path containing current node

repeat recursively.

TC = O(N) tree visited only once
SC = O(1) no extra space to store tree data
*/
signed main() {
	int n;
	cin >> n;
	map<int, vector<int>> adj;
	forn(i, 1, n) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	auto dfs = [&](auto && self, int cur, int parent) -> int {
		int d1 = 0, d2 = 0;

		if (adj[cur].size() == 1 && adj[cur][0] == parent) {
			//leaf node - return dist from parent node to cur node = 1
			return 1;
		}

		for (int nxt : adj[cur]) {
			if (nxt != parent) {
				int dist = self(self, nxt, cur);
				if (dist > d1) {
					d2 = d1;
					d1 = dist;
				} else if (dist > d2) d2 = dist;
			}
			ans = max(ans, 1 + d1 + d2);
		}
		return 1 + d1;
	};

	dfs(dfs, adj.begin()->first, -1);

	if (n == 1) {
		cout << 0;
	} else {
		cout << ans - 1;
	}


	return 0;
}