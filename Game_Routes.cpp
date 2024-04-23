/*
DFS from 1 thru all neighbors of the node

when last node (Nth node) is reached return 1 - since there is 1 way to reach this node
store this result in all the nodes of the path from 1 to N.

when DFSing through the neighbors - if we reach a node that is already visited 
then return the ways to reach node N from that node.

vector<int> ways is our dp array

recurrence rel :
    ways[cur] = 1              -- when cur == Nth Node
    ways[cur] += dfs(next)     -- when next is not visited yet
    ways[cur] += ways[next]    -- when next is already visited

final ans = ways[1]
*/

#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> ways(n + 1, 0);
    vector<bool> visited(n + 1, false);


    auto dfs = [&](auto && self, int cur) -> int {

        visited[cur] = true;

        if (cur == n) return ways[n] = 1;

        if(adj[cur].size() == 0) return ways[cur] = 0;
        
        for (int next : adj[cur]) {
            
            if (!visited[next]) {
                (ways[cur] += self(self, next)) %= mod;
            } else {
                (ways[cur] += ways[next]) %= mod;
            }
        
        }

        return ways[cur];
    };

    dfs(dfs, 1);

    cout << ways[1] << endl;

}