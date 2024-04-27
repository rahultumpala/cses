#include <bits/stdc++.h>

using namespace std;

#define forn(i,k,e) for(int i = k; i < e; i++)
/*

*/
signed main() {
	int n;
	cin >> n;
	map<int, vector<int>> adj;
	vector<bool> taken(n + 1, false);
	vector<bool> visited(n + 1, false);
	forn(i, 1, n) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		// cout << a <<  "-" << b << endl;
	}
	int ans = 0;
	auto dfs = [&](auto && self, int cur) -> void {
		visited[cur] = 1;
		for (int nxt : adj[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = 1;
				self(self, nxt);
				if (!taken[cur] && !taken[nxt]) {
					taken[cur] = 1;
					taken[nxt] = 1;
					ans++;
					// cout << cur << " " << nxt << endl;
				}
			}
		}
	};

	dfs(dfs, adj.begin()->first);

	cout << ans << endl;

	return 0;
}