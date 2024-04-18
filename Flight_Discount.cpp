#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pli;

signed main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<pli>> adj;

	while(m--){
		int a,b;
		long long w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}

	// store price to reach a stop without discounting any flight in the path
	vector<long long> price(n+1, LLONG_MAX);
	price[1] = 0;

	// store price to reach a stop with discounting any ONE flight in the path 
	vector<long long> price_with_discount(n+1, LLONG_MAX);
	price_with_discount[1] = 0;


	vector<bool> in_queue(n+1, false);

	auto comp = [&](int x, int y){ return price_with_discount[x] >= price_with_discount[y]; };

	/*

	 min heap to store the stop which has the least price to reach 
	 with 1 of the flight along the path discounted
	 this is to ensure that when the last stop is seen then we can be sure
	 that the min price to reach the last stop is already calculated.
	
	*/
	priority_queue<int, vector<int>, decltype(comp)> q(comp);
	
	q.push(1);


	while(!q.empty()){
		int cur = q.top();
		q.pop();
		in_queue[cur] = false;

		if(cur == n) break;

		for(auto [next, cost] : adj[cur]){

			bool reduced = false;

			if( price[cur] + cost < price[next] ){
				price[next] = price[cur]  + cost;
				reduced = 1;
			}

			if( price[cur] + (cost / 2) < price_with_discount[next]){
				price_with_discount[next] =  price[cur] + (cost / 2);
				reduced = 1;
			}	


			// compare with price_with_discount because the assumption is
			// earlier some flight was discounted in this path
			if( price_with_discount[cur] + cost < price_with_discount[next] ){
				price_with_discount[next] =  price_with_discount[cur] + cost;
				reduced = 1;
			}


			if(reduced && !in_queue[next]){
				q.push(next);
				in_queue[next] = 1;
			}

		}
	}

	cout << price_with_discount[n] << endl;
}