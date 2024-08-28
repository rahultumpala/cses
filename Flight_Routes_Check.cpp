#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
#define forn(i, k, e) for (int i = k; i < e; i++)
#define dbg(x) cout << #x << " = " << x << endl

/*
Brute force:

Iterate through all cities, travel through all outgoing paths, count destinations.

O(N^2)

Optimise?

If city X can visit cities A, B & C, then a city Y that can visit city X
can also visit cities A, B & C.

What if a city X can only visit a subset of cities? then the missing city is the answer

Solution:

-Root the graph at some city ( say city at index 0 ).
-Travel the graph
	if all citites are visited
	 	store this city as Center (assume Center as city that has path to all cities)
	 	and all cities that have a path to this city are also centers
	else
	 	ans = NO
- Iterate through cities
  For each city:
  	travel the graph until a center is found. 
  	If a center is found:
  		mark this as a center & stop travelling
  	else:
  		ans = NO
  		return this & some center, there is no path.

*/

int32_t main() {
	int n,m;
	cin >> n >> m;
	
	map<int, vector<int>> con;
	map<int, vector<int>> incoming;
	forn(i,0,m) {
		int a,b;
		cin >> a >> b;
		// one way
		con[a].push_back(b);
		incoming[b].push_back(a);
	}
	
	const int max_nodes = 1e5+1;
	bool centers[max_nodes];
	bool visited[max_nodes];
	memset(visited, 0, sizeof(visited));
	memset(centers, 0, sizeof(centers));

	forn(i,1,n+1){
		int count = 1;

		auto travel = [&](auto &&self, int cur) -> void {
			visited[cur] = 1;
			for(int next : con[cur]){
				if(centers[next]){
					centers[i] = 1;
					count = n;
					break;
				}

				if(!visited[next]) {
					count++;
					self(self, next);
				}
			}
			if(count == n) return;
		};

		travel(travel, i);
 		if(count >= n){
			centers[i] = 1;
			memset(visited, 0, sizeof(visited));
			stack<int> cities;
			cities.push(i);
			while(!cities.empty()){
				int cur = cities.top();
				cities.pop();
				centers[cur] = 1;
				for(int prev : incoming[cur]) if(!centers[prev]) cities.push(prev);
			}
		} else {
			cout << "NO\n";
			cout << i << " ";
			forn(j,1,n+1) if(!visited[j]) { cout << j ; return 0; }
		}
	}
	cout << "YES"; 
	return 0;
}