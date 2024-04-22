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
 
    vector<int> parent(n + 1, -1);
    vector<int> visited_len(n + 1, 0);
    vector<bool> visited(n+1, false);
 
    /*
        DFS through the graph, while tracking parent nodes amd length of path
        
        if a node is already vistied with a longer length then do not visit again.
        
        If a node is visited with a lower length:
        - update visited_len of the node
        - update parent of the node and add to stack

        Pop elements from stack and repeat above steps.

        since nodes are being added to stack:
        - visited_len of nodes present at the end of path from 1 to N will be updated 
          before the nodes present in the middle of path
          so, if dfs is done from a node that is in the middle of path then it will not
          revisit the nodes at the end of path. since visited_len[next] > visited_len[cur]

        hence entire graph is traversed atmost twice.

        Solved after many many attempts. Tried the following approaches before coming up with the correct one:
        - DFS (revisit if visited_len[next] <= visited_len[cur])
        - BFS (PriorityQ with max visited_len at top)
        - DFS once to update visited_len of each node, DFS again if visited_len[next] <= visited_len[cur] - TLE on test 15
        - Topological sort (kahn's algorithm) - fails because our start point is 1 and any node can have inedges from other
          start points not in path from 1, these nodes may not be added to queue - wrong answer
        - DFS once and add newer updates to queue , same as correct approach but with queue and visit nodes at beginning of path first
        - DFS once and iterate from 1 to N and DFS again if any neighbor has less visited_len than current node - TLE
    */

    stack<int> stk;
 
    auto dfs = [&](auto &&self, int cur) -> void {
        for (int next : adj[cur]) {
            visited[cur] = 1;
            if (visited_len[next] <= visited_len[cur]) {

                parent[next] = cur;                
                visited_len[next] = visited_len[cur] + 1;
                
                if (!visited[next]){
                    self(self, next);
                } else {
                    stk.push(next);
                }
            }
        }
    };

    stk.push(1);

    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        dfs(dfs, cur);
    }
 
    if (parent[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
 
    cout << path.size() << endl;
    for (auto iter = path.rbegin(); iter != path.rend(); iter++)
        cout << *iter << " ";
}