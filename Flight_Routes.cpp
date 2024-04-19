/*

Standard Dijkstra's Algo but do not break immediately when Nth city is reached.

Wait until Nth city is reached K times.

There's a twist: Do not naively insert each adjacent city

If current city X is visited atleast K times, then all the neighbouring cities CAN BE IGNORED.

Since we are using a priority_queue, visiting a city K times implies: ALL K shortest paths to the city were traversed.

If the city X is a node in the path from 1 to N, then all K shortest paths to N can be generated

from K shortest paths to city X.
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pli;

signed main() {

	int n, m, k;

	cin >> n >> m >> k;

	map<int, vector<pair<int,int>>> paths;

	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		paths[a].push_back({b, c});
	}


	// store {cost, city}
	priority_queue<pli, vector<pli>, greater<pli>> pq;

	pq.push({0, 1});

	vector<long long> costs;
	vector<int> visit_cnt(n+1, 0);

	while(costs.size() < k && !pq.empty()){
		auto [cost, from] = pq.top();
		pq.pop();
		if(from == n){
			costs.push_back(cost);
		}
		if(visit_cnt[from] > k) continue;
		for(auto [to, fare]: paths[from]){
			pq.push({ cost + fare, to });
		}
		visit_cnt[from]++;
	}


	for(long long cost : costs){
		cout << cost << " ";
	}
}