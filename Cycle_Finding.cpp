/*

Bellman-Ford algorithm implementation to find negative weight cycle in a graph.

*/

#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;

signed main() {
	
	int n, m;
	cin >> n >> m;
	vector<t3> edges;

	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}

	vector<long long> dist(n+1, 0);
	vector<int> parent(n+1, -1);

	int lastVisitedNode = -1;

	for(int i = 0 ; i < n; i++){
		lastVisitedNode = -1;
		for(auto [from, to, len] : edges){
			if( dist[from] + len  < dist[to]){
				dist[to] = dist[from] + len;
				parent[to] = from;
				lastVisitedNode = to;
			}
		}
	}


	/*
	 if there is a negative cycle distances will be modified in the last (Nth) iteration
	 then lastVisitedNode will not be -1
	*/
	
	if(lastVisitedNode == - 1){
		cout << "NO";
	} else {
		cout << "YES" << endl;

		/*
			from the edge that was relaxed in the Nth iteration - take the "to" node of the edge 
			("lastVisitedNode").

			"lastVisitedNode" : This vertex will either lie in a negative weight cycle, or is reachable from it. 
			
			To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex "lastVisitedNode"
			pass through to the predecessors N times.

			Hence we will get the vertex Y, namely the vertex in the cycle earliest reachable from source.

			We have to go from this vertex, through the predecessors, until we get back to the same vertex Y 
			(and it will happen, because relaxation in a negative weight cycle occurs in a circular manner).
		*/
		for (int i = 0; i < n; ++i) {
			lastVisitedNode = parent[lastVisitedNode];
		}

		vector<int> cyclePath;

		for(int cur = lastVisitedNode; ; cur = parent[cur]){
			cyclePath.push_back(cur);
			if(cur == lastVisitedNode && cyclePath.size() > 1) break;
		}

		reverse(cyclePath.begin(), cyclePath.end());

		for(int node : cyclePath) 
			cout << node << " ";
	}
}