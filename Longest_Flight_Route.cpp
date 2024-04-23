/*
DFS from 1 thru all neighbors of the node

when last node (Nth node) is reached return 1 - since there is 1 node in this route
add 1 and store this result in all the nodes of the path from 1 to N.

when DFSing through the neighbors - if we reach a node that is already visited 
then return 1 + nodes in path to reach node N from that node.

vector<int> node_count is our dp array

recurrence rel :
    node_count[cur] = 1                                        -- when cur == Nth Node
    node_count[cur] = max(node_count, 1 + dfs(next))           -- when next is not visited yet
    node_count[cur] = max(node_count[cur], node_count[next])   -- when next is already visited

set the child node accordingly when the a child with max nodes in its path is found

final ans = node_count[1]
iterate thru child and print path.
*/

#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> child(n + 1, -1);
    vector<int> node_count(n + 1, INT_MIN);
    vector<bool> visited(n + 1, false);


    auto dfs = [&](auto && self, int cur) -> int {

        visited[cur] = true;

        if (cur == n) return node_count[n] = 1;
        
        for (int next : adj[cur]) {
                
            int len = 1 + node_count[next];
            
            if (!visited[next]) {
                len = 1 + self(self, next);
            }

            if (len > node_count[cur]) {
                node_count[cur] = len;
                child[cur] = next;
            }
        }

        return node_count[cur];
    };

    dfs(dfs, 1);

    if (!visited[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << node_count[1] << endl;

    for (int v = 1; v != -1; v = child[v]) {
        cout << v << " ";
    }
}