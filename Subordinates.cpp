#include <bits/stdc++.h>

using namespace std;

#define forn(i,k,e) for(int i = k; i < e; i++)

/*

*/
signed main() {
	int n;
	cin >> n;
	map<int, vector<int>> children;

	forn(i, 2, n + 1) {
		int c;
		cin >> c;
		children[c].push_back(i);
	}
	vector<int> subordinates(n + 1, -1);

	auto dfs = [&] (auto && self, int cur) -> void {

		subordinates[cur] = children[cur].size();

		if (children[cur].size() == 0) {
			return;
		}
		
		for (int child : children[cur]) {
			if (subordinates[child] == -1)
				self(self, child);
			subordinates[cur] += subordinates[child];
		}
	};

	dfs(dfs, 1);

	for (int i = 1; i <= n ; i++) {
		cout << subordinates[i] << " ";
	}


	return 0;
}