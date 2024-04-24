#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<long long, int> pli;
 
/*
use priorirty queue to traverse through neighbors
if already visited a neighbour with a lower visit cost then ignore
else if previous visited cost is higher then visit & reset params
else if prev visit cost is equal then add ways
*/
 
signed main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pli>> adj;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    vector<long long> visit_cost(n+1, 1e17);
    vector<int> ways(n + 1);
    vector<int> min_node_cnt(n + 1, 1e6);
    vector<int> max_node_cnt(n + 1, 0);
    int mod = 1e9 + 7;
 
    ways[1] = 1;
    min_node_cnt[1] = 0;
    max_node_cnt[1] = 0;
    visit_cost[1] = 0;
 
    // store {cost , vertex}
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});
 
    while(!pq.empty()) {
        auto [cur_cost, cur] = pq.top();
        pq.pop();
 
        for(auto [next, price] : adj[cur]){
            long long cost = cur_cost + price;
 
            if(cost > visit_cost[next]) continue;
 
            if(visit_cost[next] == cost) {
                (ways[next] += ways[cur]) %= mod;
                min_node_cnt[next] = min(min_node_cnt[next], 1 + min_node_cnt[cur]);
                max_node_cnt[next] = max(max_node_cnt[next], 1 + max_node_cnt[cur]);
            } else {
                visit_cost[next] = cost;
                ways[next] = ways[cur];
                min_node_cnt[next] = 1 + min_node_cnt[cur];
                max_node_cnt[next] = 1 + max_node_cnt[cur];
                pq.push({cost, next});
            }
        }
    }
 
    cout << visit_cost[n] << " ";
    cout << ways[n] << " ";
    cout << min_node_cnt[n] << " ";
    cout << max_node_cnt[n] << endl;
}
